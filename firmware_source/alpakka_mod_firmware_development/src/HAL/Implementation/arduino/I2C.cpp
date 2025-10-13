
#if (ARDUINO)
#include "HAL/I2C.h"

#include "Middleware/Log.h"
#include "HAL/GPIO.h"
#include "HAL/MCU.h"
#include <Arduino.h>
#include <Wire.h>

namespace HAL_I2C::Master
{

    namespace
    {
        // I2C 总线处理器数组
#if defined(ARDUINO_ARCH_RP2040)
        const auto s_bus_handler_ptr_array = std::array{&Wire, &Wire1};
#elif defined(ARDUINO_ARCH_ESP32)
        const auto s_bus_handler_ptr_array = std::array{&Wire, &Wire1};
#else
        const auto s_bus_handler_ptr_array = std::array{&Wire};
#endif

        // 设备句柄结构
        struct DeviceHandle
        {
            uint16_t addr;              // 设备地址
            uint8_t port;               // 绑定 I2C 端口号
            uint32_t freq = 400 * 1000; // I2C 时钟频率 (Hz)
        };

        // 设备句柄数组（固定大小）
        constexpr size_t MAX_DEVICES = 10; // 最大设备数量
        DeviceHandle s_device_handle_array[MAX_DEVICES] = {};
        size_t s_device_count = 0; // 当前设备数量

        /**
         * @brief 查找设备句柄
         * @param port I2C 端口号
         * @param addr 设备地址
         * @return 设备句柄指针，未找到返回nullptr
         */
        DeviceHandle *FindDeviceHandle(uint8_t port, uint16_t addr)
        {
            for (size_t i = 0; i < s_device_count; i++)
            {
                if (s_device_handle_array[i].port == port && s_device_handle_array[i].addr == addr)
                {
                    return &s_device_handle_array[i];
                }
            }
            return nullptr;
        }

        /**
         * @brief 内部写入函数
         * @param handle 设备句柄
         * @param write_buffer 写入数据缓冲区
         * @param write_size 写入数据大小
         * @param stop 是否发送停止位
         * @param timeout_ms 超时时间（毫秒）
         * @return 错误代码
         */
        ErrorCode InternalWrite(DeviceHandle *handle,
                                const uint8_t *write_buffer, size_t write_size,
                                bool stop, uint16_t timeout_ms)
        {
            // 检查端口有效性
            if (handle->port >= s_bus_handler_ptr_array.size())
            {
                LOG_PRINTF(Log::ERROR, "[HAL_I2C::InternalWrite] - Invalid port %d for device 0x%02X\n",
                           handle->port, handle->addr);
                return ERROR_CODE::GENERAL;
            }

            // 获取 I2C 总线指针
            auto bus_handler_ptr = s_bus_handler_ptr_array[handle->port];

            // 设置操作超时
#if defined(ARDUINO_ARCH_RP2040)
            bus_handler_ptr->setTimeout(timeout_ms);
#elif defined(ARDUINO_ARCH_ESP32)
            bus_handler_ptr->setTimeOut(timeout_ms);
#else
            bus_handler_ptr->setTimeout(timeout_ms);
#endif

            // 设置时钟频率
            bus_handler_ptr->setClock(handle->freq);

            // 开始传输
            bus_handler_ptr->beginTransmission(handle->addr);

            // 写入数据
            size_t written = bus_handler_ptr->write(write_buffer, write_size);

            // 结束传输（指定是否发送停止位）
            uint8_t result = bus_handler_ptr->endTransmission(stop);

            // 检查结果
            if (written != write_size)
            {
                LOG_PRINTF(Log::ERROR, "[HAL_I2C::InternalWrite] - Write failed: expected %d, wrote %d for device 0x%02X\n",
                           write_size, written, handle->addr);
                return ERROR_CODE::GENERAL;
            }

            if (result != 0)
            {
                LOG_PRINTF(Log::ERROR, "[HAL_I2C::InternalWrite] - Transmission failed with code %d for device 0x%02X\n",
                           result, handle->addr);
                return ERROR_CODE::GENERAL;
            }

            LOG_PRINTF(Log::DEBUG, "[HAL_I2C::InternalWrite] - Wrote %d bytes to device 0x%02X\n",
                       write_size, handle->addr);
            return ERROR_CODE::NONE;
        }

        /**
         * @brief 内部读取函数
         * @param handle 设备句柄
         * @param read_buffer 读取数据缓冲区
         * @param read_size 读取数据大小
         * @param stop 是否发送停止位
         * @param timeout_ms 超时时间（毫秒）
         * @return 错误代码
         */
        ErrorCode InternalRead(DeviceHandle *handle,
                               uint8_t *read_buffer, size_t read_size,
                               bool stop, uint16_t timeout_ms)
        {
            // 检查端口有效性
            if (handle->port >= s_bus_handler_ptr_array.size())
            {
                LOG_PRINTF(Log::ERROR, "[HAL_I2C::InternalRead] - Invalid port %d for device 0x%02X\n",
                           handle->port, handle->addr);
                return ERROR_CODE::GENERAL;
            }

            // 获取 I2C 总线指针
            auto bus_handler_ptr = s_bus_handler_ptr_array[handle->port];

            // 设置操作超时
#if defined(ARDUINO_ARCH_RP2040)
            bus_handler_ptr->setTimeout(timeout_ms);
#elif defined(ARDUINO_ARCH_ESP32)
            bus_handler_ptr->setTimeOut(timeout_ms);
#else
            bus_handler_ptr->setTimeout(timeout_ms);
#endif

            // 设置时钟频率
            bus_handler_ptr->setClock(handle->freq);

            // 请求数据
            size_t requested = bus_handler_ptr->requestFrom(handle->addr, read_size, stop);
            if (requested != read_size)
            {
                LOG_PRINTF(Log::ERROR, "[HAL_I2C::InternalRead] - Request failed: expected %d, requested %d for device 0x%02X\n",
                           read_size, requested, handle->addr);
                return ERROR_CODE::GENERAL;
            }

            // 读取数据
            size_t bytes_read = 0;
            while (bytes_read < read_size)
            {
                if (bus_handler_ptr->available())
                {
                    read_buffer[bytes_read] = bus_handler_ptr->read();
                    bytes_read++;
                }
            }

            LOG_PRINTF(Log::DEBUG, "[HAL_I2C::InternalRead] - Read %d bytes from device 0x%02X\n",
                       read_size, handle->addr);
            return ERROR_CODE::NONE;
        }
    } // namespace

    ErrorCode InitBus(uint8_t port, GPIONumber sda_pin, GPIONumber scl_pin)
    {
        LOG_PRINTF(Log::INFO, "[HAL_I2C::InitBus] - Initializing I2C bus on port %d\n", port);

        // 参数有效性检查
        if (port >= (sizeof(s_bus_handler_ptr_array) / sizeof(s_bus_handler_ptr_array[0])))
        {
            LOG_PRINTF(Log::ERROR, "[HAL_I2C::InitBus] - Invalid port %d\n", port);
            return ERROR_CODE::GENERAL;
        }

        // 获取 I2C 总线指针
        auto bus_handler_ptr = s_bus_handler_ptr_array[port];

        // 去初始化 I2C 总线
        bus_handler_ptr->end();

        // 初始化 I2C 总线
#if defined(ARDUINO_ARCH_RP2040)
        // RP2040: 设置引脚
        if (sda_pin != GPIO_UNUSED)
            bus_handler_ptr->setSDA(sda_pin);
        if (scl_pin != GPIO_UNUSED)
            bus_handler_ptr->setSCL(scl_pin);
        bus_handler_ptr->begin();
#elif defined(ARDUINO_ARCH_ESP32)
        // ESP32: 设置引脚
        bus_handler_ptr->begin((sda_pin != GPIO_UNUSED) ? sda_pin : -1,
                               (scl_pin != GPIO_UNUSED) ? scl_pin : -1);
#else
        // 其他平台: 使用默认引脚
        bus_handler_ptr->begin();
#endif

        // 检查引脚状态
        if (!HAL_GPIO::Get(sda_pin) || !HAL_GPIO::Get(scl_pin))
        {
            LOG_PRINTF(Log::ERROR, "[HAL_I2C::InitBus] - Pin check failed for port %d\n", port);
            HAL_MCU::Reboot();
            return ERROR_CODE::GENERAL;
        }

        LOG_PRINTF(Log::INFO, "[HAL_I2C::InitBus] - I2C bus initialized on port %d\n", port);
        return ERROR_CODE::NONE;
    }

    ErrorCode DeinitBus(uint8_t port)
    {
        LOG_PRINTF(Log::INFO, "[HAL_I2C::DeinitBus] - Deinitializing I2C bus on port %d\n", port);

        // 参数有效性检查
        if (port >= (sizeof(s_bus_handler_ptr_array) / sizeof(s_bus_handler_ptr_array[0])))
        {
            LOG_PRINTF(Log::ERROR, "[HAL_I2C::DeinitBus] - Invalid port %d\n", port);
            return ERROR_CODE::GENERAL;
        }

        // 获取 I2C 总线指针
        auto bus_handler_ptr = s_bus_handler_ptr_array[port];

        // 去初始化 I2C 总线
        bus_handler_ptr->end();

        LOG_PRINTF(Log::INFO, "[HAL_I2C::DeinitBus] - I2C bus deinitialized on port %d\n", port);
        return ERROR_CODE::NONE;
    }

    ErrorCode InitDevice(uint8_t port, uint16_t addr, uint32_t freq)
    {
        LOG_PRINTF(Log::INFO, "[HAL_I2C::InitDevice] - Initializing device 0x%02X on port %d\n", addr, port);

        // 检查设备是否已存在
        if (FindDeviceHandle(port, addr))
        {
            LOG_PRINTF(Log::ERROR, "[HAL_I2C::InitDevice] - Device 0x%02X on port %d already exists\n", addr, port);
            return ERROR_CODE::GENERAL;
        }

        // 检查设备数量限制
        if (s_device_count >= MAX_DEVICES)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_I2C::InitDevice] - Maximum device limit reached (%d)\n", MAX_DEVICES);
            return ERROR_CODE::GENERAL;
        }

        // 检查端口有效性
        if (port >= s_bus_handler_ptr_array.size())
        {
            LOG_PRINTF(Log::ERROR, "[HAL_I2C::InitDevice] - Invalid port %d for device 0x%02X\n", port, addr);
            return ERROR_CODE::GENERAL;
        }

        // 添加设备句柄
        s_device_handle_array[s_device_count] = {
            .addr = addr,
            .port = port,
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
            if (s_device_handle_array[i].port == port && s_device_handle_array[i].addr == addr)
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

        // 默认发送停止位
        return InternalWrite(handle, write_buffer, write_size, true, timeout_ms);
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

        // 默认发送停止位
        return InternalRead(handle, read_buffer, read_size, true, timeout_ms);
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

        // 先写入数据（不发送停止位）
        ErrorCode err = InternalWrite(handle, write_buffer, write_size, false, timeout_ms);
        if (err != ERROR_CODE::NONE)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_I2C::WriteRead] - Write failed for device 0x%02X on port %d\n", addr, port);
            return err;
        }

        // 再读取数据（发送停止位）
        err = InternalRead(handle, read_buffer, read_size, true, timeout_ms);
        if (err != ERROR_CODE::NONE)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_I2C::WriteRead] - Read failed for device 0x%02X on port %d\n", addr, port);
            return err;
        }

        LOG_PRINTF(Log::DEBUG, "[HAL_I2C::WriteRead] - WriteRead completed for device 0x%02X on port %d\n", addr, port);
        return ERROR_CODE::NONE;
    }

} // namespace HAL_I2C::Master
#endif
