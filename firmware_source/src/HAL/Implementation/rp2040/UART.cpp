
#if defined(__has_include)
#if __has_include(<pico/version.h>)
#include <pico/version.h>
#endif
#endif

#if defined(PICO_SDK_VERSION_STRING) && !defined(ARDUINO)
#include "HAL/UART.h"

#include "Middleware/Log.h"
#include <hardware/gpio.h>
#include <hardware/uart.h>

namespace HAL_UART
{
    namespace
    {
        // UART 实例数组
        uart_inst_t *s_uart_instance_ptr_array[] = {uart0, uart1};

        // UART 配置结构
        struct UartConfigInternal
        {
            GPIONumber txd_pin; // TXD 引脚
            GPIONumber rxd_pin; // RXD 引脚
            uint32_t baud_rate; // 波特率
            uint8_t data_bits;  // 数据位
            uint8_t stop_bits;  // 停止位
            Parity parity;      // 校验方式
        };

        // UART 配置数组
        UartConfigInternal s_uart_config_array[sizeof(s_uart_instance_ptr_array) / sizeof(s_uart_instance_ptr_array[0])] = {};
    }

    ErrorCode Init(uint8_t port, const Config &config)
    {
        LOG_PRINTF(Log::INFO, "[HAL_UART::Init] - Initializing UART on port %d\n", port);

        // 参数有效性检查
        if (port >= sizeof(s_uart_instance_ptr_array) / sizeof(s_uart_instance_ptr_array[0]))
        {
            LOG_PRINTF(Log::ERROR, "[HAL_UART::Init] - Invalid port %d\n", port);
            return ERROR_CODE::GENERAL;
        }

        // 获取 UART 实例
        uart_inst_t *uart_instance_ptr = s_uart_instance_ptr_array[port];

        // 去初始化 UART
        uart_deinit(uart_instance_ptr);

        // 初始化 UART
        uart_init(uart_instance_ptr, config.baud_rate);

        // 设置 UART 格式
        uart_set_format(uart_instance_ptr, config.data_bits, config.stop_bits, (uart_parity_t)config.parity);

        // 设置引脚功能
        gpio_set_function(config.txd_pin, GPIO_FUNC_UART);
        gpio_set_function(config.rxd_pin, GPIO_FUNC_UART);

        // 保存配置
        s_uart_config_array[port] = {
            .txd_pin = config.txd_pin,
            .rxd_pin = config.rxd_pin,
            .baud_rate = config.baud_rate,
            .data_bits = config.data_bits,
            .stop_bits = config.stop_bits,
            .parity = config.parity};

        LOG_PRINTF(Log::INFO, "[HAL_UART::Init] - UART initialized on port %d @ %d baud\n",
                   port, config.baud_rate);
        return ERROR_CODE::NONE;
    }

    ErrorCode Deinit(uint8_t port)
    {
        LOG_PRINTF(Log::INFO, "[HAL_UART::Deinit] - Deinitializing UART on port %d\n", port);

        // 参数有效性检查
        if (port >= sizeof(s_uart_instance_ptr_array) / sizeof(s_uart_instance_ptr_array[0]))
        {
            LOG_PRINTF(Log::ERROR, "[HAL_UART::Deinit] - Invalid port %d\n", port);
            return ERROR_CODE::GENERAL;
        }

        // 获取 UART 实例
        uart_inst_t *uart_instance_ptr = s_uart_instance_ptr_array[port];

        // 去初始化 UART
        uart_deinit(uart_instance_ptr);

        // 获取配置
        auto config = s_uart_config_array[port];

        // 恢复 GPIO 引脚为默认状态
        if (config.txd_pin != GPIO_UNUSED)
        {
            gpio_set_function(config.txd_pin, GPIO_FUNC_NULL);
            gpio_disable_pulls(config.txd_pin);
            LOG_PRINTF(Log::DEBUG, "[HAL_UART::Deinit] - Reset TXD pin %d to default state\n", config.txd_pin);
        }

        if (config.rxd_pin != GPIO_UNUSED)
        {
            gpio_set_function(config.rxd_pin, GPIO_FUNC_NULL);
            gpio_disable_pulls(config.rxd_pin);
            LOG_PRINTF(Log::DEBUG, "[HAL_UART::Deinit] - Reset RXD pin %d to default state\n", config.rxd_pin);
        }

        LOG_PRINTF(Log::INFO, "[HAL_UART::Deinit] - UART deinitialized on port %d\n", port);
        return ERROR_CODE::NONE;
    }

    void Write(uint8_t port, const uint8_t *write_buffer, size_t write_size)
    {
        // 参数有效性检查
        if (port >= sizeof(s_uart_instance_ptr_array) / sizeof(s_uart_instance_ptr_array[0]))
        {
            LOG_PRINTF(Log::ERROR, "[HAL_UART::Write] - Invalid port %d\n", port);
            return;
        }

        // 获取 UART 实例
        uart_inst_t *uart_instance_ptr = s_uart_instance_ptr_array[port];

        // 写入数据
        uart_write_blocking(uart_instance_ptr, write_buffer, write_size);
    }

    void Read(uint8_t port, uint8_t *read_buffer, size_t read_size)
    {
        // 参数有效性检查
        if (port >= sizeof(s_uart_instance_ptr_array) / sizeof(s_uart_instance_ptr_array[0]))
        {
            LOG_PRINTF(Log::ERROR, "[HAL_UART::Read] - Invalid port %d\n", port);
            return;
        }

        // 获取 UART 实例
        uart_inst_t *uart_instance_ptr = s_uart_instance_ptr_array[port];

        // 读取数据
        uart_read_blocking(uart_instance_ptr, read_buffer, read_size);
    }

} // namespace HAL_UART
#endif
