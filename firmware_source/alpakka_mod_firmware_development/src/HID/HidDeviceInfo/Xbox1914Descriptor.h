#pragma once

#include "Library/common.h"

// https://github.com/DJm00n/ControllersInfo

#define XBOX_1914_USB_ITF0_NUM 0
#define XBOX_1914_USB_ITF1_NUM 1
#define XBOX_1914_USB_ITF2_NUM 2
#define XBOX_1914_USB_MSOS_DESCRIPTOR_VENDOR_CODE 0x90

/* HID input report id */
#define XBOX_1914_HID_INPUT_ID01 0x01
/* HID output report id */
#define XBOX_1914_HID_OUTPUT_ID03 0x03

/* Device Descriptor: */
#define XBOX_1914_USB_DEVICE_DESCRIPTOR \
    0x12,       /* .bLength */          \
        0x01,   /* .bDescriptorType */  \
        0x0200, /* .bcdUSB */           \
        0xFF,   /* .bDeviceClass */     \
        0x47,   /* .bDeviceSubClass */  \
        0xD0,   /* .bDeviceProtocol */  \
        0x40,   /* .bMaxPacketSize0 */  \
        0x045E, /* .idVendor */         \
        0x0B12, /* .idProduct */        \
        0x0503, /* .bcdDevice */        \
        0x01,   /* .iManufacturer */    \
        0x02,   /* .iProduct */         \
        0x03,   /* .iSerialNumber */    \
        0x01    /* .bNumConfiguration */

/* Configuration Descriptor: */
#define XBOX_1914_USB_CONFIGURATION_DESCRIPTOR                                        \
    0x09,                    /* bLength */                                            \
        0x02,                /* bDescriptorType */                                    \
        U16_TO_BYTE(0x0077), /* wTotalLength   (119 bytes) */                         \
        0x03,                /* bNumInterfaces */                                     \
        0x01,                /* bConfigurationValue */                                \
        0x00,                /* iConfiguration */                                     \
        0xA0,                /* bmAttributes   (Bus-powered Device, Remote-Wakeup) */ \
        0xFA                 /* bMaxPower      (500 mA) */

/* Interface Descriptor: */
#define XBOX_1914_USB_ITF0_ALT0_INTERFACE_DESCRIPTOR                         \
    0x09,                       /* bLength */                                \
        0x04,                   /* bDescriptorType */                        \
        XBOX_1914_USB_ITF0_NUM, /* bInterfaceNumber */                       \
        0x00,                   /* bAlternateSetting */                      \
        0x02,                   /* bNumEndPoints */                          \
        0xFF,                   /* bInterfaceClass      (Vendor specific) */ \
        0x47,                   /* bInterfaceSubClass  */                    \
        0xD0,                   /* bInterfaceProtocol */                     \
        0x00                    /* iInterface */

/* Endpoint Descriptor: */
#define XBOX_1914_USB_ITF0_ALT0_OUT_ENDPOINT_DESCRIPTOR                                                \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x02,                /* bEndpointAddress  (OUT endpoint 2) */                                  \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x04                 /* bInterval         (FullSpeed:4 ms, HightSpeed:8 microframes) */

/* Endpoint Descriptor: */
#define XBOX_1914_USB_ITF0_ALT0_IN_ENDPOINT_DESCRIPTOR                                                 \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x82,                /* bEndpointAddress  (IN endpoint 2) */                                   \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x04                 /* bInterval         (FullSpeed:4 ms, HightSpeed:8 microframes) */

/* Interface Descriptor: */
#define XBOX_1914_USB_ITF0_ALT1_INTERFACE_DESCRIPTOR                         \
    0x09,                       /* bLength */                                \
        0x04,                   /* bDescriptorType */                        \
        XBOX_1914_USB_ITF0_NUM, /* bInterfaceNumber */                       \
        0x01,                   /* bAlternateSetting */                      \
        0x02,                   /* bNumEndPoints */                          \
        0xFF,                   /* bInterfaceClass      (Vendor specific) */ \
        0x47,                   /* bInterfaceSubClass */                     \
        0xD0,                   /* bInterfaceProtocol */                     \
        0x00                    /* iInterface */

/* Endpoint Descriptor: */
#define XBOX_1914_USB_ITF0_ALT1_OUT_ENDPOINT_DESCRIPTOR                                                \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x02,                /* bEndpointAddress  (OUT endpoint 2) */                                  \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x04                 /* bInterval         (4 frames) */

/* Endpoint Descriptor: */
#define XBOX_1914_USB_ITF0_ALT1_IN_ENDPOINT_DESCRIPTOR                                                 \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x82,                /* bEndpointAddress  (IN endpoint 2) */                                   \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x02                 /* bInterval         (2 frames) */

/* Interface Descriptor: */
#define XBOX_1914_USB_ITF1_ALT0_INTERFACE_DESCRIPTOR                         \
    0x09,                       /* bLength */                                \
        0x04,                   /* bDescriptorType */                        \
        XBOX_1914_USB_ITF1_NUM, /* bInterfaceNumber */                       \
        0x00,                   /* bAlternateSetting */                      \
        0x00,                   /* bNumEndPoints */                          \
        0xFF,                   /* bInterfaceClass      (Vendor specific) */ \
        0x47,                   /* bInterfaceSubClass */                     \
        0xD0,                   /* bInterfaceProtocol */                     \
        0x00                    /* iInterface */

/* Interface Descriptor: */
#define XBOX_1914_USB_ITF1_ALT1_INTERFACE_DESCRIPTOR                         \
    0x09,                       /* bLength */                                \
        0x04,                   /* bDescriptorType */                        \
        XBOX_1914_USB_ITF1_NUM, /* bInterfaceNumber */                       \
        0x01,                   /* bAlternateSetting */                      \
        0x02,                   /* bNumEndPoints */                          \
        0xFF,                   /* bInterfaceClass      (Vendor specific) */ \
        0x47,                   /* bInterfaceSubClass */                     \
        0xD0,                   /* bInterfaceProtocol */                     \
        0x00                    /* iInterface */

/* Endpoint Descriptor: */
#define XBOX_1914_USB_ITF1_ALT1_OUT_ENDPOINT_DESCRIPTOR                                                  \
    0x07,                    /* bLength */                                                               \
        0x05,                /* bDescriptorType */                                                       \
        0x03,                /* bEndpointAddress  (OUT endpoint 3) */                                    \
        0x01,                /* bmAttributes      (Transfer: Isochronous / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x00E4), /* wMaxPacketSize    (1 x 228 bytes) */                                     \
        0x01                 /* bInterval         (1 frames) */

/* Endpoint Descriptor: */
#define XBOX_1914_USB_ITF1_ALT1_IN_ENDPOINT_DESCRIPTOR                                                   \
    0x07,                    /* bLength */                                                               \
        0x05,                /* bDescriptorType */                                                       \
        0x83,                /* bEndpointAddress  (IN endpoint 3) */                                     \
        0x01,                /* bmAttributes      (Transfer: Isochronous / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                      \
        0x01                 /* bInterval         (1 frames) */

/* Interface Descriptor: */
#define XBOX_1914_USB_ITF2_ALT0_INTERFACE_DESCRIPTOR                         \
    0x09,                       /* bLength */                                \
        0x04,                   /* bDescriptorType */                        \
        XBOX_1914_USB_ITF2_NUM, /* bInterfaceNumber */                       \
        0x00,                   /* bAlternateSetting */                      \
        0x00,                   /* bNumEndPoints */                          \
        0xFF,                   /* bInterfaceClass      (Vendor specific) */ \
        0x47,                   /* bInterfaceSubClass */                     \
        0xD0,                   /* bInterfaceProtocol */                     \
        0x00                    /* iInterface */

/* Interface Descriptor: */
#define XBOX_1914_USB_ITF2_ALT1_INTERFACE_DESCRIPTOR                         \
    0x09,                       /* bLength */                                \
        0x04,                   /* bDescriptorType */                        \
        XBOX_1914_USB_ITF2_NUM, /* bInterfaceNumber */                       \
        0x01,                   /* bAlternateSetting */                      \
        0x02,                   /* bNumEndPoints */                          \
        0xFF,                   /* bInterfaceClass      (Vendor specific) */ \
        0x47,                   /* bInterfaceSubClass */                     \
        0xD0,                   /* bInterfaceProtocol */                     \
        0x00                    /* iInterface */

/* Endpoint Descriptor: */
#define XBOX_1914_USB_ITF2_ALT1_OUT_ENDPOINT_DESCRIPTOR                                           \
    0x07,                    /* bLength */                                                        \
        0x05,                /* bDescriptorType */                                                \
        0x04,                /* bEndpointAddress  (OUT endpoint 4) */                             \
        0x02,                /* bmAttributes      (Transfer: Bulk / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (64 bytes) */                                   \
        0x00                 /* bInterval         (FullSpeed:Unused, HightSpeed:no NAK) */

/* Endpoint Descriptor: */
#define XBOX_1914_USB_ITF2_ALT1_IN_ENDPOINT_DESCRIPTOR                                            \
    0x07,                    /* bLength */                                                        \
        0x05,                /* bDescriptorType */                                                \
        0x84,                /* bEndpointAddress  (IN endpoint 4) */                              \
        0x02,                /* bmAttributes      (Transfer: Bulk / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (64 bytes) */                                   \
        0x00                 /* bInterval         (FullSpeed:Unused, HightSpeed:no NAK) */

/* Microsoft OS Descriptor: */
#define XBOX_1914_USB_MSOS_STRING_DESCRIPTOR                    \
    0x12, 0x03, 0x4D, 0x00, 0x53, 0x00, 0x46, 0x00, 0x54, 0x00, \
        0x31, 0x00, 0x30, 0x00, 0x30, 0x00, XBOX_1914_USB_MSOS_DESCRIPTOR_VENDOR_CODE, 0x00

#define XBOX_1914_USB_MSOS_COMPATIBLE_ID_DESCRIPTOR_SECTION(itf_idx) \
    itf_idx,                /* Interface index */                    \
        0x01,               /* Reserved */                           \
        'X', 'G', 'I', 'P', /* Compat ID */                          \
        '1', '0', 0x00, 0x00,                                        \
        0x00, 0x00, 0x00, 0x00, /* Sub-compat ID. */                 \
        0x00, 0x00, 0x00, 0x00,                                      \
        0x00, 0x00, 0x00, 0x00, /* Reserved */                       \
        0x00, 0x00              /* Reserved */

/* String Descriptor Table */
#define XBOX_1914_USB_STRING_DESCRIPTOR_0 (const char[]){0x09, 0x04}
#define XBOX_1914_USB_STRING_MANUFACTURER "Microsoft"
#define XBOX_1914_USB_STRING_PRODUCT "Controller"
#define XBOX_1914_USB_STRING_SERIAL "3039373130303637313034303231"

#define XBOX_1914_BT_HID_REPORT_DESCRIPTOR                                                                                          \
    0x05, 0x01,                       /* Usage Page (Generic Desktop Ctrls) */                                                      \
        0x09, 0x05,                   /* Usage (Game Pad) */                                                                        \
        0xA1, 0x01,                   /* Collection (Application) */                                                                \
        0x85, 0x01,                   /*   Report ID (1) */                                                                         \
        0x09, 0x01,                   /*   Usage (Pointer) */                                                                       \
        0xA1, 0x00,                   /*   Collection (Physical) */                                                                 \
        0x09, 0x30,                   /*     Usage (X) */                                                                           \
        0x09, 0x31,                   /*     Usage (Y) */                                                                           \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                 \
        0x27, 0xFF, 0xFF, 0x00, 0x00, /*     Logical Maximum (65534) */                                                             \
        0x95, 0x02,                   /*     Report Count (2) */                                                                    \
        0x75, 0x10,                   /*     Report Size (16) */                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0xC0,                         /*   End Collection */                                                                        \
        0x09, 0x01,                   /*   Usage (Pointer) */                                                                       \
        0xA1, 0x00,                   /*   Collection (Physical) */                                                                 \
        0x09, 0x32,                   /*     Usage (Z) */                                                                           \
        0x09, 0x35,                   /*     Usage (Rz) */                                                                          \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                 \
        0x27, 0xFF, 0xFF, 0x00, 0x00, /*     Logical Maximum (65534) */                                                             \
        0x95, 0x02,                   /*     Report Count (2) */                                                                    \
        0x75, 0x10,                   /*     Report Size (16) */                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0xC0,                         /*   End Collection */                                                                        \
        0x05, 0x02,                   /*   Usage Page (Sim Ctrls) */                                                                \
        0x09, 0xC5,                   /*   Usage (Brake) */                                                                         \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                                   \
        0x26, 0xFF, 0x03,             /*   Logical Maximum (1023) */                                                                \
        0x95, 0x01,                   /*   Report Count (1) */                                                                      \
        0x75, 0x0A,                   /*   Report Size (10) */                                                                      \
        0x81, 0x02,                   /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                  \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                                   \
        0x25, 0x00,                   /*   Logical Maximum (0) */                                                                   \
        0x75, 0x06,                   /*   Report Size (6) */                                                                       \
        0x95, 0x01,                   /*   Report Count (1) */                                                                      \
        0x81, 0x03,                   /*   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                 \
        0x05, 0x02,                   /*   Usage Page (Sim Ctrls) */                                                                \
        0x09, 0xC4,                   /*   Usage (Accelerator) */                                                                   \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                                   \
        0x26, 0xFF, 0x03,             /*   Logical Maximum (1023) */                                                                \
        0x95, 0x01,                   /*   Report Count (1) */                                                                      \
        0x75, 0x0A,                   /*   Report Size (10) */                                                                      \
        0x81, 0x02,                   /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                  \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                                   \
        0x25, 0x00,                   /*   Logical Maximum (0) */                                                                   \
        0x75, 0x06,                   /*   Report Size (6) */                                                                       \
        0x95, 0x01,                   /*   Report Count (1) */                                                                      \
        0x81, 0x03,                   /*   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                 \
        0x05, 0x01,                   /*   Usage Page (Generic Desktop Ctrls) */                                                    \
        0x09, 0x39,                   /*   Usage (Hat switch) */                                                                    \
        0x15, 0x01,                   /*   Logical Minimum (1) */                                                                   \
        0x25, 0x08,                   /*   Logical Maximum (8) */                                                                   \
        0x35, 0x00,                   /*   Physical Minimum (0) */                                                                  \
        0x46, 0x3B, 0x01,             /*   Physical Maximum (315) */                                                                \
        0x66, 0x14, 0x00,             /*   Unit (System: English Rotation, Length: Centimeter) */                                   \
        0x75, 0x04,                   /*   Report Size (4) */                                                                       \
        0x95, 0x01,                   /*   Report Count (1) */                                                                      \
        0x81, 0x42,                   /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,Null State) */                        \
        0x75, 0x04,                   /*   Report Size (4) */                                                                       \
        0x95, 0x01,                   /*   Report Count (1) */                                                                      \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                                   \
        0x25, 0x00,                   /*   Logical Maximum (0) */                                                                   \
        0x35, 0x00,                   /*   Physical Minimum (0) */                                                                  \
        0x45, 0x00,                   /*   Physical Maximum (0) */                                                                  \
        0x65, 0x00,                   /*   Unit (None) */                                                                           \
        0x81, 0x03,                   /*   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                 \
        0x05, 0x09,                   /*   Usage Page (Button) */                                                                   \
        0x19, 0x01,                   /*   Usage Minimum (0x01) */                                                                  \
        0x29, 0x0F,                   /*   Usage Maximum (0x0F) */                                                                  \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                                   \
        0x25, 0x01,                   /*   Logical Maximum (1) */                                                                   \
        0x75, 0x01,                   /*   Report Size (1) */                                                                       \
        0x95, 0x0F,                   /*   Report Count (15) */                                                                     \
        0x81, 0x02,                   /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                  \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                                   \
        0x25, 0x00,                   /*   Logical Maximum (0) */                                                                   \
        0x75, 0x01,                   /*   Report Size (1) */                                                                       \
        0x95, 0x01,                   /*   Report Count (1) */                                                                      \
        0x81, 0x03,                   /*   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                 \
        0x05, 0x0C,                   /*   Usage Page (Consumer) */                                                                 \
        0x0A, 0xB2, 0x00,             /*   Usage (Record) */                                                                        \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                                   \
        0x25, 0x01,                   /*   Logical Maximum (1) */                                                                   \
        0x95, 0x01,                   /*   Report Count (1) */                                                                      \
        0x75, 0x01,                   /*   Report Size (1) */                                                                       \
        0x81, 0x02,                   /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                  \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                                   \
        0x25, 0x00,                   /*   Logical Maximum (0) */                                                                   \
        0x75, 0x07,                   /*   Report Size (7) */                                                                       \
        0x95, 0x01,                   /*   Report Count (1) */                                                                      \
        0x81, 0x03,                   /*   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                 \
        0x05, 0x0F,                   /*   Usage Page (PID Page) */                                                                 \
        0x09, 0x21,                   /*   Usage (0x21) */                                                                          \
        0x85, 0x03,                   /*   Report ID (3) */                                                                         \
        0xA1, 0x02,                   /*   Collection (Logical) */                                                                  \
        0x09, 0x97,                   /*     Usage (0x97) */                                                                        \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                 \
        0x25, 0x01,                   /*     Logical Maximum (1) */                                                                 \
        0x75, 0x04,                   /*     Report Size (4) */                                                                     \
        0x95, 0x01,                   /*     Report Count (1) */                                                                    \
        0x91, 0x02,                   /*     Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                 \
        0x25, 0x00,                   /*     Logical Maximum (0) */                                                                 \
        0x75, 0x04,                   /*     Report Size (4) */                                                                     \
        0x95, 0x01,                   /*     Report Count (1) */                                                                    \
        0x91, 0x03,                   /*     Output (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x09, 0x70,                   /*     Usage (0x70) */                                                                        \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                 \
        0x25, 0x64,                   /*     Logical Maximum (100) */                                                               \
        0x75, 0x08,                   /*     Report Size (8) */                                                                     \
        0x95, 0x04,                   /*     Report Count (4) */                                                                    \
        0x91, 0x02,                   /*     Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x09, 0x50,                   /*     Usage (0x50) */                                                                        \
        0x66, 0x01, 0x10,             /*     Unit (System: SI Linear, Time: Seconds) */                                             \
        0x55, 0x0E,                   /*     Unit Exponent (-2) */                                                                  \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                 \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                               \
        0x75, 0x08,                   /*     Report Size (8) */                                                                     \
        0x95, 0x01,                   /*     Report Count (1) */                                                                    \
        0x91, 0x02,                   /*     Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x09, 0xA7,                   /*     Usage (0xA7) */                                                                        \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                 \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                               \
        0x75, 0x08,                   /*     Report Size (8) */                                                                     \
        0x95, 0x01,                   /*     Report Count (1) */                                                                    \
        0x91, 0x02,                   /*     Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x65, 0x00,                   /*     Unit (None) */                                                                         \
        0x55, 0x00,                   /*     Unit Exponent (0) */                                                                   \
        0x09, 0x7C,                   /*     Usage (0x7C) */                                                                        \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                 \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                               \
        0x75, 0x08,                   /*     Report Size (8) */                                                                     \
        0x95, 0x01,                   /*     Report Count (1) */                                                                    \
        0x91, 0x02,                   /*     Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0xC0,                         /*   End Collection */                                                                        \
        0xC0                          /* End Collection */
// 283 bytes
