#ifndef DUAL_SHOCK_4_H
#define DUAL_SHOCK_4_H

#pragma once

#include <stdint.h>
#include "util.h"

#pragma pack(push, 1)

/* HID input report id */
#define DUAL_SHOCK_4_REPORT_INPUT_ID01 0x01
/* HID output report id */
#define DUAL_SHOCK_4_REPORT_OUTPUT_ID11 0x11
/* HID feature report id */
#define DUAL_SHOCK_4_USB_REPORT_FEATURE_ID05 0x05

#define DUAL_SHOCK_4_ITF_0 0
#define DUAL_SHOCK_4_ITF_1 1
#define DUAL_SHOCK_4_ITF_2 2
#define DUAL_SHOCK_4_ITF_HID 0

/* Device Descriptor: */
#define DUAL_SHOCK_4_DEVICE_DESCRIPTOR                                 \
    0x12,       /* bLength */                                          \
        0x01,   /* bDescriptorType */                                  \
        0x0200, /* bcdUSB */                                           \
        0x00,   /* bDeviceClass */                                     \
        0x00,   /* bDeviceSubClass */                                  \
        0x00,   /* bDeviceProtocol */                                  \
        0x40,   /* bMaxPacketSize0   (64 bytes) */                     \
        0x054C, /* idVendor */                                         \
        0x09CC, /* idProduct */                                        \
        0x0100, /* bcdDevice */                                        \
        0x01,   /* iManufacturer   "Sony Interactive Entertainment" */ \
        0x02,   /* iProduct        "Wireless Controller" */            \
        0x00,   /* iSerialNumber */                                    \
        0x01    /* bNumConfigurations */

/* Configuration Descriptor: */
#define DUAL_SHOCK_4_CONFIGURATION_DESCRIPTOR                           \
    0x09,                    /* bLength */                              \
        0x02,                /* bDescriptorType */                      \
        U16_TO_BYTE(0x00E1), /* wTotalLength   (225 bytes) */           \
        0x04,                /* bNumInterfaces */                       \
        0x01,                /* bConfigurationValue */                  \
        0x00,                /* iConfiguration */                       \
        0xC0,                /* bmAttributes   (Self-powered Device) */ \
        0xFA                 /* bMaxPower      (500 mA) */

/* Interface Descriptor: */
#define DUAL_SHOCK_4_INTERFACE_DESCRIPTOR_0_0                                     \
    0x09,                   /* bLength */                                         \
        0x04,               /* bDescriptorType */                                 \
        DUAL_SHOCK_4_ITF_0, /* bInterfaceNumber */                                \
        0x00,               /* bAlternateSetting */                               \
        0x00,               /* bNumEndPoints */                                   \
        0x01,               /* bInterfaceClass      (Audio Device Class) */       \
        0x01,               /* bInterfaceSubClass   (Audio Control Interface) */  \
        0x00,               /* bInterfaceProtocol   (Audio Protocol undefined) */ \
        0x00                /* iInterface */

/* AC Interface Header Descriptor: */
#define DUAL_SHOCK_4_AC_INTERFACE_HEADER_DESCRIPTOR          \
    0x0A,                    /* bLength */                   \
        0x24,                /* bDescriptorType */           \
        0x01,                /* bDescriptorSubtype */        \
        U16_TO_BYTE(0x0100), /* bcdADC */                    \
        U16_TO_BYTE(0x0047), /* wTotalLength   (71 bytes) */ \
        0x02,                /* bInCollection */             \
        0x01,                /* baInterfaceNr(1) */          \
        0x02                 /* baInterfaceNr(2) */

/* AC Input Terminal Descriptor: */
#define DUAL_SHOCK_4_AC_INTERFACE_HEADER_DESCRIPTOR                \
    0x0C,                    /* bLength */                         \
        0x24,                /* bDescriptorType */                 \
        0x02,                /* bDescriptorSubtype */              \
        0x01,                /* bTerminalID */                     \
        U16_TO_BYTE(0x0101), /* wTerminalType   (USB Streaming) */ \
        0x06,                /* bAssocTerminal */                  \
        0x02,                /* bNrChannels   (2 channels) */      \
        U16_TO_BYTE(0x0003), /* wChannelConfig */                  \
        0x00,                /* iChannelNames */                   \
        0x00                 /* iTerminal */

/* AC Feature Unit Descriptor: */
#define DUAL_SHOCK_4_AC_FEATURE_UNIT_DESCRIPTOR                    \
    0x0A,                         /* bLength */                    \
        0x24,                     /* bDescriptorType */            \
        0x06,                     /* bDescriptorSubtype */         \
        0x02,                     /* bUnitID */                    \
        0x01,                     /* bSourceID */                  \
        0x01,                     /* bControlSize */               \
        /* bmaControls:  */ 0x03, /* Channel(0) - Mute / Volume */ \
        0x00,                     /* Channel(1) */                 \
        0x00,                     /* Channel(2) */                 \
        0x00                      /* iFeature */

/* AC Output Terminal Descriptor: */
#define DUAL_SHOCK_4_AC_OUTPUT_TERMINAL_DESCRIPTOR           \
    0x09,                    /* bLength */                   \
        0x24,                /* bDescriptorType */           \
        0x03,                /* bDescriptorSubtype */        \
        0x03,                /* bTerminalID */               \
        U16_TO_BYTE(0x0402), /* wTerminalType   (Headset) */ \
        0x04,                /* bAssocTerminal */            \
        0x02,                /* bSourceID */                 \
        0x00                 /* iTerminal */

/* AC Input Terminal Descriptor: */
#define DUAL_SHOCK_4_AC_INPUT_TERMINAL_DESCRIPTOR             \
    0x0C,                    /* bLength */                    \
        0x24,                /* bDescriptorType */            \
        0x02,                /* bDescriptorSubtype */         \
        0x04,                /* bTerminalID */                \
        U16_TO_BYTE(0x0402), /* wTerminalType   (Headset) */  \
        0x03,                /* bAssocTerminal */             \
        0x01,                /* bNrChannels   (1 channels) */ \
        U16_TO_BYTE(0x0000), /* wChannelConfig */             \
        0x00,                /* iChannelNames */              \
        0x00                 /* iTerminal */

/* AC Feature Unit Descriptor: */
#define DUAL_SHOCK_4_AC_FEATURE_UNIT_DESCRIPTOR                    \
    0x09,                         /* bLength */                    \
        0x24,                     /* bDescriptorType */            \
        0x06,                     /* bDescriptorSubtype */         \
        0x05,                     /* bUnitID */                    \
        0x04,                     /* bSourceID */                  \
        0x01,                     /* bControlSize */               \
        /* bmaControls:  */ 0x03, /* Channel(0) - Mute / Volume */ \
        0x00,                     /* Channel(1) */                 \
        0x00                      /* iFeature */

/* AC Output Terminal Descriptor: */
#define DUAL_SHOCK_4_AC_OUTPUT_TERMINAL_DESCRIPTOR                 \
    0x09,                    /* bLength */                         \
        0x24,                /* bDescriptorType */                 \
        0x03,                /* bDescriptorSubtype */              \
        0x06,                /* bTerminalID */                     \
        U16_TO_BYTE(0x0101), /* wTerminalType   (USB Streaming) */ \
        0x01,                /* bAssocTerminal */                  \
        0x05,                /* bSourceID */                       \
        0x00                 /* iTerminal */

/* Interface Descriptor: */
#define DUAL_SHOCK_4_INTERFACE_DESCRIPTOR_1_0                                      \
    0x09,                   /* bLength */                                          \
        0x04,               /* bDescriptorType */                                  \
        DUAL_SHOCK_4_ITF_1, /* bInterfaceNumber */                                 \
        0x00,               /* bAlternateSetting */                                \
        0x00,               /* bNumEndPoints */                                    \
        0x01,               /* bInterfaceClass      (Audio Device Class) */        \
        0x02,               /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,               /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00                /* iInterface */

/* Interface Descriptor: */
#define DUAL_SHOCK_4_INTERFACE_DESCRIPTOR_1_1                                      \
    0x09,                   /* bLength */                                          \
        0x04,               /* bDescriptorType */                                  \
        DUAL_SHOCK_4_ITF_1, /* bInterfaceNumber */                                 \
        0x01,               /* bAlternateSetting */                                \
        0x01,               /* bNumEndPoints */                                    \
        0x01,               /* bInterfaceClass      (Audio Device Class) */        \
        0x02,               /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,               /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00                /* iInterface */

/* AS Interface Descriptor: */
#define DUAL_SHOCK_4_AS_INTERFACE_DESCRIPTOR         \
    0x07,                   /* bLength */            \
        0x24,               /* bDescriptorType */    \
        0x01,               /* bDescriptorSubtype */ \
        0x01,               /* bTerminalLink */      \
        0x01,               /* bDelay */             \
        U16_TO_BYTE(0x0001) /* wFormatTag   (PCM) */

/* AS Format Type 1 Descriptor: */
#define DUAL_SHOCK_4_AS_FORMAT_TYPE_1_DESCRIPTOR                                   \
    0x0B,                     /* bLength */                                        \
        0x24,                 /* bDescriptorType */                                \
        0x02,                 /* bDescriptorSubtype */                             \
        0x01,                 /* bFormatType   (FORMAT_TYPE_1) */                  \
        0x02,                 /* bNrChannels   (2 channels) */                     \
        0x02,                 /* bSubframeSize */                                  \
        0x10,                 /* bBitResolution   (16 bits per sample) */          \
        0x01,                 /* bSamFreqType   (Discrete sampling frequencies) */ \
        U24_TO_BYTE(0x007D00) /* tSamFreq(1)   (32000 Hz) */

/* Endpoint Descriptor (Audio/MIDI 1.0): */
#define DUAL_SHOCK_4_ENDPOINT_DESCRIPTOR                                                                     \
    0x09,                    /* bLength */                                                                   \
        0x05,                /* bDescriptorType */                                                           \
        0x01,                /* bEndpointAddress  (OUT endpoint 1) */                                        \
        0x09,                /* bmAttributes      (Transfer: Isochronous / Synch: Adaptive / Usage: Data) */ \
        U16_TO_BYTE(0x0084), /* wMaxPacketSize    (1 x 132 bytes) */                                         \
        0x01,                /* bInterval         (1 frames) */                                              \
        0x00,                /* bRefresh */                                                                  \
        0x00                 /* bSynchAddress */

/* AS Isochronous Data Endpoint Descriptor: */
#define DUAL_SHOCK_4_ENDPOINT_DESCRIPTOR                        \
    0x07,                   /* bLength */                       \
        0x25,               /* bDescriptorType */               \
        0x01,               /* bDescriptorSubtype */            \
        0x00,               /* bmAttributes */                  \
        0x00,               /* bLockDelayUnits   (undefined) */ \
        U16_TO_BYTE(0x0000) /* wLockDelay */

/* Interface Descriptor: */
#define DUAL_SHOCK_4_INTERFACE_DESCRIPTOR_2_0                                      \
    0x09,                   /* bLength */                                          \
        0x04,               /* bDescriptorType */                                  \
        DUAL_SHOCK_4_ITF_2, /* bInterfaceNumber */                                 \
        0x00,               /* bAlternateSetting */                                \
        0x00,               /* bNumEndPoints */                                    \
        0x01,               /* bInterfaceClass      (Audio Device Class) */        \
        0x02,               /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,               /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00                /* iInterface */

/* Interface Descriptor: */
#define DUAL_SHOCK_4_INTERFACE_DESCRIPTOR_2_1                                      \
    0x09,                   /* bLength */                                          \
        0x04,               /* bDescriptorType */                                  \
        DUAL_SHOCK_4_ITF_2, /* bInterfaceNumber */                                 \
        0x01,               /* bAlternateSetting */                                \
        0x01,               /* bNumEndPoints */                                    \
        0x01,               /* bInterfaceClass      (Audio Device Class) */        \
        0x02,               /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,               /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00                /* iInterface */

/* AS Interface Descriptor: */
#define DUAL_SHOCK_4_AS_INTERFACE_DESCRIPTOR         \
    0x07,                   /* bLength */            \
        0x24,               /* bDescriptorType */    \
        0x01,               /* bDescriptorSubtype */ \
        0x06,               /* bTerminalLink */      \
        0x01,               /* bDelay */             \
        U16_TO_BYTE(0x0001) /* wFormatTag   (PCM) */

/* AS Format Type 1 Descriptor: */
#define DUAL_SHOCK_4_AS_FORMAT_TYPE_1_DESCRIPTOR                                   \
    0x0B,                     /* bLength */                                        \
        0x24,                 /* bDescriptorType */                                \
        0x02,                 /* bDescriptorSubtype */                             \
        0x01,                 /* bFormatType   (FORMAT_TYPE_1) */                  \
        0x01,                 /* bNrChannels   (1 channels) */                     \
        0x02,                 /* bSubframeSize */                                  \
        0x10,                 /* bBitResolution   (16 bits per sample) */          \
        0x01,                 /* bSamFreqType   (Discrete sampling frequencies) */ \
        U24_TO_BYTE(0x003E80) /* tSamFreq(1)   (16000 Hz) */

/* Endpoint Descriptor (Audio/MIDI 1.0): */
#define DUAL_SHOCK_4_ENDPOINT_DESCRIPTOR                                                                         \
    0x09,                    /* bLength */                                                                       \
        0x05,                /* bDescriptorType */                                                               \
        0x82,                /* bEndpointAddress  (IN endpoint 2) */                                             \
        0x05,                /* bmAttributes      (Transfer: Isochronous / Synch: Asynchronous / Usage: Data) */ \
        U16_TO_BYTE(0x0022), /* wMaxPacketSize    (1 x 34 bytes) */                                              \
        0x01,                /* bInterval         (1 frames) */                                                  \
        0x00,                /* bRefresh */                                                                      \
        0x00                 /* bSynchAddress */

/* AS Isochronous Data Endpoint Descriptor: */
#define DUAL_SHOCK_4_ENDPOINT_DESCRIPTOR                        \
    0x07,                   /* bLength */                       \
        0x25,               /* bDescriptorType */               \
        0x01,               /* bDescriptorSubtype */            \
        0x00,               /* bmAttributes */                  \
        0x00,               /* bLockDelayUnits   (undefined) */ \
        U16_TO_BYTE(0x0000) /* wLockDelay */

/* Interface Descriptor: */
#define DUAL_SHOCK_4_INTERFACE_DESCRIPTOR_3_0                                           \
    0x09,                     /* bLength */                                             \
        0x04,                 /* bDescriptorType */                                     \
        DUAL_SHOCK_4_ITF_HID, /* bInterfaceNumber */                                    \
        0x00,                 /* bAlternateSetting */                                   \
        0x02,                 /* bNumEndPoints */                                       \
        0x03,                 /* bInterfaceClass      (Human Interface Device Class) */ \
        0x00,                 /* bInterfaceSubClass */                                  \
        0x00,                 /* bInterfaceProtocol */                                  \
        0x00                  /* iInterface */

/* HID Descriptor: */
#define DUAL_SHOCK_4_HID_DESCRIPTOR(report_size)                             \
    0x09,                        /* bLength */                               \
        0x21,                    /* bDescriptorType */                       \
        U16_TO_BYTE(0x0111),     /* bcdHID */                                \
        0x00,                    /* bCountryCode */                          \
        0x01,                    /* bNumDescriptors */                       \
        0x22,                    /* bDescriptorType   (Report descriptor) */ \
        U16_TO_BYTE(report_size) /* bDescriptorLength */

/* Endpoint Descriptor: */
#define DUAL_SHOCK_4_ENDPOINT_DESCRIPTOR_IN4                                                           \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x84,                /* bEndpointAddress  (IN endpoint 4) */                                   \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x05                 /* bInterval         (5 frames) */

/* Endpoint Descriptor: */
#define DUAL_SHOCK_4_ENDPOINT_DESCRIPTOR_OUT3                                                          \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x03,                /* bEndpointAddress  (OUT endpoint 3) */                                  \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x05                 /* bInterval         (5 frames) */

/* String Descriptor Table */
#define DUAL_SHOCK_4_MANUFACTURER_STRING "Sony Interactive Entertainment"
#define DUAL_SHOCK_4_PRODUCT_STRING "Wireless Controller"

#define DUAL_SHOCK_4_STRING_DESCRIPTOR    \
    (const char[]){0x09, 0x04},           \
        DUAL_SHOCK_4_MANUFACTURER_STRING, \
        DUAL_SHOCK_4_PRODUCT_STRING

#define DUAL_SHOCK_4_REPORT_MAP                                                                                       \
    0x05, 0x01,           /* Usage Page (Generic Desktop Ctrls) */                                                    \
        0x09, 0x05,       /* Usage (Game Pad) */                                                                      \
        0xA1, 0x01,       /* Collection (Application) */                                                              \
        0x85, 0x01,       /*   Report ID (1) */                                                                       \
        0x09, 0x30,       /*   Usage (X) */                                                                           \
        0x09, 0x31,       /*   Usage (Y) */                                                                           \
        0x09, 0x32,       /*   Usage (Z) */                                                                           \
        0x09, 0x35,       /*   Usage (Rz) */                                                                          \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x26, 0xFF, 0x00, /*   Logical Maximum (255) */                                                               \
        0x75, 0x08,       /*   Report Size (8) */                                                                     \
        0x95, 0x04,       /*   Report Count (4) */                                                                    \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x09, 0x39,       /*   Usage (Hat switch) */                                                                  \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x25, 0x07,       /*   Logical Maximum (7) */                                                                 \
        0x35, 0x00,       /*   Physical Minimum (0) */                                                                \
        0x46, 0x3B, 0x01, /*   Physical Maximum (315) */                                                              \
        0x65, 0x14,       /*   Unit (System: English Rotation, Length: Centimeter) */                                 \
        0x75, 0x04,       /*   Report Size (4) */                                                                     \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0x81, 0x42,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,Null State) */                      \
        0x65, 0x00,       /*   Unit (None) */                                                                         \
        0x05, 0x09,       /*   Usage Page (Button) */                                                                 \
        0x19, 0x01,       /*   Usage Minimum (0x01) */                                                                \
        0x29, 0x0E,       /*   Usage Maximum (0x0E) */                                                                \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x25, 0x01,       /*   Logical Maximum (1) */                                                                 \
        0x75, 0x01,       /*   Report Size (1) */                                                                     \
        0x95, 0x0E,       /*   Report Count (14) */                                                                   \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x06, 0x00, 0xFF, /*   Usage Page (Vendor Defined 0xFF00) */                                                  \
        0x09, 0x20,       /*   Usage (0x20) */                                                                        \
        0x75, 0x06,       /*   Report Size (6) */                                                                     \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x25, 0x7F,       /*   Logical Maximum (127) */                                                               \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x05, 0x01,       /*   Usage Page (Generic Desktop Ctrls) */                                                  \
        0x09, 0x33,       /*   Usage (Rx) */                                                                          \
        0x09, 0x34,       /*   Usage (Ry) */                                                                          \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x26, 0xFF, 0x00, /*   Logical Maximum (255) */                                                               \
        0x75, 0x08,       /*   Report Size (8) */                                                                     \
        0x95, 0x02,       /*   Report Count (2) */                                                                    \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x06, 0x00, 0xFF, /*   Usage Page (Vendor Defined 0xFF00) */                                                  \
        0x09, 0x21,       /*   Usage (0x21) */                                                                        \
        0x95, 0x36,       /*   Report Count (54) */                                                                   \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x85, 0x05,       /*   Report ID (5) */                                                                       \
        0x09, 0x22,       /*   Usage (0x22) */                                                                        \
        0x95, 0x1F,       /*   Report Count (31) */                                                                   \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x85, 0x04,       /*   Report ID (4) */                                                                       \
        0x09, 0x23,       /*   Usage (0x23) */                                                                        \
        0x95, 0x24,       /*   Report Count (36) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x02,       /*   Report ID (2) */                                                                       \
        0x09, 0x24,       /*   Usage (0x24) */                                                                        \
        0x95, 0x24,       /*   Report Count (36) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x08,       /*   Report ID (8) */                                                                       \
        0x09, 0x25,       /*   Usage (0x25) */                                                                        \
        0x95, 0x03,       /*   Report Count (3) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x10,       /*   Report ID (16) */                                                                      \
        0x09, 0x26,       /*   Usage (0x26) */                                                                        \
        0x95, 0x04,       /*   Report Count (4) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x11,       /*   Report ID (17) */                                                                      \
        0x09, 0x27,       /*   Usage (0x27) */                                                                        \
        0x95, 0x02,       /*   Report Count (2) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x12,       /*   Report ID (18) */                                                                      \
        0x06, 0x02, 0xFF, /*   Usage Page (Vendor Defined 0xFF02) */                                                  \
        0x09, 0x21,       /*   Usage (0x21) */                                                                        \
        0x95, 0x0F,       /*   Report Count (15) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x13,       /*   Report ID (19) */                                                                      \
        0x09, 0x22,       /*   Usage (0x22) */                                                                        \
        0x95, 0x16,       /*   Report Count (22) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x14,       /*   Report ID (20) */                                                                      \
        0x06, 0x05, 0xFF, /*   Usage Page (Vendor Defined 0xFF05) */                                                  \
        0x09, 0x20,       /*   Usage (0x20) */                                                                        \
        0x95, 0x10,       /*   Report Count (16) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x15,       /*   Report ID (21) */                                                                      \
        0x09, 0x21,       /*   Usage (0x21) */                                                                        \
        0x95, 0x2C,       /*   Report Count (44) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x06, 0x80, 0xFF, /*   Usage Page (Vendor Defined 0xFF80) */                                                  \
        0x85, 0x80,       /*   Report ID (128) */                                                                     \
        0x09, 0x20,       /*   Usage (0x20) */                                                                        \
        0x95, 0x06,       /*   Report Count (6) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x81,       /*   Report ID (129) */                                                                     \
        0x09, 0x21,       /*   Usage (0x21) */                                                                        \
        0x95, 0x06,       /*   Report Count (6) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x82,       /*   Report ID (130) */                                                                     \
        0x09, 0x22,       /*   Usage (0x22) */                                                                        \
        0x95, 0x05,       /*   Report Count (5) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x83,       /*   Report ID (131) */                                                                     \
        0x09, 0x23,       /*   Usage (0x23) */                                                                        \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x84,       /*   Report ID (132) */                                                                     \
        0x09, 0x24,       /*   Usage (0x24) */                                                                        \
        0x95, 0x04,       /*   Report Count (4) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x85,       /*   Report ID (133) */                                                                     \
        0x09, 0x25,       /*   Usage (0x25) */                                                                        \
        0x95, 0x06,       /*   Report Count (6) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x86,       /*   Report ID (134) */                                                                     \
        0x09, 0x26,       /*   Usage (0x26) */                                                                        \
        0x95, 0x06,       /*   Report Count (6) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x87,       /*   Report ID (135) */                                                                     \
        0x09, 0x27,       /*   Usage (0x27) */                                                                        \
        0x95, 0x23,       /*   Report Count (35) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x88,       /*   Report ID (136) */                                                                     \
        0x09, 0x28,       /*   Usage (0x28) */                                                                        \
        0x95, 0x22,       /*   Report Count (34) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x89,       /*   Report ID (137) */                                                                     \
        0x09, 0x29,       /*   Usage (0x29) */                                                                        \
        0x95, 0x02,       /*   Report Count (2) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x90,       /*   Report ID (144) */                                                                     \
        0x09, 0x30,       /*   Usage (0x30) */                                                                        \
        0x95, 0x05,       /*   Report Count (5) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x91,       /*   Report ID (145) */                                                                     \
        0x09, 0x31,       /*   Usage (0x31) */                                                                        \
        0x95, 0x03,       /*   Report Count (3) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x92,       /*   Report ID (146) */                                                                     \
        0x09, 0x32,       /*   Usage (0x32) */                                                                        \
        0x95, 0x03,       /*   Report Count (3) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x93,       /*   Report ID (147) */                                                                     \
        0x09, 0x33,       /*   Usage (0x33) */                                                                        \
        0x95, 0x0C,       /*   Report Count (12) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA0,       /*   Report ID (160) */                                                                     \
        0x09, 0x40,       /*   Usage (0x40) */                                                                        \
        0x95, 0x06,       /*   Report Count (6) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA1,       /*   Report ID (161) */                                                                     \
        0x09, 0x41,       /*   Usage (0x41) */                                                                        \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA2,       /*   Report ID (162) */                                                                     \
        0x09, 0x42,       /*   Usage (0x42) */                                                                        \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA3,       /*   Report ID (163) */                                                                     \
        0x09, 0x43,       /*   Usage (0x43) */                                                                        \
        0x95, 0x30,       /*   Report Count (48) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA4,       /*   Report ID (164) */                                                                     \
        0x09, 0x44,       /*   Usage (0x44) */                                                                        \
        0x95, 0x0D,       /*   Report Count (13) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA5,       /*   Report ID (165) */                                                                     \
        0x09, 0x45,       /*   Usage (0x45) */                                                                        \
        0x95, 0x15,       /*   Report Count (21) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA6,       /*   Report ID (166) */                                                                     \
        0x09, 0x46,       /*   Usage (0x46) */                                                                        \
        0x95, 0x15,       /*   Report Count (21) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xF0,       /*   Report ID (240) */                                                                     \
        0x09, 0x47,       /*   Usage (0x47) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xF1,       /*   Report ID (241) */                                                                     \
        0x09, 0x48,       /*   Usage (0x48) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xF2,       /*   Report ID (242) */                                                                     \
        0x09, 0x49,       /*   Usage (0x49) */                                                                        \
        0x95, 0x0F,       /*   Report Count (15) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA7,       /*   Report ID (167) */                                                                     \
        0x09, 0x4A,       /*   Usage (0x4A) */                                                                        \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA8,       /*   Report ID (168) */                                                                     \
        0x09, 0x4B,       /*   Usage (0x4B) */                                                                        \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA9,       /*   Report ID (169) */                                                                     \
        0x09, 0x4C,       /*   Usage (0x4C) */                                                                        \
        0x95, 0x08,       /*   Report Count (8) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xAA,       /*   Report ID (170) */                                                                     \
        0x09, 0x4E,       /*   Usage (0x4E) */                                                                        \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xAB,       /*   Report ID (171) */                                                                     \
        0x09, 0x4F,       /*   Usage (0x4F) */                                                                        \
        0x95, 0x39,       /*   Report Count (57) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xAC,       /*   Report ID (172) */                                                                     \
        0x09, 0x50,       /*   Usage (0x50) */                                                                        \
        0x95, 0x39,       /*   Report Count (57) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xAD,       /*   Report ID (173) */                                                                     \
        0x09, 0x51,       /*   Usage (0x51) */                                                                        \
        0x95, 0x0B,       /*   Report Count (11) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xAE,       /*   Report ID (174) */                                                                     \
        0x09, 0x52,       /*   Usage (0x52) */                                                                        \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xAF,       /*   Report ID (175) */                                                                     \
        0x09, 0x53,       /*   Usage (0x53) */                                                                        \
        0x95, 0x02,       /*   Report Count (2) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xB0,       /*   Report ID (176) */                                                                     \
        0x09, 0x54,       /*   Usage (0x54) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0xC0              /* End Collection */
// 467 bytes

#define DUAL_SHOCK_4_2X_BT_REPORT_MAP                                                                                 \
    0x05, 0x01,           /* Usage Page (Generic Desktop Ctrls) */                                                    \
        0x09, 0x05,       /* Usage (Game Pad) */                                                                      \
        0xA1, 0x01,       /* Collection (Application) */                                                              \
        0x85, 0x01,       /*   Report ID (1) */                                                                       \
        0x09, 0x30,       /*   Usage (X) */                                                                           \
        0x09, 0x31,       /*   Usage (Y) */                                                                           \
        0x09, 0x32,       /*   Usage (Z) */                                                                           \
        0x09, 0x35,       /*   Usage (Rz) */                                                                          \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x26, 0xFF, 0x00, /*   Logical Maximum (255) */                                                               \
        0x75, 0x08,       /*   Report Size (8) */                                                                     \
        0x95, 0x04,       /*   Report Count (4) */                                                                    \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x09, 0x39,       /*   Usage (Hat switch) */                                                                  \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x25, 0x07,       /*   Logical Maximum (7) */                                                                 \
        0x75, 0x04,       /*   Report Size (4) */                                                                     \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0x81, 0x42,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,Null State) */                      \
        0x05, 0x09,       /*   Usage Page (Button) */                                                                 \
        0x19, 0x01,       /*   Usage Minimum (0x01) */                                                                \
        0x29, 0x0E,       /*   Usage Maximum (0x0E) */                                                                \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x25, 0x01,       /*   Logical Maximum (1) */                                                                 \
        0x75, 0x01,       /*   Report Size (1) */                                                                     \
        0x95, 0x0E,       /*   Report Count (14) */                                                                   \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x75, 0x06,       /*   Report Size (6) */                                                                     \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0x81, 0x01,       /*   Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position) */             \
        0x05, 0x01,       /*   Usage Page (Generic Desktop Ctrls) */                                                  \
        0x09, 0x33,       /*   Usage (Rx) */                                                                          \
        0x09, 0x34,       /*   Usage (Ry) */                                                                          \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x26, 0xFF, 0x00, /*   Logical Maximum (255) */                                                               \
        0x75, 0x08,       /*   Report Size (8) */                                                                     \
        0x95, 0x02,       /*   Report Count (2) */                                                                    \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x06, 0x04, 0xFF, /*   Usage Page (Vendor Defined 0xFF04) */                                                  \
        0x85, 0x02,       /*   Report ID (2) */                                                                       \
        0x09, 0x24,       /*   Usage (0x24) */                                                                        \
        0x95, 0x24,       /*   Report Count (36) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA3,       /*   Report ID (-93) */                                                                     \
        0x09, 0x25,       /*   Usage (0x25) */                                                                        \
        0x95, 0x30,       /*   Report Count (48) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x05,       /*   Report ID (5) */                                                                       \
        0x09, 0x26,       /*   Usage (0x26) */                                                                        \
        0x95, 0x28,       /*   Report Count (40) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x06,       /*   Report ID (6) */                                                                       \
        0x09, 0x27,       /*   Usage (0x27) */                                                                        \
        0x95, 0x34,       /*   Report Count (52) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x07,       /*   Report ID (7) */                                                                       \
        0x09, 0x28,       /*   Usage (0x28) */                                                                        \
        0x95, 0x30,       /*   Report Count (48) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x08,       /*   Report ID (8) */                                                                       \
        0x09, 0x29,       /*   Usage (0x29) */                                                                        \
        0x95, 0x2F,       /*   Report Count (47) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x09,       /*   Report ID (9) */                                                                       \
        0x09, 0x2A,       /*   Usage (0x2A) */                                                                        \
        0x95, 0x13,       /*   Report Count (19) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x06, 0x03, 0xFF, /*   Usage Page (Vendor Defined 0xFF03) */                                                  \
        0x85, 0x03,       /*   Report ID (3) */                                                                       \
        0x09, 0x21,       /*   Usage (0x21) */                                                                        \
        0x95, 0x26,       /*   Report Count (38) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x04,       /*   Report ID (4) */                                                                       \
        0x09, 0x22,       /*   Usage (0x22) */                                                                        \
        0x95, 0x2E,       /*   Report Count (46) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xF0,       /*   Report ID (-16) */                                                                     \
        0x09, 0x47,       /*   Usage (0x47) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xF1,       /*   Report ID (-15) */                                                                     \
        0x09, 0x48,       /*   Usage (0x48) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xF2,       /*   Report ID (-14) */                                                                     \
        0x09, 0x49,       /*   Usage (0x49) */                                                                        \
        0x95, 0x0F,       /*   Report Count (15) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x06, 0x00, 0xFF, /*   Usage Page (Vendor Defined 0xFF00) */                                                  \
        0x85, 0x11,       /*   Report ID (17) */                                                                      \
        0x09, 0x20,       /*   Usage (0x20) */                                                                        \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x26, 0xFF, 0x00, /*   Logical Maximum (255) */                                                               \
        0x75, 0x08,       /*   Report Size (8) */                                                                     \
        0x95, 0x4D,       /*   Report Count (77) */                                                                   \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x09, 0x21,       /*   Usage (0x21) */                                                                        \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x85, 0x12,       /*   Report ID (18) */                                                                      \
        0x09, 0x22,       /*   Usage (0x22) */                                                                        \
        0x95, 0x8D,       /*   Report Count (-115) */                                                                 \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x09, 0x23,       /*   Usage (0x23) */                                                                        \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x85, 0x13,       /*   Report ID (19) */                                                                      \
        0x09, 0x24,       /*   Usage (0x24) */                                                                        \
        0x95, 0xCD,       /*   Report Count (-51) */                                                                  \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x09, 0x25,       /*   Usage (0x25) */                                                                        \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x85, 0x14,       /*   Report ID (20) */                                                                      \
        0x09, 0x26,       /*   Usage (0x26) */                                                                        \
        0x96, 0x0D, 0x01, /*   Report Count (269) */                                                                  \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x09, 0x27,       /*   Usage (0x27) */                                                                        \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x85, 0x15,       /*   Report ID (21) */                                                                      \
        0x09, 0x28,       /*   Usage (0x28) */                                                                        \
        0x96, 0x4D, 0x01, /*   Report Count (333) */                                                                  \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x09, 0x29,       /*   Usage (0x29) */                                                                        \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x85, 0x16,       /*   Report ID (22) */                                                                      \
        0x09, 0x2A,       /*   Usage (0x2A) */                                                                        \
        0x96, 0x8D, 0x01, /*   Report Count (397) */                                                                  \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x09, 0x2B,       /*   Usage (0x2B) */                                                                        \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x85, 0x17,       /*   Report ID (23) */                                                                      \
        0x09, 0x2C,       /*   Usage (0x2C) */                                                                        \
        0x96, 0xCD, 0x01, /*   Report Count (461) */                                                                  \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x09, 0x2D,       /*   Usage (0x2D) */                                                                        \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x85, 0x18,       /*   Report ID (24) */                                                                      \
        0x09, 0x2E,       /*   Usage (0x2E) */                                                                        \
        0x96, 0x0D, 0x02, /*   Report Count (525) */                                                                  \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x09, 0x2F,       /*   Usage (0x2F) */                                                                        \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x85, 0x19,       /*   Report ID (25) */                                                                      \
        0x09, 0x30,       /*   Usage (0x30) */                                                                        \
        0x96, 0x22, 0x02, /*   Report Count (546) */                                                                  \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x09, 0x31,       /*   Usage (0x31) */                                                                        \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x06, 0x80, 0xFF, /*   Usage Page (Vendor Defined 0xFF80) */                                                  \
        0x85, 0x82,       /*   Report ID (-126) */                                                                    \
        0x09, 0x22,       /*   Usage (0x22) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x83,       /*   Report ID (-125) */                                                                    \
        0x09, 0x23,       /*   Usage (0x23) */                                                                        \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x84,       /*   Report ID (-124) */                                                                    \
        0x09, 0x24,       /*   Usage (0x24) */                                                                        \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x90,       /*   Report ID (-112) */                                                                    \
        0x09, 0x30,       /*   Usage (0x30) */                                                                        \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x91,       /*   Report ID (-111) */                                                                    \
        0x09, 0x31,       /*   Usage (0x31) */                                                                        \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x92,       /*   Report ID (-110) */                                                                    \
        0x09, 0x32,       /*   Usage (0x32) */                                                                        \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x93,       /*   Report ID (-109) */                                                                    \
        0x09, 0x33,       /*   Usage (0x33) */                                                                        \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x94,       /*   Report ID (-108) */                                                                    \
        0x09, 0x34,       /*   Usage (0x34) */                                                                        \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA0,       /*   Report ID (-96) */                                                                     \
        0x09, 0x40,       /*   Usage (0x40) */                                                                        \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA4,       /*   Report ID (-92) */                                                                     \
        0x09, 0x44,       /*   Usage (0x44) */                                                                        \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA7,       /*   Report ID (-89) */                                                                     \
        0x09, 0x45,       /*   Usage (0x45) */                                                                        \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA8,       /*   Report ID (-88) */                                                                     \
        0x09, 0x45,       /*   Usage (0x45) */                                                                        \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA9,       /*   Report ID (-87) */                                                                     \
        0x09, 0x45,       /*   Usage (0x45) */                                                                        \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xAA,       /*   Report ID (-86) */                                                                     \
        0x09, 0x45,       /*   Usage (0x45) */                                                                        \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xAB,       /*   Report ID (-85) */                                                                     \
        0x09, 0x45,       /*   Usage (0x45) */                                                                        \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xAC,       /*   Report ID (-84) */                                                                     \
        0x09, 0x45,       /*   Usage (0x45) */                                                                        \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xAD,       /*   Report ID (-83) */                                                                     \
        0x09, 0x45,       /*   Usage (0x45) */                                                                        \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xB3,       /*   Report ID (-77) */                                                                     \
        0x09, 0x45,       /*   Usage (0x45) */                                                                        \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xB4,       /*   Report ID (-76) */                                                                     \
        0x09, 0x46,       /*   Usage (0x46) */                                                                        \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xB5,       /*   Report ID (-75) */                                                                     \
        0x09, 0x47,       /*   Usage (0x47) */                                                                        \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xD0,       /*   Report ID (-48) */                                                                     \
        0x09, 0x40,       /*   Usage (0x40) */                                                                        \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xD4,       /*   Report ID (-44) */                                                                     \
        0x09, 0x44,       /*   Usage (0x44) */                                                                        \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0xC0              /* End Collection */
// 442 bytes

#define DUAL_SHOCK_4_2X_USB_REPORT_MAP                                                                                \
    0x05, 0x01,           /* Usage Page (Generic Desktop Ctrls) */                                                    \
        0x09, 0x05,       /* Usage (Game Pad) */                                                                      \
        0xA1, 0x01,       /* Collection (Application) */                                                              \
        0x85, 0x01,       /*   Report ID (1) */                                                                       \
        0x09, 0x30,       /*   Usage (X) */                                                                           \
        0x09, 0x31,       /*   Usage (Y) */                                                                           \
        0x09, 0x32,       /*   Usage (Z) */                                                                           \
        0x09, 0x35,       /*   Usage (Rz) */                                                                          \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x26, 0xFF, 0x00, /*   Logical Maximum (255) */                                                               \
        0x75, 0x08,       /*   Report Size (8) */                                                                     \
        0x95, 0x04,       /*   Report Count (4) */                                                                    \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x09, 0x39,       /*   Usage (Hat switch) */                                                                  \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x25, 0x07,       /*   Logical Maximum (7) */                                                                 \
        0x35, 0x00,       /*   Physical Minimum (0) */                                                                \
        0x46, 0x3B, 0x01, /*   Physical Maximum (315) */                                                              \
        0x65, 0x14,       /*   Unit (System: English Rotation, Length: Centimeter) */                                 \
        0x75, 0x04,       /*   Report Size (4) */                                                                     \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0x81, 0x42,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,Null State) */                      \
        0x65, 0x00,       /*   Unit (None) */                                                                         \
        0x05, 0x09,       /*   Usage Page (Button) */                                                                 \
        0x19, 0x01,       /*   Usage Minimum (0x01) */                                                                \
        0x29, 0x0E,       /*   Usage Maximum (0x0E) */                                                                \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x25, 0x01,       /*   Logical Maximum (1) */                                                                 \
        0x75, 0x01,       /*   Report Size (1) */                                                                     \
        0x95, 0x0E,       /*   Report Count (14) */                                                                   \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x06, 0x00, 0xFF, /*   Usage Page (Vendor Defined 0xFF00) */                                                  \
        0x09, 0x20,       /*   Usage (0x20) */                                                                        \
        0x75, 0x06,       /*   Report Size (6) */                                                                     \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x25, 0x7F,       /*   Logical Maximum (127) */                                                               \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x05, 0x01,       /*   Usage Page (Generic Desktop Ctrls) */                                                  \
        0x09, 0x33,       /*   Usage (Rx) */                                                                          \
        0x09, 0x34,       /*   Usage (Ry) */                                                                          \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x26, 0xFF, 0x00, /*   Logical Maximum (255) */                                                               \
        0x75, 0x08,       /*   Report Size (8) */                                                                     \
        0x95, 0x02,       /*   Report Count (2) */                                                                    \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x06, 0x00, 0xFF, /*   Usage Page (Vendor Defined 0xFF00) */                                                  \
        0x09, 0x21,       /*   Usage (0x21) */                                                                        \
        0x95, 0x36,       /*   Report Count (54) */                                                                   \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x85, 0x05,       /*   Report ID (5) */                                                                       \
        0x09, 0x22,       /*   Usage (0x22) */                                                                        \
        0x95, 0x1F,       /*   Report Count (31) */                                                                   \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x85, 0x04,       /*   Report ID (4) */                                                                       \
        0x09, 0x23,       /*   Usage (0x23) */                                                                        \
        0x95, 0x24,       /*   Report Count (36) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x02,       /*   Report ID (2) */                                                                       \
        0x09, 0x24,       /*   Usage (0x24) */                                                                        \
        0x95, 0x24,       /*   Report Count (36) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x08,       /*   Report ID (8) */                                                                       \
        0x09, 0x25,       /*   Usage (0x25) */                                                                        \
        0x95, 0x03,       /*   Report Count (3) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x10,       /*   Report ID (16) */                                                                      \
        0x09, 0x26,       /*   Usage (0x26) */                                                                        \
        0x95, 0x04,       /*   Report Count (4) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x11,       /*   Report ID (17) */                                                                      \
        0x09, 0x27,       /*   Usage (0x27) */                                                                        \
        0x95, 0x02,       /*   Report Count (2) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x12,       /*   Report ID (18) */                                                                      \
        0x06, 0x02, 0xFF, /*   Usage Page (Vendor Defined 0xFF02) */                                                  \
        0x09, 0x21,       /*   Usage (0x21) */                                                                        \
        0x95, 0x0F,       /*   Report Count (15) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x13,       /*   Report ID (19) */                                                                      \
        0x09, 0x22,       /*   Usage (0x22) */                                                                        \
        0x95, 0x16,       /*   Report Count (22) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x14,       /*   Report ID (20) */                                                                      \
        0x06, 0x05, 0xFF, /*   Usage Page (Vendor Defined 0xFF05) */                                                  \
        0x09, 0x20,       /*   Usage (0x20) */                                                                        \
        0x95, 0x10,       /*   Report Count (16) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x15,       /*   Report ID (21) */                                                                      \
        0x09, 0x21,       /*   Usage (0x21) */                                                                        \
        0x95, 0x2C,       /*   Report Count (44) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x06, 0x80, 0xFF, /*   Usage Page (Vendor Defined 0xFF80) */                                                  \
        0x85, 0x80,       /*   Report ID (-128) */                                                                    \
        0x09, 0x20,       /*   Usage (0x20) */                                                                        \
        0x95, 0x06,       /*   Report Count (6) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x81,       /*   Report ID (-127) */                                                                    \
        0x09, 0x21,       /*   Usage (0x21) */                                                                        \
        0x95, 0x06,       /*   Report Count (6) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x82,       /*   Report ID (-126) */                                                                    \
        0x09, 0x22,       /*   Usage (0x22) */                                                                        \
        0x95, 0x05,       /*   Report Count (5) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x83,       /*   Report ID (-125) */                                                                    \
        0x09, 0x23,       /*   Usage (0x23) */                                                                        \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x84,       /*   Report ID (-124) */                                                                    \
        0x09, 0x24,       /*   Usage (0x24) */                                                                        \
        0x95, 0x04,       /*   Report Count (4) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x85,       /*   Report ID (-123) */                                                                    \
        0x09, 0x25,       /*   Usage (0x25) */                                                                        \
        0x95, 0x06,       /*   Report Count (6) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x86,       /*   Report ID (-122) */                                                                    \
        0x09, 0x26,       /*   Usage (0x26) */                                                                        \
        0x95, 0x06,       /*   Report Count (6) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x87,       /*   Report ID (-121) */                                                                    \
        0x09, 0x27,       /*   Usage (0x27) */                                                                        \
        0x95, 0x23,       /*   Report Count (35) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x88,       /*   Report ID (-120) */                                                                    \
        0x09, 0x28,       /*   Usage (0x28) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x89,       /*   Report ID (-119) */                                                                    \
        0x09, 0x29,       /*   Usage (0x29) */                                                                        \
        0x95, 0x02,       /*   Report Count (2) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x90,       /*   Report ID (-112) */                                                                    \
        0x09, 0x30,       /*   Usage (0x30) */                                                                        \
        0x95, 0x05,       /*   Report Count (5) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x91,       /*   Report ID (-111) */                                                                    \
        0x09, 0x31,       /*   Usage (0x31) */                                                                        \
        0x95, 0x03,       /*   Report Count (3) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x92,       /*   Report ID (-110) */                                                                    \
        0x09, 0x32,       /*   Usage (0x32) */                                                                        \
        0x95, 0x03,       /*   Report Count (3) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x93,       /*   Report ID (-109) */                                                                    \
        0x09, 0x33,       /*   Usage (0x33) */                                                                        \
        0x95, 0x0C,       /*   Report Count (12) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x94,       /*   Report ID (-108) */                                                                    \
        0x09, 0x34,       /*   Usage (0x34) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA0,       /*   Report ID (-96) */                                                                     \
        0x09, 0x40,       /*   Usage (0x40) */                                                                        \
        0x95, 0x06,       /*   Report Count (6) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA1,       /*   Report ID (-95) */                                                                     \
        0x09, 0x41,       /*   Usage (0x41) */                                                                        \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA2,       /*   Report ID (-94) */                                                                     \
        0x09, 0x42,       /*   Usage (0x42) */                                                                        \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA3,       /*   Report ID (-93) */                                                                     \
        0x09, 0x43,       /*   Usage (0x43) */                                                                        \
        0x95, 0x30,       /*   Report Count (48) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA4,       /*   Report ID (-92) */                                                                     \
        0x09, 0x44,       /*   Usage (0x44) */                                                                        \
        0x95, 0x0D,       /*   Report Count (13) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xF0,       /*   Report ID (-16) */                                                                     \
        0x09, 0x47,       /*   Usage (0x47) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xF1,       /*   Report ID (-15) */                                                                     \
        0x09, 0x48,       /*   Usage (0x48) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xF2,       /*   Report ID (-14) */                                                                     \
        0x09, 0x49,       /*   Usage (0x49) */                                                                        \
        0x95, 0x0F,       /*   Report Count (15) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA7,       /*   Report ID (-89) */                                                                     \
        0x09, 0x4A,       /*   Usage (0x4A) */                                                                        \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA8,       /*   Report ID (-88) */                                                                     \
        0x09, 0x4B,       /*   Usage (0x4B) */                                                                        \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA9,       /*   Report ID (-87) */                                                                     \
        0x09, 0x4C,       /*   Usage (0x4C) */                                                                        \
        0x95, 0x08,       /*   Report Count (8) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xAA,       /*   Report ID (-86) */                                                                     \
        0x09, 0x4E,       /*   Usage (0x4E) */                                                                        \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xAB,       /*   Report ID (-85) */                                                                     \
        0x09, 0x4F,       /*   Usage (0x4F) */                                                                        \
        0x95, 0x39,       /*   Report Count (57) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xAC,       /*   Report ID (-84) */                                                                     \
        0x09, 0x50,       /*   Usage (0x50) */                                                                        \
        0x95, 0x39,       /*   Report Count (57) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xAD,       /*   Report ID (-83) */                                                                     \
        0x09, 0x51,       /*   Usage (0x51) */                                                                        \
        0x95, 0x0B,       /*   Report Count (11) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xAE,       /*   Report ID (-82) */                                                                     \
        0x09, 0x52,       /*   Usage (0x52) */                                                                        \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xAF,       /*   Report ID (-81) */                                                                     \
        0x09, 0x53,       /*   Usage (0x53) */                                                                        \
        0x95, 0x02,       /*   Report Count (2) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xB0,       /*   Report ID (-80) */                                                                     \
        0x09, 0x54,       /*   Usage (0x54) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xE0,       /*   Report ID (-32) */                                                                     \
        0x09, 0x57,       /*   Usage (0x57) */                                                                        \
        0x95, 0x02,       /*   Report Count (2) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xB3,       /*   Report ID (-77) */                                                                     \
        0x09, 0x55,       /*   Usage (0x55) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xB4,       /*   Report ID (-76) */                                                                     \
        0x09, 0x55,       /*   Usage (0x55) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xB5,       /*   Report ID (-75) */                                                                     \
        0x09, 0x56,       /*   Usage (0x56) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xD0,       /*   Report ID (-48) */                                                                     \
        0x09, 0x58,       /*   Usage (0x58) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xD4,       /*   Report ID (-44) */                                                                     \
        0x09, 0x59,       /*   Usage (0x59) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0xC0              /* End Collection */
// 507 bytes

#define DUAL_SHOCK_4_DONGLE_REPORT_MAP                                                                                \
    0xA1, 0x01,           /* Collection (Application) */                                                              \
        0x85, 0x01,       /*   Report ID (1) */                                                                       \
        0x09, 0x30,       /*   Usage (0x30) */                                                                        \
        0x09, 0x31,       /*   Usage (0x31) */                                                                        \
        0x09, 0x32,       /*   Usage (0x32) */                                                                        \
        0x09, 0x35,       /*   Usage (0x35) */                                                                        \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x26, 0xFF, 0x00, /*   Logical Maximum (255) */                                                               \
        0x75, 0x08,       /*   Report Size (8) */                                                                     \
        0x95, 0x04,       /*   Report Count (4) */                                                                    \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x09, 0x39,       /*   Usage (0x39) */                                                                        \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x25, 0x07,       /*   Logical Maximum (7) */                                                                 \
        0x35, 0x00,       /*   Physical Minimum (0) */                                                                \
        0x46, 0x3B, 0x01, /*   Physical Maximum (315) */                                                              \
        0x65, 0x14,       /*   Unit (System: English Rotation, Length: Centimeter) */                                 \
        0x75, 0x04,       /*   Report Size (4) */                                                                     \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0x81, 0x42,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,Null State) */                      \
        0x65, 0x00,       /*   Unit (None) */                                                                         \
        0x05, 0x09,       /*   Usage Page (Button) */                                                                 \
        0x19, 0x01,       /*   Usage Minimum (0x01) */                                                                \
        0x29, 0x0E,       /*   Usage Maximum (0x0E) */                                                                \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x25, 0x01,       /*   Logical Maximum (1) */                                                                 \
        0x75, 0x01,       /*   Report Size (1) */                                                                     \
        0x95, 0x0E,       /*   Report Count (14) */                                                                   \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x06, 0x00, 0xFF, /*   Usage Page (Vendor Defined 0xFF00) */                                                  \
        0x09, 0x20,       /*   Usage (0x20) */                                                                        \
        0x75, 0x06,       /*   Report Size (6) */                                                                     \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x25, 0x7F,       /*   Logical Maximum (127) */                                                               \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x05, 0x01,       /*   Usage Page (Generic Desktop Ctrls) */                                                  \
        0x09, 0x33,       /*   Usage (Rx) */                                                                          \
        0x09, 0x34,       /*   Usage (Ry) */                                                                          \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x26, 0xFF, 0x00, /*   Logical Maximum (255) */                                                               \
        0x75, 0x08,       /*   Report Size (8) */                                                                     \
        0x95, 0x02,       /*   Report Count (2) */                                                                    \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x06, 0x00, 0xFF, /*   Usage Page (Vendor Defined 0xFF00) */                                                  \
        0x09, 0x21,       /*   Usage (0x21) */                                                                        \
        0x95, 0x36,       /*   Report Count (54) */                                                                   \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x85, 0x05,       /*   Report ID (5) */                                                                       \
        0x09, 0x22,       /*   Usage (0x22) */                                                                        \
        0x95, 0x1F,       /*   Report Count (31) */                                                                   \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x85, 0x02,       /*   Report ID (2) */                                                                       \
        0x09, 0x24,       /*   Usage (0x24) */                                                                        \
        0x95, 0x24,       /*   Report Count (36) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x06, 0x02, 0xFF, /*   Usage Page (Vendor Defined 0xFF02) */                                                  \
        0x85, 0x12,       /*   Report ID (18) */                                                                      \
        0x09, 0x21,       /*   Usage (0x21) */                                                                        \
        0x95, 0x0F,       /*   Report Count (15) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x06, 0x05, 0xFF, /*   Usage Page (Vendor Defined 0xFF05) */                                                  \
        0x85, 0x15,       /*   Report ID (21) */                                                                      \
        0x09, 0x21,       /*   Usage (0x21) */                                                                        \
        0x95, 0x2D,       /*   Report Count (45) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x06, 0x80, 0xFF, /*   Usage Page (Vendor Defined 0xFF80) */                                                  \
        0x85, 0x80,       /*   Report ID (128) */                                                                     \
        0x09, 0x20,       /*   Usage (0x20) */                                                                        \
        0x95, 0x06,       /*   Report Count (6) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x81,       /*   Report ID (129) */                                                                     \
        0x09, 0x21,       /*   Usage (0x21) */                                                                        \
        0x95, 0x06,       /*   Report Count (6) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x85,       /*   Report ID (133) */                                                                     \
        0x09, 0x25,       /*   Usage (0x25) */                                                                        \
        0x95, 0x06,       /*   Report Count (6) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x86,       /*   Report ID (134) */                                                                     \
        0x09, 0x26,       /*   Usage (0x26) */                                                                        \
        0x95, 0x06,       /*   Report Count (6) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x8A,       /*   Report ID (138) */                                                                     \
        0x09, 0x27,       /*   Usage (0x27) */                                                                        \
        0x95, 0x16,       /*   Report Count (22) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA0,       /*   Report ID (160) */                                                                     \
        0x09, 0x40,       /*   Usage (0x40) */                                                                        \
        0x95, 0x06,       /*   Report Count (6) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA1,       /*   Report ID (161) */                                                                     \
        0x09, 0x41,       /*   Usage (0x41) */                                                                        \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA2,       /*   Report ID (162) */                                                                     \
        0x09, 0x42,       /*   Usage (0x42) */                                                                        \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA3,       /*   Report ID (163) */                                                                     \
        0x09, 0x43,       /*   Usage (0x43) */                                                                        \
        0x95, 0x30,       /*   Report Count (48) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA4,       /*   Report ID (164) */                                                                     \
        0x09, 0x44,       /*   Usage (0x44) */                                                                        \
        0x95, 0x0D,       /*   Report Count (13) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA5,       /*   Report ID (165) */                                                                     \
        0x09, 0x45,       /*   Usage (0x45) */                                                                        \
        0x95, 0x15,       /*   Report Count (21) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA6,       /*   Report ID (166) */                                                                     \
        0x09, 0x46,       /*   Usage (0x46) */                                                                        \
        0x95, 0x15,       /*   Report Count (21) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xB0,       /*   Report ID (176) */                                                                     \
        0x09, 0x54,       /*   Usage (0x54) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xE0,       /*   Report ID (224) */                                                                     \
        0x09, 0x56,       /*   Usage (0x56) */                                                                        \
        0x95, 0x02,       /*   Report Count (2) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xE1,       /*   Report ID (225) */                                                                     \
        0x09, 0x57,       /*   Usage (0x57) */                                                                        \
        0x95, 0x30,       /*   Report Count (48) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xE2,       /*   Report ID (226) */                                                                     \
        0x09, 0x57,       /*   Usage (0x57) */                                                                        \
        0x95, 0x10,       /*   Report Count (16) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xE3,       /*   Report ID (227) */                                                                     \
        0x09, 0x57,       /*   Usage (0x57) */                                                                        \
        0x95, 0x04,       /*   Report Count (4) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xE4,       /*   Report ID (228) */                                                                     \
        0x09, 0x57,       /*   Usage (0x57) */                                                                        \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xE5,       /*   Report ID (229) */                                                                     \
        0x09, 0x57,       /*   Usage (0x57) */                                                                        \
        0x95, 0x06,       /*   Report Count (6) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0xC0,             /* End Collection */
// 295 bytes

#define DUAL_SHOCK_4_DONGLE_DFU_MODE_REPORT_MAP                                                                       \
    0xA1, 0x01,           /* Collection (Application) */                                                              \
        0x85, 0x02,       /*   Report ID (2) */                                                                       \
        0x06, 0x01, 0xFF, /*   Usage Page (Vendor Defined 0xFF01) */                                                  \
        0x09, 0x22,       /*   Usage (0x22) */                                                                        \
        0x75, 0x08,       /*   Report Size (8) */                                                                     \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x85, 0xF0,       /*   Report ID (240) */                                                                     \
        0x09, 0x23,       /*   Usage (0x23) */                                                                        \
        0x95, 0x3E,       /*   Report Count (62) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0xC0,             /* End Collection */
// 24 bytes

enum DualShock4_Direction
{
    DualShock4_Direction_North = 0,
    DualShock4_Direction_NorthEast,
    DualShock4_Direction_East,
    DualShock4_Direction_SouthEast,
    DualShock4_Direction_South,
    DualShock4_Direction_SouthWest,
    DualShock4_Direction_West,
    DualShock4_Direction_NorthWest,
    DualShock4_Direction_None = 8
};

typedef struct
{
    uint8_t report_id;
    uint8_t LeftStickX;
    uint8_t LeftStickY;
    uint8_t RightStickX;
    uint8_t RightStickY;
    enum DualShock4_Direction DPad : 4;
    uint8_t ButtonSquare : 1;   // 方
    uint8_t ButtonCross : 1;    // 叉
    uint8_t ButtonCircle : 1;   // 圆
    uint8_t ButtonTriangle : 1; // 三角
    uint8_t ButtonL1 : 1;
    uint8_t ButtonR1 : 1;
    uint8_t ButtonL2 : 1;
    uint8_t ButtonR2 : 1;
    uint8_t ButtonShare : 1;
    uint8_t ButtonOptions : 1;
    uint8_t ButtonL3 : 1;
    uint8_t ButtonR3 : 1;
    uint8_t ButtonHome : 1;
    uint8_t ButtonTPad : 1;
    uint8_t Counter : 6; // Counter (counts up by 1 per report)
    uint8_t TriggerLeft;
    uint8_t TriggerRight;
} dualShock4BtInputReport01_t;

typedef struct
{
    uint8_t unknown1[3];
    uint16_t gyroscope_x;
    uint16_t gyroscope_y;
    uint16_t gyroscope_z;
    uint16_t accel_x;
    uint16_t accel_y;
    uint16_t accel_z;
    uint8_t unknown2[39];
} dualShock4BtInputReportUnknown_t;

typedef struct
{
    uint8_t reportId; // Report ID = 0x01 (1)
    // Collection: CA:GamePad
    uint8_t LeftStickX;                 // Usage 0x00010030: X, Value = 0 to 255
    uint8_t LeftStickY;                 // Usage 0x00010031: Y, Value = 0 to 255
    uint8_t RightStickX;                // Usage 0x00010032: Z, Value = 0 to 255
    uint8_t RightStickY;                // Usage 0x00010035: Rz, Value = 0 to 255
    enum DualShock4_Direction DPad : 4; // Usage 0x00010039: Hat switch, Value = 0 to 7, Physical = Value x 45 in degrees
    uint8_t ButtonSquare : 1;           // Usage 0x00090001: Button 1 Primary/trigger, Value = 0 to 1, Physical = Value x 315
    uint8_t ButtonCross : 1;            // Usage 0x00090002: Button 2 Secondary, Value = 0 to 1, Physical = Value x 315
    uint8_t ButtonCircle : 1;           // Usage 0x00090003: Button 3 Tertiary, Value = 0 to 1, Physical = Value x 315
    uint8_t ButtonTriangle : 1;         // Usage 0x00090004: Button 4, Value = 0 to 1, Physical = Value x 315
    uint8_t ButtonL1 : 1;               // Usage 0x00090005: Button 5, Value = 0 to 1, Physical = Value x 315
    uint8_t ButtonR1 : 1;               // Usage 0x00090006: Button 6, Value = 0 to 1, Physical = Value x 315
    uint8_t ButtonL2 : 1;               // Usage 0x00090007: Button 7, Value = 0 to 1, Physical = Value x 315
    uint8_t ButtonR2 : 1;               // Usage 0x00090008: Button 8, Value = 0 to 1, Physical = Value x 315
    uint8_t ButtonShare : 1;            // Usage 0x00090009: Button 9, Value = 0 to 1, Physical = Value x 315
    uint8_t ButtonOptions : 1;          // Usage 0x0009000A: Button 10, Value = 0 to 1, Physical = Value x 315
    uint8_t ButtonL3 : 1;               // Usage 0x0009000B: Button 11, Value = 0 to 1, Physical = Value x 315
    uint8_t ButtonR3 : 1;               // Usage 0x0009000C: Button 12, Value = 0 to 1, Physical = Value x 315
    uint8_t ButtonHome : 1;             // Usage 0x0009000D: Button 13, Value = 0 to 1, Physical = Value x 315
    uint8_t ButtonTPad : 1;             // Usage 0x0009000E: Button 14, Value = 0 to 1, Physical = Value x 315
    uint8_t Counter : 6;                // Usage 0xFF000020: , Value = 0 to 127, Physical = Value x 315 / 127
    uint8_t TriggerLeft;                // Usage 0x00010033: Rx, Value = 0 to 255, Physical = Value x 21 / 17
    uint8_t TriggerRight;               // Usage 0x00010034: Ry, Value = 0 to 255, Physical = Value x 21 / 17
    uint8_t unknown[54];                // Usage 0xFF000021: , Value = 0 to 255, Physical = Value x 21 / 17
} dualShock4UsbInputReport01_t;

// template<int N> struct BTCRC {
//     uint8_t Buff[N-4];
//     uint32_t CRC;
// };

// template<int N> struct BTAudio {
//     uint16_t FrameNumber;
//     uint8_t AudioTarget; // 0x02 speaker?, 0x24 headset?, 0x03 mic?
//     uint8_t SBCData[N-3];
// };

// template<int N> struct BTGetStateDataAndAudio {
//     BTGetStateData State;
//     BTAudio<N-75> Audio;
// };

#define DualShock4_BTCRC(N)  \
    struct                   \
    {                        \
        uint8_t Buff[N - 4]; \
        uint32_t CRC;        \
    }

#define DualShock4_BTAudio(N)                                              \
    struct                                                                 \
    {                                                                      \
        uint16_t FrameNumber;                                              \
        uint8_t AudioTarget; /* 0x02 speaker?, 0x24 headset?, 0x03 mic? */ \
        uint8_t SBCData[N - 3];                                            \
    }

#define DualShock4_BTGetStateDataAndAudio(N)    \
    struct                                      \
    {                                           \
        struct DualShock4_BTGetStateData State; \
        DualShock4_BTAudio(N - 75) Audio;       \
    }

struct DualShock4_TouchFingerData
{
    uint8_t Index : 7;
    uint8_t NotTouching : 1;
    uint16_t FingerX : 12;
    uint16_t FingerY : 12;
};

struct DualShock4_TouchData
{
    uint8_t Timestamp;
    struct DualShock4_TouchFingerData Finger[2];
};

struct DualShock4_BasicGetStateData
{
    /*0  */ uint8_t LeftStickX;
    /*1  */ uint8_t LeftStickY;
    /*2  */ uint8_t RightStickX;
    /*3  */ uint8_t RightStickY;
    /*4.0*/ enum DualShock4_Direction DPad : 4;
    /*4.4*/ uint8_t ButtonSquare : 1;
    /*4.5*/ uint8_t ButtonCross : 1;
    /*4.6*/ uint8_t ButtonCircle : 1;
    /*4.7*/ uint8_t ButtonTriangle : 1;
    /*5.0*/ uint8_t ButtonL1 : 1;
    /*5.1*/ uint8_t ButtonR1 : 1;
    /*5.2*/ uint8_t ButtonL2 : 1;
    /*5.3*/ uint8_t ButtonR2 : 1;
    /*5.4*/ uint8_t ButtonShare : 1;
    /*5.5*/ uint8_t ButtonOptions : 1;
    /*5.6*/ uint8_t ButtonL3 : 1;
    /*5.7*/ uint8_t ButtonR3 : 1;
    /*6.0*/ uint8_t ButtonHome : 1;
    /*6.1*/ uint8_t ButtonPad : 1;
    /*6.2*/ uint8_t Counter : 6; // always 0 on USB, counts up with some skips on BT
    /*7  */ uint8_t TriggerLeft;
    /*8  */ uint8_t TriggerRight;
};

struct DualShock4_GetStateData
{
    struct DualShock4_BasicGetStateData State;
    /* 9  */ uint16_t Timestamp; // in 5.33us units?
    /*11  */ uint8_t Temperture;
    /*12  */ int16_t AngularVelocityX;
    /*14  */ int16_t AngularVelocityZ;
    /*16  */ int16_t AngularVelocityY;
    /*18  */ int16_t AccelerometerX;
    /*20  */ int16_t AccelerometerY;
    /*22  */ int16_t AccelerometerZ;
    /*24  */ uint8_t ExtData[5];       // range can be set by EXT device
    /*29  */ uint8_t PowerPercent : 4; // 0x00-0x0A or 0x01-0x0B if plugged int
    /*29.4*/ uint8_t PluggedPowerCable : 1;
    /*29.5*/ uint8_t PluggedHeadphones : 1;
    /*29.6*/ uint8_t PluggedMic : 1;
    /*29,7*/ uint8_t PluggedExt : 1;
    /*30.0*/ uint8_t UnkExt1 : 1;      // ExtCapableOfExtraData?
    /*30.1*/ uint8_t UnkExt2 : 1;      // ExtHasExtraData?
    /*30.2*/ uint8_t NotConnected : 1; // Used by dongle to indicate no controller
    /*30.3*/ uint8_t Unk1 : 5;
    /*31  */ uint8_t Unk2; // unused?
    /*32  */ uint8_t TouchCount;
};

struct DualShock4_USBGetStateData
{
    struct DualShock4_GetStateData State;
    struct DualShock4_TouchData TouchData[3];
    uint8_t Pad[3];
};

struct DualShock4_BTGetStateData
{
    struct DualShock4_GetStateData State;
    struct DualShock4_TouchData TouchData[4];
    uint8_t Pad[6];
};

// HID Report 0x01 Input USB/Dongle
struct DualShock4_ReportIn01USB
{
    uint8_t ReportID; // 0x01
    struct DualShock4_USBGetStateData State;
};

// HID Report 0x01 Input BT
struct DualShock4_ReportIn01BT
{
    uint8_t ReportID; // 0x01
    struct DualShock4_BasicGetStateData State;
};

// HID Report 0x11 Input BT
struct DualShock4_ReportIn11
{
    union
    {
        DualShock4_BTCRC(78) CRC;
        struct
        {
            uint8_t ReportID; // 0x11
            uint8_t Unk1 : 6;
            uint8_t EnableCRC : 1;
            uint8_t EnableHID : 1;
            uint8_t Unk2 : 7;
            uint8_t EnableAudio : 1;
            union
            {
                struct DualShock4_BTGetStateData State;
                DualShock4_BTAudio(75) Audio;
            };
        } Data;
    };
};

// HID Report 0x12 Input BT
struct DualShock4_ReportIn12
{
    union
    {
        DualShock4_BTCRC(142) CRC;
        struct
        {
            uint8_t ReportID; // 0x12
            uint8_t Unk1 : 6;
            uint8_t EnableCRC : 1;
            uint8_t EnableHID : 1;
            uint8_t Unk2 : 7;
            uint8_t EnableAudio : 1;
            union
            {
                DualShock4_BTGetStateDataAndAudio(139) State;
                DualShock4_BTAudio(139) Audio;
            };
        } Data;
    };
};

// HID Report 0x13 Input BT
struct DualShock4_ReportIn13
{
    union
    {
        DualShock4_BTCRC(206) CRC;
        struct
        {
            uint8_t ReportID; // 0x13
            uint8_t Unk1 : 6;
            uint8_t EnableCRC : 1;
            uint8_t EnableHID : 1;
            uint8_t Unk2 : 7;
            uint8_t EnableAudio : 1;
            union
            {
                DualShock4_BTGetStateDataAndAudio(203) State;
                DualShock4_BTAudio(203) Audio;
            };
        } Data;
    };
};

// HID Report 0x14 Input BT
struct DualShock4_ReportIn14
{
    union
    {
        DualShock4_BTCRC(270) CRC;
        struct
        {
            uint8_t ReportID; // 0x14
            uint8_t Unk1 : 6;
            uint8_t EnableCRC : 1;
            uint8_t EnableHID : 1;
            uint8_t Unk2 : 7;
            uint8_t EnableAudio : 1;
            union
            {
                DualShock4_BTGetStateDataAndAudio(267) State;
                DualShock4_BTAudio(267) Audio;
            };
        } Data;
    };
};

// HID Report 0x15 Input BT
struct DualShock4_ReportIn15
{
    union
    {
        DualShock4_BTCRC(334) CRC;
        struct
        {
            uint8_t ReportID; // 0x15
            uint8_t Unk1 : 6;
            uint8_t EnableCRC : 1;
            uint8_t EnableHID : 1;
            uint8_t Unk2 : 7;
            uint8_t EnableAudio : 1;
            union
            {
                DualShock4_BTGetStateDataAndAudio(331) State;
                DualShock4_BTAudio(331) Audio;
            };
        } Data;
    };
};

// HID Report 0x16 Input BT
struct ReportIn16
{
    union
    {
        DualShock4_BTCRC(398) CRC;
        struct
        {
            uint8_t ReportID; // 0x16
            uint8_t Unk1 : 6;
            uint8_t EnableCRC : 1;
            uint8_t EnableHID : 1;
            uint8_t Unk2 : 7;
            uint8_t EnableAudio : 1;
            union
            {
                DualShock4_BTGetStateDataAndAudio(395) State;
                DualShock4_BTAudio(395) Audio;
            };
        } Data;
    };
};

// HID Report 0x17 Input BT
struct DualShock4_ReportIn17
{
    union
    {
        DualShock4_BTCRC(462) CRC;
        struct
        {
            uint8_t ReportID; // 0x17
            uint8_t Unk1 : 6;
            uint8_t EnableCRC : 1;
            uint8_t EnableHID : 1;
            uint8_t Unk2 : 7;
            uint8_t EnableAudio : 1;
            union
            {
                DualShock4_BTGetStateDataAndAudio(459) State;
                DualShock4_BTAudio(459) Audio;
            };
        } Data;
    };
};

// HID Report 0x18 Input BT
struct DualShock4_ReportIn18
{
    union
    {
        DualShock4_BTCRC(526) CRC;
        struct
        {
            uint8_t ReportID; // 0x18
            uint8_t Unk1 : 6;
            uint8_t EnableCRC : 1;
            uint8_t EnableHID : 1;
            uint8_t Unk2 : 7;
            uint8_t EnableAudio : 1;
            union
            {
                DualShock4_BTGetStateDataAndAudio(523) State;
                DualShock4_BTAudio(523) Audio;
            };
        } Data;
    };
};

// HID Report 0x19 Input BT
struct ReportIn19
{
    union
    {
        DualShock4_BTCRC(547) CRC;
        struct
        {
            uint8_t ReportID; // 0x19
            uint8_t Unk1 : 6;
            uint8_t EnableCRC : 1;
            uint8_t EnableHID : 1;
            uint8_t Unk2 : 7;
            uint8_t EnableAudio : 1;
            union
            {
                DualShock4_BTGetStateDataAndAudio(544) State;
                DualShock4_BTAudio(544) Audio;
            };
        } Data;
    };
};

/* Output Reports */

// template<int N> struct BTSetStateDataAndAudio {
//     BTSetStateData State;
//     BTAudio<N-75> Audio;
// };

#define DualShock4_BTSetStateDataAndAudio(N) \
    struct                                   \
    {                                        \
        DualShock4_BTSetStateData State;     \
        DualShock4_BTAudio(N - 75) Audio;    \
    }

typedef struct
{
    uint8_t EnableRumbleUpdate : 1;
    uint8_t EnableLedUpdate : 1;
    uint8_t EnableLedBlink : 1;
    uint8_t EnableExtWrite : 1;
    uint8_t EnableVolumeLeftUpdate : 1;
    uint8_t EnableVolumeRightUpdate : 1;
    uint8_t EnableVolumeMicUpdate : 1;
    uint8_t EnableVolumeSpeakerUpdate : 1;
    uint8_t UNK_RESET1 : 1; // unknown reset, both set high by Remote Play
    uint8_t UNK_RESET2 : 1; // unknown reset, both set high by Remote Play
    uint8_t UNK1 : 1;
    uint8_t UNK2 : 1;
    uint8_t UNK3 : 1;
    uint8_t UNKPad : 3;
    uint8_t Empty1;
    uint8_t RumbleRight; // weak
    uint8_t RumbleLeft;  // strong
    uint8_t LedRed;
    uint8_t LedGreen;
    uint8_t LedBlue;
    uint8_t LedFlashOnPeriod;
    uint8_t LedFlashOffPeriod;
    uint8_t ExtDataSend[8]; // sent to I2C EXT port, stored in 8x8 byte block
    uint8_t VolumeLeft;     // 0x00 - 0x4F inclusive
    uint8_t VolumeRight;    // 0x00 - 0x4F inclusive
    uint8_t VolumeMic;      // 0x00, 0x01 - 0x40 inclusive (0x00 is special behavior)
    uint8_t VolumeSpeaker;  // 0x00 - 0x4F
    uint8_t UNK_AUDIO1 : 7; // clamped to 1-64 inclusive, appears to be set to 5 for audio
    uint8_t UNK_AUDIO2 : 1; // unknown, appears to be set to 1 for audio
    uint8_t Pad[8];
} DualShock4_USBSetStateData;

typedef struct
{
    uint8_t EnableRumbleUpdate : 1;
    uint8_t EnableLedUpdate : 1;
    uint8_t EnableLedBlink : 1;
    uint8_t EnableExtWrite : 1;
    uint8_t EnableVolumeLeftUpdate : 1;
    uint8_t EnableVolumeRightUpdate : 1;
    uint8_t EnableVolumeMicUpdate : 1;
    uint8_t EnableVolumeSpeakerUpdate : 1;
    uint8_t UNK_RESET1 : 1; // unknown reset, both set high by Remote Play
    uint8_t UNK_RESET2 : 1; // unknown reset, both set high by Remote Play
    uint8_t UNK1 : 1;
    uint8_t UNK2 : 1;
    uint8_t UNK3 : 1;
    uint8_t UNKPad : 3;
    uint8_t Empty1;
    uint8_t RumbleRight; // weak
    uint8_t RumbleLeft;  // strong
    uint8_t LedRed;
    uint8_t LedGreen;
    uint8_t LedBlue;
    uint8_t LedFlashOnPeriod;
    uint8_t LedFlashOffPeriod;
    uint8_t ExtDataSend[8]; // sent to I2C EXT port, stored in 8x8 byte block
    uint8_t VolumeLeft;     // 0x00 - 0x4F inclusive
    uint8_t VolumeRight;    // 0x00 - 0x4F inclusive
    uint8_t VolumeMic;      // 0x00, 0x01 - 0x40 inclusive (0x00 is special behavior)
    uint8_t VolumeSpeaker;  // 0x00 - 0x4F
    uint8_t UNK_AUDIO1 : 7; // clamped to 1-64 inclusive, appears to be set to 5 for audio
    uint8_t UNK_AUDIO2 : 1; // unknown, appears to be set to 1 for audio
    uint8_t Pad[52];
} DualShock4_BTSetStateData;

// HID Report 0x05 Output USB/Dongle
struct DualShock4_ReportIn05
{
    uint8_t ReportID; // 0x05
    DualShock4_USBSetStateData State;
};

// HID Report 0x11 Output BT
struct DualShock4_ReportOut11
{
    union
    {
        DualShock4_BTCRC(78) CRC;
        struct
        {
            uint8_t ReportID;        // 0x11
            uint8_t PollingRate : 6; // note 0 appears to be clamped to 1
            uint8_t EnableCRC : 1;
            uint8_t EnableHID : 1;
            uint8_t EnableMic : 3; // somehow enables mic, appears to be 3 bit flags
            uint8_t UnkA4 : 1;
            uint8_t UnkB1 : 1;
            uint8_t UnkB2 : 1; // seems to always be 1
            uint8_t UnkB3 : 1;
            uint8_t EnableAudio : 1;
            union
            {
                DualShock4_BTSetStateData State;
                DualShock4_BTAudio(75) Audio;
            };
        } Data;
    };
};

// HID Report 0x12 Output BT
struct ReportOut12
{
    union
    {
        DualShock4_BTCRC(142) CRC;
        struct
        {
            uint8_t ReportID;        // 0x12
            uint8_t PollingRate : 6; // note 0 appears to be clamped to 1
            uint8_t EnableCRC : 1;
            uint8_t EnableHID : 1;
            uint8_t EnableMic : 3; // somehow enables mic, appears to be 3 bit flags
            uint8_t UnkA4 : 1;
            uint8_t UnkB1 : 1;
            uint8_t UnkB2 : 1; // seems to always be 1
            uint8_t UnkB3 : 1;
            uint8_t EnableAudio : 1;
            union
            {
                DualShock4_BTSetStateDataAndAudio(139) State;
                DualShock4_BTAudio(139) Audio;
            };
        } Data;
    };
};

// HID Report 0x13 Output BT
struct ReportOut13
{
    union
    {
        DualShock4_BTCRC(206) CRC;
        struct
        {
            uint8_t ReportID;        // 0x13
            uint8_t PollingRate : 6; // note 0 appears to be clamped to 1
            uint8_t EnableCRC : 1;
            uint8_t EnableHID : 1;
            uint8_t EnableMic : 3; // somehow enables mic, appears to be 3 bit flags
            uint8_t UnkA4 : 1;
            uint8_t UnkB1 : 1;
            uint8_t UnkB2 : 1; // seems to always be 1
            uint8_t UnkB3 : 1;
            uint8_t EnableAudio : 1;
            union
            {
                DualShock4_BTSetStateDataAndAudio(203) State;
                DualShock4_BTAudio(203) Audio;
            };
        } Data;
    };
};

// HID Report 0x14 Output BT
struct ReportOut14
{
    union
    {
        DualShock4_BTCRC(270) CRC;
        struct
        {
            uint8_t ReportID;        // 0x14
            uint8_t PollingRate : 6; // note 0 appears to be clamped to 1
            uint8_t EnableCRC : 1;
            uint8_t EnableHID : 1;
            uint8_t EnableMic : 3; // somehow enables mic, appears to be 3 bit flags
            uint8_t UnkA4 : 1;
            uint8_t UnkB1 : 1;
            uint8_t UnkB2 : 1; // seems to always be 1
            uint8_t UnkB3 : 1;
            uint8_t EnableAudio : 1;
            union
            {
                DualShock4_BTSetStateDataAndAudio(267) State;
                DualShock4_BTAudio(267) Audio;
            };
        } Data;
    };
};

// HID Report 0x15 Output BT
struct DualShock4_ReportOut15
{
    union
    {
        DualShock4_BTCRC(334) CRC;
        struct
        {
            uint8_t ReportID;        // 0x15
            uint8_t PollingRate : 6; // note 0 appears to be clamped to 1
            uint8_t EnableCRC : 1;
            uint8_t EnableHID : 1;
            uint8_t EnableMic : 3; // somehow enables mic, appears to be 3 bit flags
            uint8_t UnkA4 : 1;
            uint8_t UnkB1 : 1;
            uint8_t UnkB2 : 1; // seems to always be 1
            uint8_t UnkB3 : 1;
            uint8_t EnableAudio : 1;
            union
            {
                DualShock4_BTSetStateDataAndAudio(331) State;
                DualShock4_BTAudio(331) Audio;
            };
        } Data;
    };
};

// HID Report 0x16 Output BT
struct DualShock4_ReportOut16
{
    union
    {
        DualShock4_BTCRC(398) CRC;
        struct
        {
            uint8_t ReportID;        // 0x16
            uint8_t PollingRate : 6; // note 0 appears to be clamped to 1
            uint8_t EnableCRC : 1;
            uint8_t EnableHID : 1;
            uint8_t EnableMic : 3; // somehow enables mic, appears to be 3 bit flags
            uint8_t UnkA4 : 1;
            uint8_t UnkB1 : 1;
            uint8_t UnkB2 : 1; // seems to always be 1
            uint8_t UnkB3 : 1;
            uint8_t EnableAudio : 1;
            union
            {
                DualShock4_BTSetStateDataAndAudio(395) State;
                DualShock4_BTAudio(395) Audio;
            };
        } Data;
    };
};

// HID Report 0x17 Output BT
struct DualShock4_ReportOut17
{
    union
    {
        DualShock4_BTCRC(462) CRC;
        struct
        {
            uint8_t ReportID;        // 0x17
            uint8_t PollingRate : 6; // note 0 appears to be clamped to 1
            uint8_t EnableCRC : 1;
            uint8_t EnableHID : 1;
            uint8_t EnableMic : 3; // somehow enables mic, appears to be 3 bit flags
            uint8_t UnkA4 : 1;
            uint8_t UnkB1 : 1;
            uint8_t UnkB2 : 1; // seems to always be 1
            uint8_t UnkB3 : 1;
            uint8_t EnableAudio : 1;
            union
            {
                DualShock4_BTSetStateDataAndAudio(459) State;
                DualShock4_BTAudio(459) Audio;
            };
        } Data;
    };
};

// HID Report 0x18 Output BT
struct DualShock4_ReportOut18
{
    union
    {
        DualShock4_BTCRC(526) CRC;
        struct
        {
            uint8_t ReportID;        // 0x18
            uint8_t PollingRate : 6; // note 0 appears to be clamped to 1
            uint8_t EnableCRC : 1;
            uint8_t EnableHID : 1;
            uint8_t EnableMic : 3; // somehow enables mic, appears to be 3 bit flags
            uint8_t UnkA4 : 1;
            uint8_t UnkB1 : 1;
            uint8_t UnkB2 : 1; // seems to always be 1
            uint8_t UnkB3 : 1;
            uint8_t EnableAudio : 1;
            union
            {
                DualShock4_BTSetStateDataAndAudio(523) State;
                DualShock4_BTAudio(523) Audio;
            };
        } Data;
    };
};

// HID Report 0x19 Output BT
struct DualShock4_ReportOut19
{
    union
    {
        DualShock4_BTCRC(547) CRC;
        struct
        {
            uint8_t ReportID;        // 0x19
            uint8_t PollingRate : 6; // note 0 appears to be clamped to 1
            uint8_t EnableCRC : 1;
            uint8_t EnableHID : 1;
            uint8_t EnableMic : 3; // somehow enables mic, appears to be 3 bit flags
            uint8_t UnkA4 : 1;
            uint8_t UnkB1 : 1;
            uint8_t UnkB2 : 1; // seems to always be 1
            uint8_t UnkB3 : 1;
            uint8_t EnableAudio : 1;
            union
            {
                DualShock4_BTSetStateDataAndAudio(544) State;
                DualShock4_BTAudio(544) Audio;
            };
        } Data;
    };
};

/* Feature Reports */
/* Calibration */
/* Reading calibration is required to switch input reports from
 the truncated 0x01 report to the expanded 0x11-0x19 reports. */

//  USB 0x02
struct DualShock4_ReportFeatureInCalibrateUSB
{
    uint8_t ReportID; // 0x02
    int16_t GyroPitchBias;
    int16_t GyroYawBias;
    int16_t GyroRollBias;
    int16_t GyroPitchPlus;
    int16_t GyroPitchMinus;
    int16_t GyroYawPlus;
    int16_t GyroYawMinus;
    int16_t GyroRollPlus;
    int16_t GyroRollMinus;
    int16_t GyroSpeedPlus;
    int16_t GyroSpeedMinus;
    int16_t AccelXPlus;
    int16_t AccelXMinus;
    int16_t AccelYPlus;
    int16_t AccelYMinus;
    int16_t AccelZPlus;
    int16_t AccelZMinus;
    int16_t Unknown;
};

// Bluetooth 0x05
struct DualShock4_ReportFeatureInCalibrateBT
{
    union
    {
        DualShock4_BTCRC(41) CRC;
        struct
        {
            uint8_t ReportID; // 0x05
            int16_t GyroPitchBias;
            int16_t GyroYawBias;
            int16_t GyroRollBias;
            int16_t GyroPitchPlus;
            int16_t GyroYawPlus;
            int16_t GyroRollPlus;
            int16_t GyroPitchMinus;
            int16_t GyroYawMinus;
            int16_t GyroRollMinus;
            int16_t GyroSpeedPlus;
            int16_t GyroSpeedMinus;
            int16_t AccelXPlus;
            int16_t AccelXMinus;
            int16_t AccelYPlus;
            int16_t AccelYMinus;
            int16_t AccelZPlus;
            int16_t AccelZMinus;
            int16_t Unknown;
        } Data;
    };
};

// Dongle 0x02
struct DualShock4_ReportFeatureInCalibrateDongle
{
    uint8_t ReportID; // 0x02
    int16_t GyroPitchBias;
    int16_t GyroYawBias;
    int16_t GyroRollBias;
    int16_t GyroPitchPlus;
    int16_t GyroYawPlus;
    int16_t GyroRollPlus;
    int16_t GyroPitchMinus;
    int16_t GyroYawMinus;
    int16_t GyroRollMinus;
    int16_t GyroSpeedPlus;
    int16_t GyroSpeedMinus;
    int16_t AccelXPlus;
    int16_t AccelXMinus;
    int16_t AccelYPlus;
    int16_t AccelYMinus;
    int16_t AccelZPlus;
    int16_t AccelZMinus;
    int16_t Unknown;
};

/* MAC */
/* Need to confirm these on BT */

// Get All MAC USB/Dongle 0x12
struct DualShock4_ReportFeatureInMacAll
{
    uint8_t ReportID;     // 0x12 (0x09 for BT)
    uint8_t ClientMac[6]; // Right to Left
    uint8_t Hard08;
    uint8_t Hard25;
    uint8_t Hard00;
    uint8_t HostMac[6]; // Right to Left
};

// Controller Date/Version Dongle/USB 0xA3
struct DualShock4_ReportFeatureInControllerVersion
{
    uint8_t ReportID;              // 0xA3 (0x06 for BT)
    char Date[16];                 // string
    char Time[16];                 // string
    uint16_t HardwareVersionMajor; // %04x.%04x AKA DevRel
    uint16_t HardwareVersionMinor; // Must be >= 0x3100u for Remote Play
                                   // might be bitwise anded with 0xFFC0
    uint32_t SoftwareVersionMajor; // firmware ignores this for debug terminal output a hardcode of 3
    uint16_t SoftwareVersionMinor; // written %08x.%04x, 3, sw_ver_minor
    uint16_t SoftwareSeries;       // %04x
    uint32_t CodeSize;
};

// Get All MAC BT 0x09
struct DualShock4_ReportFeatureInMacAllBT
{
    union
    {
        DualShock4_BTCRC(53) CRC;
        struct DualShock4_ReportFeatureInControllerVersion Data; // with ReportID 0x09
    };
};

// Get Client MAC USB/Dongle 0x81
struct DualShock4_ReportFeatureInMacClient
{
    uint8_t ReportID;     // 0x81
    uint8_t ClientMac[6]; // Right to Left
};

// Get Host Dongle 0xE5
struct DualShock4_ReportFeatureInMacHost
{
    uint8_t ReportID;   // 0xE5
    uint8_t HostMac[6]; // Right to Left
};

// Set Host MAC and Linkkey USB 0x13
struct DualShock4_ReportFeatureOutMacHost
{
    uint8_t ReportID;     // 0x13
    uint8_t ClientMac[6]; // Right to Left
    uint8_t Linkkey[16];
};

// Set Client MAC USB 0x80
struct DualShock4_ReportFeatureOutMacClient
{
    uint8_t ReportID;     // 0x80
    uint8_t ClientMac[6]; // Right to Left
};

/* Date and Version */

// Controller Date/Version Bluetooth 0x06
struct DualShock4_ReportFeatureInControllerVersionBT
{
    union
    {
        DualShock4_BTCRC(53) CRC;
        struct DualShock4_ReportFeatureInControllerVersion Data; // with ReportID 0x06
    };
};

// Dongle Date/Version Dongle 0xE1
struct DualShock4_ReportFeatureInDongleVersion
{
    uint8_t ReportID; // 0xE1
    char Date[16];    // string
    char Time[16];    // string
    uint16_t HardwareVersionMajor;
    uint16_t HardwareVersionMinor;
    uint32_t SoftwareVersionMajor;
    uint16_t SoftwareVersionMinor;
    uint16_t SoftwareSeries;
    uint32_t CodeSize;
};

#endif
