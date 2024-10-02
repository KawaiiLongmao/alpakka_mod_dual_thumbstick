#ifndef DUAL_SHOCK_3_H
#define DUAL_SHOCK_3_H

#pragma once

#include <stdint.h>
#include "util.h"

#pragma pack(push, 1)

/* HID input report id */
#define DUAL_SHOCK_3_REPORT_INPUT_ID01 0x01
/* HID output report id */
/* HID feature report id */

#define DUAL_SHOCK_3_REPORT_MAP                                                                                         \
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

#define DS3_REPORT_LENTH_BYTE 49 - 1
#define DS3_MAX_BUTTON_IDX 17
#define DS3_STICK_MIN_VALUE 0
#define DS3_STICK_MAX_VALUE 255
#define DS3_STICK_CENTER 127
typedef struct
{
    // uint8_t report_id;
    uint8_t reserved;      /*     NOTE: reserved byte */
    uint8_t buttons_byte1; // D Left	D Down	D Right	D Up	Start	R3	L3	Select
    uint8_t buttons_byte2; // Square	X	Circle	Triangle	R1	L1	R2	L2
    uint8_t buttons_byte3; // ?	 ?	 ?	 ?	 ?	 ?	 ?	PS
    uint8_t buttons_byte4; // ?	 ?	 ?	 ?	 ?	 ?	 ?	 ?
    /*     NOTE: 32 bit integer, where 0:18 are buttons and 19:31 are reserved */

    // Byte 6 is left stick X axis; byte 7 is left stick Y axis; byte 8 is right stick X axis; byte 9 is right stick Y axis; top left is 0
    uint8_t lx;
    uint8_t ly;
    uint8_t rx;
    uint8_t ry;
    /*       NOTE: four joysticks */

    uint8_t unknown1[2];

    // Byte 13 to byte 24 contains analog button data, 8 bits each, 0 is released and FF is fully pressed. The ordering follows the order of the bits shown in the table above.
    uint8_t analog_button_data[12];

    uint8_t unknown2[16];

    // Byte 40 and 41: accelerometer X axis, little endian 10 bit unsigned
    uint16_t accelerometer_x;
    // Byte 42 and 43: accelerometer Y axis, little endian 10 bit unsigned
    uint16_t accelerometer_y;
    // Byte 44 and 45: accelerometer Z axis, little endian 10 bit unsigned
    uint16_t accelerometer_z;
    // Byte 46 and 47: gyroscope, little endian 10 bit unsigned
    uint16_t gyroscope;

    // uint8_t unknown3[97];
    uint8_t unknown3;
} ds3_input_report_t;

#endif
