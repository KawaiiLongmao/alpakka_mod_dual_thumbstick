#pragma once

#include "Library/common.h"
#include "Middleware/USB/usb_common.h"

// https://github.com/DJm00n/ControllersInfo

/* 扬声器配置 */
#define DUAL_SENSE_USB_AUDIO_SPEAKER_FREQ 48000U        /* 采样率: 48 kHz */
#define DUAL_SENSE_USB_AUDIO_SPEAKER_RESOLUTION_BIT 16u /* 位深度: 16 位 */
#define DUAL_SENSE_USB_AUDIO_SPEAKER_CHANNELS 4u        /* 声道数: 立体声 (2 通道) */

/* 麦克风配置 */
#define DUAL_SENSE_USB_AUDIO_MIC_FREQ 48000U        /* 采样率: 48 kHz */
#define DUAL_SENSE_USB_AUDIO_MIC_RESOLUTION_BIT 16u /* 位深度: 16 位 */
#define DUAL_SENSE_USB_AUDIO_MIC_CHANNELS 2u        /* 声道数: 立体声 (2 通道) */

/* 扬声器输出包大小 */
#define DUAL_SENSE_USB_AUDIO_OUT_PACKET_SIZE         \
    USB_AUDIO_CALC_PACKET_SIZE(                      \
        DUAL_SENSE_USB_AUDIO_SPEAKER_FREQ,           \
        DUAL_SENSE_USB_AUDIO_SPEAKER_RESOLUTION_BIT, \
        DUAL_SENSE_USB_AUDIO_SPEAKER_CHANNELS)

/* 麦克风输入包大小 */
#define DUAL_SENSE_USB_AUDIO_IN_PACKET_SIZE      \
    USB_AUDIO_CALC_PACKET_SIZE(                  \
        DUAL_SENSE_USB_AUDIO_MIC_FREQ,           \
        DUAL_SENSE_USB_AUDIO_MIC_RESOLUTION_BIT, \
        DUAL_SENSE_USB_AUDIO_MIC_CHANNELS)

#define DUAL_SENSE_USB_AC_ITF_NUM 0
#define DUAL_SENSE_USB_AS_OUT_ITF_NUM (DUAL_SENSE_USB_AC_ITF_NUM + 1)
#define DUAL_SENSE_USB_AS_IN_ITF_NUM (DUAL_SENSE_USB_AC_ITF_NUM + 2)
#define DUAL_SENSE_USB_AUDIO_OUT_EP_ADDR 0x01
#define DUAL_SENSE_USB_AUDIO_IN_EP_ADDR 0x82
#define DUAL_SENSE_USB_AUDIO_OUT_EP_SIZE DUAL_SENSE_USB_AUDIO_OUT_PACKET_SIZE
#define DUAL_SENSE_USB_AUDIO_IN_EP_SIZE DUAL_SENSE_USB_AUDIO_IN_PACKET_SIZE
#define DUAL_SENSE_USB_AUDIO_OUT_FEATURE_UNIT_ID 0x02
#define DUAL_SENSE_USB_AUDIO_IN_FEATURE_UNIT_ID 0x05

#define DUAL_SENSE_USB_HID_ITF_NUM 3
#define DUAL_SENSE_USB_HID_IN_EP_ADDR 0x84
#define DUAL_SENSE_USB_HID_OUT_EP_ADDR 0x03
#define DUAL_SENSE_USB_HID_EP_SIZE 64

/* HID input report id */
#define DUAL_SENSE_BT_HID_INPUT_ID01 0x01
/* HID output report id */
#define DUAL_SENSE_BT_HID_OUTPUT_ID31 0x31
#define DUAL_SENSE_BT_HID_OUTPUT_ID32 0x32
#define DUAL_SENSE_BT_HID_OUTPUT_ID33 0x33
#define DUAL_SENSE_BT_HID_OUTPUT_ID34 0x34
#define DUAL_SENSE_BT_HID_OUTPUT_ID35 0x35
#define DUAL_SENSE_BT_HID_OUTPUT_ID36 0x36
#define DUAL_SENSE_BT_HID_OUTPUT_ID37 0x37
#define DUAL_SENSE_BT_HID_OUTPUT_ID38 0x38
#define DUAL_SENSE_BT_HID_OUTPUT_ID39 0x39
/* HID feature report id */
#define DUAL_SENSE_BT_HID_FEATURE_ID05 0x05
#define DUAL_SENSE_BT_HID_FEATURE_ID08 0x08
#define DUAL_SENSE_BT_HID_FEATURE_ID09 0x09
#define DUAL_SENSE_BT_HID_FEATURE_ID20 0x20
#define DUAL_SENSE_BT_HID_FEATURE_ID22 0x22
#define DUAL_SENSE_BT_HID_FEATURE_ID80 0x80
#define DUAL_SENSE_BT_HID_FEATURE_ID81 0x81
#define DUAL_SENSE_BT_HID_FEATURE_ID82 0x82
#define DUAL_SENSE_BT_HID_FEATURE_ID83 0x83
#define DUAL_SENSE_BT_HID_FEATURE_IDF0 0xF0
#define DUAL_SENSE_BT_HID_FEATURE_IDF1 0xF1
#define DUAL_SENSE_BT_HID_FEATURE_IDF2 0xF2

/* HID input report id */
#define DUAL_SENSE_USB_HID_INPUT_ID01 0x01
/* HID output report id */
#define DUAL_SENSE_USB_HID_OUTPUT_ID02 0x02
/* HID feature report id */
#define DUAL_SENSE_USB_HID_FEATURE_ID05 0x05
#define DUAL_SENSE_USB_HID_FEATURE_ID08 0x08
#define DUAL_SENSE_USB_HID_FEATURE_ID09 0x09
#define DUAL_SENSE_USB_HID_FEATURE_ID0A 0x0A
#define DUAL_SENSE_USB_HID_FEATURE_ID20 0x20
#define DUAL_SENSE_USB_HID_FEATURE_ID21 0x21
#define DUAL_SENSE_USB_HID_FEATURE_ID22 0x22
#define DUAL_SENSE_USB_HID_FEATURE_ID80 0x80
#define DUAL_SENSE_USB_HID_FEATURE_ID81 0x81
#define DUAL_SENSE_USB_HID_FEATURE_ID83 0x83
#define DUAL_SENSE_USB_HID_FEATURE_ID84 0x84
#define DUAL_SENSE_USB_HID_FEATURE_ID85 0x85
#define DUAL_SENSE_USB_HID_FEATURE_IDA0 0xA0
#define DUAL_SENSE_USB_HID_FEATURE_IDE0 0xE0
#define DUAL_SENSE_USB_HID_FEATURE_IDF1 0xF1
#define DUAL_SENSE_USB_HID_FEATURE_IDF2 0xF2
#define DUAL_SENSE_USB_HID_FEATURE_IDF4 0xF4
#define DUAL_SENSE_USB_HID_FEATURE_IDF5 0xF5

/* Device Descriptor: */
#define DUAL_SENSE_USB_DEVICE_DESCRIPTOR                                            \
    0x12,                    /* bLength */                                          \
        0x01,                /* bDescriptorType */                                  \
        U16_TO_BYTE(0x0200), /* bcdUSB */                                           \
        0x00,                /* bDeviceClass */                                     \
        0x00,                /* bDeviceSubClass */                                  \
        0x00,                /* bDeviceProtocol */                                  \
        0x40,                /* bMaxPacketSize0   (64 bytes) */                     \
        U16_TO_BYTE(0x054C), /* idVendor */                                         \
        U16_TO_BYTE(0x0CE6), /* idProduct */                                        \
        U16_TO_BYTE(0x0100), /* bcdDevice */                                        \
        0x01,                /* iManufacturer   "Sony Interactive Entertainment" */ \
        0x02,                /* iProduct        "Wireless Controller" */            \
        0x00,                /* iSerialNumber */                                    \
        0x01                 /* bNumConfigurations */

/* Device Qualifier Descriptor: */
#define DUAL_SENSE_USB_DEVICE_QUALIFIER_DESCRIPTOR              \
    0x0A,                    /* bLength */                      \
        0x06,                /* bDescriptorType */              \
        U16_TO_BYTE(0x0200), /* bcdUSB */                       \
        0x00,                /* bDeviceClass */                 \
        0x00,                /* bDeviceSubClass */              \
        0x00,                /* bDeviceProtocol */              \
        0x40,                /* bMaxPacketSize0   (64 bytes) */ \
        0x01,                /* bNumConfigurations */           \
        0x00                 /* bReserved */

/* Configuration Descriptor: */
#define DUAL_SENSE_USB_CFG0_CONFIGURATION_DESCRIPTOR                    \
    0x09,                    /* bLength */                              \
        0x02,                /* bDescriptorType */                      \
        U16_TO_BYTE(0x00E3), /* wTotalLength   (227 bytes) */           \
        0x04,                /* bNumInterfaces */                       \
        0x01,                /* bConfigurationValue */                  \
        0x00,                /* iConfiguration */                       \
        0xC0,                /* bmAttributes   (Self-powered Device) */ \
        0xFA                 /* bMaxPower      (500 mA) */

/* Interface Descriptor: */
#define DUAL_SENSE_USB_CFG0_ITF0_INTERFACE_DESCRIPTOR                                    \
    0x09,                          /* bLength */                                         \
        0x04,                      /* bDescriptorType */                                 \
        DUAL_SENSE_USB_AC_ITF_NUM, /* bInterfaceNumber */                                \
        0x00,                      /* bAlternateSetting */                               \
        0x00,                      /* bNumEndPoints */                                   \
        0x01,                      /* bInterfaceClass      (Audio Device Class) */       \
        0x01,                      /* bInterfaceSubClass   (Audio Control Interface) */  \
        0x00,                      /* bInterfaceProtocol   (Audio Protocol undefined) */ \
        0x00                       /* iInterface */

/* AC Interface Header Descriptor: */
#define DUAL_SENSE_USB_CFG0_ITF0_AC_DESCRIPTOR                         \
    0x0A,                              /* bLength */                   \
        0x24,                          /* bDescriptorType */           \
        0x01,                          /* bDescriptorSubtype */        \
        U16_TO_BYTE(0x0100),           /* bcdADC */                    \
        U16_TO_BYTE(0x0049),           /* wTotalLength   (73 bytes) */ \
        0x02,                          /* bInCollection */             \
        DUAL_SENSE_USB_AS_OUT_ITF_NUM, /* baInterfaceNr(1) */          \
        DUAL_SENSE_USB_AS_IN_ITF_NUM   /* baInterfaceNr(2) */

/* AC Input Terminal Descriptor: */
#define DUAL_SENSE_USB_CFG0_ITF0_SPK_AC_INPUT_TERMINAL_DESCRIPTOR  \
    0x0C,                    /* bLength */                         \
        0x24,                /* bDescriptorType */                 \
        0x02,                /* bDescriptorSubtype */              \
        0x01,                /* bTerminalID */                     \
        U16_TO_BYTE(0x0101), /* wTerminalType   (USB Streaming) */ \
        0x06,                /* bAssocTerminal */                  \
        0x04,                /* bNrChannels   (4 channels) */      \
        U16_TO_BYTE(0x0033), /* wChannelConfig */                  \
        0x00,                /* iChannelNames */                   \
        0x00                 /* iTerminal */

/* AC Feature Unit Descriptor: */
#define DUAL_SENSE_USB_CFG0_ITF0_SPK_AC_FEATURE_UNIT_DESCRIPTOR \
    0x0C,                  /* bLength */                        \
        0x24,              /* bDescriptorType */                \
        0x06,              /* bDescriptorSubtype */             \
        0x02,              /* bUnitID */                        \
        0x01,              /* bSourceID */                      \
        0x01,              /* bControlSize */                   \
        /* bmaControls: */ /**/                                 \
        0x03,              /* Channel(0) - Mute / Volume */     \
        0x00,              /* Channel(1) */                     \
        0x00,              /* Channel(2) */                     \
        0x00,              /* Channel(3) */                     \
        0x00,              /* Channel(4) */                     \
        0x00               /* iFeature */

/* AC Output Terminal Descriptor: */
#define DUAL_SENSE_USB_CFG0_ITF0_SPK_AC_OUTPUT_TERMINAL_DESCRIPTOR \
    0x09,                    /* bLength */                         \
        0x24,                /* bDescriptorType */                 \
        0x03,                /* bDescriptorSubtype */              \
        0x03,                /* bTerminalID */                     \
        U16_TO_BYTE(0x0301), /* wTerminalType   (Speaker) */       \
        0x04,                /* bAssocTerminal */                  \
        0x02,                /* bSourceID */                       \
        0x00                 /* iTerminal */

/* AC Input Terminal Descriptor: */
#define DUAL_SENSE_USB_CFG0_ITF0_MIC_AC_INPUT_TERMINAL_DESCRIPTOR \
    0x0C,                    /* bLength */                        \
        0x24,                /* bDescriptorType */                \
        0x02,                /* bDescriptorSubtype */             \
        0x04,                /* bTerminalID */                    \
        U16_TO_BYTE(0x0402), /* wTerminalType   (Headset) */      \
        0x03,                /* bAssocTerminal */                 \
        0x02,                /* bNrChannels   (2 channels) */     \
        U16_TO_BYTE(0x0003), /* wChannelConfig */                 \
        0x00,                /* iChannelNames */                  \
        0x00                 /* iTerminal */

/* AC Feature Unit Descriptor: */
#define DUAL_SENSE_USB_CFG0_ITF0_MIC_AC_FEATURE_UNIT_DESCRIPTOR \
    0x09,                  /* bLength */                        \
        0x24,              /* bDescriptorType */                \
        0x06,              /* bDescriptorSubtype */             \
        0x05,              /* bUnitID */                        \
        0x04,              /* bSourceID */                      \
        0x01,              /* bControlSize */                   \
        /* bmaControls: */ /**/                                 \
        0x03,              /* Channel(0) - Mute / Volume */     \
        0x00,              /* Channel(1) */                     \
        0x00               /* iFeature */

/* AC Output Terminal Descriptor: */
#define DUAL_SENSE_USB_CFG0_ITF0_MIC_AC_OUTPUT_TERMINAL_DESCRIPTOR \
    0x09,                    /* bLength */                         \
        0x24,                /* bDescriptorType */                 \
        0x03,                /* bDescriptorSubtype */              \
        0x06,                /* bTerminalID */                     \
        U16_TO_BYTE(0x0101), /* wTerminalType   (USB Streaming) */ \
        0x01,                /* bAssocTerminal */                  \
        0x05,                /* bSourceID */                       \
        0x00                 /* iTerminal */

/* Interface Descriptor: */
#define DUAL_SENSE_USB_CFG0_ITF1_ALT0_INTERFACE_DESCRIPTOR                                    \
    0x09,                              /* bLength */                                          \
        0x04,                          /* bDescriptorType */                                  \
        DUAL_SENSE_USB_AS_OUT_ITF_NUM, /* bInterfaceNumber */                                 \
        0x00,                          /* bAlternateSetting */                                \
        0x00,                          /* bNumEndPoints */                                    \
        0x01,                          /* bInterfaceClass      (Audio Device Class) */        \
        0x02,                          /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,                          /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00                           /* iInterface */

/* Interface Descriptor: */
#define DUAL_SENSE_USB_CFG0_ITF1_ALT1_INTERFACE_DESCRIPTOR                                    \
    0x09,                              /* bLength */                                          \
        0x04,                          /* bDescriptorType */                                  \
        DUAL_SENSE_USB_AS_OUT_ITF_NUM, /* bInterfaceNumber */                                 \
        0x01,                          /* bAlternateSetting */                                \
        0x01,                          /* bNumEndPoints */                                    \
        0x01,                          /* bInterfaceClass      (Audio Device Class) */        \
        0x02,                          /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,                          /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00                           /* iInterface */

/* AS Interface Descriptor: */
#define DUAL_SENSE_USB_CFG0_ITF1_ALT1_AS_DESCRIPTOR  \
    0x07,                   /* bLength */            \
        0x24,               /* bDescriptorType */    \
        0x01,               /* bDescriptorSubtype */ \
        0x01,               /* bTerminalLink */      \
        0x01,               /* bDelay */             \
        U16_TO_BYTE(0x0001) /* wFormatTag   (PCM) */

/* AS Format Type 1 Descriptor: */
#define DUAL_SENSE_USB_CFG0_ITF1_ALT1_AS_FORMAT_DESCRIPTOR                         \
    0x0B,                     /* bLength */                                        \
        0x24,                 /* bDescriptorType */                                \
        0x02,                 /* bDescriptorSubtype */                             \
        0x01,                 /* bFormatType   (FORMAT_TYPE_1) */                  \
        0x04,                 /* bNrChannels   (4 channels) */                     \
        0x02,                 /* bSubframeSize */                                  \
        0x10,                 /* bBitResolution   (16 bits per sample) */          \
        0x01,                 /* bSamFreqType   (Discrete sampling frequencies) */ \
        U24_TO_BYTE(0x00BB80) /* tSamFreq(1)   (48000 Hz) */

/* Endpoint Descriptor (Audio/MIDI 1.0): */
#define DUAL_SENSE_USB_CFG0_ITF1_ALT1_AUDIO_OUT_ENDPOINT_DESCRIPTOR                                          \
    0x09,                    /* bLength */                                                                   \
        0x05,                /* bDescriptorType */                                                           \
        0x01,                /* bEndpointAddress  (OUT endpoint 1) */                                        \
        0x09,                /* bmAttributes      (Transfer: Isochronous / Synch: Adaptive / Usage: Data) */ \
        U16_TO_BYTE(0x0188), /* wMaxPacketSize    (1 x 392 bytes) */                                         \
        0x04,                /* bInterval         (8 microframes) */                                         \
        0x00,                /* bRefresh */                                                                  \
        0x00                 /* bSynchAddress */

/* AS Isochronous Data Endpoint Descriptor: */
#define DUAL_SENSE_USB_CFG0_ITF1_ALT1_AS_ISOCHRONOUS_DATA_ENDPOINT_DESCRIPTOR \
    0x07,                   /* bLength */                                     \
        0x25,               /* bDescriptorType */                             \
        0x01,               /* bDescriptorSubtype */                          \
        0x00,               /* bmAttributes */                                \
        0x00,               /* bLockDelayUnits   (undefined) */               \
        U16_TO_BYTE(0x0000) /* wLockDelay */

/* Interface Descriptor: */
#define DUAL_SENSE_USB_CFG0_ITF2_ALT0_INTERFACE_DESCRIPTOR                                   \
    0x09,                             /* bLength */                                          \
        0x04,                         /* bDescriptorType */                                  \
        DUAL_SENSE_USB_AS_IN_ITF_NUM, /* bInterfaceNumber */                                 \
        0x00,                         /* bAlternateSetting */                                \
        0x00,                         /* bNumEndPoints */                                    \
        0x01,                         /* bInterfaceClass      (Audio Device Class) */        \
        0x02,                         /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,                         /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00                          /* iInterface */

/* Interface Descriptor: */
#define DUAL_SENSE_USB_CFG0_ITF2_ALT1_INTERFACE_DESCRIPTOR                                   \
    0x09,                             /* bLength */                                          \
        0x04,                         /* bDescriptorType */                                  \
        DUAL_SENSE_USB_AS_IN_ITF_NUM, /* bInterfaceNumber */                                 \
        0x01,                         /* bAlternateSetting */                                \
        0x01,                         /* bNumEndPoints */                                    \
        0x01,                         /* bInterfaceClass      (Audio Device Class) */        \
        0x02,                         /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,                         /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00                          /* iInterface */

/* AS Interface Descriptor: */
#define DUAL_SENSE_USB_CFG0_ITF2_ALT1_AS_DESCRIPTOR  \
    0x07,                   /* bLength */            \
        0x24,               /* bDescriptorType */    \
        0x01,               /* bDescriptorSubtype */ \
        0x06,               /* bTerminalLink */      \
        0x01,               /* bDelay */             \
        U16_TO_BYTE(0x0001) /* wFormatTag   (PCM) */

/* AS Format Type 1 Descriptor: */
#define DUAL_SENSE_USB_CFG0_ITF2_ALT1_AS_FORMAT_DESCRIPTOR                         \
    0x0B,                     /* bLength */                                        \
        0x24,                 /* bDescriptorType */                                \
        0x02,                 /* bDescriptorSubtype */                             \
        0x01,                 /* bFormatType   (FORMAT_TYPE_1) */                  \
        0x02,                 /* bNrChannels   (2 channels) */                     \
        0x02,                 /* bSubframeSize */                                  \
        0x10,                 /* bBitResolution   (16 bits per sample) */          \
        0x01,                 /* bSamFreqType   (Discrete sampling frequencies) */ \
        U24_TO_BYTE(0x00BB80) /* tSamFreq(1)   (48000 Hz) */

/* Endpoint Descriptor (Audio/MIDI 1.0): */
#define DUAL_SENSE_USB_CFG0_ITF2_ALT1_AUDIO_IN_ENDPOINT_DESCRIPTOR                                               \
    0x09,                    /* bLength */                                                                       \
        0x05,                /* bDescriptorType */                                                               \
        0x82,                /* bEndpointAddress  (IN endpoint 2) */                                             \
        0x05,                /* bmAttributes      (Transfer: Isochronous / Synch: Asynchronous / Usage: Data) */ \
        U16_TO_BYTE(0x00C4), /* wMaxPacketSize    (1 x 196 bytes) */                                             \
        0x04,                /* bInterval         (8 microframes) */                                             \
        0x00,                /* bRefresh */                                                                      \
        0x00                 /* bSynchAddress */

/* AS Isochronous Data Endpoint Descriptor: */
#define DUAL_SENSE_USB_CFG0_ITF2_ALT1_AS_ISOCHRONOUS_DATA_ENDPOINT_DESCRIPTOR \
    0x07,                   /* bLength */                                     \
        0x25,               /* bDescriptorType */                             \
        0x01,               /* bDescriptorSubtype */                          \
        0x00,               /* bmAttributes */                                \
        0x00,               /* bLockDelayUnits   (undefined) */               \
        U16_TO_BYTE(0x0000) /* wLockDelay */

/* Interface Descriptor: */
#define DUAL_SENSE_USB_CFG0_ITF3_INTERFACE_DESCRIPTOR                                         \
    0x09,                           /* bLength */                                             \
        0x04,                       /* bDescriptorType */                                     \
        DUAL_SENSE_USB_HID_ITF_NUM, /* bInterfaceNumber */                                    \
        0x00,                       /* bAlternateSetting */                                   \
        0x02,                       /* bNumEndPoints */                                       \
        0x03,                       /* bInterfaceClass      (Human Interface Device Class) */ \
        0x00,                       /* bInterfaceSubClass */                                  \
        0x00,                       /* bInterfaceProtocol */                                  \
        0x00                        /* iInterface */

/* HID Descriptor: */
#define DUAL_SENSE_USB_CFG0_ITF3_HID_DESCRIPTOR                          \
    0x09,                    /* bLength */                               \
        0x21,                /* bDescriptorType */                       \
        U16_TO_BYTE(0x0111), /* bcdHID */                                \
        0x00,                /* bCountryCode */                          \
        0x01,                /* bNumDescriptors */                       \
        0x22,                /* bDescriptorType   (Report descriptor) */ \
        U16_TO_BYTE(0x0111)  /* bDescriptorLength */

/* Endpoint Descriptor: */
#define DUAL_SENSE_USB_CFG0_ITF3_IN_ENDPOINT_DESCRIPTOR                                                \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x84,                /* bEndpointAddress  (IN endpoint 4) */                                   \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x06                 /* bInterval         (32 microframes) */

/* Endpoint Descriptor: */
#define DUAL_SENSE_USB_CFG0_ITF3_OUT_ENDPOINT_DESCRIPTOR                                               \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x03,                /* bEndpointAddress  (OUT endpoint 3) */                                  \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x06                 /* bInterval         (32 microframes) */

/* ------------------------------ */
/* Other Speed Configuration Descriptor: */
/* ------------------------------ */

#define DUAL_SENSE_USB_CFG1_CONFIGURATION_DESCRIPTOR                    \
    0x09,                    /* bLength */                              \
        0x07,                /* bDescriptorType */                      \
        U16_TO_BYTE(0x00E3), /* wTotalLength   (227 bytes) */           \
        0x04,                /* bNumInterfaces */                       \
        0x01,                /* bConfigurationValue */                  \
        0x00,                /* iConfiguration */                       \
        0xC0,                /* bmAttributes   (Self-powered Device) */ \
        0xFA                 /* bMaxPower      (500 mA) */

/* Interface Descriptor: */
#define DUAL_SENSE_USB_CFG1_ITF0_INTERFACE_DESCRIPTOR                                    \
    0x09,                          /* bLength */                                         \
        0x04,                      /* bDescriptorType */                                 \
        DUAL_SENSE_USB_AC_ITF_NUM, /* bInterfaceNumber */                                \
        0x00,                      /* bAlternateSetting */                               \
        0x00,                      /* bNumEndPoints */                                   \
        0x01,                      /* bInterfaceClass      (Audio Device Class) */       \
        0x01,                      /* bInterfaceSubClass   (Audio Control Interface) */  \
        0x00,                      /* bInterfaceProtocol   (Audio Protocol undefined) */ \
        0x00                       /* iInterface */

/* AC Interface Header Descriptor: */
#define DUAL_SENSE_USB_CFG1_ITF0_AC_DESCRIPTOR                         \
    0x0A,                              /* bLength */                   \
        0x24,                          /* bDescriptorType */           \
        0x01,                          /* bDescriptorSubtype */        \
        U16_TO_BYTE(0x0100),           /* bcdADC */                    \
        U16_TO_BYTE(0x0049),           /* wTotalLength   (73 bytes) */ \
        0x02,                          /* bInCollection */             \
        DUAL_SENSE_USB_AS_OUT_ITF_NUM, /* baInterfaceNr(1) */          \
        DUAL_SENSE_USB_AS_IN_ITF_NUM   /* baInterfaceNr(2) */

/* AC Input Terminal Descriptor: */
#define DUAL_SENSE_USB_CFG1_ITF0_SPK_AC_INPUT_TERMINAL_DESCRIPTOR  \
    0x0C,                    /* bLength */                         \
        0x24,                /* bDescriptorType */                 \
        0x02,                /* bDescriptorSubtype */              \
        0x01,                /* bTerminalID */                     \
        U16_TO_BYTE(0x0101), /* wTerminalType   (USB Streaming) */ \
        0x06,                /* bAssocTerminal */                  \
        0x04,                /* bNrChannels   (4 channels) */      \
        U16_TO_BYTE(0x0033), /* wChannelConfig */                  \
        0x00,                /* iChannelNames */                   \
        0x00                 /* iTerminal */

/* AC Feature Unit Descriptor: */
#define DUAL_SENSE_USB_CFG1_ITF0_SPK_AC_FEATURE_UNIT_DESCRIPTOR \
    0x0C,                  /* bLength */                        \
        0x24,              /* bDescriptorType */                \
        0x06,              /* bDescriptorSubtype */             \
        0x02,              /* bUnitID */                        \
        0x01,              /* bSourceID */                      \
        0x01,              /* bControlSize */                   \
        /* bmaControls: */ /**/                                 \
        0x03,              /* Channel(0) - Mute / Volume */     \
        0x00,              /* Channel(1) */                     \
        0x00,              /* Channel(2) */                     \
        0x00,              /* Channel(3) */                     \
        0x00,              /* Channel(4) */                     \
        0x00               /* iFeature */

/* AC Output Terminal Descriptor: */
#define DUAL_SENSE_USB_CFG1_ITF0_SPK_AC_OUTPUT_TERMINAL_DESCRIPTOR \
    0x09,                    /* bLength */                         \
        0x24,                /* bDescriptorType */                 \
        0x03,                /* bDescriptorSubtype */              \
        0x03,                /* bTerminalID */                     \
        U16_TO_BYTE(0x0301), /* wTerminalType   (Speaker) */       \
        0x04,                /* bAssocTerminal */                  \
        0x02,                /* bSourceID */                       \
        0x00                 /* iTerminal */

/* AC Input Terminal Descriptor: */
#define DUAL_SENSE_USB_CFG1_ITF0_MIC_AC_INPUT_TERMINAL_DESCRIPTOR \
    0x0C,                    /* bLength */                        \
        0x24,                /* bDescriptorType */                \
        0x02,                /* bDescriptorSubtype */             \
        0x04,                /* bTerminalID */                    \
        U16_TO_BYTE(0x0402), /* wTerminalType   (Headset) */      \
        0x03,                /* bAssocTerminal */                 \
        0x01,                /* bNrChannels   (1 channels) */     \
        U16_TO_BYTE(0x0000), /* wChannelConfig */                 \
        0x00,                /* iChannelNames */                  \
        0x00                 /* iTerminal */

/* AC Feature Unit Descriptor: */
#define DUAL_SENSE_USB_CFG1_ITF0_MIC_AC_FEATURE_UNIT_DESCRIPTOR \
    0x09,                  /* bLength */                        \
        0x24,              /* bDescriptorType */                \
        0x06,              /* bDescriptorSubtype */             \
        0x05,              /* bUnitID */                        \
        0x04,              /* bSourceID */                      \
        0x01,              /* bControlSize */                   \
        /* bmaControls: */ /**/                                 \
        0x03,              /* Channel(0) - Mute / Volume */     \
        0x00,              /* Channel(1) */                     \
        0x00               /* iFeature */

/* AC Output Terminal Descriptor: */
#define DUAL_SENSE_USB_CFG1_ITF0_MIC_AC_OUTPUT_TERMINAL_DESCRIPTOR \
    0x09,                    /* bLength */                         \
        0x24,                /* bDescriptorType */                 \
        0x03,                /* bDescriptorSubtype */              \
        0x06,                /* bTerminalID */                     \
        U16_TO_BYTE(0x0101), /* wTerminalType   (USB Streaming) */ \
        0x01,                /* bAssocTerminal */                  \
        0x05,                /* bSourceID */                       \
        0x00                 /* iTerminal */

/* Interface Descriptor: */
#define DUAL_SENSE_USB_CFG1_ITF1_ALT0_INTERFACE_DESCRIPTOR                                    \
    0x09,                              /* bLength */                                          \
        0x04,                          /* bDescriptorType */                                  \
        DUAL_SENSE_USB_AS_OUT_ITF_NUM, /* bInterfaceNumber */                                 \
        0x00,                          /* bAlternateSetting */                                \
        0x00,                          /* bNumEndPoints */                                    \
        0x01,                          /* bInterfaceClass      (Audio Device Class) */        \
        0x02,                          /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,                          /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00                           /* iInterface */

/* Interface Descriptor: */
#define DUAL_SENSE_USB_CFG1_ITF1_ALT1_INTERFACE_DESCRIPTOR                                    \
    0x09,                              /* bLength */                                          \
        0x04,                          /* bDescriptorType */                                  \
        DUAL_SENSE_USB_AS_OUT_ITF_NUM, /* bInterfaceNumber */                                 \
        0x01,                          /* bAlternateSetting */                                \
        0x01,                          /* bNumEndPoints */                                    \
        0x01,                          /* bInterfaceClass      (Audio Device Class) */        \
        0x02,                          /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,                          /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00                           /* iInterface */

/* AS Interface Descriptor: */
#define DUAL_SENSE_USB_CFG1_ITF1_ALT1_AS_DESCRIPTOR  \
    0x07,                   /* bLength */            \
        0x24,               /* bDescriptorType */    \
        0x01,               /* bDescriptorSubtype */ \
        0x01,               /* bTerminalLink */      \
        0x01,               /* bDelay */             \
        U16_TO_BYTE(0x0001) /* wFormatTag   (PCM) */

/* AS Format Type 1 Descriptor: */
#define DUAL_SENSE_USB_CFG1_ITF1_ALT1_AS_FORMAT_DESCRIPTOR                         \
    0x0B,                     /* bLength */                                        \
        0x24,                 /* bDescriptorType */                                \
        0x02,                 /* bDescriptorSubtype */                             \
        0x01,                 /* bFormatType   (FORMAT_TYPE_1) */                  \
        0x04,                 /* bNrChannels   (4 channels) */                     \
        0x02,                 /* bSubframeSize */                                  \
        0x10,                 /* bBitResolution   (16 bits per sample) */          \
        0x01,                 /* bSamFreqType   (Discrete sampling frequencies) */ \
        U24_TO_BYTE(0x00BB80) /* tSamFreq(1)   (48000 Hz) */

/* Endpoint Descriptor (Audio/MIDI 1.0): */
#define DUAL_SENSE_USB_CFG1_ITF1_ALT1_AUDIO_OUT_ENDPOINT_DESCRIPTOR                                          \
    0x09,                    /* bLength */                                                                   \
        0x05,                /* bDescriptorType */                                                           \
        0x01,                /* bEndpointAddress  (OUT endpoint 1) */                                        \
        0x09,                /* bmAttributes      (Transfer: Isochronous / Synch: Adaptive / Usage: Data) */ \
        U16_TO_BYTE(0x0188), /* wMaxPacketSize    (1 x 392 bytes) */                                         \
        0x01,                /* bInterval         (1 frames) */                                              \
        0x00,                /* bRefresh */                                                                  \
        0x00                 /* bSynchAddress */

/* AS Isochronous Data Endpoint Descriptor: */
#define DUAL_SENSE_USB_CFG1_ITF1_ALT1_AS_ISOCHRONOUS_DATA_ENDPOINT_DESCRIPTOR \
    0x07,                   /* bLength */                                     \
        0x25,               /* bDescriptorType */                             \
        0x01,               /* bDescriptorSubtype */                          \
        0x01,               /* bmAttributes   (Sampling Frequency) */         \
        0x00,               /* bLockDelayUnits   (undefined) */               \
        U16_TO_BYTE(0x0000) /* wLockDelay */

/* Interface Descriptor: */
#define DUAL_SENSE_USB_CFG1_ITF2_ALT0_INTERFACE_DESCRIPTOR                                   \
    0x09,                             /* bLength */                                          \
        0x04,                         /* bDescriptorType */                                  \
        DUAL_SENSE_USB_AS_IN_ITF_NUM, /* bInterfaceNumber */                                 \
        0x00,                         /* bAlternateSetting */                                \
        0x00,                         /* bNumEndPoints */                                    \
        0x01,                         /* bInterfaceClass      (Audio Device Class) */        \
        0x02,                         /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,                         /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00                          /* iInterface */

/* Interface Descriptor: */
#define DUAL_SENSE_USB_CFG1_ITF2_ALT1_INTERFACE_DESCRIPTOR                                   \
    0x09,                             /* bLength */                                          \
        0x04,                         /* bDescriptorType */                                  \
        DUAL_SENSE_USB_AS_IN_ITF_NUM, /* bInterfaceNumber */                                 \
        0x01,                         /* bAlternateSetting */                                \
        0x01,                         /* bNumEndPoints */                                    \
        0x01,                         /* bInterfaceClass      (Audio Device Class) */        \
        0x02,                         /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,                         /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00                          /* iInterface */

/* AS Interface Descriptor: */
#define DUAL_SENSE_USB_CFG1_ITF2_ALT1_AS_DESCRIPTOR  \
    0x07,                   /* bLength */            \
        0x24,               /* bDescriptorType */    \
        0x01,               /* bDescriptorSubtype */ \
        0x06,               /* bTerminalLink */      \
        0x01,               /* bDelay */             \
        U16_TO_BYTE(0x0001) /* wFormatTag   (PCM) */

/* AS Format Type 1 Descriptor: */
#define DUAL_SENSE_USB_CFG1_ITF2_ALT1_AS_FORMAT_DESCRIPTOR                         \
    0x0B,                     /* bLength */                                        \
        0x24,                 /* bDescriptorType */                                \
        0x02,                 /* bDescriptorSubtype */                             \
        0x01,                 /* bFormatType   (FORMAT_TYPE_1) */                  \
        0x02,                 /* bNrChannels   (2 channels) */                     \
        0x02,                 /* bSubframeSize */                                  \
        0x10,                 /* bBitResolution   (16 bits per sample) */          \
        0x01,                 /* bSamFreqType   (Discrete sampling frequencies) */ \
        U24_TO_BYTE(0x00BB80) /* tSamFreq(1)   (48000 Hz) */

/* Endpoint Descriptor (Audio/MIDI 1.0): */
#define DUAL_SENSE_USB_CFG1_ITF2_ALT1_AUDIO_IN_ENDPOINT_DESCRIPTOR                                               \
    0x09,                    /* bLength */                                                                       \
        0x05,                /* bDescriptorType */                                                               \
        0x82,                /* bEndpointAddress  (IN endpoint 2) */                                             \
        0x05,                /* bmAttributes      (Transfer: Isochronous / Synch: Asynchronous / Usage: Data) */ \
        U16_TO_BYTE(0x00C4), /* wMaxPacketSize    (1 x 196 bytes) */                                             \
        0x01,                /* bInterval         (1 frames) */                                                  \
        0x00,                /* bRefresh */                                                                      \
        0x00                 /* bSynchAddress */

/* AS Isochronous Data Endpoint Descriptor: */
#define DUAL_SENSE_USB_CFG1_ITF2_ALT1_AS_ISOCHRONOUS_DATA_ENDPOINT_DESCRIPTOR \
    0x07,                   /* bLength */                                     \
        0x25,               /* bDescriptorType */                             \
        0x01,               /* bDescriptorSubtype */                          \
        0x00,               /* bmAttributes */                                \
        0x00,               /* bLockDelayUnits   (undefined) */               \
        U16_TO_BYTE(0x0000) /* wLockDelay */

/* Interface Descriptor: */
#define DUAL_SENSE_USB_CFG1_ITF3_INTERFACE_DESCRIPTOR                                         \
    0x09,                           /* bLength */                                             \
        0x04,                       /* bDescriptorType */                                     \
        DUAL_SENSE_USB_HID_ITF_NUM, /* bInterfaceNumber */                                    \
        0x00,                       /* bAlternateSetting */                                   \
        0x02,                       /* bNumEndPoints */                                       \
        0x03,                       /* bInterfaceClass      (Human Interface Device Class) */ \
        0x00,                       /* bInterfaceSubClass */                                  \
        0x00,                       /* bInterfaceProtocol */                                  \
        0x00                        /* iInterface */

/* HID Descriptor: */
#define DUAL_SENSE_USB_CFG1_ITF3_HID_DESCRIPTOR                          \
    0x09,                    /* bLength */                               \
        0x21,                /* bDescriptorType */                       \
        U16_TO_BYTE(0x0111), /* bcdHID */                                \
        0x00,                /* bCountryCode */                          \
        0x01,                /* bNumDescriptors */                       \
        0x22,                /* bDescriptorType   (Report descriptor) */ \
        U16_TO_BYTE(0x0111)  /* bDescriptorLength */

/* Endpoint Descriptor: */
#define DUAL_SENSE_USB_CFG1_ITF3_IN_ENDPOINT_DESCRIPTOR                                                \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x84,                /* bEndpointAddress  (IN endpoint 4) */                                   \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x06                 /* bInterval         (6 frames) */

/* Endpoint Descriptor: */
#define DUAL_SENSE_USB_CFG1_ITF3_OUT_ENDPOINT_DESCRIPTOR                                               \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x03,                /* bEndpointAddress  (OUT endpoint 3) */                                  \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x06                 /* bInterval         (6 frames) */

/* String Descriptor Table */
#define DUAL_SENSE_USB_STRING_DESCRIPTOR_0 (const char[]){0x09, 0x04}
#define DUAL_SENSE_USB_STRING_MANUFACTURER "Sony Interactive Entertainment"
#define DUAL_SENSE_USB_STRING_PRODUCT "Wireless Controller"

#define DUAL_SENSE_BT_HID_REPORT_DESCRIPTOR                                                                           \
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
        0x06, 0x00, 0xFF, /*   Usage Page (Vendor Defined 0xFF00) */                                                  \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x26, 0xFF, 0x00, /*   Logical Maximum (255) */                                                               \
        0x75, 0x08,       /*   Report Size (8) */                                                                     \
        0x95, 0x4D,       /*   Report Count (77) */                                                                   \
        0x85, 0x31,       /*   Report ID (49) */                                                                      \
        0x09, 0x31,       /*   Usage (0x31) */                                                                        \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x09, 0x3B,       /*   Usage (0x3B) */                                                                        \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x85, 0x32,       /*   Report ID (50) */                                                                      \
        0x09, 0x32,       /*   Usage (0x32) */                                                                        \
        0x95, 0x8D,       /*   Report Count (141) */                                                                  \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x85, 0x33,       /*   Report ID (51) */                                                                      \
        0x09, 0x33,       /*   Usage (0x33) */                                                                        \
        0x95, 0xCD,       /*   Report Count (205) */                                                                  \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x85, 0x34,       /*   Report ID (52) */                                                                      \
        0x09, 0x34,       /*   Usage (0x34) */                                                                        \
        0x96, 0x0D, 0x01, /*   Report Count (269) */                                                                  \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x85, 0x35,       /*   Report ID (53) */                                                                      \
        0x09, 0x35,       /*   Usage (0x35) */                                                                        \
        0x96, 0x4D, 0x01, /*   Report Count (333) */                                                                  \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x85, 0x36,       /*   Report ID (54) */                                                                      \
        0x09, 0x36,       /*   Usage (0x36) */                                                                        \
        0x96, 0x8D, 0x01, /*   Report Count (397) */                                                                  \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x85, 0x37,       /*   Report ID (55) */                                                                      \
        0x09, 0x37,       /*   Usage (0x37) */                                                                        \
        0x96, 0xCD, 0x01, /*   Report Count (461) */                                                                  \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x85, 0x38,       /*   Report ID (56) */                                                                      \
        0x09, 0x38,       /*   Usage (0x38) */                                                                        \
        0x96, 0x0D, 0x02, /*   Report Count (525) */                                                                  \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x85, 0x39,       /*   Report ID (57) */                                                                      \
        0x09, 0x39,       /*   Usage (0x39) */                                                                        \
        0x96, 0x22, 0x02, /*   Report Count (546) */                                                                  \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x06, 0x80, 0xFF, /*   Usage Page (Vendor Defined 0xFF80) */                                                  \
        0x85, 0x05,       /*   Report ID (5) */                                                                       \
        0x09, 0x33,       /*   Usage (0x33) */                                                                        \
        0x95, 0x28,       /*   Report Count (40) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x08,       /*   Report ID (8) */                                                                       \
        0x09, 0x34,       /*   Usage (0x34) */                                                                        \
        0x95, 0x2F,       /*   Report Count (47) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x09,       /*   Report ID (9) */                                                                       \
        0x09, 0x24,       /*   Usage (0x24) */                                                                        \
        0x95, 0x13,       /*   Report Count (19) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x20,       /*   Report ID (32) */                                                                      \
        0x09, 0x26,       /*   Usage (0x26) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x22,       /*   Report ID (34) */                                                                      \
        0x09, 0x40,       /*   Usage (0x40) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x80,       /*   Report ID (128) */                                                                     \
        0x09, 0x28,       /*   Usage (0x28) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x81,       /*   Report ID (129) */                                                                     \
        0x09, 0x29,       /*   Usage (0x29) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x82,       /*   Report ID (130) */                                                                     \
        0x09, 0x2A,       /*   Usage (0x2A) */                                                                        \
        0x95, 0x09,       /*   Report Count (9) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x83,       /*   Report ID (131) */                                                                     \
        0x09, 0x2B,       /*   Usage (0x2B) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xF1,       /*   Report ID (241) */                                                                     \
        0x09, 0x31,       /*   Usage (0x31) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xF2,       /*   Report ID (242) */                                                                     \
        0x09, 0x32,       /*   Usage (0x32) */                                                                        \
        0x95, 0x0F,       /*   Report Count (15) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xF0,       /*   Report ID (240) */                                                                     \
        0x09, 0x30,       /*   Usage (0x30) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0xC0              /* End Collection */
// 279 bytes

#define DUAL_SENSE_USB_HID_REPORT_DESCRIPTOR                                                                          \
    0x05, 0x01,           /* Usage Page (Generic Desktop Ctrls) */                                                    \
        0x09, 0x05,       /* Usage (Game Pad) */                                                                      \
        0xA1, 0x01,       /* Collection (Application) */                                                              \
        0x85, 0x01,       /*   Report ID (1) */                                                                       \
        0x09, 0x30,       /*   Usage (X) */                                                                           \
        0x09, 0x31,       /*   Usage (Y) */                                                                           \
        0x09, 0x32,       /*   Usage (Z) */                                                                           \
        0x09, 0x35,       /*   Usage (Rz) */                                                                          \
        0x09, 0x33,       /*   Usage (Rx) */                                                                          \
        0x09, 0x34,       /*   Usage (Ry) */                                                                          \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x26, 0xFF, 0x00, /*   Logical Maximum (255) */                                                               \
        0x75, 0x08,       /*   Report Size (8) */                                                                     \
        0x95, 0x06,       /*   Report Count (6) */                                                                    \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x06, 0x00, 0xFF, /*   Usage Page (Vendor Defined 0xFF00) */                                                  \
        0x09, 0x20,       /*   Usage (0x20) */                                                                        \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x05, 0x01,       /*   Usage Page (Generic Desktop Ctrls) */                                                  \
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
        0x29, 0x0F,       /*   Usage Maximum (0x0F) */                                                                \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x25, 0x01,       /*   Logical Maximum (1) */                                                                 \
        0x75, 0x01,       /*   Report Size (1) */                                                                     \
        0x95, 0x0F,       /*   Report Count (15) */                                                                   \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x06, 0x00, 0xFF, /*   Usage Page (Vendor Defined 0xFF00) */                                                  \
        0x09, 0x21,       /*   Usage (0x21) */                                                                        \
        0x95, 0x0D,       /*   Report Count (13) */                                                                   \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x06, 0x00, 0xFF, /*   Usage Page (Vendor Defined 0xFF00) */                                                  \
        0x09, 0x22,       /*   Usage (0x22) */                                                                        \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x26, 0xFF, 0x00, /*   Logical Maximum (255) */                                                               \
        0x75, 0x08,       /*   Report Size (8) */                                                                     \
        0x95, 0x34,       /*   Report Count (52) */                                                                   \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x85, 0x02,       /*   Report ID (2) */                                                                       \
        0x09, 0x23,       /*   Usage (0x23) */                                                                        \
        0x95, 0x2F,       /*   Report Count (47) */                                                                   \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x85, 0x05,       /*   Report ID (5) */                                                                       \
        0x09, 0x33,       /*   Usage (0x33) */                                                                        \
        0x95, 0x28,       /*   Report Count (40) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x08,       /*   Report ID (8) */                                                                       \
        0x09, 0x34,       /*   Usage (0x34) */                                                                        \
        0x95, 0x2F,       /*   Report Count (47) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x09,       /*   Report ID (9) */                                                                       \
        0x09, 0x24,       /*   Usage (0x24) */                                                                        \
        0x95, 0x13,       /*   Report Count (19) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x0A,       /*   Report ID (10) */                                                                      \
        0x09, 0x25,       /*   Usage (0x25) */                                                                        \
        0x95, 0x1A,       /*   Report Count (26) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x20,       /*   Report ID (32) */                                                                      \
        0x09, 0x26,       /*   Usage (0x26) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x21,       /*   Report ID (33) */                                                                      \
        0x09, 0x27,       /*   Usage (0x27) */                                                                        \
        0x95, 0x04,       /*   Report Count (4) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x22,       /*   Report ID (34) */                                                                      \
        0x09, 0x40,       /*   Usage (0x40) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x80,       /*   Report ID (128) */                                                                     \
        0x09, 0x28,       /*   Usage (0x28) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x81,       /*   Report ID (129) */                                                                     \
        0x09, 0x29,       /*   Usage (0x29) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x82,       /*   Report ID (130) */                                                                     \
        0x09, 0x2A,       /*   Usage (0x2A) */                                                                        \
        0x95, 0x09,       /*   Report Count (9) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x83,       /*   Report ID (131) */                                                                     \
        0x09, 0x2B,       /*   Usage (0x2B) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x84,       /*   Report ID (132) */                                                                     \
        0x09, 0x2C,       /*   Usage (0x2C) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0x85,       /*   Report ID (133) */                                                                     \
        0x09, 0x2D,       /*   Usage (0x2D) */                                                                        \
        0x95, 0x02,       /*   Report Count (2) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xA0,       /*   Report ID (160) */                                                                     \
        0x09, 0x2E,       /*   Usage (0x2E) */                                                                        \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xE0,       /*   Report ID (224) */                                                                     \
        0x09, 0x2F,       /*   Usage (0x2F) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xF0,       /*   Report ID (240) */                                                                     \
        0x09, 0x30,       /*   Usage (0x30) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xF1,       /*   Report ID (241) */                                                                     \
        0x09, 0x31,       /*   Usage (0x31) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xF2,       /*   Report ID (242) */                                                                     \
        0x09, 0x32,       /*   Usage (0x32) */                                                                        \
        0x95, 0x0F,       /*   Report Count (15) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xF4,       /*   Report ID (244) */                                                                     \
        0x09, 0x35,       /*   Usage (0x35) */                                                                        \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x85, 0xF5,       /*   Report ID (245) */                                                                     \
        0x09, 0x36,       /*   Usage (0x36) */                                                                        \
        0x95, 0x03,       /*   Report Count (3) */                                                                    \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0xC0              /* End Collection */
// 273 bytes
