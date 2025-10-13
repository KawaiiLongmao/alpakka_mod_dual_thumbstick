#pragma once

#include "Library/common.h"
#include "hal_public.h"

namespace HAL_UART
{

    // 校验方式
    enum class Parity
    {
        NONE, // 无校验位
        EVEN, // 偶校验
        ODD   // 奇校验
    };

    enum class FlowCtrl
    {
        NONE,
        CTS,
        RTS,
        CTS_RTS,
    };

    struct Config
    {
        GPIONumber txd_pin;
        GPIONumber rxd_pin;
        uint32_t baud_rate = 115200;  // 波特率
        uint8_t data_bits = 8;        // 数据位 5~8
        uint8_t stop_bits = 1;        // 停止位 1~2
        Parity parity = Parity::NONE; // 校验方式
        struct
        {
            FlowCtrl flow_ctrl = FlowCtrl::NONE; // 硬件流控
            GPIONumber cts_pin;
            GPIONumber rts_pin;
        };
    };

    // 初始化
    ErrorCode Init(uint8_t port, const Config &config);

    // 去初始化
    ErrorCode Deinit(uint8_t port);

    // 写入数据
    void Write(uint8_t port, const uint8_t *write_buffer, size_t write_size);

    // 读取数据
    void Read(uint8_t port, uint8_t *read_buffer, size_t read_size);

}
