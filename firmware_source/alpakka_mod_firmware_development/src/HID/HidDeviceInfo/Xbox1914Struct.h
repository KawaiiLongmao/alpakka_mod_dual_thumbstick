#pragma once

#include "Library/cstd_lib.h"
#include "Library/common.h"
#include "Application/HID/HidDevice/Shared/XgipProtocol.h"

namespace Xbox1914Struct
{
    enum class Direction : uint8_t
    {
        None = 0,
        North,
        NorthEast,
        East,
        SouthEast,
        South,
        SouthWest,
        West,
        NorthWest = 8
    };

    struct __PACKED USB_InputReportFull
    {
        GipHeader_t header;

        uint8_t sync : 1;
        uint8_t guide : 1;
        uint8_t start : 1; // menu
        uint8_t back : 1;  // view

        uint8_t a : 1;
        uint8_t b : 1;
        uint8_t x : 1;
        uint8_t y : 1;

        uint8_t dpad_up : 1;
        uint8_t dpad_down : 1;
        uint8_t dpad_left : 1;
        uint8_t dpad_right : 1;

        uint8_t left_shoulder : 1;
        uint8_t right_shoulder : 1;
        uint8_t left_thumbClick : 1;
        uint8_t right_thumbClick : 1;

        uint16_t left_trigger;
        uint16_t right_trigger;

        int16_t left_stick_x;
        int16_t left_stick_y;
        int16_t right_stick_x;
        int16_t right_stick_y;

        uint8_t reserved[18]; // 18-byte padding at the end
    };
    static_assert(sizeof(USB_InputReportFull) == 36, "Expected size error");

    struct __PACKED USB_InputReportSimple
    {
        GipHeader_t header;
        uint8_t sync : 1;
        uint8_t guide : 1;
        uint8_t start : 1; // menu
        uint8_t back : 1;  // view
    };
    static_assert(sizeof(USB_InputReportSimple) == 5, "Expected size error");

    struct __PACKED USB_ReportLEDData
    {
        GipHeader_t header;
        uint8_t unk;
        uint8_t mode;
        uint8_t brightness;
    };
    static_assert(sizeof(USB_ReportLEDData) == 7, "Expected size error");

    struct __PACKED BT_InputReport01
    {
        uint8_t ReportID;           // Report ID = 0x01 (1)
        uint16_t LeftStickX;        // Usage 0x00010030: X, Value = 0 to 65535
        uint16_t LeftStickY;        // Usage 0x00010031: Y, Value = 0 to 65535
        uint16_t RightStickX;       // Usage 0x00010032: Z, Value = 0 to 65535
        uint16_t RightStickY;       // Usage 0x00010035: Rz, Value = 0 to 65535
        uint16_t TriggerLeft : 10;  // Usage 0x000200C5: Brake, Value = 0 to 1023
        uint16_t : 6;               // Pad
        uint16_t TriggerRight : 10; // Usage 0x000200C4: Accelerator, Value = 0 to 1023
        uint16_t : 6;               // Pad
        Direction HatSwitch : 4;    // Usage 0x00010039: Hat switch, Value = 1 to 8, Physical = (Value - 1) x 45 in degrees
        Direction : 4;              // Pad
        struct
        {
            uint8_t A : 1;     // Usage 0x00090001: Button 1 Primary/trigger, Value = 0 to 1
            uint8_t B : 1;     // Usage 0x00090002: Button 2 Secondary, Value = 0 to 1
            uint8_t btn3 : 1;  // Usage 0x00090003: Button 3 Tertiary, Value = 0 to 1
            uint8_t X : 1;     // Usage 0x00090004: Button 4, Value = 0 to 1
            uint8_t Y : 1;     // Usage 0x00090005: Button 5, Value = 0 to 1
            uint8_t btn6 : 1;  // Usage 0x00090006: Button 6, Value = 0 to 1
            uint8_t LB : 1;    // Usage 0x00090007: Button 7, Value = 0 to 1
            uint8_t RB : 1;    // Usage 0x00090008: Button 8, Value = 0 to 1
            uint8_t btn9 : 1;  // Usage 0x00090009: Button 9, Value = 0 to 1
            uint8_t btn10 : 1; // Usage 0x0009000A: Button 10, Value = 0 to 1
            uint8_t Back : 1;  // Usage 0x0009000B: Button 11, Value = 0 to 1
            uint8_t Start : 1; // Usage 0x0009000C: Button 12, Value = 0 to 1
            uint8_t Home : 1;  // Usage 0x0009000D: Button 13, Value = 0 to 1
            uint8_t LS : 1;    // Usage 0x0009000E: Button 14, Value = 0 to 1
            uint8_t RS : 1;    // Usage 0x0009000F: Button 15, Value = 0 to 1
            uint8_t : 1;       // Pad
        } Buttons;
        uint8_t Record : 1; // Usage 0x000C00B2: Record, Value = 0 to 1
        uint8_t : 7;        // Pad
    };
    static_assert(sizeof(BT_InputReport01) == 17, "Expected size error");

    struct __PACKED BT_OutputReport03
    {
        uint8_t ReportID;              // Report ID = 0x03 (3)
        uint8_t DcEnableActuators : 4; // Usage 0x000F0097: DC Enable Actuators, Value = 0 to 1
        uint8_t : 4;                   // Pad
        uint8_t LeftTriggerMagnitude;  // Usage 0x000F0070: Magnitude, Value = 0 to 100
        uint8_t RightTriggerMagnitude; // Usage 0x000F0070: Magnitude, Value = 0 to 100
        uint8_t StrongMagnitude;       // Usage 0x000F0070: Magnitude, Value = 0 to 100
        uint8_t WeakMagnitude;         // Usage 0x000F0070: Magnitude, Value = 0 to 100
        uint8_t Duration;              // Usage 0x000F0050: Duration, Value = 0 to 255, Physical = Value in 10⁻² s units
        uint8_t DtartDelay;            // Usage 0x000F00A7: Start Delay, Value = 0 to 255, Physical = Value in 10⁻² s units
        uint8_t LoopCount;             // Usage 0x000F007C: Loop Count, Value = 0 to 255
    };
    static_assert(sizeof(BT_OutputReport03) == 9, "Expected size error");
}
