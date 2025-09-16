#pragma once

#include "Library/cstd_lib.h"
#include "Library/common.h"

/* HID input report id */
#define DUAL_SHOCK_3_HID_INPUT_ID01 0x01
/* HID output report id */
/* HID feature report id */

// 来自：https://eleccelerator.com/wiki/index.php/DualShock_3
#define DUAL_SHOCK_3_HID_REPORT_DESCRIPTOR                                                                              \
    0x05, 0x01,           /* Usage Page (Generic Desktop Ctrls) */                                                      \
        0x09, 0x04,       /* Usage (Joystick) */                                                                        \
        0xA1, 0x01,       /* Collection (Physical) */                                                                   \
        0xA1, 0x02,       /*   Collection (Application) */                                                              \
        0x85, 0x01,       /*     Report ID (1) */                                                                       \
        0x75, 0x08,       /*     Report Size (8) */                                                                     \
        0x95, 0x01,       /*     Report Count (1) */                                                                    \
        0x15, 0x00,       /*     Logical Minimum (0) */                                                                 \
        0x26, 0xFF, 0x00, /*     Logical Maximum (255) */                                                               \
        0x81, 0x03,       /*     Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */               \
        0x75, 0x01,       /*     Report Size (1) */                                                                     \
        0x95, 0x13,       /*     Report Count (19) */                                                                   \
        0x15, 0x00,       /*     Logical Minimum (0) */                                                                 \
        0x25, 0x01,       /*     Logical Maximum (1) */                                                                 \
        0x35, 0x00,       /*     Physical Minimum (0) */                                                                \
        0x45, 0x01,       /*     Physical Maximum (1) */                                                                \
        0x05, 0x09,       /*     Usage Page (Button) */                                                                 \
        0x19, 0x01,       /*     Usage Minimum (0x01) */                                                                \
        0x29, 0x13,       /*     Usage Maximum (0x13) */                                                                \
        0x81, 0x02,       /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x75, 0x01,       /*     Report Size (1) */                                                                     \
        0x95, 0x0D,       /*     Report Count (13) */                                                                   \
        0x06, 0x00, 0xFF, /*     Usage Page (Vendor Defined 0xFF00) */                                                  \
        0x81, 0x03,       /*     Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */               \
        0x15, 0x00,       /*     Logical Minimum (0) */                                                                 \
        0x26, 0xFF, 0x00, /*     Logical Maximum (255) */                                                               \
        0x05, 0x01,       /*     Usage Page (Generic Desktop Ctrls) */                                                  \
        0x09, 0x01,       /*     Usage (Pointer) */                                                                     \
        0xA1, 0x00,       /*     Collection (Undefined) */                                                              \
        0x75, 0x08,       /*       Report Size (8) */                                                                   \
        0x95, 0x04,       /*       Report Count (4) */                                                                  \
        0x35, 0x00,       /*       Physical Minimum (0) */                                                              \
        0x46, 0xFF, 0x00, /*       Physical Maximum (255) */                                                            \
        0x09, 0x30,       /*       Usage (X) */                                                                         \
        0x09, 0x31,       /*       Usage (Y) */                                                                         \
        0x09, 0x32,       /*       Usage (Z) */                                                                         \
        0x09, 0x35,       /*       Usage (Rz) */                                                                        \
        0x81, 0x02,       /*       Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */              \
        0xC0,             /*     End Collection */                                                                      \
        0x05, 0x01,       /*     Usage Page (Generic Desktop Ctrls) */                                                  \
        0x75, 0x08,       /*     Report Size (8) */                                                                     \
        0x95, 0x27,       /*     Report Count (39) */                                                                   \
        0x09, 0x01,       /*     Usage (Pointer) */                                                                     \
        0x81, 0x02,       /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x75, 0x08,       /*     Report Size (8) */                                                                     \
        0x95, 0x30,       /*     Report Count (48) */                                                                   \
        0x09, 0x01,       /*     Usage (Pointer) */                                                                     \
        0x91, 0x02,       /*     Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x75, 0x08,       /*     Report Size (8) */                                                                     \
        0x95, 0x30,       /*     Report Count (48) */                                                                   \
        0x09, 0x01,       /*     Usage (Pointer) */                                                                     \
        0xB1, 0x02,       /*     Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0xC0,             /*   End Collection */                                                                        \
        0xA1, 0x02,       /*   Collection (Application) */                                                              \
        0x85, 0x02,       /*     Report ID (2) */                                                                       \
        0x75, 0x08,       /*     Report Size (8) */                                                                     \
        0x95, 0x30,       /*     Report Count (48) */                                                                   \
        0x09, 0x01,       /*     Usage (Pointer) */                                                                     \
        0xB1, 0x02,       /*     Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0xC0,             /*   End Collection */                                                                        \
        0xA1, 0x02,       /*   Collection (Application) */                                                              \
        0x85, 0xEE,       /*     Report ID (238) */                                                                     \
        0x75, 0x08,       /*     Report Size (8) */                                                                     \
        0x95, 0x30,       /*     Report Count (48) */                                                                   \
        0x09, 0x01,       /*     Usage (Pointer) */                                                                     \
        0xB1, 0x02,       /*     Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0xC0,             /*   End Collection */                                                                        \
        0xA1, 0x02,       /*   Collection (Application) */                                                              \
        0x85, 0xEF,       /*     Report ID (239) */                                                                     \
        0x75, 0x08,       /*     Report Size (8) */                                                                     \
        0x95, 0x30,       /*     Report Count (48) */                                                                   \
        0x09, 0x01,       /*     Usage (Pointer) */                                                                     \
        0xB1, 0x02,       /*     Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0xC0,             /*   End Collection */                                                                        \
        0xC0              /* End Collection */
// 148 bytes

// 来自：https://github.com/passinglink/passinglink
#define DUAL_SHOCK_3_PC_HID_REPORT_DESCRIPTOR                                                                         \
    0x05, 0x01,           /* Usage Page (Generic Desktop Ctrls) */                                                    \
        0x09, 0x05,       /* Usage (Game Pad) */                                                                      \
        0xA1, 0x01,       /* Collection (Application) */                                                              \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x25, 0x01,       /*   Logical Maximum (1) */                                                                 \
        0x35, 0x00,       /*   Physical Minimum (0) */                                                                \
        0x45, 0x01,       /*   Physical Maximum (1) */                                                                \
        0x75, 0x01,       /*   Report Size (1) */                                                                     \
        0x95, 0x0D,       /*   Report Count (13) */                                                                   \
        0x05, 0x09,       /*   Usage Page (Button) */                                                                 \
        0x19, 0x01,       /*   Usage Minimum (0x01) */                                                                \
        0x29, 0x0D,       /*   Usage Maximum (0x0D) */                                                                \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x95, 0x03,       /*   Report Count (3) */                                                                    \
        0x81, 0x01,       /*   Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position) */             \
        0x05, 0x01,       /*   Usage Page (Generic Desktop Ctrls) */                                                  \
        0x25, 0x07,       /*   Logical Maximum (7) */                                                                 \
        0x46, 0x3B, 0x01, /*   Physical Maximum (315) */                                                              \
        0x75, 0x04,       /*   Report Size (4) */                                                                     \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0x65, 0x14,       /*   Unit (System: English Rotation, Length: Centimeter) */                                 \
        0x09, 0x39,       /*   Usage (Hat switch) */                                                                  \
        0x81, 0x42,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,Null State) */                      \
        0x65, 0x00,       /*   Unit (None) */                                                                         \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0x81, 0x01,       /*   Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position) */             \
        0x26, 0xFF, 0x00, /*   Logical Maximum (255) */                                                               \
        0x46, 0xFF, 0x00, /*   Physical Maximum (255) */                                                              \
        0x09, 0x30,       /*   Usage (X) */                                                                           \
        0x09, 0x31,       /*   Usage (Y) */                                                                           \
        0x09, 0x32,       /*   Usage (Z) */                                                                           \
        0x09, 0x35,       /*   Usage (Rz) */                                                                          \
        0x75, 0x08,       /*   Report Size (8) */                                                                     \
        0x95, 0x04,       /*   Report Count (4) */                                                                    \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x06, 0x00, 0xFF, /*   Usage Page (Vendor Defined 0xFF00) */                                                  \
        0x09, 0x20,       /*   Usage (0x20) */                                                                        \
        0x09, 0x21,       /*   Usage (0x21) */                                                                        \
        0x09, 0x22,       /*   Usage (0x22) */                                                                        \
        0x09, 0x23,       /*   Usage (0x23) */                                                                        \
        0x09, 0x24,       /*   Usage (0x24) */                                                                        \
        0x09, 0x25,       /*   Usage (0x25) */                                                                        \
        0x09, 0x26,       /*   Usage (0x26) */                                                                        \
        0x09, 0x27,       /*   Usage (0x27) */                                                                        \
        0x09, 0x28,       /*   Usage (0x28) */                                                                        \
        0x09, 0x29,       /*   Usage (0x29) */                                                                        \
        0x09, 0x2A,       /*   Usage (0x2A) */                                                                        \
        0x09, 0x2B,       /*   Usage (0x2B) */                                                                        \
        0x95, 0x0C,       /*   Report Count (12) */                                                                   \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x0A, 0x21, 0x26, /*   Usage (0x2621) */                                                                      \
        0x95, 0x08,       /*   Report Count (8) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x0A, 0x21, 0x26, /*   Usage (0x2621) */                                                                      \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x26, 0xFF, 0x03, /*   Logical Maximum (1023) */                                                              \
        0x46, 0xFF, 0x03, /*   Physical Maximum (1023) */                                                             \
        0x09, 0x2C,       /*   Usage (0x2C) */                                                                        \
        0x09, 0x2D,       /*   Usage (0x2D) */                                                                        \
        0x09, 0x2E,       /*   Usage (0x2E) */                                                                        \
        0x09, 0x2F,       /*   Usage (0x2F) */                                                                        \
        0x75, 0x10,       /*   Report Size (16) */                                                                    \
        0x95, 0x04,       /*   Report Count (4) */                                                                    \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0xC0              /* End Collection */

namespace DualShock3Struct
{
    struct __PACKED InputReport
    {
        uint8_t ReportID;
        uint8_t Reserved;
        union
        {
            uint32_t Mask;
            struct
            {
                uint32_t Select : 1;
                uint32_t L3 : 1;
                uint32_t R3 : 1;
                uint32_t Start : 1;
                uint32_t Up : 1;
                uint32_t Right : 1;
                uint32_t Down : 1;
                uint32_t Left : 1;
                uint32_t L2 : 1;
                uint32_t R2 : 1;
                uint32_t L1 : 1;
                uint32_t R1 : 1;
                uint32_t Triangle : 1; // 三角
                uint32_t Circle : 1;   // 圆圈
                uint32_t Cross : 1;    // 交叉
                uint32_t Square : 1;   // 方形
                uint32_t PS : 1;
                uint32_t TP : 1;
                uint32_t : 6;
                uint32_t : 8;
            };
            /*     NOTE: 32 bit integer, where 0:18 are buttons and 19:31 are reserved */
        } Buttons;

        // Byte 6 is left stick X axis; byte 7 is left stick Y axis; byte 8 is right stick X axis; byte 9 is right stick Y axis; top left is 0
        uint8_t LeftStickX;
        uint8_t LeftStickY;
        uint8_t RightStickX;
        uint8_t RightStickY;
        /*       NOTE: four joysticks */

        uint8_t Unknown1[2];

        // Byte 13 to byte 24 contains analog button data, 8 bits each, 0 is released and FF is fully pressed. The ordering follows the order of the bits shown in the table above.
        uint8_t AnalogButtonData[12];

        uint8_t Unknown2[16];

        // Byte 40 and 41: accelerometer X axis, little endian 10 bit unsigned
        uint16_t AccelerometerX : 10;
        uint16_t : 6;
        // Byte 42 and 43: accelerometer Y axis, little endian 10 bit unsigned
        uint16_t AccelerometerY : 10;
        uint16_t : 6;
        // Byte 44 and 45: accelerometer Z axis, little endian 10 bit unsigned
        uint16_t AccelerometerZ : 10;
        uint16_t : 6;
        // Byte 46 and 47: gyroscope, little endian 10 bit unsigned
        uint16_t Gyroscope : 10;
        uint16_t : 6;

        uint8_t unknown3;
    };
    static_assert(sizeof(InputReport) == 49, "Expected size error");

    struct __PACKED PC_InputReport
    {
        union
        {
            uint16_t Mask;
            struct
            {
                uint16_t Square : 1;   // 方形
                uint16_t Cross : 1;    // 交叉
                uint16_t Circle : 1;   // 圆圈
                uint16_t Triangle : 1; // 三角
                uint16_t L1 : 1;
                uint16_t R1 : 1;
                uint16_t L2 : 1;
                uint16_t R2 : 1;
                uint16_t Select : 1;
                uint16_t Start : 1;
                uint16_t L3 : 1;
                uint16_t R3 : 1;
                uint16_t Home : 1;
                uint16_t : 3;
            };
        } buttons;
        uint8_t DPad : 4;
        uint8_t : 4;
        uint8_t LeftStickX;
        uint8_t LeftStickY;
        uint8_t RightStickX;
        uint8_t RightStickY;
        uint8_t padding_3[13];
        uint8_t two_1;
        uint8_t padding_4;
        uint8_t two_2;
        uint8_t padding_5;
        uint8_t two_3;
        uint8_t padding_6;
        uint8_t two_4;
    };
    static_assert(sizeof(PC_InputReport) == 27, "Expected size error");
}
