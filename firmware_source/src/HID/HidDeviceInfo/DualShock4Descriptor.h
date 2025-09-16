#pragma once

#include "Library/Utils/Utils.h"

// https://github.com/DJm00n/ControllersInfo

#define DUAL_SHOCK_4_USB_AC_ITF_NUM 0
#define DUAL_SHOCK_4_USB_AS_OUT_ITF_NUM (DUAL_SHOCK_4_USB_AC_ITF_NUM + 1)
#define DUAL_SHOCK_4_USB_AS_IN_ITF_NUM (DUAL_SHOCK_4_USB_AC_ITF_NUM + 2)
#define DUAL_SHOCK_4_USB_HID_ITF_NUM 3

/* HID input report id */
#define DUAL_SHOCK_4_HID_INPUT_ID01 0x01
/* HID output report id */
#define DUAL_SHOCK_4_HID_OUTPUT_ID11 0x11
/* HID feature report id */
#define DUAL_SHOCK_4_USB_HID_FEATURE_ID05 0x05

/* Device Descriptor: */
#define DUAL_SHOCK_4_USB_DEVICE_DESCRIPTOR                                          \
    0x12,                    /* bLength */                                          \
        0x01,                /* bDescriptorType */                                  \
        U16_TO_BYTE(0x0200), /* bcdUSB */                                           \
        0x00,                /* bDeviceClass */                                     \
        0x00,                /* bDeviceSubClass */                                  \
        0x00,                /* bDeviceProtocol */                                  \
        0x40,                /* bMaxPacketSize0   (64 bytes) */                     \
        U16_TO_BYTE(0x054C), /* idVendor */                                         \
        U16_TO_BYTE(0x09CC), /* idProduct */                                        \
        U16_TO_BYTE(0x0100), /* bcdDevice */                                        \
        0x01,                /* iManufacturer   "Sony Interactive Entertainment" */ \
        0x02,                /* iProduct        "Wireless Controller" */            \
        0x00,                /* iSerialNumber */                                    \
        0x01                 /* bNumConfigurations */

/* Configuration Descriptor: */
#define DUAL_SHOCK_4_USB_CONFIGURATION_DESCRIPTOR                       \
    0x09,                    /* bLength */                              \
        0x02,                /* bDescriptorType */                      \
        U16_TO_BYTE(0x00E1), /* wTotalLength   (225 bytes) */           \
        0x04,                /* bNumInterfaces */                       \
        0x01,                /* bConfigurationValue */                  \
        0x00,                /* iConfiguration */                       \
        0xC0,                /* bmAttributes   (Self-powered Device) */ \
        0xFA                 /* bMaxPower      (500 mA) */

/* Interface Descriptor: */
#define DUAL_SHOCK_4_USB_ITF0_INTERFACE_DESCRIPTOR                                         \
    0x09,                            /* bLength */                                         \
        0x04,                        /* bDescriptorType */                                 \
        DUAL_SHOCK_4_USB_AC_ITF_NUM, /* bInterfaceNumber */                                \
        0x00,                        /* bAlternateSetting */                               \
        0x00,                        /* bNumEndPoints */                                   \
        0x01,                        /* bInterfaceClass      (Audio Device Class) */       \
        0x01,                        /* bInterfaceSubClass   (Audio Control Interface) */  \
        0x00,                        /* bInterfaceProtocol   (Audio Protocol undefined) */ \
        0x00                         /* iInterface */

/* AC Interface Header Descriptor: */
#define DUAL_SHOCK_4_USB_ITF0_AC_DESCRIPTOR                              \
    0x0A,                                /* bLength */                   \
        0x24,                            /* bDescriptorType */           \
        0x01,                            /* bDescriptorSubtype */        \
        U16_TO_BYTE(0x0100),             /* bcdADC */                    \
        U16_TO_BYTE(0x0047),             /* wTotalLength   (71 bytes) */ \
        0x02,                            /* bInCollection */             \
        DUAL_SHOCK_4_USB_AS_OUT_ITF_NUM, /* baInterfaceNr(1) */          \
        DUAL_SHOCK_4_USB_AS_IN_ITF_NUM   /* baInterfaceNr(2) */

/* AC Input Terminal Descriptor: */
#define DUAL_SHOCK_4_USB_ITF0_SPK_AC_INPUT_TERMINAL_DESCRIPTOR     \
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
#define DUAL_SHOCK_4_USB_ITF0_SPK_AC_FEATURE_UNIT_DESCRIPTOR \
    0x0A,                   /* bLength */                    \
        0x24,               /* bDescriptorType */            \
        0x06,               /* bDescriptorSubtype */         \
        0x02,               /* bUnitID */                    \
        0x01,               /* bSourceID */                  \
        0x01,               /* bControlSize */               \
        /* bmaControls:  */ /**/                             \
        0x03,               /* Channel(0) - Mute / Volume */ \
        0x00,               /* Channel(1) */                 \
        0x00,               /* Channel(2) */                 \
        0x00                /* iFeature */

/* AC Output Terminal Descriptor: */
#define DUAL_SHOCK_4_USB_ITF0_SPK_AC_OUTPUT_TERMINAL_DESCRIPTOR \
    0x09,                    /* bLength */                      \
        0x24,                /* bDescriptorType */              \
        0x03,                /* bDescriptorSubtype */           \
        0x03,                /* bTerminalID */                  \
        U16_TO_BYTE(0x0402), /* wTerminalType   (Headset) */    \
        0x04,                /* bAssocTerminal */               \
        0x02,                /* bSourceID */                    \
        0x00                 /* iTerminal */

/* AC Input Terminal Descriptor: */
#define DUAL_SHOCK_4_USB_ITF0_MIC_AC_INPUT_TERMINAL_DESCRIPTOR \
    0x0C,                    /* bLength */                     \
        0x24,                /* bDescriptorType */             \
        0x02,                /* bDescriptorSubtype */          \
        0x04,                /* bTerminalID */                 \
        U16_TO_BYTE(0x0402), /* wTerminalType   (Headset) */   \
        0x03,                /* bAssocTerminal */              \
        0x01,                /* bNrChannels   (1 channels) */  \
        U16_TO_BYTE(0x0000), /* wChannelConfig */              \
        0x00,                /* iChannelNames */               \
        0x00                 /* iTerminal */

/* AC Feature Unit Descriptor: */
#define DUAL_SHOCK_4_USB_ITF0_MIC_AC_FEATURE_UNIT_DESCRIPTOR \
    0x09,                   /* bLength */                    \
        0x24,               /* bDescriptorType */            \
        0x06,               /* bDescriptorSubtype */         \
        0x05,               /* bUnitID */                    \
        0x04,               /* bSourceID */                  \
        0x01,               /* bControlSize */               \
        /* bmaControls:  */ /**/                             \
        0x03,               /* Channel(0) - Mute / Volume */ \
        0x00,               /* Channel(1) */                 \
        0x00                /* iFeature */

/* AC Output Terminal Descriptor: */
#define DUAL_SHOCK_4_USB_ITF0_MIC_AC_OUTPUT_TERMINAL_DESCRIPTOR    \
    0x09,                    /* bLength */                         \
        0x24,                /* bDescriptorType */                 \
        0x03,                /* bDescriptorSubtype */              \
        0x06,                /* bTerminalID */                     \
        U16_TO_BYTE(0x0101), /* wTerminalType   (USB Streaming) */ \
        0x01,                /* bAssocTerminal */                  \
        0x05,                /* bSourceID */                       \
        0x00                 /* iTerminal */

/* Interface Descriptor: */
#define DUAL_SHOCK_4_USB_ITF1_ALT0_INTERFACE_DESCRIPTOR                                         \
    0x09,                                /* bLength */                                          \
        0x04,                            /* bDescriptorType */                                  \
        DUAL_SHOCK_4_USB_AS_OUT_ITF_NUM, /* bInterfaceNumber */                                 \
        0x00,                            /* bAlternateSetting */                                \
        0x00,                            /* bNumEndPoints */                                    \
        0x01,                            /* bInterfaceClass      (Audio Device Class) */        \
        0x02,                            /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,                            /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00                             /* iInterface */

/* Interface Descriptor: */
#define DUAL_SHOCK_4_USB_ITF1_ALT1_INTERFACE_DESCRIPTOR                                         \
    0x09,                                /* bLength */                                          \
        0x04,                            /* bDescriptorType */                                  \
        DUAL_SHOCK_4_USB_AS_OUT_ITF_NUM, /* bInterfaceNumber */                                 \
        0x01,                            /* bAlternateSetting */                                \
        0x01,                            /* bNumEndPoints */                                    \
        0x01,                            /* bInterfaceClass      (Audio Device Class) */        \
        0x02,                            /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,                            /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00                             /* iInterface */

/* AS Interface Descriptor: */
#define DUAL_SHOCK_4_USB_ITF1_ALT1_AS_DESCRIPTOR     \
    0x07,                   /* bLength */            \
        0x24,               /* bDescriptorType */    \
        0x01,               /* bDescriptorSubtype */ \
        0x01,               /* bTerminalLink */      \
        0x01,               /* bDelay */             \
        U16_TO_BYTE(0x0001) /* wFormatTag   (PCM) */

/* AS Format Type 1 Descriptor: */
#define DUAL_SHOCK_4_USB_ITF1_ALT1_AS_FORMAT_DESCRIPTOR                            \
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
#define DUAL_SHOCK_4_USB_ITF1_ALT1_AUDIO_OUT_ENDPOINT_DESCRIPTOR                                             \
    0x09,                    /* bLength */                                                                   \
        0x05,                /* bDescriptorType */                                                           \
        0x01,                /* bEndpointAddress  (OUT endpoint 1) */                                        \
        0x09,                /* bmAttributes      (Transfer: Isochronous / Synch: Adaptive / Usage: Data) */ \
        U16_TO_BYTE(0x0084), /* wMaxPacketSize    (1 x 132 bytes) */                                         \
        0x01,                /* bInterval         (1 frames) */                                              \
        0x00,                /* bRefresh */                                                                  \
        0x00                 /* bSynchAddress */

/* AS Isochronous Data Endpoint Descriptor: */
#define DUAL_SHOCK_4_USB_ITF1_ALT1_AS_ISOCHRONOUS_DATA_ENDPOINT_DESCRIPTOR \
    0x07,                   /* bLength */                                  \
        0x25,               /* bDescriptorType */                          \
        0x01,               /* bDescriptorSubtype */                       \
        0x00,               /* bmAttributes */                             \
        0x00,               /* bLockDelayUnits   (undefined) */            \
        U16_TO_BYTE(0x0000) /* wLockDelay */

/* Interface Descriptor: */
#define DUAL_SHOCK_4_USB_ITF2_ALT0_INTERFACE_DESCRIPTOR                                        \
    0x09,                               /* bLength */                                          \
        0x04,                           /* bDescriptorType */                                  \
        DUAL_SHOCK_4_USB_AS_IN_ITF_NUM, /* bInterfaceNumber */                                 \
        0x00,                           /* bAlternateSetting */                                \
        0x00,                           /* bNumEndPoints */                                    \
        0x01,                           /* bInterfaceClass      (Audio Device Class) */        \
        0x02,                           /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,                           /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00                            /* iInterface */

/* Interface Descriptor: */
#define DUAL_SHOCK_4_USB_ITF2_ALT1_INTERFACE_DESCRIPTOR                                        \
    0x09,                               /* bLength */                                          \
        0x04,                           /* bDescriptorType */                                  \
        DUAL_SHOCK_4_USB_AS_IN_ITF_NUM, /* bInterfaceNumber */                                 \
        0x01,                           /* bAlternateSetting */                                \
        0x01,                           /* bNumEndPoints */                                    \
        0x01,                           /* bInterfaceClass      (Audio Device Class) */        \
        0x02,                           /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,                           /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00                            /* iInterface */

/* AS Interface Descriptor: */
#define DUAL_SHOCK_4_USB_ITF2_ALT1_AS_DESCRIPTOR     \
    0x07,                   /* bLength */            \
        0x24,               /* bDescriptorType */    \
        0x01,               /* bDescriptorSubtype */ \
        0x06,               /* bTerminalLink */      \
        0x01,               /* bDelay */             \
        U16_TO_BYTE(0x0001) /* wFormatTag   (PCM) */

/* AS Format Type 1 Descriptor: */
#define DUAL_SHOCK_4_USB_ITF2_ALT1_AS_FORMAT_DESCRIPTOR                            \
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
#define DUAL_SHOCK_4_USB_ITF2_ALT1_AUDIO_IN_ENDPOINT_DESCRIPTOR                                                  \
    0x09,                    /* bLength */                                                                       \
        0x05,                /* bDescriptorType */                                                               \
        0x82,                /* bEndpointAddress  (IN endpoint 2) */                                             \
        0x05,                /* bmAttributes      (Transfer: Isochronous / Synch: Asynchronous / Usage: Data) */ \
        U16_TO_BYTE(0x0022), /* wMaxPacketSize    (1 x 34 bytes) */                                              \
        0x01,                /* bInterval         (1 frames) */                                                  \
        0x00,                /* bRefresh */                                                                      \
        0x00                 /* bSynchAddress */

/* AS Isochronous Data Endpoint Descriptor: */
#define DUAL_SHOCK_4_USB_ITF2_ALT1_AS_ISOCHRONOUS_DATA_ENDPOINT_DESCRIPTOR \
    0x07,                   /* bLength */                                  \
        0x25,               /* bDescriptorType */                          \
        0x01,               /* bDescriptorSubtype */                       \
        0x00,               /* bmAttributes */                             \
        0x00,               /* bLockDelayUnits   (undefined) */            \
        U16_TO_BYTE(0x0000) /* wLockDelay */

/* Interface Descriptor: */
#define DUAL_SHOCK_4_USB_ITF3_INTERFACE_DESCRIPTOR                                              \
    0x09,                             /* bLength */                                             \
        0x04,                         /* bDescriptorType */                                     \
        DUAL_SHOCK_4_USB_HID_ITF_NUM, /* bInterfaceNumber */                                    \
        0x00,                         /* bAlternateSetting */                                   \
        0x02,                         /* bNumEndPoints */                                       \
        0x03,                         /* bInterfaceClass      (Human Interface Device Class) */ \
        0x00,                         /* bInterfaceSubClass */                                  \
        0x00,                         /* bInterfaceProtocol */                                  \
        0x00                          /* iInterface */

/* HID Descriptor: */
#define DUAL_SHOCK_4_USB_ITF3_HID_DESCRIPTOR                             \
    0x09,                    /* bLength */                               \
        0x21,                /* bDescriptorType */                       \
        U16_TO_BYTE(0x0111), /* bcdHID */                                \
        0x00,                /* bCountryCode */                          \
        0x01,                /* bNumDescriptors */                       \
        0x22,                /* bDescriptorType   (Report descriptor) */ \
        U16_TO_BYTE(0x01FB)  /* bDescriptorLength */

/* Endpoint Descriptor: */
#define DUAL_SHOCK_4_USB_ITF3_IN_ENDPOINT_DESCRIPTOR                                                   \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x84,                /* bEndpointAddress  (IN endpoint 4) */                                   \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x05                 /* bInterval         (5 frames) */

/* Endpoint Descriptor: */
#define DUAL_SHOCK_4_USB_ITF3_OUT_ENDPOINT_DESCRIPTOR                                                  \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x03,                /* bEndpointAddress  (OUT endpoint 3) */                                  \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x05                 /* bInterval         (5 frames) */

/* String Descriptor Table */
#define DUAL_SHOCK_4_USB_STRING_DESCRIPTOR_0 (const char[]){0x09, 0x04}
#define DUAL_SHOCK_4_USB_STRING_MANUFACTURER "Sony Interactive Entertainment"
#define DUAL_SHOCK_4_USB_STRING_PRODUCT "Wireless Controller"

#define DUAL_SHOCK_4_HID_REPORT_DESCRIPTOR                                                                            \
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

#define DUAL_SHOCK_4_2X_BT_HID_REPORT_DESCRIPTOR                                                                      \
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

#define DUAL_SHOCK_4_2X_USB_HID_REPORT_DESCRIPTOR                                                                     \
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

#define DUAL_SHOCK_4_DONGLE_HID_REPORT_DESCRIPTOR                                                                     \
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

#define DUAL_SHOCK_4_DONGLE_DFU_MODE_HID_REPORT_DESCRIPTOR                                                            \
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
