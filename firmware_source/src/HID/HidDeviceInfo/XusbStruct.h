#pragma once

#include "Library/cstd_lib.h"
#include "Library/common.h"

namespace XusbStruct
{
    enum class OutputReportID : uint8_t
    {
        RUMBLE = 0x00,
        LED = 0x01,
    };

    // Move to Proto Enums
    enum class PLEDPattern : uint8_t
    {
        OFF = 0x00,       // All off
        BLINKALL = 0x01,  // All blinking
        FLASH1 = 0x02,    // 1 flashes, then on
        FLASH2 = 0x03,    // 2 flashes, then on
        FLASH3 = 0x04,    // 3 flashes, then on
        FLASH4 = 0x05,    // 4 flashes, then on
        ON1 = 0x06,       // 1 on
        ON2 = 0x07,       // 2 on
        ON3 = 0x08,       // 3 on
        ON4 = 0x09,       // 4 on
        ROTATE = 0x0A,    // Rotating (e.g. 1-2-4-3)
        BLINK = 0x0B,     // Blinking*
        SLOWBLINK = 0x0C, // Slow blinking*
        ALTERNATE = 0x0D, // Alternating (e.g. 1+4-2+3), then back to previous*
    };

    struct __PACKED InputReport
    {
        uint8_t report_id = 0; // 0x00
        uint8_t report_size;
        union
        {
            struct
            {
                uint16_t buttons_mask;
            };
            struct
            {
                uint8_t up : 1;
                uint8_t down : 1;
                uint8_t left : 1;
                uint8_t right : 1;
                uint8_t start : 1;
                uint8_t select : 1;
                uint8_t ls : 1;
                uint8_t rs : 1;
                uint8_t lb : 1;
                uint8_t rb : 1;
                uint8_t home : 1;
                uint8_t unused : 1;
                uint8_t a : 1;
                uint8_t b : 1;
                uint8_t x : 1;
                uint8_t y : 1;
            } buttons;
        };
        uint8_t lt;
        uint8_t rt;
        int16_t lx;
        int16_t ly;
        int16_t rx;
        int16_t ry;
        uint8_t reserved[6];
    };
    static_assert(sizeof(InputReport) == 20, "Expected size error");

    struct __PACKED OutputReport
    {
        OutputReportID report_id; // 0x00 或 0x01
        uint8_t report_size;      // 数据长度（ 0x08 或 0x03）
        union
        {
            struct
            {
                PLEDPattern led_state; // LED 状态
            };
            struct
            {
                uint8_t : 8;
                uint8_t left_motor;  // 左马达强度 (0x00 ~ 0x80)
                uint8_t right_motor; // 右马达强度 (0x00 ~ 0x80)
                uint8_t reserved[3]; // 保留字段
            };
        };
    };
    static_assert(sizeof(OutputReport) == 8, "Expected size error");
}
