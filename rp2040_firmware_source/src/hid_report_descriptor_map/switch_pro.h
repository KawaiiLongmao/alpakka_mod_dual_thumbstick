#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "util.h"

#pragma pack(push, 1)

/* HID input report id */
#define SWITCH_PRO_BT_INPUT_ID_STD 0x21           // Standard input reports used for subcommand replies.
#define SWITCH_PRO_BT_INPUT_ID_NFC_FW_UPDATE 0x23 // NFC/IR MCU FW update input report.
#define SWITCH_PRO_BT_INPUT_ID_FULL 0x30          // input reports with IMU data instead of subcommand replies.Pushes current state @120Hz
#define SWITCH_PRO_BT_INPUT_ID_NFC_MCU 0x31       // Pushes large packets with standard input report + NFC/IR MCU data input report.
#define SWITCH_PRO_BT_INPUT_ID_UNKNOWN1 0x32      // Sends standard input reports.
#define SWITCH_PRO_BT_INPUT_ID_UNKNOWN2 0x33      // Sends standard input reports.
#define SWITCH_PRO_BT_INPUT_ID 0x3F

/* HID output report id */
#define SWITCH_PRO_BT_OUTPUT_ID_RUMBLE_SUBCMD 0x01
#define SWITCH_PRO_BT_OUTPUT_ID_RUMBLE 0x10
#define SWITCH_PRO_BT_OUTPUT_ID_REQ_NFC_OR_RUMBLE 0x11
#define SWITCH_PRO_BT_OUTPUT_ID_UNKNOWN 0x12

/* HID input report id */
#define SWITCH_PRO_USB_INPUT_ID_SUBCOMMAND_REPLY 0x21
#define SWITCH_PRO_USB_INPUT_ID_FULL_CONTROLLER_STATE 0x30
#define SWITCH_PRO_USB_INPUT_ID_FULL_CONTROLLER_AND_MCU_STATE 0x31
#define SWITCH_PRO_USB_INPUT_ID_SIMPLE_CONTROLLER_STATE 0x3F
#define SWITCH_PRO_USB_INPUT_ID_COMMAND_ACK 0x81

/* HID output report id */
#define SWITCH_PRO_USB_OUTPUT_ID_RUMBLE_AND_SUBCOMMAND 0x01
#define SWITCH_PRO_USB_OUTPUT_ID_RUMBLE 0x10
#define SWITCH_PRO_USB_OUTPUT_ID_PROPRIETARY 0x80

/* HID report size */
#define MaxInputReportSizeBytes 64
#define SWITCH_PRO_USB_REPORT_SIZE 63
#define SWITCH_PRO_USB_INPUT_REPORT_SIMPLE_SIZE 63
#define SWITCH_PRO_USB_INPUT_REPORT_FULL_SIZE 63
#define SWITCH_PRO_USB_INPUT_REPORT_STAND_SIZE 63

#define SWITCH_PRO_BT_INPUT_REPORT_SIMPLE_SIZE 11
#define SWITCH_PRO_BT_INPUT_REPORT_FULL_SIZE 48
#define SWITCH_PRO_BT_INPUT_REPORT_STAND_SIZE 48

/* Device Descriptor: */
#define SWITCH_PRO_DEVICE_DESCRIPTOR   \
    0x12,       /* .bLength */         \
        0x01,   /* .bDescriptorType */ \
        0x0200, /* .bcdUSB */          \
        0x00,   /* .bDeviceClass */    \
        0x00,   /* .bDeviceSubClass */ \
        0x00,   /* .bDeviceProtocol */ \
        0x40,   /* .bMaxPacketSize0 */ \
        0x057E, /* .idVendor */        \
        0x2009, /* .idProduct */       \
        0x0210, /* .bcdDevice */       \
        0x01,   /* .iManufacturer */   \
        0x02,   /* .iProduct */        \
        0x03,   /* .iSerialNumber */   \
        0x01    /* .bNumConfiguration */

/* Configuration Descriptor: */
#define SWITCH_PRO_CONFIGURATION_DESCRIPTOR                                           \
    0x09,                    /* bLength */                                            \
        0x02,                /* bDescriptorType */                                    \
        U16_TO_BYTE(0x0029), /* wTotalLength   (41 bytes) */                          \
        0x01,                /* bNumInterfaces */                                     \
        0x01,                /* bConfigurationValue */                                \
        0x00,                /* iConfiguration */                                     \
        0xA0,                /* bmAttributes   (Bus-powered Device, Remote-Wakeup) */ \
        0xFA                 /* bMaxPower      (500 mA) */

/* Interface Descriptor: */
#define SWITCH_PRO_INTERFACE_DESCRIPTOR                                 \
    0x09,     /* bLength */                                             \
        0x04, /* bDescriptorType */                                     \
        0x00, /* bInterfaceNumber */                                    \
        0x00, /* bAlternateSetting */                                   \
        0x02, /* bNumEndPoints */                                       \
        0x03, /* bInterfaceClass      (Human Interface Device Class) */ \
        0x00, /* bInterfaceSubClass */                                  \
        0x00, /* bInterfaceProtocol */                                  \
        0x00  /* iInterface */

/* HID Descriptor: */
#define SWITCH_PRO_HID_DESCRIPTOR(report_size)                               \
    0x09,                        /* bLength */                               \
        0x21,                    /* bDescriptorType */                       \
        U16_TO_BYTE(0x0111),     /* bcdHID */                                \
        0x00,                    /* bCountryCode */                          \
        0x01,                    /* bNumDescriptors */                       \
        0x22,                    /* bDescriptorType   (Report descriptor) */ \
        U16_TO_BYTE(report_size) /* bDescriptorLength */

/* Endpoint Descriptor: */
#define SWITCH_PRO_ENDPOINT_DESCRIPTOR_IN1                                                             \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x81,                /* bEndpointAddress  (IN endpoint 1) */                                   \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x08                 /* bInterval         (8 frames) */

/* Endpoint Descriptor: */
#define SWITCH_PRO_ENDPOINT_DESCRIPTOR_OUT1                                                            \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x01,                /* bEndpointAddress  (OUT endpoint 1) */                                  \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x08                 /* bInterval         (8 frames) */

#define SWITCH_PRO_MANUFACTURER_STRING "Nintendo"
#define SWITCH_PRO_PRODUCT_STRING "Pro Controller"
#define SWITCH_PRO_SERIAL_STRING 0

#define SWITCH_PRO_STRING_DESCRIPTOR    \
    (const char[]){0x09, 0x04},         \
        SWITCH_PRO_MANUFACTURER_STRING, \
        SWITCH_PRO_PRODUCT_STRING,      \
        SWITCH_PRO_SERIAL_STRING

#define SWITCH_PRO_USB_REPORT_MAP                                                                                             \
    0x05, 0x01,                       /* Usage Page (Generic Desktop Ctrls) */                                                \
        0x15, 0x00,                   /* Logical Minimum (0) */                                                               \
        0x09, 0x04,                   /* Usage (Joystick) */                                                                  \
        0xA1, 0x01,                   /* Collection (Application) */                                                          \
        0x85, 0x30,                   /*   Report ID (48) */                                                                  \
        0x05, 0x01,                   /*   Usage Page (Generic Desktop Ctrls) */                                              \
        0x05, 0x09,                   /*   Usage Page (Button) */                                                             \
        0x19, 0x01,                   /*   Usage Minimum (0x01) */                                                            \
        0x29, 0x0A,                   /*   Usage Maximum (0x0A) */                                                            \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                             \
        0x25, 0x01,                   /*   Logical Maximum (1) */                                                             \
        0x75, 0x01,                   /*   Report Size (1) */                                                                 \
        0x95, 0x0A,                   /*   Report Count (10) */                                                               \
        0x55, 0x00,                   /*   Unit Exponent (0) */                                                               \
        0x65, 0x00,                   /*   Unit (None) */                                                                     \
        0x81, 0x02,                   /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */            \
        0x05, 0x09,                   /*   Usage Page (Button) */                                                             \
        0x19, 0x0B,                   /*   Usage Minimum (0x0B) */                                                            \
        0x29, 0x0E,                   /*   Usage Maximum (0x0E) */                                                            \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                             \
        0x25, 0x01,                   /*   Logical Maximum (1) */                                                             \
        0x75, 0x01,                   /*   Report Size (1) */                                                                 \
        0x95, 0x04,                   /*   Report Count (4) */                                                                \
        0x81, 0x02,                   /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */            \
        0x75, 0x01,                   /*   Report Size (1) */                                                                 \
        0x95, 0x02,                   /*   Report Count (2) */                                                                \
        0x81, 0x03,                   /*   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */           \
        0x0B, 0x01, 0x00, 0x01, 0x00, /*   Usage (0x010001) */                                                                \
        0xA1, 0x00,                   /*   Collection (Physical) */                                                           \
        0x0B, 0x30, 0x00, 0x01, 0x00, /*     Usage (0x010030) */                                                              \
        0x0B, 0x31, 0x00, 0x01, 0x00, /*     Usage (0x010031) */                                                              \
        0x0B, 0x32, 0x00, 0x01, 0x00, /*     Usage (0x010032) */                                                              \
        0x0B, 0x35, 0x00, 0x01, 0x00, /*     Usage (0x010035) */                                                              \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                           \
        0x27, 0xFF, 0xFF, 0x00, 0x00, /*     Logical Maximum (65534) */                                                       \
        0x75, 0x10,                   /*     Report Size (16) */                                                              \
        0x95, 0x04,                   /*     Report Count (4) */                                                              \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */          \
        0xC0,                         /*   End Collection */                                                                  \
        0x0B, 0x39, 0x00, 0x01, 0x00, /*   Usage (0x010039) */                                                                \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                             \
        0x25, 0x07,                   /*   Logical Maximum (7) */                                                             \
        0x35, 0x00,                   /*   Physical Minimum (0) */                                                            \
        0x46, 0x3B, 0x01,             /*   Physical Maximum (315) */                                                          \
        0x65, 0x14,                   /*   Unit (System: English Rotation, Length: Centimeter) */                             \
        0x75, 0x04,                   /*   Report Size (4) */                                                                 \
        0x95, 0x01,                   /*   Report Count (1) */                                                                \
        0x81, 0x02,                   /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */            \
        0x05, 0x09,                   /*   Usage Page (Button) */                                                             \
        0x19, 0x0F,                   /*   Usage Minimum (0x0F) */                                                            \
        0x29, 0x12,                   /*   Usage Maximum (0x12) */                                                            \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                             \
        0x25, 0x01,                   /*   Logical Maximum (1) */                                                             \
        0x75, 0x01,                   /*   Report Size (1) */                                                                 \
        0x95, 0x04,                   /*   Report Count (4) */                                                                \
        0x81, 0x02,                   /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */            \
        0x75, 0x08,                   /*   Report Size (8) */                                                                 \
        0x95, 0x34,                   /*   Report Count (52) */                                                               \
        0x81, 0x03,                   /*   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */           \
        0x06, 0x00, 0xFF,             /*   Usage Page (Vendor Defined 0xFF00) */                                              \
        0x85, 0x21,                   /*   Report ID (33) */                                                                  \
        0x09, 0x01,                   /*   Usage (0x01) */                                                                    \
        0x75, 0x08,                   /*   Report Size (8) */                                                                 \
        0x95, 0x3F,                   /*   Report Count (63) */                                                               \
        0x81, 0x03,                   /*   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */           \
        0x85, 0x81,                   /*   Report ID (-127) */                                                                \
        0x09, 0x02,                   /*   Usage (0x02) */                                                                    \
        0x75, 0x08,                   /*   Report Size (8) */                                                                 \
        0x95, 0x3F,                   /*   Report Count (63) */                                                               \
        0x81, 0x03,                   /*   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */           \
        0x85, 0x01,                   /*   Report ID (1) */                                                                   \
        0x09, 0x03,                   /*   Usage (0x03) */                                                                    \
        0x75, 0x08,                   /*   Report Size (8) */                                                                 \
        0x95, 0x3F,                   /*   Report Count (63) */                                                               \
        0x91, 0x83,                   /*   Output (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Volatile) */ \
        0x85, 0x10,                   /*   Report ID (16) */                                                                  \
        0x09, 0x04,                   /*   Usage (0x04) */                                                                    \
        0x75, 0x08,                   /*   Report Size (8) */                                                                 \
        0x95, 0x3F,                   /*   Report Count (63) */                                                               \
        0x91, 0x83,                   /*   Output (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Volatile) */ \
        0x85, 0x80,                   /*   Report ID (-128) */                                                                \
        0x09, 0x05,                   /*   Usage (0x05) */                                                                    \
        0x75, 0x08,                   /*   Report Size (8) */                                                                 \
        0x95, 0x3F,                   /*   Report Count (63) */                                                               \
        0x91, 0x83,                   /*   Output (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Volatile) */ \
        0x85, 0x82,                   /*   Report ID (-126) */                                                                \
        0x09, 0x06,                   /*   Usage (0x06) */                                                                    \
        0x75, 0x08,                   /*   Report Size (8) */                                                                 \
        0x95, 0x3F,                   /*   Report Count (63) */                                                               \
        0x91, 0x83,                   /*   Output (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Volatile) */ \
        0xC0                          /* End Collection */
// 203 bytes

#define SWITCH_PRO_BT_REPORT_MAP                                                                                                                    \
    0x05, 0x01,                                          /* Usage Page (Generic Desktop Ctrls) */                                                   \
        0x09, 0x05,                                      /* Usage (Game Pad) */                                                                     \
        0xA1, 0x01,                                      /* Collection (Application) */                                                             \
        0x06, 0x01, 0xFF,                                /*   Usage Page (Vendor Defined 0xFF01) */                                                 \
        0x85, SWITCH_PRO_BT_INPUT_ID_STD,                /*   Report ID (33) */                                                                     \
        0x09, 0x21,                                      /*   Usage (0x21) */                                                                       \
        0x75, 0x08,                                      /*   Report Size (8) */                                                                    \
        0x95, 0x30,                                      /*   Report Count (48) */                                                                  \
        0x81, 0x02,                                      /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */               \
        0x85, SWITCH_PRO_BT_INPUT_ID_FULL,               /*   Report ID (48) */                                                                     \
        0x09, 0x30,                                      /*   Usage (0x30) */                                                                       \
        0x75, 0x08,                                      /*   Report Size (8) */                                                                    \
        0x95, 0x30,                                      /*   Report Count (48) */                                                                  \
        0x81, 0x02,                                      /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */               \
        0x85, SWITCH_PRO_BT_INPUT_ID_NFC_MCU,            /*   Report ID (49) */                                                                     \
        0x09, 0x31,                                      /*   Usage (0x31) */                                                                       \
        0x75, 0x08,                                      /*   Report Size (8) */                                                                    \
        0x96, 0x69, 0x01,                                /*   Report Count (361) */                                                                 \
        0x81, 0x02,                                      /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */               \
        0x85, SWITCH_PRO_BT_INPUT_ID_UNKNOWN1,           /*   Report ID (50) */                                                                     \
        0x09, 0x32,                                      /*   Usage (0x32) */                                                                       \
        0x75, 0x08,                                      /*   Report Size (8) */                                                                    \
        0x96, 0x69, 0x01,                                /*   Report Count (361) */                                                                 \
        0x81, 0x02,                                      /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */               \
        0x85, SWITCH_PRO_BT_INPUT_ID_UNKNOWN2,           /*   Report ID (51) */                                                                     \
        0x09, 0x33,                                      /*   Usage (0x33) */                                                                       \
        0x75, 0x08,                                      /*   Report Size (8) */                                                                    \
        0x96, 0x69, 0x01,                                /*   Report Count (361) */                                                                 \
        0x81, 0x02,                                      /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */               \
        0x85, SWITCH_PRO_BT_INPUT_ID,                    /*   Report ID (63) */                                                                     \
        0x05, 0x09,                                      /*   Usage Page (Button) */                                                                \
        0x19, 0x01,                                      /*   Usage Minimum (0x01) */                                                               \
        0x29, 0x10,                                      /*   Usage Maximum (0x10) */                                                               \
        0x15, 0x00,                                      /*   Logical Minimum (0) */                                                                \
        0x25, 0x01,                                      /*   Logical Maximum (1) */                                                                \
        0x75, 0x01,                                      /*   Report Size (1) */                                                                    \
        0x95, 0x10,                                      /*   Report Count (16) */                                                                  \
        0x81, 0x02,                                      /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */               \
        0x05, 0x01,                                      /*   Usage Page (Generic Desktop Ctrls) */                                                 \
        0x09, 0x39,                                      /*   Usage (Hat switch) */                                                                 \
        0x15, 0x00,                                      /*   Logical Minimum (0) */                                                                \
        0x25, 0x07,                                      /*   Logical Maximum (7) */                                                                \
        0x75, 0x04,                                      /*   Report Size (4) */                                                                    \
        0x95, 0x01,                                      /*   Report Count (1) */                                                                   \
        0x81, 0x42,                                      /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,Null State) */                     \
        0x05, 0x09,                                      /*   Usage Page (Button) */                                                                \
        0x75, 0x04,                                      /*   Report Size (4) */                                                                    \
        0x95, 0x01,                                      /*   Report Count (1) */                                                                   \
        0x81, 0x01,                                      /*   Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position) */            \
        0x05, 0x01,                                      /*   Usage Page (Generic Desktop Ctrls) */                                                 \
        0x09, 0x30,                                      /*   Usage (X) */                                                                          \
        0x09, 0x31,                                      /*   Usage (Y) */                                                                          \
        0x09, 0x33,                                      /*   Usage (Rx) */                                                                         \
        0x09, 0x34,                                      /*   Usage (Ry) */                                                                         \
        0x16, 0x00, 0x00,                                /*   Logical Minimum (0) */                                                                \
        0x27, 0xFF, 0xFF, 0x00, 0x00,                    /*   Logical Maximum (65534) */                                                            \
        0x75, 0x10,                                      /*   Report Size (16) */                                                                   \
        0x95, 0x04,                                      /*   Report Count (4) */                                                                   \
        0x81, 0x02,                                      /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */               \
        0x06, 0x01, 0xFF,                                /*   Usage Page (Vendor Defined 0xFF01) */                                                 \
        0x85, SWITCH_PRO_BT_OUTPUT_ID_RUMBLE_SUBCMD,     /*   Report ID (1) */                                                                      \
        0x09, 0x01,                                      /*   Usage (0x01) */                                                                       \
        0x75, 0x08,                                      /*   Report Size (8) */                                                                    \
        0x95, 0x30,                                      /*   Report Count (48) */                                                                  \
        0x91, 0x02,                                      /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, SWITCH_PRO_BT_OUTPUT_ID_RUMBLE,            /*   Report ID (16) */                                                                     \
        0x09, 0x10,                                      /*   Usage (0x10) */                                                                       \
        0x75, 0x08,                                      /*   Report Size (8) */                                                                    \
        0x95, 0x30,                                      /*   Report Count (48) */                                                                  \
        0x91, 0x02,                                      /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, SWITCH_PRO_BT_OUTPUT_ID_REQ_NFC_OR_RUMBLE, /*   Report ID (17) */                                                                     \
        0x09, 0x11,                                      /*   Usage (0x11) */                                                                       \
        0x75, 0x08,                                      /*   Report Size (8) */                                                                    \
        0x95, 0x30,                                      /*   Report Count (48) */                                                                  \
        0x91, 0x02,                                      /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, SWITCH_PRO_BT_OUTPUT_ID_UNKNOWN,           /*   Report ID (18) */                                                                     \
        0x09, 0x12,                                      /*   Usage (0x12) */                                                                       \
        0x75, 0x08,                                      /*   Report Size (8) */                                                                    \
        0x95, 0x30,                                      /*   Report Count (48) */                                                                  \
        0x91, 0x02,                                      /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0xC0                                             /* End Collection */

enum SwitchPro_Direction
{
    SwitchPro_Direction_North = 0,
    SwitchPro_Direction_NorthEast,
    SwitchPro_Direction_East,
    SwitchPro_Direction_SouthEast,
    SwitchPro_Direction_South,
    SwitchPro_Direction_SouthWest,
    SwitchPro_Direction_West,
    SwitchPro_Direction_NorthWest,
    SwitchPro_Direction_None = 8
};

typedef struct
{
    uint8_t btnA : 1;       // Usage 0x00090001: Button 1 Primary/trigger, Value = 0 to 1
    uint8_t btnB : 1;       // Usage 0x00090002: Button 2 Secondary, Value = 0 to 1
    uint8_t btnX : 1;       // Usage 0x00090003: Button 3 Tertiary, Value = 0 to 1
    uint8_t btnY : 1;       // Usage 0x00090004: Button 4, Value = 0 to 1
    uint8_t btnL : 1;       // Usage 0x00090005: Button 5, Value = 0 to 1
    uint8_t btnR : 1;       // Usage 0x00090006: Button 6, Value = 0 to 1
    uint8_t btnZL : 1;      // Usage 0x00090007: Button 7, Value = 0 to 1
    uint8_t btnZR : 1;      // Usage 0x00090008: Button 8, Value = 0 to 1
    uint8_t btnMinus : 1;   // Usage 0x00090009: Button 9, Value = 0 to 1
    uint8_t btnPlus : 1;    // Usage 0x0009000A: Button 10, Value = 0 to 1
    uint8_t btnLS : 1;      // Usage 0x0009000B: Button 11, Value = 0 to 1
    uint8_t btnRS : 1;      // Usage 0x0009000C: Button 12, Value = 0 to 1
    uint8_t btnHome : 1;    // Usage 0x0009000D: Button 13, Value = 0 to 1
    uint8_t btnCapture : 1; // Usage 0x0009000E: Button 14, Value = 0 to 1
    uint8_t btn15 : 1;      // Usage 0x0009000F: Button 15, Value = 0 to 1
    uint8_t : 1;            // Pad
    uint8_t hat : 4;        // Usage 0x00010039: Hat switch, Value = 0 to 7, Physical = (Value - 1) x 45 in degrees
    uint8_t : 4;            // Pad

    uint16_t X;  // Usage 0x00010030: X, Value = 0 to 65535
    uint16_t Y;  // Usage 0x00010031: Y, Value = 0 to 65535
    uint16_t Z;  // Usage 0x00010032: Z, Value = 0 to 65535
    uint16_t Rz; // Usage 0x00010035: Rz, Value = 0 to 65535
} switchProBtInputReport63_t;

typedef struct
{
    uint8_t reportId; // Report ID = 0x30 (48) '0'
    // Collection: CA:Joystick
    uint8_t ButtonA : 1;                    // Usage 0x00090001: Button 1 Primary/trigger, Value = 0 to 1
    uint8_t ButtonB : 1;                    // Usage 0x00090002: Button 2 Secondary, Value = 0 to 1
    uint8_t ButtonX : 1;                    // Usage 0x00090003: Button 3 Tertiary, Value = 0 to 1
    uint8_t ButtonY : 1;                    // Usage 0x00090004: Button 4, Value = 0 to 1
    uint8_t ButtonL : 1;                    // Usage 0x00090005: Button 5, Value = 0 to 1
    uint8_t ButtonR : 1;                    // Usage 0x00090006: Button 6, Value = 0 to 1
    uint8_t ButtonZL : 1;                   // Usage 0x00090007: Button 7, Value = 0 to 1
    uint8_t ButtonZR : 1;                   // Usage 0x00090008: Button 8, Value = 0 to 1
    uint8_t ButtonMinus : 1;                // Usage 0x00090009: Button 9, Value = 0 to 1
    uint8_t ButtonPlus : 1;                 // Usage 0x0009000A: Button 10, Value = 0 to 1
    uint8_t ButtonLS : 1;                   // Usage 0x0009000B: Button 11, Value = 0 to 1
    uint8_t ButtonRS : 1;                   // Usage 0x0009000C: Button 12, Value = 0 to 1
    uint8_t ButtonHome : 1;                 // Usage 0x0009000D: Button 13, Value = 0 to 1
    uint8_t ButtonCapture : 1;              // Usage 0x0009000E: Button 14, Value = 0 to 1
    uint8_t : 1;                            // Pad
    uint8_t : 1;                            // Pad
                                            // Collection: CA:Joystick CP:Pointer
    uint16_t X;                             // Usage 0x00010030: X, Value = 0 to 65535
    uint16_t Y;                             // Usage 0x00010031: Y, Value = 0 to 65535
    uint16_t Z;                             // Usage 0x00010032: Z, Value = 0 to 65535
    uint16_t Rz;                            // Usage 0x00010035: Rz, Value = 0 to 65535
                                            // Collection: CA:Joystick
    enum SwitchPro_Direction HatSwitch : 4; // Usage 0x00010039: Hat switch, Value = 0 to 7, Physical = Value x 45 in degrees
    uint8_t Button15 : 1;                   // Usage 0x0009000F: Button 15, Value = 0 to 1, Physical = Value x 315 in degrees
    uint8_t Button16 : 1;                   // Usage 0x00090010: Button 16, Value = 0 to 1, Physical = Value x 315 in degrees
    uint8_t Button17 : 1;                   // Usage 0x00090011: Button 17, Value = 0 to 1, Physical = Value x 315 in degrees
    uint8_t Button18 : 1;                   // Usage 0x00090012: Button 18, Value = 0 to 1, Physical = Value x 315 in degrees
    uint8_t pad_7[52];                      // Pad
} switchProUsbInputReport30_t;

typedef struct
{
    uint8_t reportId;             // Report ID = 0x21 (33)
                                  // Collection: CA:Joystick
    uint8_t VEN_Joystick0001[63]; // Usage 0xFF000001: , Value = 0 to 1, Physical = Value x 315 in degrees
} switchProUsbInputReport21_t;

typedef struct
{
    uint8_t reportId;             // Report ID = 0x81 (129)
                                  // Collection: CA:Joystick
    uint8_t VEN_Joystick0002[63]; // Usage 0xFF000002: , Value = 0 to 1, Physical = Value x 315 in degrees
} switchProUsbInputReport81_t;

typedef struct
{
    uint8_t reportId;             // Report ID = 0x01 (1)
                                  // Collection: CA:Joystick
    uint8_t VEN_Joystick0003[63]; // Usage 0xFF000003: , Value = 0 to 1, Physical = Value x 315 in degrees
} switchProUsbOutputReport01_t;

typedef struct
{
    uint8_t reportId;             // Report ID = 0x10 (16)
                                  // Collection: CA:Joystick
    uint8_t VEN_Joystick0004[63]; // Usage 0xFF000004: , Value = 0 to 1, Physical = Value x 315 in degrees
} switchProUsbOutputReport10_t;

typedef struct
{
    uint8_t reportId;             // Report ID = 0x80 (128)
                                  // Collection: CA:Joystick
    uint8_t VEN_Joystick0005[63]; // Usage 0xFF000005: , Value = 0 to 1, Physical = Value x 315 in degrees
} switchProUsbOutputReport80_t;

typedef struct
{
    uint8_t reportId;             // Report ID = 0x82 (130)
                                  // Collection: CA:Joystick
    uint8_t VEN_Joystick0006[63]; // Usage 0xFF000006: , Value = 0 to 1, Physical = Value x 315 in degrees
} switchProUsbOutputReport82_t;

/* ------------------------------ */
/* ------------------------------ */
/* ------------------------------ */
/* ------------------------------ */
/* ------------------------------ */
/* Bluetooth: */
/* ------------------------------ */
/* ------------------------------ */
/* ------------------------------ */
/* ------------------------------ */
/* ------------------------------ */
/* ------------------------------ */

/* input */
#define INPUT_REPORT_STAND_SIZE 64
#define INPUT_REPORT_LARGE_SIZE 362
#define INPUT_PACKET_STAND_SIZE 36
#define INPUT_PACKET_EXTRA_SIZE 313

typedef enum Power
{
    SELF = 0,
    SWITCH = 1,
} power_t;

typedef enum Battery
{
    BATT_EMPTY = 0,    // 0000
    BATT_CHARGING = 1, // 0001
    BATT_CRITICAL = 2, // 0010
    BATT_LOW = 4,      // 0100
    BATT_MEDIUM = 6,   // 0110
    BATT_FULL = 8,     // 1000
} battery_t;

typedef enum Category
{
    PRO_GRIP = 0,
    JOYCON_L = 1,
    JOYCON_R = 2,
    JOYCON = 3,
} category_t;

typedef enum ButtonState
{
    RELEASE = 0,
    PRESSED = 1,
} button_state_t;

typedef struct Button
{
    union
    {
        struct
        {
            // Right byte
            button_state_t Y : 1;
            button_state_t X : 1;
            button_state_t B : 1;
            button_state_t A : 1;
            button_state_t RSR : 1; // right Joy-Con only
            button_state_t RSL : 1; // right Joy-Con only
            button_state_t R : 1;
            button_state_t ZR : 1;
            // Shared byte
            button_state_t MINUS : 1;
            button_state_t PLUS : 1;
            button_state_t RS : 1;
            button_state_t LS : 1;
            button_state_t HOME : 1;
            button_state_t CAPTURE : 1;
            button_state_t NA : 1;
            button_state_t CAHRGING_GRIP : 1;
            // Left byte
            button_state_t DPAD_DOWN : 1;
            button_state_t DPAD_UP : 1;
            button_state_t DPAD_RIGHT : 1;
            button_state_t DPAD_LEFT : 1;
            button_state_t LSR : 1; // left Joy-Con only
            button_state_t LSL : 1; // left Joy-Con only
            button_state_t L : 1;
            button_state_t ZL : 1;
        };
        struct
        {
            uint8_t left;
            uint8_t shared;
            uint8_t right;
        };
    };
} button_t;

typedef struct Stick
{
    union
    {
        struct
        {
            uint16_t X : 12;
            uint16_t Y : 12;
        };
        uint8_t raw[3];
    };
} stick_t;

typedef struct Accelerator
{
    int16_t X;
    int16_t Y;
    int16_t Z;
} accelerator_t;

typedef struct Gyroscope
{
    int16_t X;
    int16_t Y;
    int16_t Z;
} gyroscope_t;

typedef struct ControllerState
{
    power_t power : 1;
    category_t category : 2;
    uint8_t _ : 1;
    battery_t battery : 4;
} controller_state_t;

typedef struct // ControllerData
{
    button_t button;
    stick_t left_stick;
    stick_t right_stick;
    void *meta[0];
} controller_data_t;

// 0x21 : 13~48(36)
typedef struct ReplyData
{
    uint8_t subcmd_ack;                        // 13
    uint8_t subcmd_id;                         // 14
    uint8_t data[INPUT_PACKET_STAND_SIZE - 2]; // 15~48(34)
} reply_data_t;

// 0x23 : 13~48(36)
typedef struct McuData
{
    uint8_t raw[INPUT_PACKET_STAND_SIZE];
} mcu_data_t;

// 0x30,0x31,0x32,0x33 : 13~48(36)
typedef struct ImuData
{
    accelerator_t acc_0;
    gyroscope_t gyro_0;
    accelerator_t acc_1;
    gyroscope_t gyro_1;
    accelerator_t acc_2;
    gyroscope_t gyro_2;
} imu_data_t;

typedef struct InputReport
{
    uint8_t id; // 0
    union
    {
        // raw [1:362]
        uint8_t raw[INPUT_REPORT_STAND_SIZE];
        // usb [1:?]
        uint8_t usb[0];
        struct
        {
            // standard part [1:12],
            uint8_t timer;                       // 1
            controller_state_t controller_state; // 2
            controller_data_t controller_data;   // 3~11
            uint8_t vib_ack;                     // 12
            union
            { // 13~48
                reply_data_t reply;
                mcu_data_t mcu;
                imu_data_t imu;
            };
            // extra part [49:361]
            union
            {
                uint8_t nfc[INPUT_PACKET_EXTRA_SIZE];
                uint8_t ir[INPUT_PACKET_EXTRA_SIZE];
            };
        };
    };
} input_report_t;

/* -output */
#define OUTPUT_REPORT_SIZE 0x31 // 49 is OK?
#define OUTPUT_REPORT_CMD 0x01
#define OUTPUT_REPORT_RUM 0x10
#define OUTPUT_REPORT_PHL 0x11
#define OUTPUT_REPORT_USB 0x80

#define FLASH_MEM_STEP 0x1d

typedef enum HciMode
{
    HCI_DISCONNECT = 0x0,
    HCI_RECONNECT = 0x1,
    HCI_REPAIR = 0x2,
    HCI_REBOOT = 0x4,
} hci_mode_t;

typedef enum GyroSensitivity
{
    GYRO_SENS_250DPS = 0x0,
    GYRO_SENS_500DPS = 0x1,
    GYRO_SENS_1000DPS = 0x2,
    GYRO_SENS_2000DPS = 0x3,
#define GYRO_SENS_DEFAULT GYRO_SENS_2000DPS
} gyro_sensitivity_t;

typedef enum AccSensitivity
{
    ACC_SENS_8G = 0x0,
    ACC_SENS_4G = 0x1,
    ACC_SENS_2G = 0x2,
    ACC_SENS_16G = 0x3,
#define ACC_SENS_DEFAULT ACC_SENS_8G
} acc_sensitivity_t;

typedef enum GyroPerformance
{
    GYRO_PERF_833HZ = 0x0,
    GYRO_PERF_208HZ = 0x1,
#define GYRO_PERF_DEFAULT GYRO_PERF_208HZ
} gyro_performance_t;

typedef enum AccBandwidth
{
    ACC_BW_200HZ = 0x0,
    ACC_BW_100HZ = 0x1,
#define ACC_BW_DEFAULT ACC_BW_100HZ
} acc_bandwidth_t;

typedef struct MacAddress
{
    uint8_t _0;
    uint8_t _1;
    uint8_t _2;
    uint8_t _3;
    uint8_t _4;
    uint8_t _5;
} mac_address_t;

typedef struct Alias
{
    char raw[20];
} alias_t;

typedef enum PollType
{
    POLL_NFC_IR_CAM = 0x0,
    POLL_NFC_IR_MCU = 0x1,
    POLL_NFC_IR_DATA = 0x2,
    POLL_IR_CAM = 0x3,
    POLL_STANDARD = 0x30,
    POLL_NFC_IR = 0x31,
    POLL_33 = 0x33, // ?
    POLL_35 = 0x35, // ?
    POLL_SIMPLE_HID = 0x3F,
} poll_type_t;

typedef struct U16
{
    uint8_t _0;
    uint8_t _1;
} u16_t;

typedef enum McuCmd
{
    MCU_CMD_SET_MODE = 0x21, // 0x21
    MCU_CMD_WRITE = 0x23,    // 0x23
} mcu_cmd_t;

typedef enum McuSubcmd
{
    MCU_SET_IR_MODE = 0x1,
    MCU_SET_IR_REG = 0x4,
} mcu_subcmd_t;

typedef enum McuMode
{
    MCU_MODE_STANDBY = 0x1, // 1: Standby
    MCU_MODE_NFC = 0x4,     // 4: NFC
    MCU_MODE_IR = 0x5,      // 5: IR
    MCU_MODE_INIT = 0x6,    // 6: Initializing/FW Update?
} mcu_mode_t;

typedef enum McuState
{
    MCU_STATE_SUSPEND = 0,
    MCU_STATE_RESUME,
    MCU_STATE_UPDATE,
} mcu_state_t;

typedef struct McuReg
{
    u16_t address;
    uint8_t value;
} mcu_reg_t;

typedef enum Player
{
#define _PLAYER(n) ((0x1 << (n)) - 1)
    PLAYER_0 = _PLAYER(0),
    PLAYER_1 = _PLAYER(1),
    PLAYER_2 = _PLAYER(2),
    PLAYER_3 = _PLAYER(3),
    PLAYER_4 = _PLAYER(4),
} player_t;
#define Player_(n) player_t(_PLAYER(n))

typedef enum PlayerFlash
{
#define _PLAYER_FLASH(n) ((0x1 << (n)) - 1)
    PLAYER_FLASH_0 = _PLAYER_FLASH(0),
    PLAYER_FLASH_1 = _PLAYER_FLASH(1),
    PLAYER_FLASH_2 = _PLAYER_FLASH(2),
    PLAYER_FLASH_3 = _PLAYER_FLASH(3),
    PLAYER_FLASH_4 = _PLAYER_FLASH(4),
} player_flash_t;
#define PlayerFlash_(n) player_flash_t(_PLAYER_FLASH(n))

typedef struct Patterns
{
    uint8_t raw[23];
} patterns_t;

// 10~63(54)
typedef struct Subcmd
{
    uint8_t cmd; // 10
    uint8_t raw[53];
} subcmd_t;

// Sub-command 0x01: Bluetooth manual pairing
typedef struct Subcmd_01
{
    uint8_t cmd;           // 10
    uint8_t subcmd;        // 11
    mac_address_t address; // 12~17(6), little endian
    uint8_t fixed[3];      // 18~20(3)
    alias_t alias;         // 21 ~40(20)
    uint8_t extra[8];      // 41~48(8)
} subcmd_01_t;

// Sub-command 0x02: Request device info
typedef struct Subcmd_02
{
    uint8_t cmd; // 10
} subcmd_02_t;

typedef struct Subcmd_03
{
    uint8_t cmd; // 10
    struct
    {
        union
        {
            poll_type_t poll_type : 8; // 11
            uint8_t raw[36];           // [11:46] 36
        };
        uint8_t crc;  // 47
        uint8_t tail; // 48
    };
} subcmd_03_t;

typedef struct Subcmd_04
{
    uint8_t cmd; // 10
    u16_t time;
} subcmd_04_t;

typedef struct Subcmd_05
{
    uint8_t cmd; // 10
} subcmd_05_t;

typedef struct Subcmd_06
{
    uint8_t cmd; // 10
    hci_mode_t mode : 8;
} subcmd_06_t;

typedef struct Subcmd_07
{
    uint8_t cmd; // 10
} subcmd_07_t;

typedef struct Subcmd_08
{
    uint8_t cmd; // 10
    uint8_t enable;
} subcmd_08_t;

typedef struct Subcmd_10
{
    uint8_t cmd; // 10
    uint32_t address;
    uint8_t length;
} subcmd_10_t;

typedef struct Subcmd_11
{
    uint8_t cmd; // 10
    uint32_t address;
    uint8_t length;
    uint8_t data[FLASH_MEM_STEP];
} subcmd_11_t;

typedef struct Subcmd_12
{
    uint8_t cmd; // 10
    uint32_t address;
    uint8_t length;
} subcmd_12_t;

typedef struct Subcmd_20
{
    uint8_t cmd; // 10
} subcmd_20_t;

typedef struct Subcmd_21
{
    uint8_t cmd;          // 10
    mcu_cmd_t subcmd : 8; // 11
    union
    {
#define SUBCMD_21_CRC_LEN 36
        // crc8 begin [12:47] 36
        struct
        {
            uint8_t raw[SUBCMD_21_CRC_LEN]; // [12:47] 36
            uint8_t crc;                    // 48
        };
        struct
        {
            mcu_subcmd_t mcu_subcmd : 8; // 12
            union
            {
                // #21
                mcu_mode_t mcu_mode : 8; // 13
                // #23#01
                struct
                {
                    uint8_t mcu_ir_mode;   // 13
                    uint8_t mcu_fragments; // 14
                    u16_t mcu_major_v;     // [15:16] 2
                    u16_t mcu_minor_v;     // [17:18] 2
                };
                // #23#04
                struct
                {
                    uint8_t mcu_reg_size; // 13
                    mcu_reg_t reg[9];     // [14:40] 27
                };
            };
        };
    };
} subcmd_21_t;

typedef struct Subcmd_22
{
    uint8_t cmd; // 10
    mcu_state_t state;
} subcmd_22_t;

typedef struct Subcmd_30
{
    uint8_t cmd; // 10
    player_t player : 4;
    player_flash_t flash : 4;
} subcmd_30_t;

typedef struct Subcmd_38
{
    uint8_t cmd;                 // 10
    uint8_t base_duration : 4;   // 0_L : 1~F = 8~175ms, 0 = OFF
    uint8_t pattern_count : 4;   // 0_H :
    uint8_t repeat_count : 4;    // 1_L : 0 = forever
    uint8_t start_intensity : 4; //
    patterns_t patterns;
} subcmd_38_t;

typedef struct Subcmd_40
{
    uint8_t cmd; // 10
    uint8_t enable;
} subcmd_40_t;

typedef struct Subcmd_41
{
    uint8_t cmd; // 10
    gyro_sensitivity_t gyro_sensitivity : 8;
    acc_sensitivity_t acc_sensitivity : 8;
    gyro_performance_t gyro_performance : 8;
    acc_bandwidth_t acc_bandwidth : 8;
} subcmd_41_t;

typedef struct Subcmd_42
{
    uint8_t cmd; // 10
    uint8_t address;
    uint8_t operation;
    uint8_t value;
} subcmd_42_t;

typedef struct Subcmd_43
{
    uint8_t cmd; // 10
    uint8_t address;
    uint8_t count;
} subcmd_43_t;

typedef struct Subcmd_48
{
    uint8_t cmd; // 10
    uint8_t enable_vibration;
} subcmd_48_t;

typedef struct Subcmd_50
{
    uint8_t cmd; // 10
} subcmd_50_t;

typedef struct RumbleData
{
    uint8_t freq_h;
    uint8_t freq_h_amp;
    uint8_t freq_l;
    uint8_t freq_l_amp;
} rumble_data_t;

typedef struct Rumble
{
    union
    {
        uint8_t raw[8];
        struct
        {
            rumble_data_t rumble_l;
            rumble_data_t rumble_r;
        };
    };
} rumble_t;

typedef struct OutputReport
{
    uint8_t id;    // 0 : 0x01,0x80,0x10,0x11
    uint8_t timer; // 1
    union
    { // 2~63(62)
        uint8_t raw[62];
        uint8_t usb[0];
        struct
        {
            rumble_t rumble; // 2~9(8)
            union
            { // 10~63(54)
                subcmd_t subcmd;
                subcmd_01_t subcmd_01;
                subcmd_03_t subcmd_03;
                subcmd_04_t subcmd_04;
                subcmd_08_t subcmd_08;
                subcmd_10_t subcmd_10;
                subcmd_11_t subcmd_11;
                subcmd_21_t subcmd_21;
                subcmd_22_t subcmd_22;
                subcmd_30_t subcmd_30;
                subcmd_38_t subcmd_38;
                subcmd_40_t subcmd_40;
                subcmd_43_t subcmd_43;
                subcmd_48_t subcmd_48;
            };
        };
    };
} output_report_t;

// this need not be packed
typedef struct RumbleDataF
{
    float freq_h;
    float freq_h_amp;
    float freq_l;
    float freq_l_amp;
} rumble_data_f_t;

/* ------------------------------ */
/* ------------------------------ */
/* ------------------------------ */
/* ------------------------------ */
/* ------------------------------ */
/* USB: */
/* ------------------------------ */
/* ------------------------------ */
/* ------------------------------ */
/* ------------------------------ */
/* ------------------------------ */
/* ------------------------------ */

typedef struct SwitchProUsb SwitchProUsb;
struct SwitchProUsb
{
    void (*do_work)(SwitchProUsb *self, uint8_t *hid_rx_buffer, uint8_t len);
    void (*handle_input_0x30)(SwitchProUsb *self);
    input_report_t gamepad_data;
    uint8_t hid_report_buffer[0x40];
    bool hid_report_open;
    uint8_t joyStickMode;
};

SwitchProUsb SwitchProUsb_();
void hid_switch_pro_report(uint8_t *hid_rx_buffer, uint8_t len);
// 0.0~1.0
float calcRumbleAmp(const rumble_data_t *rumble);
