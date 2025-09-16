
#if defined(__has_include)
#if __has_include(<pico/version.h>)
#include <pico/version.h>
#endif
#endif

#if defined(PICO_SDK_VERSION_STRING) || defined(ARDUINO_ARCH_RP2040)
#include "HAL/PWM.h"

#include "Middleware/Log.h"
#include <hardware/gpio.h>
#include <hardware/pwm.h>
#include <hardware/clocks.h>

namespace HAL_PWM
{

    // PWM 模块内部状态管理
    namespace
    {
        // PWM 切片状态结构体
        struct SliceState
        {
            bool initialized = false;     // 切片是否已初始化
            bool enabled = false;         // 切片是否已启用
            uint8_t resolution_bit = 8;   // PWM 分辨率（位宽）
            uint32_t frequency_hz = 1000; // PWM 频率（Hz）
        };

        // PWM 通道状态结构体
        struct ChannelState
        {
            bool initialized = false;          // 通道是否已初始化
            GPIONumber gpio_num = GPIO_UNUSED; // 绑定的GPIO引脚号（使用0xFF表示未使用）
            uint8_t slice_num = 0;             // 所属的PWM切片编号
            uint8_t channel_num = 0;           // 通道编号 (0=A, 1=B)
        };

        // 切片状态数组 (RP2040 有 8 个 PWM 切片)
        std::array<SliceState, 8> s_slice_state_array = {};

        // 通道状态数组 (RP2040 有 16 个通道)
        std::array<ChannelState, 16> s_channel_state_array = {};

        /**
         * @brief 获取通道索引
         * @param slice_num PWM切片编号 (0-7)
         * @param channel_num 通道编号 (0或1)
         * @return 通道在状态数组中的索引
         */
        uint8_t get_channel_index(uint8_t slice_num, uint8_t channel_num)
        {
            return slice_num * 2 + channel_num;
        }

        /**
         * @brief 检查切片是否还有其他通道在使用
         * @param slice_num 切片编号
         * @param exclude_gpio 要排除的GPIO引脚（通常是要删除的引脚）
         * @return true如果有其他通道使用该切片，false如果没有
         */
        bool is_slice_used_by_other_channels(uint8_t slice_num, GPIONumber exclude_gpio = GPIO_UNUSED)
        {
            for (uint8_t i = 0; i < 2; i++)
            {
                uint8_t idx = get_channel_index(slice_num, i);
                if (s_channel_state_array[idx].initialized &&
                    s_channel_state_array[idx].gpio_num != exclude_gpio)
                {
                    return true;
                }
            }
            return false;
        }

        /**
         * @brief 配置 PWM 切片参数
         * @param slice_num PWM 切片编号 (0-7)
         * @param resolution_bit PWM 分辨率（位宽）
         * @param frequency_hz PWM 频率（Hz）
         */
        void ConfigureSlice(uint slice_num, uint8_t resolution_bit, uint32_t frequency_hz)
        {
            SliceState &slice_state = s_slice_state_array[slice_num];

            // 检查是否需要更新配置
            if (slice_state.initialized &&
                slice_state.resolution_bit == resolution_bit &&
                slice_state.frequency_hz == frequency_hz)
            {
                LOG_PRINTF(Log::DEBUG, "HAL_PWM::ConfigureSlice - Slice %u config unchanged\n", slice_num);
                return;
            }

            // 计算新的占空比最大值（wrap值）
            const uint16_t new_wrap = (1 << resolution_bit) - 1;

            // 获取系统时钟频率
            const uint32_t sys_clock_freq = clock_get_hz(clk_sys);

            // 计算时钟分频系数
            const float clk_div = (float)sys_clock_freq / (frequency_hz * (new_wrap + 1));

            // 禁用 PWM 切片以安全更新配置
            pwm_set_enabled(slice_num, false);

            // 配置PWM切片
            pwm_config cfg = pwm_get_default_config();
            pwm_config_set_clkdiv_mode(&cfg, PWM_DIV_FREE_RUNNING);
            pwm_config_set_clkdiv(&cfg, clk_div);
            pwm_config_set_wrap(&cfg, new_wrap);
            pwm_init(slice_num, &cfg, false); // 初始化但不立即启用

            // 更新切片状态
            slice_state.resolution_bit = resolution_bit;
            slice_state.frequency_hz = frequency_hz;
            slice_state.initialized = true;

            LOG_PRINTF(Log::INFO, "HAL_PWM::ConfigureSlice - Slice %u configured: res=%ubit, freq=%uHz\n",
                       slice_num, resolution_bit, frequency_hz);
        }
    } // namespace

    void Init(GPIONumber pin, uint8_t resolution_bit, uint32_t frequency_hz)
    {
        LOG_PRINTF(Log::INFO, "HAL_PWM::Init - Start! Pin: %d, Resolution: %d-bit, Freq: %dHz\n",
                   pin, resolution_bit, frequency_hz);

        // 验证引脚编号有效性
        if (pin >= HAL_GPIO_MAX_NUMBER)
        {
            LOG_PRINTF(Log::ERROR, "HAL_PWM::Init - Invalid pin: %u\n", pin);
            return;
        }

        // 检查引脚是否已初始化
        for (const auto &state : s_channel_state_array)
        {
            if (state.initialized && state.gpio_num == pin)
            {
                LOG_PRINTF(Log::ERROR, "HAL_PWM::Init - PWM already initialized for pin %d\n", pin);
                return;
            }
        }

        // 获取 PWM 切片编号和通道编号
        const uint slice_num = pwm_gpio_to_slice_num(pin);
        const uint channel_num = pwm_gpio_to_channel(pin);
        const uint8_t channel_idx = get_channel_index(slice_num, channel_num);

        // 检查通道是否已初始化
        if (s_channel_state_array[channel_idx].initialized)
        {
            LOG_PRINTF(Log::ERROR, "HAL_PWM::Init - Channel %u on slice %u already initialized\n",
                       channel_num, slice_num);
            return;
        }

        // 获取切片状态
        SliceState &slice_state = s_slice_state_array[slice_num];

        // 检查切片是否已初始化
        if (slice_state.initialized)
        {
            // 检查配置是否匹配
            if (slice_state.resolution_bit != resolution_bit ||
                slice_state.frequency_hz != frequency_hz)
            {
                LOG_PRINTF(Log::WARNING, "HAL_PWM::Init - Slice %u already configured with different settings (%ubit @ %uHz)\n",
                           slice_num, slice_state.resolution_bit, slice_state.frequency_hz);
            }
        }

        // 设置 GPIO 为 PWM 功能
        gpio_set_function(pin, GPIO_FUNC_PWM);

        // 配置 PWM 切片参数
        ConfigureSlice(slice_num, resolution_bit, frequency_hz);

        // 确保切片已启用
        if (!slice_state.enabled)
        {
            pwm_set_enabled(slice_num, true);
            slice_state.enabled = true;
            LOG_PRINTF(Log::INFO, "HAL_PWM::Init - Enabled slice %u\n", slice_num);
        }

        // 初始化占空比为 0（关闭输出）
        pwm_set_gpio_level(pin, 0);

        // 更新通道状态
        s_channel_state_array[channel_idx] = {
            .initialized = true,
            .gpio_num = pin,
            .slice_num = static_cast<uint8_t>(slice_num),
            .channel_num = static_cast<uint8_t>(channel_num)};

        LOG_PRINTF(Log::INFO, "HAL_PWM::Init - PWM initialized: Pin %d, Slice %u, Channel %u\n",
                   pin, slice_num, channel_num);
    }

    void Deinit(GPIONumber pin)
    {
        LOG_PRINTF(Log::INFO, "HAL_PWM::Deinit - Start! Pin: %d\n", pin);

        // 验证引脚编号有效性
        if (pin >= HAL_GPIO_MAX_NUMBER)
        {
            LOG_PRINTF(Log::ERROR, "HAL_PWM::Deinit - Invalid pin: %u\n", pin);
            return;
        }

        // 查找通道状态
        ChannelState *channel_state = nullptr;
        for (auto &state : s_channel_state_array)
        {
            if (state.initialized && state.gpio_num == pin)
            {
                channel_state = &state;
                break;
            }
        }

        if (!channel_state)
        {
            LOG_PRINTF(Log::WARNING, "HAL_PWM::Deinit - PWM not initialized for pin %d\n", pin);
            return;
        }

        // 禁用 PWM 输出（设置占空比为 0）
        pwm_set_gpio_level(pin, 0);

        // 恢复 GPIO 为默认状态
        gpio_set_function(pin, GPIO_FUNC_NULL);

        // 获取切片编号
        const uint8_t slice_num = channel_state->slice_num;
        SliceState &slice_state = s_slice_state_array[slice_num];

        // 检查切片是否还有其他通道在使用
        bool other_channels_active = is_slice_used_by_other_channels(slice_num, pin);

        // 如果没有其他通道使用该切片，禁用切片
        if (!other_channels_active && slice_state.enabled)
        {
            pwm_set_enabled(slice_num, false);
            slice_state.enabled = false;
            LOG_PRINTF(Log::INFO, "HAL_PWM::Deinit - Disabled slice %u\n", slice_num);
        }

        // 重置通道状态
        *channel_state = {};
        channel_state->gpio_num = GPIO_UNUSED; // 明确标记为未使用

        LOG_PRINTF(Log::INFO, "HAL_PWM::Deinit - PWM deinitialized for pin %d\n", pin);
    }

    void SetPWMConfig(GPIONumber pin, uint8_t resolution_bit, uint32_t frequency_hz)
    {
        LOG_PRINTF(Log::INFO, "HAL_PWM::SetPWMConfig - Start! Pin: %d, Resolution: %d-bit, Freq: %dHz\n",
                   pin, resolution_bit, frequency_hz);

        // 查找通道状态
        ChannelState *channel_state = nullptr;
        for (auto &state : s_channel_state_array)
        {
            if (state.initialized && state.gpio_num == pin)
            {
                channel_state = &state;
                break;
            }
        }

        if (!channel_state)
        {
            LOG_PRINTF(Log::WARNING, "HAL_PWM::SetPWMConfig - PWM not initialized for pin %d\n", pin);
            return;
        }

        // 使用当前值作为默认值（如果参数为0）
        if (resolution_bit == 0)
            resolution_bit = s_slice_state_array[channel_state->slice_num].resolution_bit;
        if (frequency_hz == 0)
            frequency_hz = s_slice_state_array[channel_state->slice_num].frequency_hz;

        // 获取切片编号
        const uint8_t slice_num = channel_state->slice_num;

        // 检查切片是否还有其他通道在使用
        bool other_channels_active = is_slice_used_by_other_channels(slice_num, pin);

        if (other_channels_active)
        {
            LOG_PRINTF(Log::WARNING, "HAL_PWM::SetPWMConfig - Slice %u has other active channels, config not changed\n", slice_num);
            return;
        }

        // 重新配置切片
        ConfigureSlice(slice_num, resolution_bit, frequency_hz);

        // 确保切片已启用
        if (!s_slice_state_array[slice_num].enabled)
        {
            pwm_set_enabled(slice_num, true);
            s_slice_state_array[slice_num].enabled = true;
            LOG_PRINTF(Log::INFO, "HAL_PWM::SetPWMConfig - Enabled slice %u\n", slice_num);
        }

        LOG_PRINTF(Log::INFO, "HAL_PWM::SetPWMConfig - PWM config updated: Pin %d, %d-bit @ %dHz\n", pin, resolution_bit, frequency_hz);
    }

    void SetDutyCompareCount(GPIONumber pin, uint16_t duty_compare_count)
    {
        // 直接设置 PWM 占空比
        pwm_set_gpio_level(pin, duty_compare_count);
    }

    uint8_t GetResolution(GPIONumber pin)
    {
        // 获取 PWM 切片编号
        const uint slice_num = pwm_gpio_to_slice_num(pin);

        // 获取切片状态引用
        const SliceState &slice_state = s_slice_state_array[slice_num];

        // 参数验证
        if (pin >= HAL_GPIO_MAX_NUMBER || !slice_state.initialized)
        {
            LOG_PRINTF(Log::WARNING, "HAL_PWM::GetResolution - pin %d\n", pin);
            return 0;
        }

        return slice_state.resolution_bit;
    }

    uint32_t GetFrequency(GPIONumber pin)
    {
        // 获取 PWM 切片编号
        const uint slice_num = pwm_gpio_to_slice_num(pin);

        // 获取切片状态引用
        const SliceState &slice_state = s_slice_state_array[slice_num];

        // 参数验证
        if (pin >= HAL_GPIO_MAX_NUMBER || !slice_state.initialized)
        {
            LOG_PRINTF(Log::WARNING, "HAL_PWM::GetFrequency - pin %d\n", pin);
            return 0;
        }

        return slice_state.frequency_hz;
    }

}
#endif
