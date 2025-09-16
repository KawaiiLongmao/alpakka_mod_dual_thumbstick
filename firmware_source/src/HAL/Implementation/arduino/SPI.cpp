
#if defined(ARDUINO)
#include "HAL/SPI.h"

#include "Middleware/Log.h"
#include <Arduino.h>
#include <SPI.h>

namespace HAL_SPI::Master
{

    namespace
    {
#if defined(ARDUINO_ARCH_RP2040)
        const auto s_bus_handler_ptr_array = std::array{&::SPI, &SPI1};
#elif defined(ARDUINO_ARCH_ESP32)
#if defined(CONFIG_IDF_TARGET_ESP32)
        SPIClass SPI1(FSPI);
        SPIClass SPI2(HSPI);
        const auto s_bus_handler_ptr_array = std::array{
            static_cast<SPIClass *>(nullptr),
            &SPI1,
            &SPI2,
            &::SPI};
#elif CONFIG_IDF_TARGET_ESP32S2 || CONFIG_IDF_TARGET_ESP32S3 || CONFIG_IDF_TARGET_ESP32P4
        SPIClass SPI3(HSPI);
        const auto s_bus_handler_ptr_array = std::array{
            static_cast<SPIClass *>(nullptr),
            static_cast<SPIClass *>(nullptr),
            &::SPI,
            &SPI3};
#else
        const auto s_bus_handler_ptr_array = std::array{
            static_cast<SPIClass *>(nullptr),
            static_cast<SPIClass *>(nullptr),
            &::SPI};
#endif
#else
        const auto s_bus_handler_ptr_array = std::array{&::SPI};
#endif

        // SPI 设备句柄结构
        struct DeviceHandle
        {
            uint8_t port;         // SPI 端口号
            GPIONumber cs_pin;    // 片选引脚
            SPISettings settings; // SPI 设置（时钟速度、位序、模式）
        };

        // 设备句柄数组（固定大小）
        constexpr size_t MAX_DEVICES = 10; // 最大设备数量
        DeviceHandle s_device_handle_array[MAX_DEVICES] = {};
        size_t s_device_count = 0; // 当前设备数量

        /**
         * @brief 查找设备句柄
         * @param port SPI 端口号
         * @param cs_pin 片选引脚
         * @return 设备句柄指针，未找到返回nullptr
         */
        DeviceHandle *FindDeviceHandle(uint8_t port, GPIONumber cs_pin)
        {
            for (size_t i = 0; i < s_device_count; i++)
            {
                if (s_device_handle_array[i].port == port &&
                    s_device_handle_array[i].cs_pin == cs_pin)
                {
                    return &s_device_handle_array[i];
                }
            }
            return nullptr;
        }
    }

    ErrorCode InitBus(uint8_t port, const BusConfig &config)
    {
        LOG_PRINTF(Log::INFO, "[HAL_SPI::InitBus] - Initializing SPI bus on port %d\n", port);

        // 参数有效性检查
        if (port >= s_bus_handler_ptr_array.size())
        {
            LOG_PRINTF(Log::ERROR, "[HAL_SPI::InitBus] - Invalid port %d\n", port);
            return ERROR_CODE::GENERAL;
        }

        // 获取 SPI 总线指针
        auto bus_handler_ptr = s_bus_handler_ptr_array[port];
        if (!bus_handler_ptr)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_SPI::InitBus] - Bus handler not found for port %d\n", port);
            return ERROR_CODE::GENERAL;
        }

        // 去初始化 SPI 总线
        bus_handler_ptr->end();

        // 初始化 SPI 总线
#if defined(ARDUINO_ARCH_RP2040)
        // RP2040: 设置引脚
        if (config.mosi_pin != GPIO_UNUSED)
            bus_handler_ptr->setMOSI(config.mosi_pin);
        if (config.miso_pin != GPIO_UNUSED)
            bus_handler_ptr->setMISO(config.miso_pin);
        if (config.sclk_pin != GPIO_UNUSED)
            bus_handler_ptr->setSCK(config.sclk_pin);
        bus_handler_ptr->begin(false);
#elif defined(ARDUINO_ARCH_ESP32)
        // ESP32: 设置引脚
        bus_handler_ptr->begin((config.sclk_pin != GPIO_UNUSED) ? config.sclk_pin : -1,
                               (config.miso_pin != GPIO_UNUSED) ? config.miso_pin : -1,
                               (config.mosi_pin != GPIO_UNUSED) ? config.mosi_pin : -1);
#else
        // 其他平台: 使用默认引脚
        bus_handler_ptr->begin();
#endif

        LOG_PRINTF(Log::INFO, "[HAL_SPI::InitBus] - SPI bus initialized on port %d\n", port);
        return ERROR_CODE::NONE;
    }

    ErrorCode DeinitBus(uint8_t port)
    {
        LOG_PRINTF(Log::INFO, "[HAL_SPI::DeinitBus] - Deinitializing SPI bus on port %d\n", port);

        // 参数有效性检查
        if (port >= s_bus_handler_ptr_array.size())
        {
            LOG_PRINTF(Log::ERROR, "[HAL_SPI::DeinitBus] - Invalid port %d\n", port);
            return ERROR_CODE::GENERAL;
        }

        // 获取 SPI 总线指针
        auto bus_handler_ptr = s_bus_handler_ptr_array[port];
        if (!bus_handler_ptr)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_SPI::DeinitBus] - Bus handler not found for port %d\n", port);
            return ERROR_CODE::GENERAL;
        }

        // 去初始化 SPI 总线
        bus_handler_ptr->end();

        LOG_PRINTF(Log::INFO, "[HAL_SPI::DeinitBus] - SPI bus deinitialized on port %d\n", port);
        return ERROR_CODE::NONE;
    }

    ErrorCode InitDevice(uint8_t port, GPIONumber cs_pin, const DeviceConfig &config)
    {
        LOG_PRINTF(Log::INFO, "[HAL_SPI::InitDevice] - Initializing device on port %d, CS pin %d\n", port, cs_pin);

        // 检查设备是否已存在
        if (FindDeviceHandle(port, cs_pin))
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
        if (port >= s_bus_handler_ptr_array.size())
        {
            LOG_PRINTF(Log::ERROR, "[HAL_SPI::InitDevice] - Invalid port %d\n", port);
            return ERROR_CODE::GENERAL;
        }

        // 初始化片选引脚（如果不是 GPIO_UNUSED）
        if (cs_pin != GPIO_UNUSED)
        {
            pinMode(cs_pin, OUTPUT);
            digitalWrite(cs_pin, HIGH);
        }

        // 转换 SPI 模式
        uint8_t spi_mode = SPI_MODE0;
        if (config.cpol == CPOL_0 && config.cpha == CPHA_0)
            spi_mode = SPI_MODE0;
        else if (config.cpol == CPOL_0 && config.cpha == CPHA_1)
            spi_mode = SPI_MODE1;
        else if (config.cpol == CPOL_1 && config.cpha == CPHA_0)
            spi_mode = SPI_MODE2;
        else if (config.cpol == CPOL_1 && config.cpha == CPHA_1)
            spi_mode = SPI_MODE3;

        // 转换位顺序
        const auto bit_order = (config.bit_order == LSB_FIRST) ? LSBFIRST : MSBFIRST;

        // 添加设备句柄
        s_device_handle_array[s_device_count] = {
            .port = port,
            .cs_pin = cs_pin,
            .settings = SPISettings(config.freq, bit_order, spi_mode)};
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
            if (s_device_handle_array[i].port == port &&
                s_device_handle_array[i].cs_pin == cs_pin)
            {
                // 移除设备：将最后一个元素移到当前位置
                s_device_handle_array[i] = s_device_handle_array[s_device_count - 1];
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
        // 查找设备句柄
        auto handle = FindDeviceHandle(port, cs_pin);
        if (!handle)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_SPI::Write] - Device not initialized on port %d, CS pin %d\n", port, cs_pin);
            return ERROR_CODE::GENERAL;
        }

        // 获取 SPI 总线指针
        auto bus_handler_ptr = s_bus_handler_ptr_array[port];

        // 激活设备（如果不是 GPIO_UNUSED）
        if (cs_pin != GPIO_UNUSED)
        {
            digitalWrite(cs_pin, LOW);
        }

        // 开始 SPI 传输事务
        bus_handler_ptr->beginTransaction(handle->settings);
        for (size_t i = 0; i < write_size; i++)
        {
            bus_handler_ptr->transfer(write_buffer[i]);
        }
        bus_handler_ptr->endTransaction();

        // 释放设备（如果不是 GPIO_UNUSED）
        if (cs_pin != GPIO_UNUSED)
        {
            digitalWrite(cs_pin, HIGH);
        }

        return ERROR_CODE::NONE;
    }

    ErrorCode Read(uint8_t port, GPIONumber cs_pin, uint8_t repeated_tx_data, uint8_t *read_buffer, size_t read_size)
    {
        // 查找设备句柄
        auto handle = FindDeviceHandle(port, cs_pin);
        if (!handle)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_SPI::Read] - Device not initialized on port %d, CS pin %d\n", port, cs_pin);
            return ERROR_CODE::GENERAL;
        }

        // 获取 SPI 总线指针
        auto bus_handler_ptr = s_bus_handler_ptr_array[port];

        // 激活设备（如果不是 GPIO_UNUSED）
        if (cs_pin != GPIO_UNUSED)
        {
            digitalWrite(cs_pin, LOW);
        }

        // 开始 SPI 传输事务
        bus_handler_ptr->beginTransaction(handle->settings);
        for (size_t i = 0; i < read_size; i++)
        {
            read_buffer[i] = bus_handler_ptr->transfer(repeated_tx_data);
        }
        bus_handler_ptr->endTransaction();

        // 释放设备（如果不是 GPIO_UNUSED）
        if (cs_pin != GPIO_UNUSED)
        {
            digitalWrite(cs_pin, HIGH);
        }

        return ERROR_CODE::NONE;
    }

    ErrorCode WriteRead(uint8_t port, GPIONumber cs_pin,
                        const uint8_t *write_buffer, size_t write_size,
                        uint8_t repeated_tx_data, uint8_t *read_buffer, size_t read_size)
    {
        // 查找设备句柄
        auto handle = FindDeviceHandle(port, cs_pin);
        if (!handle)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_SPI::WriteRead] - Device not initialized on port %d, CS pin %d\n", port, cs_pin);
            return ERROR_CODE::GENERAL;
        }

        // 获取 SPI 总线指针
        auto bus_handler_ptr = s_bus_handler_ptr_array[port];

        // 激活设备（如果不是 GPIO_UNUSED）
        if (cs_pin != GPIO_UNUSED)
        {
            digitalWrite(cs_pin, LOW);
        }

        // 开始 SPI 传输事务
        bus_handler_ptr->beginTransaction(handle->settings);

        // 写入数据
        for (size_t i = 0; i < write_size; i++)
        {
            bus_handler_ptr->transfer(write_buffer[i]);
        }

        // 读取数据
        for (size_t i = 0; i < read_size; i++)
        {
            read_buffer[i] = bus_handler_ptr->transfer(repeated_tx_data);
        }

        // 结束 SPI 传输事务
        bus_handler_ptr->endTransaction();

        // 释放设备（如果不是 GPIO_UNUSED）
        if (cs_pin != GPIO_UNUSED)
        {
            digitalWrite(cs_pin, HIGH);
        }

        return ERROR_CODE::NONE;
    }

} // namespace HAL_SPI::Master
#endif
