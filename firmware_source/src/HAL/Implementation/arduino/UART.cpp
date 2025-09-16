
#if defined(ARDUINO)
#include "HAL/UART.h"

#include <Arduino.h>

namespace HAL_UART
{

#if defined(ARDUINO_ARCH_RP2040)
    static const auto s_uart_handler_ptr_array = std::array{&Serial1, &Serial2};
#elif defined(ARDUINO_ARCH_ESP32)
    static const auto s_uart_handler_ptr_array = std::array{&Serial, &Serial1, &Serial2};
#elif defined(ARDUINO_ARCH_STM32)
#if defined(STM32F411xE)
    static const auto s_uart_handler_ptr_array = std::array{
        static_cast<HardwareSerial *>(nullptr),
        &Serial1,
        &Serial2,
        static_cast<HardwareSerial *>(nullptr),
        static_cast<HardwareSerial *>(nullptr),
        static_cast<HardwareSerial *>(nullptr),
        &Serial6};
#endif
#else
    static const auto s_uart_handler_ptr_array = std::array{&Serial, &Serial1};
#endif

    // 定义配置映射表
    static const uint32_t SERIAL_CONFIG_MAP[4][2][3] = {
        // 数据位5
        {
            // 停止位1
            {SERIAL_5N1, SERIAL_5E1, SERIAL_5O1},
            // 停止位2
            {SERIAL_5N2, SERIAL_5E2, SERIAL_5O2}},
        // 数据位6
        {
            // 停止位1
            {SERIAL_6N1, SERIAL_6E1, SERIAL_6O1},
            // 停止位2
            {SERIAL_6N2, SERIAL_6E2, SERIAL_6O2}},
        // 数据位7
        {
            // 停止位1
            {SERIAL_7N1, SERIAL_7E1, SERIAL_7O1},
            // 停止位2
            {SERIAL_7N2, SERIAL_7E2, SERIAL_7O2}},
        // 数据位8
        {
            // 停止位1
            {SERIAL_8N1, SERIAL_8E1, SERIAL_8O1},
            // 停止位2
            {SERIAL_8N2, SERIAL_8E2, SERIAL_8O2}}};

    static uint32_t GetSerialConfigFlags(uint8_t data_bits, uint8_t stop_bits, Parity parity)
    {
        // 转换数据位索引 (5->0, 6->1, 7->2, 8->3)
        const int data_idx = (data_bits >= 5 && data_bits <= 8) ? (data_bits - 5) : 3;

        // 转换停止位索引 (1->0, 2->1)
        const int stop_idx = (stop_bits == 2) ? 1 : 0;

        // 转换校验位索引 (NONE->0, EVEN->1, ODD->2)
        int parity_idx = 0;
        switch (parity)
        {
        case Parity::EVEN:
            parity_idx = 1;
            break;
        case Parity::ODD:
            parity_idx = 2;
            break;
        default:
            parity_idx = 0;
            break;
        }

        // 返回配置值
        return SERIAL_CONFIG_MAP[data_idx][stop_idx][parity_idx];
    }

    ErrorCode Init(const Config &config)
    {
        // 参数有效性检查
        if (config.port >= (sizeof(s_uart_handler_ptr_array) / sizeof(s_uart_handler_ptr_array[0])))
        {
            return ERROR_CODE::GENERAL;
        }

        // 获取 UART 操作器指针
        auto uart_handler_ptr = s_uart_handler_ptr_array[config.port];
        if (!uart_handler_ptr)
        {
            return ERROR_CODE::GENERAL;
        }

        // 去初始化串口
        uart_handler_ptr->end();

        // 配置串口参数
        const uint32_t config_flags = GetSerialConfigFlags(config.data_bits,
                                                           config.stop_bits,
                                                           config.parity);

#if defined(ARDUINO_ARCH_RP2040)
        // 设置引脚
        uart_handler_ptr->setTX(config.txd_pin);
        uart_handler_ptr->setRX(config.rxd_pin);

        // 初始化串口
        uart_handler_ptr->begin(config.baud_rate, (uint16_t)config_flags);
#elif defined(ARDUINO_ARCH_ESP32)
        // 初始化串口
        uart_handler_ptr->begin(config.baud_rate, config_flags,
                                config.rxd_pin, config.txd_pin);
#else
        // 初始化串口
        uart_handler_ptr->begin(config.baud_rate, config_flags);
#endif

        return ERROR_CODE::NONE;
    }

    ErrorCode Deinit(uint8_t port)
    {
        // 参数有效性检查
        if (port >= (sizeof(s_uart_handler_ptr_array) / sizeof(s_uart_handler_ptr_array[0])))
        {
            return ERROR_CODE::GENERAL;
        }

        // 获取 UART 操作器指针
        auto uart_handler_ptr = s_uart_handler_ptr_array[port];
        if (!uart_handler_ptr)
        {
            return ERROR_CODE::GENERAL;
        }

        // 去初始化串口
        uart_handler_ptr->end();

        return ERROR_CODE::NONE;
    }

    void Write(uint8_t port, const uint8_t *write_buffer, size_t write_size)
    {
        auto uart_handler_ptr = s_uart_handler_ptr_array[port];
        uart_handler_ptr->write(write_buffer, write_size);
    }

    void Read(uint8_t port, uint8_t *read_buffer, size_t read_size)
    {
        auto uart_handler_ptr = s_uart_handler_ptr_array[port];
        size_t bytes_read = 0;

        // 阻塞读取直到获取所需字节数
        while (bytes_read < read_size)
        {
            if (uart_handler_ptr->available() > 0)
            {
                read_buffer[bytes_read] = uart_handler_ptr->read();
                bytes_read++;
            }
        }
    }

    void Read(uint8_t port, uint8_t *read_buffer, size_t read_size, uint32_t timeout_ms)
    {
        auto uart_handler_ptr = s_uart_handler_ptr_array[port];
        uart_handler_ptr->setTimeout(timeout_ms);
        uart_handler_ptr->readBytes(read_buffer, read_size);
    }

}
#endif
