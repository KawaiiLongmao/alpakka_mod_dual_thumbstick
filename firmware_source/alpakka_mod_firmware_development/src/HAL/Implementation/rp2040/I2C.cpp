
#if defined(__has_include)
#if __has_include(<pico/version.h>)
#include <pico/version.h>
#endif
#endif

#if defined(PICO_SDK_VERSION_STRING) && !defined(ARDUINO)
#include "HAL/I2C.h"

#include "Middleware/Log.h"
#include "HAL/GPIO.h"
#include "HAL/MCU.h"
#include <hardware/gpio.h>
#include <hardware/i2c.h>

namespace HAL_I2C::Master
{
    namespace
    {
        // I2C 总线处理器数组
        i2c_inst_t *s_bus_handler_ptr_array[] = {i2c0, i2c1};

        // 总线配置结构
        struct BusConfigInternal
        {
            GPIONumber sda_pin; // SDA 引脚
            GPIONumber scl_pin; // SCL 引脚
        };

        // 总线配置数组
        BusConfigInternal s_bus_config_array[sizeof(s_bus_handler_ptr_array) / sizeof(s_bus_handler_ptr_array[0])] = {};

        // 设备句柄结构
        struct DeviceHandleInternal
        {
            uint8_t port;  // I2C 端口号
            uint16_t addr; // 设备地址
            uint32_t freq; // I2C 时钟频率 (Hz)
        };

        // 设备句柄数组（固定大小）
        constexpr size_t MAX_DEVICES = 10; // 最大设备数量
        DeviceHandleInternal s_device_handle_array[MAX_DEVICES] = {};
        size_t s_device_count = 0; // 当前设备数量

        /**
         * @brief 查找设备句柄
         * @param port I2C 端口号
         * @param addr 设备地址
         * @return 设备句柄指针，未找到返回nullptr
         */
        DeviceHandleInternal *FindDeviceHandle(uint8_t port, uint16_t addr)
        {
            for (size_t i = 0; i < s_device_count; i++)
            {
                if (s_device_handle_array[i].port == port &&
                    s_device_handle_array[i].addr == addr)
                {
                    return &s_device_handle_array[i];
                }
            }
            return nullptr;
        }
    } // namespace

    ErrorCode InitBus(uint8_t port, GPIONumber sda_pin, GPIONumber scl_pin)
    {
        LOG_PRINTF(Log::INFO, "[HAL_I2C::InitBus] - Initializing I2C bus on port %d\n", port);

        // 参数有效性检查
        if (port >= sizeof(s_bus_handler_ptr_array) / sizeof(s_bus_handler_ptr_array[0]))
        {
            LOG_PRINTF(Log::ERROR, "[HAL_I2C::InitBus] - Invalid port %d\n", port);
            return ERROR_CODE::GENERAL;
        }

        // 获取 I2C 总线指针
        auto bus_handler_ptr = s_bus_handler_ptr_array[port];

        // 确定实际使用的引脚
        if (sda_pin == GPIO_UNUSED)
        {
            sda_pin = (port == 0) ? 4 : 26; // RP2040 默认引脚
            LOG_PRINTF(Log::INFO, "[HAL_I2C::InitBus] - Using default SDA pin %d for port %d\n", sda_pin, port);
        }

        if (scl_pin == GPIO_UNUSED)
        {
            scl_pin = (port == 0) ? 5 : 27; // RP2040 默认引脚
            LOG_PRINTF(Log::INFO, "[HAL_I2C::InitBus] - Using default SCL pin %d for port %d\n", scl_pin, port);
        }

        // 初始化 I2C 总线
        i2c_init(bus_handler_ptr, 400 * 1000); // 默认频率 400kHz

        // 设置引脚功能
        gpio_set_function(sda_pin, GPIO_FUNC_I2C);
        gpio_set_function(scl_pin, GPIO_FUNC_I2C);

        // 启用上拉电阻
        gpio_pull_up(sda_pin);
        gpio_pull_up(scl_pin);

        // 检查引脚状态
        if (!HAL_GPIO::Get(sda_pin) || !HAL_GPIO::Get(scl_pin))
        {
            LOG_PRINTF(Log::ERROR, "[HAL_I2C::InitBus] - Pin check failed for port %d\n", port);
            HAL_MCU::Reboot();
            return ERROR_CODE::GENERAL;
        }

        // 保存总线配置
        s_bus_config_array[port] = {
            .sda_pin = sda_pin,
            .scl_pin = scl_pin};

        LOG_PRINTF(Log::INFO, "[HAL_I2C::InitBus] - I2C bus initialized on port %d\n", port);
        return ERROR_CODE::NONE;
    }

    ErrorCode DeinitBus(uint8_t port)
    {
        LOG_PRINTF(Log::INFO, "[HAL_I2C::DeinitBus] - Deinitializing I2C bus on port %d\n", port);

        // 参数有效性检查
        if (port >= sizeof(s_bus_handler_ptr_array) / sizeof(s_bus_handler_ptr_array[0]))
        {
            LOG_PRINTF(Log::ERROR, "[HAL_I2C::DeinitBus] - Invalid port %d\n", port);
            return ERROR_CODE::GENERAL;
        }

        // 获取 I2C 总线指针
        auto bus_handler_ptr = s_bus_handler_ptr_array[port];

        // 去初始化 I2C 总线
        i2c_deinit(bus_handler_ptr);

        // 获取总线配置
        auto config = s_bus_config_array[port];

        // 恢复 GPIO 为默认状态
        if (config.sda_pin != GPIO_UNUSED)
        {
            gpio_set_function(config.sda_pin, GPIO_FUNC_NULL);
            gpio_disable_pulls(config.sda_pin);
            LOG_PRINTF(Log::DEBUG, "[HAL_I2C::DeinitBus] - Reset SDA pin %d to default state\n", config.sda_pin);
        }

        if (config.scl_pin != GPIO_UNUSED)
        {
            gpio_set_function(config.scl_pin, GPIO_FUNC_NULL);
            gpio_disable_pulls(config.scl_pin);
            LOG_PRINTF(Log::DEBUG, "[HAL_I2C::DeinitBus] - Reset SCL pin %d to default state\n", config.scl_pin);
        }

        LOG_PRINTF(Log::INFO, "[HAL_I2C::DeinitBus] - I2C bus deinitialized on port %d\n", port);
        return ERROR_CODE::NONE;
    }

    ErrorCode InitDevice(uint8_t port, uint16_t addr, uint32_t freq)
    {
        LOG_PRINTF(Log::INFO, "[HAL_I2C::InitDevice] - Initializing device 0x%02X on port %d\n", addr, port);

        // 检查设备是否已存在
        if (FindDeviceHandle(port, addr))
        {
            LOG_PRINTF(Log::ERROR, "[HAL_I2C::InitDevice] - Device 0x%02X already exists on port %d\n", addr, port);
            return ERROR_CODE::GENERAL;
        }

        // 检查设备数量限制
        if (s_device_count >= MAX_DEVICES)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_I2C::InitDevice] - Maximum device limit reached (%d)\n", MAX_DEVICES);
            return ERROR_CODE::GENERAL;
        }

        // 检查端口有效性
        if (port >= sizeof(s_bus_handler_ptr_array) / sizeof(s_bus_handler_ptr_array[0]))
        {
            LOG_PRINTF(Log::ERROR, "[HAL_I2C::InitDevice] - Invalid port %d for device 0x%02X\n", port, addr);
            return ERROR_CODE::GENERAL;
        }

        // 添加设备句柄
        s_device_handle_array[s_device_count] = {
            .port = port,
            .addr = addr,
            .freq = freq};
        s_device_count++;

        LOG_PRINTF(Log::INFO, "[HAL_I2C::InitDevice] - Device 0x%02X initialized on port %d @ %dHz\n",
                   addr, port, freq);
        return ERROR_CODE::NONE;
    }

    ErrorCode DeinitDevice(uint8_t port, uint16_t addr)
    {
        LOG_PRINTF(Log::INFO, "[HAL_I2C::DeinitDevice] - Deinitializing device 0x%02X on port %d\n", addr, port);

        // 查找设备索引
        for (size_t i = 0; i < s_device_count; i++)
        {
            if (s_device_handle_array[i].port == port &&
                s_device_handle_array[i].addr == addr)
            {
                // 移除设备：将最后一个元素移到当前位置
                s_device_handle_array[i] = s_device_handle_array[s_device_count - 1];
                s_device_count--;

                LOG_PRINTF(Log::INFO, "[HAL_I2C::DeinitDevice] - Device 0x%02X deinitialized on port %d\n", addr, port);
                return ERROR_CODE::NONE;
            }
        }

        LOG_PRINTF(Log::ERROR, "[HAL_I2C::DeinitDevice] - Device 0x%02X not found on port %d\n", addr, port);
        return ERROR_CODE::GENERAL;
    }

    ErrorCode Write(uint8_t port, uint16_t addr,
                    const uint8_t *write_buffer, size_t write_size, uint16_t timeout_ms)
    {
        // 查找设备句柄
        auto handle = FindDeviceHandle(port, addr);
        if (!handle)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_I2C::Write] - Device 0x%02X not initialized on port %d\n", addr, port);
            return ERROR_CODE::GENERAL;
        }

        // 获取 I2C 总线指针
        auto bus_handler_ptr = s_bus_handler_ptr_array[port];

        // 设置时钟频率
        i2c_set_baudrate(bus_handler_ptr, handle->freq);

        // 写入数据
        int result = i2c_write_timeout_us(bus_handler_ptr, addr, write_buffer, write_size, false, timeout_ms * 1000);
        if (result != (int)write_size)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_I2C::Write] - Write failed for device 0x%02X: %d\n", addr, result);
            return ERROR_CODE::GENERAL;
        }

        LOG_PRINTF(Log::DEBUG, "[HAL_I2C::Write] - Wrote %d bytes to device 0x%02X\n", write_size, addr);
        return ERROR_CODE::NONE;
    }

    ErrorCode Read(uint8_t port, uint16_t addr,
                   uint8_t *read_buffer, size_t read_size, uint16_t timeout_ms)
    {
        // 查找设备句柄
        auto handle = FindDeviceHandle(port, addr);
        if (!handle)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_I2C::Read] - Device 0x%02X not initialized on port %d\n", addr, port);
            return ERROR_CODE::GENERAL;
        }

        // 获取 I2C 总线指针
        auto bus_handler_ptr = s_bus_handler_ptr_array[port];

        // 设置时钟频率
        i2c_set_baudrate(bus_handler_ptr, handle->freq);

        // 读取数据
        int result = i2c_read_timeout_us(bus_handler_ptr, addr, read_buffer, read_size, false, timeout_ms * 1000);
        if (result != (int)read_size)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_I2C::Read] - Read failed for device 0x%02X: %d\n", addr, result);
            return ERROR_CODE::GENERAL;
        }

        LOG_PRINTF(Log::DEBUG, "[HAL_I2C::Read] - Read %d bytes from device 0x%02X\n", read_size, addr);
        return ERROR_CODE::NONE;
    }

    ErrorCode WriteRead(uint8_t port, uint16_t addr,
                        const uint8_t *write_buffer, size_t write_size,
                        uint8_t *read_buffer, size_t read_size, uint16_t timeout_ms)
    {
        // 查找设备句柄
        auto handle = FindDeviceHandle(port, addr);
        if (!handle)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_I2C::WriteRead] - Device 0x%02X not initialized on port %d\n", addr, port);
            return ERROR_CODE::GENERAL;
        }

        // 获取 I2C 总线指针
        auto bus_handler_ptr = s_bus_handler_ptr_array[port];

        // 设置时钟频率
        i2c_set_baudrate(bus_handler_ptr, handle->freq);

        // 先写入数据（不发送停止位）
        int write_result = i2c_write_timeout_us(bus_handler_ptr, addr, write_buffer, write_size, true, timeout_ms * 1000);
        if (write_result != (int)write_size)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_I2C::WriteRead] - Write failed for device 0x%02X: %d\n", addr, write_result);
            return ERROR_CODE::GENERAL;
        }

        // 再读取数据
        int read_result = i2c_read_timeout_us(bus_handler_ptr, addr, read_buffer, read_size, false, timeout_ms * 1000);
        if (read_result != (int)read_size)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_I2C::WriteRead] - Read failed for device 0x%02X: %d\n", addr, read_result);
            return ERROR_CODE::GENERAL;
        }

        LOG_PRINTF(Log::DEBUG, "[HAL_I2C::WriteRead] - WriteRead completed for device 0x%02X\n", addr);
        return ERROR_CODE::NONE;
    }

} // namespace HAL_I2C::Master
#endif
