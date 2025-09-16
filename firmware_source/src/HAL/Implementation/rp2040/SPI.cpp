
#if defined(__has_include)
#if __has_include(<pico/version.h>)
#include <pico/version.h>
#endif
#endif

#if defined(PICO_SDK_VERSION_STRING) && !defined(ARDUINO)
#include "HAL/SPI.h"

#include "Middleware/Log.h"
#include "HAL/GPIO.h"
#include <hardware/gpio.h>
#include <hardware/spi.h>

namespace HAL_SPI::Master
{

    namespace
    {
        // SPI 总线处理器数组
        spi_inst_t *s_bus_handler_ptr_array[] = {spi0, spi1};

        // 总线配置数组
        BusConfig s_bus_config_array[sizeof(s_bus_handler_ptr_array) / sizeof(s_bus_handler_ptr_array[0])] = {};

        // 设备配置结构
        struct DeviceConfigInternal
        {
            uint8_t port;          // SPI 端口号
            GPIONumber cs_pin;     // 片选引脚
            spi_cpol_t cpol;       // 时钟极性
            spi_cpha_t cpha;       // 时钟相位
            spi_order_t bit_order; // 位顺序
            uint32_t freq;         // SPI 时钟频率 (Hz)
        };

        // 设备句柄数组（固定大小）
        constexpr size_t MAX_DEVICES = 10; // 最大设备数量
        DeviceConfigInternal s_device_config_array[MAX_DEVICES] = {};
        size_t s_device_count = 0; // 当前设备数量

        /**
         * @brief 查找设备配置
         * @param port SPI 端口号
         * @param cs_pin 片选引脚
         * @return 设备配置指针，未找到返回nullptr
         */
        DeviceConfigInternal *FindDeviceConfig(uint8_t port, GPIONumber cs_pin)
        {
            for (size_t i = 0; i < s_device_count; i++)
            {
                if (s_device_config_array[i].port == port &&
                    s_device_config_array[i].cs_pin == cs_pin)
                {
                    return &s_device_config_array[i];
                }
            }
            return nullptr;
        }
    }

    ErrorCode InitBus(uint8_t port, const BusConfig &config)
    {
        LOG_PRINTF(Log::INFO, "[HAL_SPI::InitBus] - Initializing SPI bus on port %d\n", port);

        // 参数有效性检查
        if (port >= sizeof(s_bus_handler_ptr_array) / sizeof(s_bus_handler_ptr_array[0]))
        {
            LOG_PRINTF(Log::ERROR, "[HAL_SPI::InitBus] - Invalid port %d\n", port);
            return ERROR_CODE::GENERAL;
        }

        // 获取 SPI 总线指针
        auto bus_handler_ptr = s_bus_handler_ptr_array[port];

        // 确定实际使用的引脚
        GPIONumber mosi_pin = config.mosi_pin;
        GPIONumber miso_pin = config.miso_pin;
        GPIONumber sclk_pin = config.sclk_pin;

        // 如果引脚为 GPIO_UNUSED，使用平台默认引脚
        if (mosi_pin == GPIO_UNUSED)
        {
            mosi_pin = (port == 0) ? 19 : 11; // RP2040 默认引脚
            LOG_PRINTF(Log::INFO, "[HAL_SPI::InitBus] - Using default MOSI pin %d for port %d\n", mosi_pin, port);
        }

        if (miso_pin == GPIO_UNUSED)
        {
            miso_pin = (port == 0) ? 16 : 8; // RP2040 默认引脚
            LOG_PRINTF(Log::INFO, "[HAL_SPI::InitBus] - Using default MISO pin %d for port %d\n", miso_pin, port);
        }

        if (sclk_pin == GPIO_UNUSED)
        {
            sclk_pin = (port == 0) ? 18 : 10; // RP2040 默认引脚
            LOG_PRINTF(Log::INFO, "[HAL_SPI::InitBus] - Using default SCLK pin %d for port %d\n", sclk_pin, port);
        }

        // 初始化 SPI 总线
        spi_init(bus_handler_ptr, 1000 * 1000); // 默认频率 1MHz

        // 设置引脚功能
        gpio_set_function(mosi_pin, GPIO_FUNC_SPI);
        gpio_set_function(miso_pin, GPIO_FUNC_SPI);
        gpio_set_function(sclk_pin, GPIO_FUNC_SPI);

        // 保存总线配置
        s_bus_config_array[port] = {
            .mosi_pin = mosi_pin,
            .miso_pin = miso_pin,
            .sclk_pin = sclk_pin};

        LOG_PRINTF(Log::INFO, "[HAL_SPI::InitBus] - SPI bus initialized on port %d\n", port);
        return ERROR_CODE::NONE;
    }

    ErrorCode DeinitBus(uint8_t port)
    {
        LOG_PRINTF(Log::INFO, "[HAL_SPI::DeinitBus] - Deinitializing SPI bus on port %d\n", port);

        // 参数有效性检查
        if (port >= sizeof(s_bus_handler_ptr_array) / sizeof(s_bus_handler_ptr_array[0]))
        {
            LOG_PRINTF(Log::ERROR, "[HAL_SPI::DeinitBus] - Invalid port %d\n", port);
            return ERROR_CODE::GENERAL;
        }

        // 获取 SPI 总线指针
        auto bus_handler_ptr = s_bus_handler_ptr_array[port];

        // 去初始化 SPI 总线
        spi_deinit(bus_handler_ptr);

        // 获取总线配置
        auto config = s_bus_config_array[port];

        // 恢复 GPIO 引脚为默认状态
        if (config.mosi_pin != GPIO_UNUSED)
        {
            gpio_set_function(config.mosi_pin, GPIO_FUNC_NULL);
            gpio_disable_pulls(config.mosi_pin);
            LOG_PRINTF(Log::DEBUG, "[HAL_SPI::DeinitBus] - Reset MOSI pin %d to default state\n", config.mosi_pin);
        }

        if (config.miso_pin != GPIO_UNUSED)
        {
            gpio_set_function(config.miso_pin, GPIO_FUNC_NULL);
            gpio_disable_pulls(config.miso_pin);
            LOG_PRINTF(Log::DEBUG, "[HAL_SPI::DeinitBus] - Reset MISO pin %d to default state\n", config.miso_pin);
        }

        if (config.sclk_pin != GPIO_UNUSED)
        {
            gpio_set_function(config.sclk_pin, GPIO_FUNC_NULL);
            gpio_disable_pulls(config.sclk_pin);
            LOG_PRINTF(Log::DEBUG, "[HAL_SPI::DeinitBus] - Reset SCLK pin %d to default state\n", config.sclk_pin);
        }

        LOG_PRINTF(Log::INFO, "[HAL_SPI::DeinitBus] - SPI bus deinitialized on port %d\n", port);
        return ERROR_CODE::NONE;
    }

    ErrorCode InitDevice(uint8_t port, GPIONumber cs_pin, const DeviceConfig &config)
    {
        LOG_PRINTF(Log::INFO, "[HAL_SPI::InitDevice] - Initializing device on port %d, CS pin %d\n", port, cs_pin);

        // 检查设备是否已存在
        if (FindDeviceConfig(port, cs_pin))
        {
            LOG_PRINTF(Log::ERROR, "[HAL_SPI::InitDevice] - Device already exists on port %d, CS pin %d\n", port, cs_pin);
            return ERROR_CODE::GENERAL;
        }

        // 检查设备数量限制
        if (s_device_count >= MAX_DEVICES)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_SPI::InitDevice] - Maximum device limit reached (%d)\n", MAX_DEVICES);
            return ERROR_CODE::GENERAL;
        }

        // 检查端口有效性
        if (port >= sizeof(s_bus_handler_ptr_array) / sizeof(s_bus_handler_ptr_array[0]))
        {
            LOG_PRINTF(Log::ERROR, "[HAL_SPI::InitDevice] - Invalid port %d for device\n", port);
            return ERROR_CODE::GENERAL;
        }

        // 初始化片选引脚（如果不是 GPIO_UNUSED）
        if (cs_pin != GPIO_UNUSED)
        {
            gpio_init(cs_pin);
            gpio_set_dir(cs_pin, GPIO_OUT);
            gpio_put(cs_pin, true);
            LOG_PRINTF(Log::DEBUG, "[HAL_SPI::InitDevice] - Initialized CS pin %d\n", cs_pin);
        }

        // 添加设备句柄
        s_device_config_array[s_device_count] = {
            .port = port,
            .cs_pin = cs_pin,
            .cpol = (spi_cpol_t)config.cpol,
            .cpha = (spi_cpha_t)config.cpha,
            .bit_order = (spi_order_t)config.bit_order,
            .freq = config.freq};
        s_device_count++;

        LOG_PRINTF(Log::INFO, "[HAL_SPI::InitDevice] - Device initialized on port %d, CS pin %d\n", port, cs_pin);
        return ERROR_CODE::NONE;
    }

    ErrorCode DeinitDevice(uint8_t port, GPIONumber cs_pin)
    {
        LOG_PRINTF(Log::INFO, "[HAL_SPI::DeinitDevice] - Deinitializing device on port %d, CS pin %d\n", port, cs_pin);

        // 查找设备索引
        for (size_t i = 0; i < s_device_count; i++)
        {
            if (s_device_config_array[i].port == port &&
                s_device_config_array[i].cs_pin == cs_pin)
            {
                // 移除设备：将最后一个元素移到当前位置
                s_device_config_array[i] = s_device_config_array[s_device_count - 1];
                s_device_count--;

                LOG_PRINTF(Log::INFO, "[HAL_SPI::DeinitDevice] - Device deinitialized on port %d, CS pin %d\n", port, cs_pin);
                return ERROR_CODE::NONE;
            }
        }

        LOG_PRINTF(Log::ERROR, "[HAL_SPI::DeinitDevice] - Device not found on port %d, CS pin %d\n", port, cs_pin);
        return ERROR_CODE::GENERAL;
    }

    ErrorCode Write(uint8_t port, GPIONumber cs_pin, const uint8_t *write_buffer, size_t write_size)
    {
        // 查找设备配置
        auto config = FindDeviceConfig(port, cs_pin);
        if (!config)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_SPI::Write] - Device not initialized on port %d, CS pin %d\n", port, cs_pin);
            return ERROR_CODE::GENERAL;
        }

        // 获取 SPI 总线指针
        auto bus_handler_ptr = s_bus_handler_ptr_array[port];

        // 设置 SPI 格式
        spi_set_format(bus_handler_ptr, 8, config->cpol, config->cpha, config->bit_order);

        // 设置 SPI 时钟频率
        spi_set_baudrate(bus_handler_ptr, config->freq);

        // 激活设备（如果不是 GPIO_UNUSED）
        if (cs_pin != GPIO_UNUSED)
        {
            gpio_put(cs_pin, false);
        }

        // 写入数据
        int result = spi_write_blocking(bus_handler_ptr, write_buffer, write_size);

        // 释放设备（如果不是 GPIO_UNUSED）
        if (cs_pin != GPIO_UNUSED)
        {
            gpio_put(cs_pin, true);
        }

        // 检查结果
        if (result != (int)write_size)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_SPI::Write] - Write failed for device on port %d, CS pin %d: %d/%d bytes written\n",
                        port, cs_pin, result, write_size);
            return ERROR_CODE::GENERAL;
        }

        LOG_PRINTF(Log::DEBUG, "[HAL_SPI::Write] - Wrote %d bytes to device on port %d, CS pin %d\n",
                    write_size, port, cs_pin);
        return ERROR_CODE::NONE;
    }

    ErrorCode Read(uint8_t port, GPIONumber cs_pin, uint8_t repeated_tx_data, uint8_t *read_buffer, size_t read_size)
    {
        // 查找设备配置
        auto config = FindDeviceConfig(port, cs_pin);
        if (!config)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_SPI::Read] - Device not initialized on port %d, CS pin %d\n", port, cs_pin);
            return ERROR_CODE::GENERAL;
        }

        // 获取 SPI 总线指针
        auto bus_handler_ptr = s_bus_handler_ptr_array[port];

        // 设置 SPI 格式
        spi_set_format(bus_handler_ptr, 8, config->cpol, config->cpha, config->bit_order);

        // 设置 SPI 时钟频率
        spi_set_baudrate(bus_handler_ptr, config->freq);

        // 激活设备（如果不是 GPIO_UNUSED）
        if (cs_pin != GPIO_UNUSED)
        {
            gpio_put(cs_pin, false);
        }

        // 读取数据
        int result = spi_read_blocking(bus_handler_ptr, repeated_tx_data, read_buffer, read_size);

        // 释放设备（如果不是 GPIO_UNUSED）
        if (cs_pin != GPIO_UNUSED)
        {
            gpio_put(cs_pin, true);
        }

        // 检查结果
        if (result != (int)read_size)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_SPI::Read] - Read failed for device on port %d, CS pin %d: %d/%d bytes read\n",
                        port, cs_pin, result, read_size);
            return ERROR_CODE::GENERAL;
        }

        LOG_PRINTF(Log::DEBUG, "[HAL_SPI::Read] - Read %d bytes from device on port %d, CS pin %d\n",
                    read_size, port, cs_pin);
        return ERROR_CODE::NONE;
    }

    ErrorCode WriteRead(uint8_t port, GPIONumber cs_pin,
                        const uint8_t *write_buffer, size_t write_size,
                        uint8_t repeated_tx_data, uint8_t *read_buffer, size_t read_size)
    {
        // 查找设备配置
        auto config = FindDeviceConfig(port, cs_pin);
        if (!config)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_SPI::WriteRead] - Device not initialized on port %d, CS pin %d\n", port, cs_pin);
            return ERROR_CODE::GENERAL;
        }

        // 获取 SPI 总线指针
        auto bus_handler_ptr = s_bus_handler_ptr_array[port];

        // 设置 SPI 格式
        spi_set_format(bus_handler_ptr, 8, config->cpol, config->cpha, config->bit_order);

        // 设置 SPI 时钟频率
        spi_set_baudrate(bus_handler_ptr, config->freq);

        // 激活设备（如果不是 GPIO_UNUSED）
        if (cs_pin != GPIO_UNUSED)
        {
            gpio_put(cs_pin, false);
        }

        // 写入数据
        int write_result = spi_write_blocking(bus_handler_ptr, write_buffer, write_size);

        // 检查写入结果
        if (write_result != (int)write_size)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_SPI::WriteRead] - Write failed for device on port %d, CS pin %d: %d/%d bytes written\n",
                        port, cs_pin, write_result, write_size);
            if (cs_pin != GPIO_UNUSED)
                gpio_put(cs_pin, true);
            return ERROR_CODE::GENERAL;
        }

        // 读取数据
        int read_result = spi_read_blocking(bus_handler_ptr, repeated_tx_data, read_buffer, read_size);

        // 释放设备（如果不是 GPIO_UNUSED）
        if (cs_pin != GPIO_UNUSED)
        {
            gpio_put(cs_pin, true);
        }

        // 检查读取结果
        if (read_result != (int)read_size)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_SPI::WriteRead] - Read failed for device on port %d, CS pin %d: %d/%d bytes read\n",
                        port, cs_pin, read_result, read_size);
            return ERROR_CODE::GENERAL;
        }

        LOG_PRINTF(Log::DEBUG, "[HAL_SPI::WriteRead] - WriteRead completed for device on port %d, CS pin %d\n",
                    port, cs_pin);
        return ERROR_CODE::NONE;
    }

}
#endif
