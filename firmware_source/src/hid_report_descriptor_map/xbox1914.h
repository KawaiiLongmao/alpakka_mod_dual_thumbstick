#pragma once

#include <stdint.h>
#include "util.h"

#pragma pack(push, 1)

/* HID input report id */
#define XBOX_1914_INPUT_ID01 0x01
/* HID output report id */
#define XBOX_1914_OUTPUT_ID03 0x03

#define XBOX_1914_ITF_0 0
#define XBOX_1914_ITF_1 1
#define XBOX_1914_ITF_2 2
#define XBOX_1914_OS_VENDOR 0x90

/* Device Descriptor: */
#define XBOX_1914_DEVICE_DESCRIPTOR    \
    0x12,       /* .bLength */         \
        0x01,   /* .bDescriptorType */ \
        0x0200, /* .bcdUSB */          \
        0xFF,   /* .bDeviceClass */    \
        0x47,   /* .bDeviceSubClass */ \
        0xD0,   /* .bDeviceProtocol */ \
        0x40,   /* .bMaxPacketSize0 */ \
        0x045E, /* .idVendor */        \
        0x0B12, /* .idProduct */       \
        0x0503, /* .bcdDevice */       \
        0x01,   /* .iManufacturer */   \
        0x02,   /* .iProduct */        \
        0x03,   /* .iSerialNumber */   \
        0x01    /* .bNumConfiguration */

/* Configuration Descriptor: */
#define XBOX_1914_CONFIGURATION_DESCRIPTOR                                            \
    0x09,                    /* bLength */                                            \
        0x02,                /* bDescriptorType */                                    \
        U16_TO_BYTE(0x0077), /* wTotalLength   (119 bytes) */                         \
        0x03,                /* bNumInterfaces */                                     \
        0x01,                /* bConfigurationValue */                                \
        0x00,                /* iConfiguration */                                     \
        0xA0,                /* bmAttributes   (Bus-powered Device, Remote-Wakeup) */ \
        0xFA                 /* bMaxPower      (500 mA) */

/* Interface Descriptor: */
#define XBOX_1914_INTERFACE_DESCRIPTOR_0_0                            \
    0x09,                /* bLength */                                \
        0x04,            /* bDescriptorType */                        \
        XBOX_1914_ITF_0, /* bInterfaceNumber */                       \
        0x00,            /* bAlternateSetting */                      \
        0x02,            /* bNumEndPoints */                          \
        0xFF,            /* bInterfaceClass      (Vendor specific) */ \
        0x47,            /* bInterfaceSubClass  */                    \
        0xD0,            /* bInterfaceProtocol */                     \
        0x00,            /* iInterface */                             \
        XBOX_1914_ENDPOINT_DESCRIPTOR_0_0_OUT2,                       \
        XBOX_1914_ENDPOINT_DESCRIPTOR_0_0_IN2

/* Endpoint Descriptor: */
#define XBOX_1914_ENDPOINT_DESCRIPTOR_0_0_OUT2                                                         \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x02,                /* bEndpointAddress  (OUT endpoint 2) */                                  \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x04                 /* bInterval         (4 frames) */

/* Endpoint Descriptor: */
#define XBOX_1914_ENDPOINT_DESCRIPTOR_0_0_IN2                                                          \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x82,                /* bEndpointAddress  (IN endpoint 2) */                                   \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x04                 /* bInterval         (4 frames) */

/* Interface Descriptor: */
#define XBOX_1914_INTERFACE_DESCRIPTOR_0_1                            \
    0x09,                /* bLength */                                \
        0x04,            /* bDescriptorType */                        \
        XBOX_1914_ITF_0, /* bInterfaceNumber */                       \
        0x01,            /* bAlternateSetting */                      \
        0x02,            /* bNumEndPoints */                          \
        0xFF,            /* bInterfaceClass      (Vendor specific) */ \
        0x47,            /* bInterfaceSubClass */                     \
        0xD0,            /* bInterfaceProtocol */                     \
        0x00,            /* iInterface */                             \
        XBOX_1914_ENDPOINT_DESCRIPTOR_0_1_OUT2,                       \
        XBOX_1914_ENDPOINT_DESCRIPTOR_0_1_IN2

/* Endpoint Descriptor: */
#define XBOX_1914_ENDPOINT_DESCRIPTOR_0_1_OUT2                                                         \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x02,                /* bEndpointAddress  (OUT endpoint 2) */                                  \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x04                 /* bInterval         (4 frames) */

/* Endpoint Descriptor: */
#define XBOX_1914_ENDPOINT_DESCRIPTOR_0_1_IN2                                                          \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x82,                /* bEndpointAddress  (IN endpoint 2) */                                   \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x02                 /* bInterval         (2 frames) */

/* Interface Descriptor: */
#define XBOX_1914_INTERFACE_DESCRIPTOR_1_0                            \
    0x09,                /* bLength */                                \
        0x04,            /* bDescriptorType */                        \
        XBOX_1914_ITF_1, /* bInterfaceNumber */                       \
        0x00,            /* bAlternateSetting */                      \
        0x00,            /* bNumEndPoints */                          \
        0xFF,            /* bInterfaceClass      (Vendor specific) */ \
        0x47,            /* bInterfaceSubClass */                     \
        0xD0,            /* bInterfaceProtocol */                     \
        0x00             /* iInterface */

/* Interface Descriptor: */
#define XBOX_1914_INTERFACE_DESCRIPTOR_1_1                            \
    0x09,                /* bLength */                                \
        0x04,            /* bDescriptorType */                        \
        XBOX_1914_ITF_1, /* bInterfaceNumber */                       \
        0x01,            /* bAlternateSetting */                      \
        0x02,            /* bNumEndPoints */                          \
        0xFF,            /* bInterfaceClass      (Vendor specific) */ \
        0x47,            /* bInterfaceSubClass */                     \
        0xD0,            /* bInterfaceProtocol */                     \
        0x00,            /* iInterface */                             \
        XBOX_1914_ENDPOINT_DESCRIPTOR_1_1_OUT3,                       \
        XBOX_1914_ENDPOINT_DESCRIPTOR_1_1_IN3

/* Endpoint Descriptor: */
#define XBOX_1914_ENDPOINT_DESCRIPTOR_1_1_OUT3                                                           \
    0x07,                    /* bLength */                                                               \
        0x05,                /* bDescriptorType */                                                       \
        0x03,                /* bEndpointAddress  (OUT endpoint 3) */                                    \
        0x01,                /* bmAttributes      (Transfer: Isochronous / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x00E4), /* wMaxPacketSize    (1 x 228 bytes) */                                     \
        0x01                 /* bInterval         (1 frames) */

/* Endpoint Descriptor: */
#define XBOX_1914_ENDPOINT_DESCRIPTOR_1_1_IN3                                                            \
    0x07,                    /* bLength */                                                               \
        0x05,                /* bDescriptorType */                                                       \
        0x83,                /* bEndpointAddress  (IN endpoint 3) */                                     \
        0x01,                /* bmAttributes      (Transfer: Isochronous / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                      \
        0x01                 /* bInterval         (1 frames) */

/* Interface Descriptor: */
#define XBOX_1914_INTERFACE_DESCRIPTOR_2_0                            \
    0x09,                /* bLength */                                \
        0x04,            /* bDescriptorType */                        \
        XBOX_1914_ITF_2, /* bInterfaceNumber */                       \
        0x00,            /* bAlternateSetting */                      \
        0x00,            /* bNumEndPoints */                          \
        0xFF,            /* bInterfaceClass      (Vendor specific) */ \
        0x47,            /* bInterfaceSubClass */                     \
        0xD0,            /* bInterfaceProtocol */                     \
        0x00             /* iInterface */

/* Interface Descriptor: */
#define XBOX_1914_INTERFACE_DESCRIPTOR_2_1                            \
    0x09,                /* bLength */                                \
        0x04,            /* bDescriptorType */                        \
        XBOX_1914_ITF_2, /* bInterfaceNumber */                       \
        0x01,            /* bAlternateSetting */                      \
        0x02,            /* bNumEndPoints */                          \
        0xFF,            /* bInterfaceClass      (Vendor specific) */ \
        0x47,            /* bInterfaceSubClass */                     \
        0xD0,            /* bInterfaceProtocol */                     \
        0x00,            /* iInterface */                             \
        XBOX_1914_ENDPOINT_DESCRIPTOR_2_1_OUT4,                       \
        XBOX_1914_ENDPOINT_DESCRIPTOR_2_1_IN4

/* Endpoint Descriptor: */
#define XBOX_1914_ENDPOINT_DESCRIPTOR_2_1_OUT4                                                    \
    0x07,                    /* bLength */                                                        \
        0x05,                /* bDescriptorType */                                                \
        0x04,                /* bEndpointAddress  (OUT endpoint 4) */                             \
        0x02,                /* bmAttributes      (Transfer: Bulk / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (64 bytes) */                                   \
        0x00                 /* bInterval */

/* Endpoint Descriptor: */
#define XBOX_1914_ENDPOINT_DESCRIPTOR_2_1_IN4                                                     \
    0x07,                    /* bLength */                                                        \
        0x05,                /* bDescriptorType */                                                \
        0x84,                /* bEndpointAddress  (IN endpoint 4) */                              \
        0x02,                /* bmAttributes      (Transfer: Bulk / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (64 bytes) */                                   \
        0x00                 /* bInterval */

/* Microsoft OS Descriptor: */
#define XBOX_1914_OS_DESCRIPTOR                                 \
    0x12, 0x03, 0x4D, 0x00, 0x53, 0x00, 0x46, 0x00, 0x54, 0x00, \
        0x31, 0x00, 0x30, 0x00, 0x30, 0x00, XBOX_1914_OS_VENDOR, 0x00

/* String Descriptor Table */
#define XBOX_1914_MANUFACTURER_STRING "Microsoft"
#define XBOX_1914_PRODUCT_STRING "Controller"
#define XBOX_1914_SERIAL_STRING "3039373130303637313034303231"

#define XBOX_1914_STRING_DESCRIPTOR    \
    (const char[]){0x09, 0x04},        \
        XBOX_1914_MANUFACTURER_STRING, \
        XBOX_1914_PRODUCT_STRING,      \
        XBOX_1914_SERIAL_STRING

#define XBOX_1914_BT_REPORT_MAP                                                                                                     \
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

enum Xbox1914_Direction
{
    Xbox1914_Direction_None = 0,
    Xbox1914_Direction_North,
    Xbox1914_Direction_NorthEast,
    Xbox1914_Direction_East,
    Xbox1914_Direction_SouthEast,
    Xbox1914_Direction_South,
    Xbox1914_Direction_SouthWest,
    Xbox1914_Direction_West,
    Xbox1914_Direction_NorthWest = 8
};

typedef struct
{
    uint8_t reportId; // Report ID = 0x01 (1)
    // Collection: CA:GamePad CP:Pointer
    uint16_t X;                            // Usage 0x00010030: X, Value = 0 to 65535
    uint16_t Y;                            // Usage 0x00010031: Y, Value = 0 to 65535
    uint16_t Z;                            // Usage 0x00010032: Z, Value = 0 to 65535
    uint16_t Rz;                           // Usage 0x00010035: Rz, Value = 0 to 65535
                                           // Collection: CA:GamePad
    uint16_t Brake : 10;                   // Usage 0x000200C5: Brake, Value = 0 to 1023
    uint8_t : 6;                           // Pad
    uint16_t Accelerator : 10;             // Usage 0x000200C4: Accelerator, Value = 0 to 1023
    uint8_t : 6;                           // Pad
    enum Xbox1914_Direction HatSwitch : 4; // Usage 0x00010039: Hat switch, Value = 1 to 8, Physical = (Value - 1) x 45 in degrees
    uint8_t : 4;                           // Pad
    uint8_t ButtonA : 1;                   // Usage 0x00090001: Button 1 Primary/trigger, Value = 0 to 1
    uint8_t ButtonB : 1;                   // Usage 0x00090002: Button 2 Secondary, Value = 0 to 1
    uint8_t Button3 : 1;                   // Usage 0x00090003: Button 3 Tertiary, Value = 0 to 1
    uint8_t ButtonX : 1;                   // Usage 0x00090004: Button 4, Value = 0 to 1
    uint8_t ButtonY : 1;                   // Usage 0x00090005: Button 5, Value = 0 to 1
    uint8_t Button6 : 1;                   // Usage 0x00090006: Button 6, Value = 0 to 1
    uint8_t ButtonLB : 1;                  // Usage 0x00090007: Button 7, Value = 0 to 1
    uint8_t ButtonRB : 1;                  // Usage 0x00090008: Button 8, Value = 0 to 1
    uint8_t Button9 : 1;                   // Usage 0x00090009: Button 9, Value = 0 to 1
    uint8_t Button10 : 1;                  // Usage 0x0009000A: Button 10, Value = 0 to 1
    uint8_t ButtonBack : 1;                // Usage 0x0009000B: Button 11, Value = 0 to 1
    uint8_t ButtonStart : 1;               // Usage 0x0009000C: Button 12, Value = 0 to 1
    uint8_t ButtonXbox : 1;                // Usage 0x0009000D: Button 13, Value = 0 to 1
    uint8_t ButtonLS : 1;                  // Usage 0x0009000E: Button 14, Value = 0 to 1
    uint8_t ButtonRS : 1;                  // Usage 0x0009000F: Button 15, Value = 0 to 1
    uint8_t : 1;                           // Pad
    uint8_t Record : 1;                    // Usage 0x000C00B2: Record, Value = 0 to 1
    uint8_t : 7;                           // Pad
} xbox1914BtInputReport01_t;

typedef struct
{
    uint8_t reportId; // Report ID = 0x03 (3)
    // Collection: CA:GamePad CL:SetEffectReport
    uint8_t PID_GamePadSetEffectReportDcEnableActuators : 4; // Usage 0x000F0097: DC Enable Actuators, Value = 0 to 1
    uint8_t : 4;                                             // Pad
    uint8_t lTMagnitude;                                     // Usage 0x000F0070: Magnitude, Value = 0 to 100
    uint8_t rTMagnitude;                                     // Usage 0x000F0070: Magnitude, Value = 0 to 100
    uint8_t strongMagnitude;                                 // Usage 0x000F0070: Magnitude, Value = 0 to 100
    uint8_t weakMagnitude;                                   // Usage 0x000F0070: Magnitude, Value = 0 to 100
    uint8_t PID_GamePadSetEffectReportDuration;              // Usage 0x000F0050: Duration, Value = 0 to 255, Physical = Value in 10⁻² s units
    uint8_t PID_GamePadSetEffectReportStartDelay;            // Usage 0x000F00A7: Start Delay, Value = 0 to 255, Physical = Value in 10⁻² s units
    uint8_t PID_GamePadSetEffectReportLoopCount;             // Usage 0x000F007C: Loop Count, Value = 0 to 255
} xbox1914BtOutputReport03_t;
