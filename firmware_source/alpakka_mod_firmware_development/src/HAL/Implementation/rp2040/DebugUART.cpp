
#if defined(__has_include)
#if __has_include(<pico/version.h>)
#include <pico/version.h>
#endif
#endif

#if defined(PICO_SDK_VERSION_STRING) && !defined(ARDUINO)
#include "HAL/DebugUART.h"

#include "HAL/UART.h"
#include "pico/stdio.h"

namespace DebugUART
{

    static bool s_init_state = false;
    static uint8_t s_uart_port = 0;

    void Init()
    {
        HAL_UART::Config cfg = {};

        s_uart_port = 0;
        cfg.txd_pin = PICO_DEFAULT_UART_TX_PIN;
        cfg.rxd_pin = PICO_DEFAULT_UART_RX_PIN;

        HAL_UART::Init(s_uart_port, cfg);
        s_init_state = true;
    }

    void Deinit()
    {
        if (!s_init_state)
            return;
        HAL_UART::Deinit(s_uart_port);
        s_init_state = false;
    }

    void Send(const uint8_t *tx_buf, size_t tx_len)
    {
        if (!s_init_state || !tx_buf)
        {
            return;
        }

        HAL_UART::Write(s_uart_port, tx_buf, tx_len);
    }

    void Send(const char *str)
    {
        if (!s_init_state || !str)
        {
            return;
        }

        // 空字符串检查
        if (str[0] == '\0')
        {
            return;
        }

        // 计算字符串长度（不包括终止符）
        const size_t len = strlen(str);

        Send(reinterpret_cast<const uint8_t *>(str), len);
    }

} // namespace DebugUART
#endif
