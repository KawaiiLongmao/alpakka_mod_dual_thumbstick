#pragma once

#include "Library/common.h"
#include "hal_public.h"

namespace HAL_PWM
{

    /**
     * @brief 初始化 PWM 功能
     * @param pin GPIO 引脚编号
     * @param resolution_bit PWM 分辨率（位宽），默认 8 位
     * @param frequency_hz PWM 频率（Hz），默认 1000 Hz
     *
     * 此函数将指定 GPIO 引脚配置为 PWM 输出功能：
     * - 自动分配 PWM 通道和定时器
     * - 复用相同配置的定时器以节省资源
     * - 如果引脚已初始化，将立即返回
     *
     * 平台特定说明：
     * - Arduino:
     *   - 所有引脚共用同一个 PWM 定时器
     *   - 分辨率设置会影响所有引脚
     *   - 频率设置会影响所有引脚
     * - RP2040:
     *   - 引脚与 PWM 切片（slice）和通道（channel）固定绑定
     *   - 每个切片支持两个通道（A 和 B）
     *   - 同一切片的所有通道共享相同的频率和分辨率
     *   - 最多支持 8 个 PWM 切片（16 个通道）
     * - ESP32:
     *   - 支持高速模式（HS）和低速模式（LS）
     *   - 最多支持 8 个 PWM 通道（HS+LS）
     *   - 最多支持 4 个 PWM 定时器（HS+LS）
     *   - 自动优先选择高速模式
     */
    void Init(GPIONumber pin, uint8_t resolution_bit = 8, uint32_t frequency_hz = 1000);

    /**
     * @brief 去初始化 PWM 功能
     * @param pin GPIO 引脚编号
     *
     * 此函数将：
     * - 停止 PWM 输出
     * - 恢复 GPIO 为默认状态
     * - 释放 PWM 通道
     * - 如果定时器无其他通道使用，将暂停定时器
     *
     * 平台特定说明：
     * - Arduino:
     *   - 无法单独停用定时器，会影响所有引脚
     * - RP2040:
     *   - 当切片无其他通道使用时禁用切片
     *   - 切片配置保留，可被重新启用
     * - ESP32:
     *   - 当定时器引用计数为 0 时暂停定时器
     *   - 定时器配置保留，可被重新启用
     */
    void Deinit(GPIONumber pin);

    /**
     * @brief 设置 PWM 参数
     * @param pin GPIO 引脚编号
     * @param resolution_bit PWM 分辨率（位宽），0 表示保持当前值
     * @param frequency_hz PWM 频率（Hz），0 表示保持当前值
     *
     * 此函数更新指定引脚的 PWM 配置：
     * - 自动复用匹配配置的定时器
     * - 自动处理定时器共享情况
     * - 配置未更改时跳过操作
     *
     * 平台特定说明：
     * - Arduino:
     *   - 更改配置会影响所有引脚
     *   - 无法单独更改单个引脚的配置
     * - RP2040:
     *   - 同一切片的所有通道必须使用相同配置
     *   - 更改一个通道的配置会影响同一切片的所有通道
     *   - 如果切片有其他通道使用，将发出警告并强制更新配置
     * - ESP32:
     *   - 如果定时器被多个通道共享，将尝试查找空闲定时器
     *   - 若无空闲定时器，将拒绝更改配置
     */
    void SetPWMConfig(GPIONumber pin, uint8_t resolution_bit = 0, uint32_t frequency_hz = 0);

    /**
     * @brief 设置 PWM 占空比（比较计数值）
     * @param pin GPIO 引脚编号
     * @param duty_compare_count 占空比比较计数值
     *
     * 此函数直接设置 PWM 的占空比原始值：
     * - 范围取决于当前分辨率设置
     *   - 8位分辨率：0-255
     *   - 12位分辨率：0-4095
     *   - 16位分辨率：0-65535
     */
    void SetDutyCompareCount(GPIONumber pin, uint16_t duty_compare_count);

    /**
     * @brief 获取当前分辨率
     * @param pin GPIO 引脚编号
     * @return PWM 分辨率（位宽），如果未初始化则返回 0
     *
     * 平台特定说明：
     * - Arduino: 返回全局 PWM 分辨率
     * - RP2040: 返回所属切片的当前分辨率
     * - ESP32: 返回所属定时器的当前分辨率
     */
    uint8_t GetResolution(GPIONumber pin);

    /**
     * @brief 获取当前频率
     * @param pin GPIO 引脚编号
     * @return PWM 频率（Hz），如果未初始化则返回 0
     *
     * 平台特定说明：
     * - Arduino: 返回全局 PWM 频率
     * - RP2040: 返回所属切片的当前频率
     * - ESP32: 返回所属定时器的当前频率
     */
    uint32_t GetFrequency(GPIONumber pin);

    /**
     * @brief 获取最大比较计数值
     * @param pin GPIO 引脚编号
     * @return 最大占空比比较计数值，如果未初始化则返回 0
     *
     * 此函数根据当前分辨率计算最大占空比值：
     * - 例如：8位分辨率返回 255，12位分辨率返回 4095
     */
    inline uint16_t GetMaxDutyCount(GPIONumber pin)
    {
        const uint8_t resolution_bit = GetResolution(pin);
        if (resolution_bit == 0)
        {
            return 0;
        }
        const uint32_t max_possible_count = (1 << resolution_bit) - 1;
        return (uint16_t)max_possible_count;
    }

    /**
     * @brief 设置 PWM 占空比（百分比）
     * @param pin GPIO 引脚编号
     * @param duty_cycle 占空比百分比（0.0-1.0）
     *
     * 此函数将百分比占空比转换为原始值并设置：
     * - 自动处理范围限制（小于0设为0，大于1设为1）
     * - 自动计算对应的比较计数值
     */
    inline void SetDutyCycle(GPIONumber pin, float duty_cycle)
    {
        // 确保占空比在 0.0-1.0 范围内
        duty_cycle = duty_cycle < 0.f ? 0.f : (duty_cycle > 1.f ? 1.f : duty_cycle);
        const uint16_t max_possible_count = GetMaxDutyCount(pin);
        SetDutyCompareCount(pin, (uint16_t)(max_possible_count * duty_cycle));
    }

};
