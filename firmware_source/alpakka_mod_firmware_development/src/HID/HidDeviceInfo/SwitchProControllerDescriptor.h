#pragma once

#include "Library/common.h"

/* HID input report id */
#define SWITCH_PRO_BT_HID_INPUT_ID_STD 0x21           // Standard input reports used for subcommand replies.
#define SWITCH_PRO_BT_HID_INPUT_ID_NFC_FW_UPDATE 0x23 // NFC/IR MCU FW update input report.
#define SWITCH_PRO_BT_HID_INPUT_ID_FULL 0x30          // input reports with IMU data instead of subcommand replies.Pushes current state @120Hz
#define SWITCH_PRO_BT_HID_INPUT_ID_NFC_MCU 0x31       // Pushes large packets with standard input report + NFC/IR MCU data input report.
#define SWITCH_PRO_BT_HID_INPUT_ID_UNKNOWN1 0x32      // Sends standard input reports.
#define SWITCH_PRO_BT_HID_INPUT_ID_UNKNOWN2 0x33      // Sends standard input reports.
#define SWITCH_PRO_BT_HID_INPUT_ID 0x3F

/* HID output report id */
#define SWITCH_PRO_BT_HID_OUTPUT_ID_RUMBLE_SUBCMD 0x01
#define SWITCH_PRO_BT_HID_OUTPUT_ID_RUMBLE 0x10
#define SWITCH_PRO_BT_HID_OUTPUT_ID_REQ_NFC_OR_RUMBLE 0x11
#define SWITCH_PRO_BT_HID_OUTPUT_ID_UNKNOWN 0x12

/* HID input report id */
#define SWITCH_PRO_USB_HID_INPUT_ID_SUBCOMMAND_REPLY 0x21
#define SWITCH_PRO_USB_HID_INPUT_ID_FULL_CONTROLLER_STATE 0x30
#define SWITCH_PRO_USB_HID_INPUT_ID_FULL_CONTROLLER_AND_MCU_STATE 0x31
#define SWITCH_PRO_USB_HID_INPUT_ID_SIMPLE_CONTROLLER_STATE 0x3F
#define SWITCH_PRO_USB_HID_INPUT_ID_COMMAND_ACK 0x81

/* HID output report id */
#define SWITCH_PRO_USB_HID_OUTPUT_ID_RUMBLE_AND_SUBCOMMAND 0x01
#define SWITCH_PRO_USB_HID_OUTPUT_ID_RUMBLE 0x10
#define SWITCH_PRO_USB_HID_OUTPUT_ID_PROPRIETARY 0x80

/* HID report size */
#define MaxInputReportSizeBytes 64
#define SWITCH_PRO_USB_HID_REPORT_SIZE 63
#define SWITCH_PRO_USB_HID_INPUT_REPORT_SIMPLE_SIZE 63
#define SWITCH_PRO_USB_HID_INPUT_REPORT_FULL_SIZE 63
#define SWITCH_PRO_USB_HID_INPUT_REPORT_STAND_SIZE 63

#define SWITCH_PRO_BT_HID_INPUT_REPORT_SIMPLE_SIZE 11
#define SWITCH_PRO_BT_HID_INPUT_REPORT_FULL_SIZE 48
#define SWITCH_PRO_BT_HID_INPUT_REPORT_STAND_SIZE 48

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
#define SWITCH_PRO_DESCRIPTOR_CONFIGURATION                                           \
    0x09,                    /* bLength */                                            \
        0x02,                /* bDescriptorType */                                    \
        U16_TO_BYTE(0x0029), /* wTotalLength   (41 bytes) */                          \
        0x01,                /* bNumInterfaces */                                     \
        0x01,                /* bConfigurationValue */                                \
        0x00,                /* iConfiguration */                                     \
        0xA0,                /* bmAttributes   (Bus-powered Device, Remote-Wakeup) */ \
        0xFA                 /* bMaxPower      (500 mA) */

/* Interface Descriptor: */
#define SWITCH_PRO_DESCRIPTOR_INTERFACE                                 \
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
#define SWITCH_PRO_DESCRIPTOR_HID                                        \
    0x09,                    /* bLength */                               \
        0x21,                /* bDescriptorType */                       \
        U16_TO_BYTE(0x0111), /* bcdHID */                                \
        0x00,                /* bCountryCode */                          \
        0x01,                /* bNumDescriptors */                       \
        0x22,                /* bDescriptorType   (Report descriptor) */ \
        U16_TO_BYTE(0x00CB)  /* bDescriptorLength */

/* Endpoint Descriptor: */
#define SWITCH_PRO_DESCRIPTOR_ENDPOINT_IN                                                              \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x81,                /* bEndpointAddress  (IN endpoint 1) */                                   \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x08                 /* bInterval         (8 frames) */

/* Endpoint Descriptor: */
#define SWITCH_PRO_DESCRIPTOR_ENDPOINT_OUT                                                             \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x01,                /* bEndpointAddress  (OUT endpoint 1) */                                  \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x08                 /* bInterval         (8 frames) */

/* String Descriptor Table */
#define SWITCH_PRO_STRING_DESCRIPTOR_0 (const char[]){0x09, 0x04}
#define SWITCH_PRO_MANUFACTURER_STRING "Nintendo"
#define SWITCH_PRO_PRODUCT_STRING "Pro Controller"
#define SWITCH_PRO_SERIAL_STRING 0

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

#define SWITCH_PRO_BT_REPORT_MAP                                                                                                                        \
    0x05, 0x01,                                              /* Usage Page (Generic Desktop Ctrls) */                                                   \
        0x09, 0x05,                                          /* Usage (Game Pad) */                                                                     \
        0xA1, 0x01,                                          /* Collection (Application) */                                                             \
        0x06, 0x01, 0xFF,                                    /*   Usage Page (Vendor Defined 0xFF01) */                                                 \
        0x85, SWITCH_PRO_BT_HID_INPUT_ID_STD,                /*   Report ID (33) */                                                                     \
        0x09, 0x21,                                          /*   Usage (0x21) */                                                                       \
        0x75, 0x08,                                          /*   Report Size (8) */                                                                    \
        0x95, 0x30,                                          /*   Report Count (48) */                                                                  \
        0x81, 0x02,                                          /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */               \
        0x85, SWITCH_PRO_BT_HID_INPUT_ID_FULL,               /*   Report ID (48) */                                                                     \
        0x09, 0x30,                                          /*   Usage (0x30) */                                                                       \
        0x75, 0x08,                                          /*   Report Size (8) */                                                                    \
        0x95, 0x30,                                          /*   Report Count (48) */                                                                  \
        0x81, 0x02,                                          /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */               \
        0x85, SWITCH_PRO_BT_HID_INPUT_ID_NFC_MCU,            /*   Report ID (49) */                                                                     \
        0x09, 0x31,                                          /*   Usage (0x31) */                                                                       \
        0x75, 0x08,                                          /*   Report Size (8) */                                                                    \
        0x96, 0x69, 0x01,                                    /*   Report Count (361) */                                                                 \
        0x81, 0x02,                                          /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */               \
        0x85, SWITCH_PRO_BT_HID_INPUT_ID_UNKNOWN1,           /*   Report ID (50) */                                                                     \
        0x09, 0x32,                                          /*   Usage (0x32) */                                                                       \
        0x75, 0x08,                                          /*   Report Size (8) */                                                                    \
        0x96, 0x69, 0x01,                                    /*   Report Count (361) */                                                                 \
        0x81, 0x02,                                          /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */               \
        0x85, SWITCH_PRO_BT_HID_INPUT_ID_UNKNOWN2,           /*   Report ID (51) */                                                                     \
        0x09, 0x33,                                          /*   Usage (0x33) */                                                                       \
        0x75, 0x08,                                          /*   Report Size (8) */                                                                    \
        0x96, 0x69, 0x01,                                    /*   Report Count (361) */                                                                 \
        0x81, 0x02,                                          /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */               \
        0x85, SWITCH_PRO_BT_HID_INPUT_ID,                    /*   Report ID (63) */                                                                     \
        0x05, 0x09,                                          /*   Usage Page (Button) */                                                                \
        0x19, 0x01,                                          /*   Usage Minimum (0x01) */                                                               \
        0x29, 0x10,                                          /*   Usage Maximum (0x10) */                                                               \
        0x15, 0x00,                                          /*   Logical Minimum (0) */                                                                \
        0x25, 0x01,                                          /*   Logical Maximum (1) */                                                                \
        0x75, 0x01,                                          /*   Report Size (1) */                                                                    \
        0x95, 0x10,                                          /*   Report Count (16) */                                                                  \
        0x81, 0x02,                                          /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */               \
        0x05, 0x01,                                          /*   Usage Page (Generic Desktop Ctrls) */                                                 \
        0x09, 0x39,                                          /*   Usage (Hat switch) */                                                                 \
        0x15, 0x00,                                          /*   Logical Minimum (0) */                                                                \
        0x25, 0x07,                                          /*   Logical Maximum (7) */                                                                \
        0x75, 0x04,                                          /*   Report Size (4) */                                                                    \
        0x95, 0x01,                                          /*   Report Count (1) */                                                                   \
        0x81, 0x42,                                          /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,Null State) */                     \
        0x05, 0x09,                                          /*   Usage Page (Button) */                                                                \
        0x75, 0x04,                                          /*   Report Size (4) */                                                                    \
        0x95, 0x01,                                          /*   Report Count (1) */                                                                   \
        0x81, 0x01,                                          /*   Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position) */            \
        0x05, 0x01,                                          /*   Usage Page (Generic Desktop Ctrls) */                                                 \
        0x09, 0x30,                                          /*   Usage (X) */                                                                          \
        0x09, 0x31,                                          /*   Usage (Y) */                                                                          \
        0x09, 0x33,                                          /*   Usage (Rx) */                                                                         \
        0x09, 0x34,                                          /*   Usage (Ry) */                                                                         \
        0x16, 0x00, 0x00,                                    /*   Logical Minimum (0) */                                                                \
        0x27, 0xFF, 0xFF, 0x00, 0x00,                        /*   Logical Maximum (65534) */                                                            \
        0x75, 0x10,                                          /*   Report Size (16) */                                                                   \
        0x95, 0x04,                                          /*   Report Count (4) */                                                                   \
        0x81, 0x02,                                          /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */               \
        0x06, 0x01, 0xFF,                                    /*   Usage Page (Vendor Defined 0xFF01) */                                                 \
        0x85, SWITCH_PRO_BT_HID_OUTPUT_ID_RUMBLE_SUBCMD,     /*   Report ID (1) */                                                                      \
        0x09, 0x01,                                          /*   Usage (0x01) */                                                                       \
        0x75, 0x08,                                          /*   Report Size (8) */                                                                    \
        0x95, 0x30,                                          /*   Report Count (48) */                                                                  \
        0x91, 0x02,                                          /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, SWITCH_PRO_BT_HID_OUTPUT_ID_RUMBLE,            /*   Report ID (16) */                                                                     \
        0x09, 0x10,                                          /*   Usage (0x10) */                                                                       \
        0x75, 0x08,                                          /*   Report Size (8) */                                                                    \
        0x95, 0x30,                                          /*   Report Count (48) */                                                                  \
        0x91, 0x02,                                          /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, SWITCH_PRO_BT_HID_OUTPUT_ID_REQ_NFC_OR_RUMBLE, /*   Report ID (17) */                                                                     \
        0x09, 0x11,                                          /*   Usage (0x11) */                                                                       \
        0x75, 0x08,                                          /*   Report Size (8) */                                                                    \
        0x95, 0x30,                                          /*   Report Count (48) */                                                                  \
        0x91, 0x02,                                          /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, SWITCH_PRO_BT_HID_OUTPUT_ID_UNKNOWN,           /*   Report ID (18) */                                                                     \
        0x09, 0x12,                                          /*   Usage (0x12) */                                                                       \
        0x75, 0x08,                                          /*   Report Size (8) */                                                                    \
        0x95, 0x30,                                          /*   Report Count (48) */                                                                  \
        0x91, 0x02,                                          /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0xC0                                                 /* End Collection */
