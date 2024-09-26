#ifndef DUAL_SENSE_H
#define DUAL_SENSE_H

#pragma once

#include <stdint.h>
#include "util.h"

#pragma pack(push, 1)

/* HID input report id */
#define DUAL_SENSE_BT_REPORT_INPUT_ID01 0x01
/* HID output report id */
#define DUAL_SENSE_BT_REPORT_OUTPUT_ID31 0x31
#define DUAL_SENSE_BT_REPORT_OUTPUT_ID32 0x32
#define DUAL_SENSE_BT_REPORT_OUTPUT_ID33 0x33
#define DUAL_SENSE_BT_REPORT_OUTPUT_ID34 0x34
#define DUAL_SENSE_BT_REPORT_OUTPUT_ID35 0x35
#define DUAL_SENSE_BT_REPORT_OUTPUT_ID36 0x36
#define DUAL_SENSE_BT_REPORT_OUTPUT_ID37 0x37
#define DUAL_SENSE_BT_REPORT_OUTPUT_ID38 0x38
#define DUAL_SENSE_BT_REPORT_OUTPUT_ID39 0x39
/* HID feature report id */
#define DUAL_SENSE_BT_REPORT_FEATURE_ID05 0x05
#define DUAL_SENSE_BT_REPORT_FEATURE_ID08 0x08
#define DUAL_SENSE_BT_REPORT_FEATURE_ID09 0x09
#define DUAL_SENSE_BT_REPORT_FEATURE_ID20 0x20
#define DUAL_SENSE_BT_REPORT_FEATURE_ID22 0x22
#define DUAL_SENSE_BT_REPORT_FEATURE_ID80 0x80
#define DUAL_SENSE_BT_REPORT_FEATURE_ID81 0x81
#define DUAL_SENSE_BT_REPORT_FEATURE_ID82 0x82
#define DUAL_SENSE_BT_REPORT_FEATURE_ID83 0x83
#define DUAL_SENSE_BT_REPORT_FEATURE_IDF0 0xF0
#define DUAL_SENSE_BT_REPORT_FEATURE_IDF1 0xF1
#define DUAL_SENSE_BT_REPORT_FEATURE_IDF2 0xF2

/* HID input report id */
#define DUAL_SENSE_USB_REPORT_INPUT_ID01 0x01
/* HID output report id */
#define DUAL_SENSE_USB_REPORT_OUTPUT_ID02 0x02
/* HID feature report id */
#define DUAL_SENSE_USB_REPORT_FEATURE_ID05 0x05
#define DUAL_SENSE_USB_REPORT_FEATURE_ID08 0x08
#define DUAL_SENSE_USB_REPORT_FEATURE_ID09 0x09
#define DUAL_SENSE_USB_REPORT_FEATURE_ID0A 0x0A
#define DUAL_SENSE_USB_REPORT_FEATURE_ID20 0x20
#define DUAL_SENSE_USB_REPORT_FEATURE_ID21 0x21
#define DUAL_SENSE_USB_REPORT_FEATURE_ID22 0x22
#define DUAL_SENSE_USB_REPORT_FEATURE_ID80 0x80
#define DUAL_SENSE_USB_REPORT_FEATURE_ID81 0x81
#define DUAL_SENSE_USB_REPORT_FEATURE_ID83 0x83
#define DUAL_SENSE_USB_REPORT_FEATURE_ID84 0x84
#define DUAL_SENSE_USB_REPORT_FEATURE_ID85 0x85
#define DUAL_SENSE_USB_REPORT_FEATURE_IDA0 0xA0
#define DUAL_SENSE_USB_REPORT_FEATURE_IDE0 0xE0
#define DUAL_SENSE_USB_REPORT_FEATURE_IDF1 0xF1
#define DUAL_SENSE_USB_REPORT_FEATURE_IDF2 0xF2
#define DUAL_SENSE_USB_REPORT_FEATURE_IDF4 0xF4
#define DUAL_SENSE_USB_REPORT_FEATURE_IDF5 0xF5

#define DUAL_SENSE_ITF_0 0
#define DUAL_SENSE_ITF_1 1
#define DUAL_SENSE_ITF_2 2
#define DUAL_SENSE_ITF_HID 0

/* Device Descriptor: */
#define DUAL_SENSE_DEVICE_DESCRIPTOR                                   \
    0x12,       /* bLength */                                          \
        0x01,   /* bDescriptorType */                                  \
        0x0200, /* bcdUSB */                                           \
        0x00,   /* bDeviceClass */                                     \
        0x00,   /* bDeviceSubClass */                                  \
        0x00,   /* bDeviceProtocol */                                  \
        0x40,   /* bMaxPacketSize0   (64 bytes) */                     \
        0x054C, /* idVendor */                                         \
        0x0CE6, /* idProduct */                                        \
        0x0100, /* bcdDevice */                                        \
        0x01,   /* iManufacturer   "Sony Interactive Entertainment" */ \
        0x02,   /* iProduct        "Wireless Controller" */            \
        0x00,   /* iSerialNumber */                                    \
        0x01    /* bNumConfigurations */

/* Device Qualifier Descriptor: */
#define DUAL_SENSE_DEVICE_QUALIFIER_DESCRIPTOR                  \
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
#define DUAL_SENSE_CONFIGURATION_DESCRIPTOR                             \
    0x09,                    /* bLength */                              \
        0x02,                /* bDescriptorType */                      \
        U16_TO_BYTE(0x00E3), /* wTotalLength   (227 bytes) */           \
        0x04,                /* bNumInterfaces */                       \
        0x01,                /* bConfigurationValue */                  \
        0x00,                /* iConfiguration */                       \
        0xC0,                /* bmAttributes   (Self-powered Device) */ \
        0xFA                 /* bMaxPower      (500 mA) */

/* Interface Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                                   \
    0x09,                 /* bLength */                                         \
        0x04,             /* bDescriptorType */                                 \
        DUAL_SENSE_ITF_0, /* bInterfaceNumber */                                \
        0x00,             /* bAlternateSetting */                               \
        0x00,             /* bNumEndPoints */                                   \
        0x01,             /* bInterfaceClass      (Audio Device Class) */       \
        0x01,             /* bInterfaceSubClass   (Audio Control Interface) */  \
        0x00,             /* bInterfaceProtocol   (Audio Protocol undefined) */ \
        0x00              /* iInterface */

/* AC Interface Header Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                \
    0x0A,                    /* bLength */                   \
        0x24,                /* bDescriptorType */           \
        0x01,                /* bDescriptorSubtype */        \
        U16_TO_BYTE(0x0100), /* bcdADC */                    \
        U16_TO_BYTE(0x0049), /* wTotalLength   (73 bytes) */ \
        0x02,                /* bInCollection */             \
        0x01,                /* baInterfaceNr(1) */          \
        0x02                 /* baInterfaceNr(2) */

/* AC Input Terminal Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                      \
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
#define DUAL_SENSE_DESCRIPTOR                                     \
    0x0C,                        /* bLength */                    \
        0x24,                    /* bDescriptorType */            \
        0x06,                    /* bDescriptorSubtype */         \
        0x02,                    /* bUnitID */                    \
        0x01,                    /* bSourceID */                  \
        0x01,                    /* bControlSize */               \
        /* bmaControls: */ 0x03, /* Channel(0) - Mute / Volume */ \
        0x00,                    /* Channel(1) */                 \
        0x00,                    /* Channel(2) */                 \
        0x00,                    /* Channel(3) */                 \
        0x00,                    /* Channel(4) */                 \
        0x00                     /* iFeature */

/* AC Output Terminal Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                \
    0x09,                    /* bLength */                   \
        0x24,                /* bDescriptorType */           \
        0x03,                /* bDescriptorSubtype */        \
        0x03,                /* bTerminalID */               \
        U16_TO_BYTE(0x0301), /* wTerminalType   (Speaker) */ \
        0x04,                /* bAssocTerminal */            \
        0x02,                /* bSourceID */                 \
        0x00                 /* iTerminal */

/* AC Input Terminal Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                 \
    0x0C,                    /* bLength */                    \
        0x24,                /* bDescriptorType */            \
        0x02,                /* bDescriptorSubtype */         \
        0x04,                /* bTerminalID */                \
        U16_TO_BYTE(0x0402), /* wTerminalType   (Headset) */  \
        0x03,                /* bAssocTerminal */             \
        0x02,                /* bNrChannels   (2 channels) */ \
        U16_TO_BYTE(0x0003), /* wChannelConfig */             \
        0x00,                /* iChannelNames */              \
        0x00                 /* iTerminal */

/* AC Feature Unit Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                     \
    0x09,                        /* bLength */                    \
        0x24,                    /* bDescriptorType */            \
        0x06,                    /* bDescriptorSubtype */         \
        0x05,                    /* bUnitID */                    \
        0x04,                    /* bSourceID */                  \
        0x01,                    /* bControlSize */               \
        /* bmaControls: */ 0x03, /* Channel(0) - Mute / Volume */ \
        0x00,                    /* Channel(1) */                 \
        0x00                     /* iFeature */

/* AC Output Terminal Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                      \
    0x09,                    /* bLength */                         \
        0x24,                /* bDescriptorType */                 \
        0x03,                /* bDescriptorSubtype */              \
        0x06,                /* bTerminalID */                     \
        U16_TO_BYTE(0x0101), /* wTerminalType   (USB Streaming) */ \
        0x01,                /* bAssocTerminal */                  \
        0x05,                /* bSourceID */                       \
        0x00                 /* iTerminal */

/* Interface Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                                    \
    0x09,                 /* bLength */                                          \
        0x04,             /* bDescriptorType */                                  \
        DUAL_SENSE_ITF_1, /* bInterfaceNumber */                                 \
        0x00,             /* bAlternateSetting */                                \
        0x00,             /* bNumEndPoints */                                    \
        0x01,             /* bInterfaceClass      (Audio Device Class) */        \
        0x02,             /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,             /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00              /* iInterface */

/* Interface Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                                    \
    0x09,                 /* bLength */                                          \
        0x04,             /* bDescriptorType */                                  \
        DUAL_SENSE_ITF_1, /* bInterfaceNumber */                                 \
        0x01,             /* bAlternateSetting */                                \
        0x01,             /* bNumEndPoints */                                    \
        0x01,             /* bInterfaceClass      (Audio Device Class) */        \
        0x02,             /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,             /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00              /* iInterface */

/* AS Interface Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                        \
    0x07,                   /* bLength */            \
        0x24,               /* bDescriptorType */    \
        0x01,               /* bDescriptorSubtype */ \
        0x01,               /* bTerminalLink */      \
        0x01,               /* bDelay */             \
        U16_TO_BYTE(0x0001) /* wFormatTag   (PCM) */

/* AS Format Type 1 Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                                      \
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
#define DUAL_SENSE_DESCRIPTOR                                                                                \
    0x09,                    /* bLength */                                                                   \
        0x05,                /* bDescriptorType */                                                           \
        0x01,                /* bEndpointAddress  (OUT endpoint 1) */                                        \
        0x09,                /* bmAttributes      (Transfer: Isochronous / Synch: Adaptive / Usage: Data) */ \
        U16_TO_BYTE(0x0188), /* wMaxPacketSize    (1 x 392 bytes) */                                         \
        0x04,                /* bInterval         (8 microframes) */                                         \
        0x00,                /* bRefresh */                                                                  \
        0x00                 /* bSynchAddress */

/* AS Isochronous Data Endpoint Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                   \
    0x07,                   /* bLength */                       \
        0x25,               /* bDescriptorType */               \
        0x01,               /* bDescriptorSubtype */            \
        0x00,               /* bmAttributes */                  \
        0x00,               /* bLockDelayUnits   (undefined) */ \
        U16_TO_BYTE(0x0000) /* wLockDelay */

/* Interface Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                                    \
    0x09,                 /* bLength */                                          \
        0x04,             /* bDescriptorType */                                  \
        DUAL_SENSE_ITF_2, /* bInterfaceNumber */                                 \
        0x00,             /* bAlternateSetting */                                \
        0x00,             /* bNumEndPoints */                                    \
        0x01,             /* bInterfaceClass      (Audio Device Class) */        \
        0x02,             /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,             /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00              /* iInterface */

/* Interface Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                                    \
    0x09,                 /* bLength */                                          \
        0x04,             /* bDescriptorType */                                  \
        DUAL_SENSE_ITF_2, /* bInterfaceNumber */                                 \
        0x01,             /* bAlternateSetting */                                \
        0x01,             /* bNumEndPoints */                                    \
        0x01,             /* bInterfaceClass      (Audio Device Class) */        \
        0x02,             /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,             /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00              /* iInterface */

/* AS Interface Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                        \
    0x07,                   /* bLength */            \
        0x24,               /* bDescriptorType */    \
        0x01,               /* bDescriptorSubtype */ \
        0x06,               /* bTerminalLink */      \
        0x01,               /* bDelay */             \
        U16_TO_BYTE(0x0001) /* wFormatTag   (PCM) */

/* AS Format Type 1 Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                                      \
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
#define DUAL_SENSE_DESCRIPTOR                                                                                    \
    0x09,                    /* bLength */                                                                       \
        0x05,                /* bDescriptorType */                                                               \
        0x82,                /* bEndpointAddress  (IN endpoint 2) */                                             \
        0x05,                /* bmAttributes      (Transfer: Isochronous / Synch: Asynchronous / Usage: Data) */ \
        U16_TO_BYTE(0x00C4), /* wMaxPacketSize    (1 x 196 bytes) */                                             \
        0x04,                /* bInterval         (8 microframes) */                                             \
        0x00,                /* bRefresh */                                                                      \
        0x00                 /* bSynchAddress */

/* AS Isochronous Data Endpoint Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                   \
    0x07,                   /* bLength */                       \
        0x25,               /* bDescriptorType */               \
        0x01,               /* bDescriptorSubtype */            \
        0x00,               /* bmAttributes */                  \
        0x00,               /* bLockDelayUnits   (undefined) */ \
        U16_TO_BYTE(0x0000) /* wLockDelay */

/* Interface Descriptor: */
#define DUAL_SENSE_INTERFACE_DESCRIPTOR_3_0                                           \
    0x09,                   /* bLength */                                             \
        0x04,               /* bDescriptorType */                                     \
        DUAL_SENSE_ITF_HID, /* bInterfaceNumber */                                    \
        0x00,               /* bAlternateSetting */                                   \
        0x02,               /* bNumEndPoints */                                       \
        0x03,               /* bInterfaceClass      (Human Interface Device Class) */ \
        0x00,               /* bInterfaceSubClass */                                  \
        0x00,               /* bInterfaceProtocol */                                  \
        0x00                /* iInterface */

/* HID Descriptor: */
#define DUAL_SENSE_HID_DESCRIPTOR(report_size)                               \
    0x09,                        /* bLength */                               \
        0x21,                    /* bDescriptorType */                       \
        U16_TO_BYTE(0x0111),     /* bcdHID */                                \
        0x00,                    /* bCountryCode */                          \
        0x01,                    /* bNumDescriptors */                       \
        0x22,                    /* bDescriptorType   (Report descriptor) */ \
        U16_TO_BYTE(report_size) /* bDescriptorLength */

/* Endpoint Descriptor: */
#define DUAL_SENSE_ENDPOINT_DESCRIPTOR_IN4                                                             \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x84,                /* bEndpointAddress  (IN endpoint 4) */                                   \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x06                 /* bInterval         (32 microframes) */

/* Endpoint Descriptor: */
#define DUAL_SENSE_ENDPOINT_DESCRIPTOR_OUT3                                                            \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x03,                /* bEndpointAddress  (OUT endpoint 3) */                                  \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x06                 /* bInterval         (32 microframes) */

/* ------------------------------ */
/* Other Speed Configuration Descriptor: */
/* ------------------------------ */
#define DUAL_SENSE_DESCRIPTOR                                           \
    0x09,                    /* bLength */                              \
        0x07,                /* bDescriptorType */                      \
        U16_TO_BYTE(0x00E3), /* wTotalLength   (227 bytes) */           \
        0x04,                /* bNumInterfaces */                       \
        0x01,                /* bConfigurationValue */                  \
        0x00,                /* iConfiguration */                       \
        0xC0,                /* bmAttributes   (Self-powered Device) */ \
        0xFA                 /* bMaxPower      (500 mA) */

/* Interface Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                                   \
    0x09,                 /* bLength */                                         \
        0x04,             /* bDescriptorType */                                 \
        DUAL_SENSE_ITF_0, /* bInterfaceNumber */                                \
        0x00,             /* bAlternateSetting */                               \
        0x00,             /* bNumEndPoints */                                   \
        0x01,             /* bInterfaceClass      (Audio Device Class) */       \
        0x01,             /* bInterfaceSubClass   (Audio Control Interface) */  \
        0x00,             /* bInterfaceProtocol   (Audio Protocol undefined) */ \
        0x00              /* iInterface */

/* AC Interface Header Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                \
    0x0A,                    /* bLength */                   \
        0x24,                /* bDescriptorType */           \
        0x01,                /* bDescriptorSubtype */        \
        U16_TO_BYTE(0x0100), /* bcdADC */                    \
        U16_TO_BYTE(0x0049), /* wTotalLength   (73 bytes) */ \
        0x02,                /* bInCollection */             \
        0x01,                /* baInterfaceNr(1) */          \
        0x02                 /* baInterfaceNr(2) */

/* AC Input Terminal Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                      \
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
#define DUAL_SENSE_DESCRIPTOR                                     \
    0x0C,                        /* bLength */                    \
        0x24,                    /* bDescriptorType */            \
        0x06,                    /* bDescriptorSubtype */         \
        0x02,                    /* bUnitID */                    \
        0x01,                    /* bSourceID */                  \
        0x01,                    /* bControlSize */               \
        /* bmaControls: */ 0x03, /* Channel(0) - Mute / Volume */ \
        0x00,                    /* Channel(1) */                 \
        0x00,                    /* Channel(2) */                 \
        0x00,                    /* Channel(3) */                 \
        0x00,                    /* Channel(4) */                 \
        0x00                     /* iFeature */

/* AC Output Terminal Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                \
    0x09,                    /* bLength */                   \
        0x24,                /* bDescriptorType */           \
        0x03,                /* bDescriptorSubtype */        \
        0x03,                /* bTerminalID */               \
        U16_TO_BYTE(0x0301), /* wTerminalType   (Speaker) */ \
        0x04,                /* bAssocTerminal */            \
        0x02,                /* bSourceID */                 \
        0x00                 /* iTerminal */

/* AC Input Terminal Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                 \
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
#define DUAL_SENSE_DESCRIPTOR                                     \
    0x09,                        /* bLength */                    \
        0x24,                    /* bDescriptorType */            \
        0x06,                    /* bDescriptorSubtype */         \
        0x05,                    /* bUnitID */                    \
        0x04,                    /* bSourceID */                  \
        0x01,                    /* bControlSize */               \
        /* bmaControls: */ 0x03, /* Channel(0) - Mute / Volume */ \
        0x00,                    /* Channel(1) */                 \
        0x00                     /* iFeature */

/* AC Output Terminal Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                      \
    0x09,                    /* bLength */                         \
        0x24,                /* bDescriptorType */                 \
        0x03,                /* bDescriptorSubtype */              \
        0x06,                /* bTerminalID */                     \
        U16_TO_BYTE(0x0101), /* wTerminalType   (USB Streaming) */ \
        0x01,                /* bAssocTerminal */                  \
        0x05,                /* bSourceID */                       \
        0x00                 /* iTerminal */

/* Interface Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                                    \
    0x09,                 /* bLength */                                          \
        0x04,             /* bDescriptorType */                                  \
        DUAL_SENSE_ITF_1, /* bInterfaceNumber */                                 \
        0x00,             /* bAlternateSetting */                                \
        0x00,             /* bNumEndPoints */                                    \
        0x01,             /* bInterfaceClass      (Audio Device Class) */        \
        0x02,             /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,             /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00              /* iInterface */

/* Interface Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                                    \
    0x09,                 /* bLength */                                          \
        0x04,             /* bDescriptorType */                                  \
        DUAL_SENSE_ITF_1, /* bInterfaceNumber */                                 \
        0x01,             /* bAlternateSetting */                                \
        0x01,             /* bNumEndPoints */                                    \
        0x01,             /* bInterfaceClass      (Audio Device Class) */        \
        0x02,             /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,             /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00              /* iInterface */

/* AS Interface Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                        \
    0x07,                   /* bLength */            \
        0x24,               /* bDescriptorType */    \
        0x01,               /* bDescriptorSubtype */ \
        0x01,               /* bTerminalLink */      \
        0x01,               /* bDelay */             \
        U16_TO_BYTE(0x0001) /* wFormatTag   (PCM) */

/* AS Format Type 1 Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                                      \
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
#define DUAL_SENSE_DESCRIPTOR                                                                                \
    0x09,                    /* bLength */                                                                   \
        0x05,                /* bDescriptorType */                                                           \
        0x01,                /* bEndpointAddress  (OUT endpoint 1) */                                        \
        0x09,                /* bmAttributes      (Transfer: Isochronous / Synch: Adaptive / Usage: Data) */ \
        U16_TO_BYTE(0x0188), /* wMaxPacketSize    (1 x 392 bytes) */                                         \
        0x01,                /* bInterval         (1 frames) */                                              \
        0x00,                /* bRefresh */                                                                  \
        0x00                 /* bSynchAddress */

/* AS Isochronous Data Endpoint Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                         \
    0x07,                   /* bLength */                             \
        0x25,               /* bDescriptorType */                     \
        0x01,               /* bDescriptorSubtype */                  \
        0x01,               /* bmAttributes   (Sampling Frequency) */ \
        0x00,               /* bLockDelayUnits   (undefined) */       \
        U16_TO_BYTE(0x0000) /* wLockDelay */

/* Interface Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                                    \
    0x09,                 /* bLength */                                          \
        0x04,             /* bDescriptorType */                                  \
        DUAL_SENSE_ITF_2, /* bInterfaceNumber */                                 \
        0x00,             /* bAlternateSetting */                                \
        0x00,             /* bNumEndPoints */                                    \
        0x01,             /* bInterfaceClass      (Audio Device Class) */        \
        0x02,             /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,             /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00              /* iInterface */

/* Interface Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                                    \
    0x09,                 /* bLength */                                          \
        0x04,             /* bDescriptorType */                                  \
        DUAL_SENSE_ITF_2, /* bInterfaceNumber */                                 \
        0x01,             /* bAlternateSetting */                                \
        0x01,             /* bNumEndPoints */                                    \
        0x01,             /* bInterfaceClass      (Audio Device Class) */        \
        0x02,             /* bInterfaceSubClass   (Audio Streaming Interface) */ \
        0x00,             /* bInterfaceProtocol   (Audio Protocol undefined) */  \
        0x00              /* iInterface */

/* AS Interface Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                        \
    0x07,                   /* bLength */            \
        0x24,               /* bDescriptorType */    \
        0x01,               /* bDescriptorSubtype */ \
        0x06,               /* bTerminalLink */      \
        0x01,               /* bDelay */             \
        U16_TO_BYTE(0x0001) /* wFormatTag   (PCM) */

/* AS Format Type 1 Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                                      \
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
#define DUAL_SENSE_DESCRIPTOR                                                                                    \
    0x09,                    /* bLength */                                                                       \
        0x05,                /* bDescriptorType */                                                               \
        0x82,                /* bEndpointAddress  (IN endpoint 2) */                                             \
        0x05,                /* bmAttributes      (Transfer: Isochronous / Synch: Asynchronous / Usage: Data) */ \
        U16_TO_BYTE(0x00C4), /* wMaxPacketSize    (1 x 196 bytes) */                                             \
        0x01,                /* bInterval         (1 frames) */                                                  \
        0x00,                /* bRefresh */                                                                      \
        0x00                 /* bSynchAddress */

/* AS Isochronous Data Endpoint Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                   \
    0x07,                   /* bLength */                       \
        0x25,               /* bDescriptorType */               \
        0x01,               /* bDescriptorSubtype */            \
        0x00,               /* bmAttributes */                  \
        0x00,               /* bLockDelayUnits   (undefined) */ \
        U16_TO_BYTE(0x0000) /* wLockDelay */

/* Interface Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                                         \
    0x09,                   /* bLength */                                             \
        0x04,               /* bDescriptorType */                                     \
        DUAL_SENSE_ITF_HID, /* bInterfaceNumber */                                    \
        0x00,               /* bAlternateSetting */                                   \
        0x02,               /* bNumEndPoints */                                       \
        0x03,               /* bInterfaceClass      (Human Interface Device Class) */ \
        0x00,               /* bInterfaceSubClass */                                  \
        0x00,               /* bInterfaceProtocol */                                  \
        0x00                /* iInterface */

/* HID Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                            \
    0x09,                    /* bLength */                               \
        0x21,                /* bDescriptorType */                       \
        U16_TO_BYTE(0x0111), /* bcdHID */                                \
        0x00,                /* bCountryCode */                          \
        0x01,                /* bNumDescriptors */                       \
        0x22,                /* bDescriptorType   (Report descriptor) */ \
        U16_TO_BYTE(0x0111)  /* bDescriptorLength */

/* Endpoint Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                                                          \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x84,                /* bEndpointAddress  (IN endpoint 4) */                                   \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x06                 /* bInterval         (6 frames) */

/* Endpoint Descriptor: */
#define DUAL_SENSE_DESCRIPTOR                                                                          \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x03,                /* bEndpointAddress  (OUT endpoint 3) */                                  \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x06                 /* bInterval         (6 frames) */

/* String Descriptor Table */
#define DUAL_SENSE_MANUFACTURER_STRING "Sony Interactive Entertainment"
#define DUAL_SENSE_PRODUCT_STRING "Wireless Controller"

#define DUAL_SENSE_STRING_DESCRIPTOR    \
    (const char[]){0x09, 0x04},         \
        DUAL_SENSE_MANUFACTURER_STRING, \
        DUAL_SENSE_PRODUCT_STRING

#define DUAL_SENSE_BT_REPORT_MAP                                                                                      \
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

#define DUAL_SENSE_USB_REPORT_MAP                                                                                     \
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

// C++11 allows setting enum base type. If enum sizes cannot be assured please use the indicated base types instead of the enum types.
enum DualSense_Direction
{
    DualSense_Direction_North = 0,
    DualSense_Direction_NorthEast,
    DualSense_Direction_East,
    DualSense_Direction_SouthEast,
    DualSense_Direction_South,
    DualSense_Direction_SouthWest,
    DualSense_Direction_West,
    DualSense_Direction_NorthWest,
    DualSense_Direction_None = 8
};

enum DualSense_PowerState
{
    DualSense_PowerState_Discharging = 0x00,         // Use PowerPercent
    DualSense_PowerState_Charging = 0x01,            // Use PowerPercent
    DualSense_PowerState_Complete = 0x02,            // PowerPercent not valid? assume 100%?
    DualSense_PowerState_AbnormalVoltage = 0x0A,     // PowerPercent not valid?
    DualSense_PowerState_AbnormalTemperature = 0x0B, // PowerPercent not valid?
    DualSense_PowerState_ChargingError = 0x0F        // PowerPercent not valid?
};

enum DualSense_MuteLight
{
    DualSense_MuteLight_Off = 0,
    DualSense_MuteLight_On,
    DualSense_MuteLight_Breathing,
    DualSense_MuteLight_DoNothing, // literally nothing, this input is ignored,
                                   // though it might be a faster blink in other versions
    DualSense_MuteLight_NoAction4,
    DualSense_MuteLight_NoAction5,
    DualSense_MuteLight_NoAction6,
    DualSense_MuteLight_NoAction7 = 7
};

enum DualSense_LightBrightness
{
    DualSense_LightBrightness_Bright = 0,
    DualSense_LightBrightness_Mid,
    DualSense_LightBrightness_Dim,
    DualSense_LightBrightness_NoAction3,
    DualSense_LightBrightness_NoAction4,
    DualSense_LightBrightness_NoAction5,
    DualSense_LightBrightness_NoAction6,
    DualSense_LightBrightness_NoAction7 = 7
};

enum DualSense_LightFadeAnimation
{
    DualSense_LightFadeAnimation_Nothing = 0,
    DualSense_LightFadeAnimation_FadeIn, // from black to blue
    DualSense_LightFadeAnimation_FadeOut // from blue to black
};

// template<int N> struct BTCRC {
//     uint8_t[N-4] Buff;
//     uint32_t CRC;
// };

#define DualSense_BTCRC(N)   \
    struct                   \
    {                        \
        uint8_t Buff[N - 4]; \
        uint32_t CRC;        \
    }

/* ****** Input Reports ****** */

struct DualSense_TouchFingerData
{ // 4
    /*0.0*/ uint32_t Index : 7;
    /*0.7*/ uint32_t NotTouching : 1;
    /*1.0*/ uint32_t FingerX : 12;
    /*2.4*/ uint32_t FingerY : 12;
};

struct DualSense_TouchData
{ // 9
    /*0*/ struct DualSense_TouchFingerData Finger[2];
    /*8*/ uint8_t Timestamp;
};

struct DualSense_BTSimpleGetStateData
{ // 9
    /*0  */ uint8_t LeftStickX;
    /*1  */ uint8_t LeftStickY;
    /*2  */ uint8_t RightStickX;
    /*3  */ uint8_t RightStickY;
    /*4.0*/ enum DualSense_Direction DPad : 4;
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
    /*6.1*/ uint8_t ButtonHome : 1;
    /*6.2*/ uint8_t ButtonPad : 1;
    /*6.3*/ uint8_t Counter : 6;
    /*7  */ uint8_t TriggerLeft;
    /*8  */ uint8_t TriggerRight;
    // anything beyond this point, if set, is invalid junk data that was not cleared
};

struct DualSense_USBGetStateData
{ // 63
    /* 0  */ uint8_t LeftStickX;
    /* 1  */ uint8_t LeftStickY;
    /* 2  */ uint8_t RightStickX;
    /* 3  */ uint8_t RightStickY;
    /* 4  */ uint8_t TriggerLeft;
    /* 5  */ uint8_t TriggerRight;
    /* 6  */ uint8_t SeqNo; // always 0x01 on BT
    /* 7.0*/ enum DualSense_Direction DPad : 4;
    /* 7.4*/ uint8_t ButtonSquare : 1;
    /* 7.5*/ uint8_t ButtonCross : 1;
    /* 7.6*/ uint8_t ButtonCircle : 1;
    /* 7.7*/ uint8_t ButtonTriangle : 1;
    /* 8.0*/ uint8_t ButtonL1 : 1;
    /* 8.1*/ uint8_t ButtonR1 : 1;
    /* 8.2*/ uint8_t ButtonL2 : 1;
    /* 8.3*/ uint8_t ButtonR2 : 1;
    /* 8.4*/ uint8_t ButtonCreate : 1;
    /* 8.5*/ uint8_t ButtonOptions : 1;
    /* 8.6*/ uint8_t ButtonL3 : 1;
    /* 8.7*/ uint8_t ButtonR3 : 1;
    /* 9.0*/ uint8_t ButtonHome : 1;
    /* 9.1*/ uint8_t ButtonPad : 1;
    /* 9.2*/ uint8_t ButtonMute : 1;
    /* 9.3*/ uint8_t UNK1 : 1;                // appears unused
    /* 9.4*/ uint8_t ButtonLeftFunction : 1;  // DualSense Edge
    /* 9.5*/ uint8_t ButtonRightFunction : 1; // DualSense Edge
    /* 9.6*/ uint8_t ButtonLeftPaddle : 1;    // DualSense Edge
    /* 9.7*/ uint8_t ButtonRightPaddle : 1;   // DualSense Edge
    /*10  */ uint8_t UNK2;                    // appears unused
    /*11  */ uint32_t UNK_COUNTER;            // Linux driver calls this reserved, tools leak calls the 2 high bytes "random"
    /*15  */ int16_t AngularVelocityX;
    /*17  */ int16_t AngularVelocityZ;
    /*19  */ int16_t AngularVelocityY;
    /*21  */ int16_t AccelerometerX;
    /*23  */ int16_t AccelerometerY;
    /*25  */ int16_t AccelerometerZ;
    /*27  */ uint32_t SensorTimestamp;
    /*31  */ int8_t Temperature; // reserved2 in Linux driver
    /*32  */ struct DualSense_TouchData TouchData;
    /*41.0*/ uint8_t TriggerRightStopLocation : 4; // trigger stop can be a range from 0 to 9 (F/9.0 for Apple interface)
    /*41.4*/ uint8_t TriggerRightStatus : 4;
    /*42.0*/ uint8_t TriggerLeftStopLocation : 4;
    /*42.4*/ uint8_t TriggerLeftStatus : 4;  // 0 feedbackNoLoad
                                             // 1 feedbackLoadApplied
                                             // 0 weaponReady
                                             // 1 weaponFiring
                                             // 2 weaponFired
                                             // 0 vibrationNotVibrating
                                             // 1 vibrationIsVibrating
    /*43  */ uint32_t HostTimestamp;         // mirrors data from report write
    /*47.0*/ uint8_t TriggerRightEffect : 4; // Active trigger effect, previously we thought this was status max
    /*47.4*/ uint8_t TriggerLeftEffect : 4;  // 0 for reset and all other effects
                                             // 1 for feedback effect
                                             // 2 for weapon effect
                                             // 3 for vibration
    /*48  */ uint32_t DeviceTimeStamp;
    /*52.0*/ uint8_t PowerPercent : 4; // 0x00-0x0A
    /*52.4*/ enum DualSense_PowerState PowerState : 4;
    /*53.0*/ uint8_t PluggedHeadphones : 1;
    /*53.1*/ uint8_t PluggedMic : 1;
    /*53.2*/ uint8_t MicMuted : 1; // Mic muted by powersave/mute command
    /*53.3*/ uint8_t PluggedUsbData : 1;
    /*53.4*/ uint8_t PluggedUsbPower : 1;
    /*53.5*/ uint8_t PluggedUnk1 : 3;
    /*54.0*/ uint8_t PluggedExternalMic : 1;  // Is external mic active (automatic in mic auto mode)
    /*54.1*/ uint8_t HapticLowPassFilter : 1; // Is the Haptic Low-Pass-Filter active?
    /*54.2*/ uint8_t PluggedUnk3 : 6;
    /*55  */ uint8_t AesCmac[8];
};

struct DualSense_BTGetStateData
{ // 77
    /* 0*/ struct DualSense_USBGetStateData StateData;
    /*63*/ uint8_t UNK1; // Oscillates between 00101100 and 00101101 when rumbling
                         // Not affected by rumble volume or enhanced vs normal rumble
                         // Audio rumble not yet tested as this is only on BT
    /*64*/ uint8_t BtCrcFailCount;
    /*65*/ uint8_t Pad[11];
};

struct DualSense_ReportIn01USB
{
    uint8_t ReportID; // 0x01
    struct DualSense_USBGetStateData State;
};

struct DualSense_ReportIn01BT
{
    uint8_t ReportID; // 0x01
    struct DualSense_BTSimpleGetStateData State;
};

struct DualSense_ReportIn31
{
    union
    {
        DualSense_BTCRC(78) CRC;
        struct
        {
            uint8_t ReportID;   // 0x31
            uint8_t HasHID : 1; // Present for packets with state data
            uint8_t HasMic : 1; // Looks mutually exclusive, possible mic data
            uint8_t Unk1 : 2;
            uint8_t SeqNo : 4; // unclear progression
            struct DualSense_BTGetStateData State;
        } Data;
    };
};

/* ****** Output Reports ****** */

typedef struct DualSense_SetStateData
{                                                  // 47
    /*    */                                       // Report Set Flags
    /*    */                                       // These flags are used to indicate what contents from this report should be processed
    /* 0.0*/ uint8_t EnableRumbleEmulation : 1;    // Suggest halving rumble strength
    /* 0.1*/ uint8_t UseRumbleNotHaptics : 1;      //
                                                   /*    */
    /* 0.2*/ uint8_t AllowRightTriggerFFB : 1;     // Enable setting RightTriggerFFB
    /* 0.3*/ uint8_t AllowLeftTriggerFFB : 1;      // Enable setting LeftTriggerFFB
                                                   /*    */
    /* 0.4*/ uint8_t AllowHeadphoneVolume : 1;     // Enable setting VolumeHeadphones
    /* 0.5*/ uint8_t AllowSpeakerVolume : 1;       // Enable setting VolumeSpeaker
    /* 0.6*/ uint8_t AllowMicVolume : 1;           // Enable setting VolumeMic
                                                   /*    */
    /* 0.7*/ uint8_t AllowAudioControl : 1;        // Enable setting AudioControl section
    /* 1.0*/ uint8_t AllowMuteLight : 1;           // Enable setting MuteLightMode
    /* 1.1*/ uint8_t AllowAudioMute : 1;           // Enable setting MuteControl section
                                                   /*    */
    /* 1.2*/ uint8_t AllowLedColor : 1;            // Enable RGB LED section
                                                   /*    */
    /* 1.3*/ uint8_t ResetLights : 1;              // Release the LEDs from Wireless firmware control
    /*    */                                       // When in wireless mode this must be signaled to control LEDs
    /*    */                                       // This cannot be applied during the BT pair animation.
    /*    */                                       // SDL2 waits until the SensorTimestamp value is >= 10200000
    /*    */                                       // before pulsing this bit once.
                                                   /*    */
    /* 1.4*/ uint8_t AllowPlayerIndicators : 1;    // Enable setting PlayerIndicators section
    /* 1.5*/ uint8_t AllowHapticLowPassFilter : 1; // Enable HapticLowPassFilter
    /* 1.6*/ uint8_t AllowMotorPowerLevel : 1;     // MotorPowerLevel reductions for trigger/haptic
    /* 1.7*/ uint8_t AllowAudioControl2 : 1;       // Enable setting AudioControl2 section
                                                   /*    */
    /* 2  */ uint8_t RumbleEmulationRight;         // emulates the light weight
    /* 3  */ uint8_t RumbleEmulationLeft;          // emulated the heavy weight
                                                   /*    */
    /* 4  */ uint8_t VolumeHeadphones;             // max 0x7f
    /* 5  */ uint8_t VolumeSpeaker;                // PS5 appears to only use the range 0x3d-0x64
    /* 6  */ uint8_t VolumeMic;                    // not linier, seems to max at 64, 0 is not fully muted
                                                   /*    */
    /*    */                                       // AudioControl
    /* 7.0*/ uint8_t MicSelect : 2;                // 0 Auto
    /*    */                                       // 1 Internal Only
    /*    */                                       // 2 External Only
    /*    */                                       // 3 Unclear, sets external mic flag but might use internal mic, do test
    /* 7.2*/ uint8_t EchoCancelEnable : 1;
    /* 7.3*/ uint8_t NoiseCancelEnable : 1;
    /* 7.4*/ uint8_t OutputPathSelect : 2; // 0 L_R_X
    /*    */                               // 1 L_L_X
    /*    */                               // 2 L_L_R
    /*    */                               // 3 X_X_R
    /* 7.6*/ uint8_t InputPathSelect : 2;  // 0 CHAT_ASR
    /*    */                               // 1 CHAT_CHAT
    /*    */                               // 2 ASR_ASR
    /*    */                               // 3 Does Nothing, invalid
                                           /*    */
    /* 8  */ enum DualSense_MuteLight MuteLightMode;
    /*    */
    /*    */ // MuteControl
    /* 9.0*/ uint8_t TouchPowerSave : 1;
    /* 9.1*/ uint8_t MotionPowerSave : 1;
    /* 9.2*/ uint8_t HapticPowerSave : 1; // AKA BulletPowerSave
    /* 9.3*/ uint8_t AudioPowerSave : 1;
    /* 9.4*/ uint8_t MicMute : 1;
    /* 9.5*/ uint8_t SpeakerMute : 1;
    /* 9.6*/ uint8_t HeadphoneMute : 1;
    /* 9.7*/ uint8_t HapticMute : 1; // AKA BulletMute
                                     /*    */
    /*10  */ uint8_t RightTriggerFFB[11];
    /*21  */ uint8_t LeftTriggerFFB[11];
    /*32  */ uint32_t HostTimestamp;                    // mirrored into report read
                                                        /*    */
    /*    */                                            // MotorPowerLevel
    /*36.0*/ uint8_t TriggerMotorPowerReduction : 4;    // 0x0-0x7 (no 0x8?) Applied in 12.5% reductions
    /*36.4*/ uint8_t RumbleMotorPowerReduction : 4;     // 0x0-0x7 (no 0x8?) Applied in 12.5% reductions
                                                        /*    */
    /*    */                                            // AudioControl2
    /*37.0*/ uint8_t SpeakerCompPreGain : 3;            // additional speaker volume boost
    /*37.3*/ uint8_t BeamformingEnable : 1;             // Probably for MIC given there's 2, might be more bits, can't find what it does
    /*37.4*/ uint8_t UnkAudioControl2 : 4;              // some of these bits might apply to the above
                                                        /*    */
    /*38.0*/ uint8_t AllowLightBrightnessChange : 1;    // LED_BRIHTNESS_CONTROL
    /*38.1*/ uint8_t AllowColorLightFadeAnimation : 1;  // LIGHTBAR_SETUP_CONTROL
    /*38.2*/ uint8_t EnableImprovedRumbleEmulation : 1; // Use instead of EnableRumbleEmulation
                                                        // requires FW >= 0x0224
                                                        // No need to halve rumble strength
    /*38.3*/ uint8_t UNKBITC : 5;                       // unused
                                                        /*    */
    /*39.0*/ uint8_t HapticLowPassFilter : 1;
    /*39.1*/ uint8_t UNKBIT : 7;
    /*    */
    /*40  */ uint8_t UNKBYTE; // previous notes suggested this was HLPF, was probably off by 1
                              /*    */
    /*41  */ enum DualSense_LightFadeAnimation LightFadeAnimation;
    /*42  */ enum DualSense_LightBrightness LightBrightness;
    /*    */
    /*    */                              // PlayerIndicators
    /*    */                              // These bits control the white LEDs under the touch pad.
    /*    */                              // Note the reduction in functionality for later revisions.
    /*    */                              // Generation 0x03 - Full Functionality
    /*    */                              // Generation 0x04 - Mirrored Only
    /*    */                              // Suggested detection: (HardwareInfo & 0x00FFFF00) == 0X00000400
    /*    */                              //
    /*    */                              // Layout used by PS5:
    /*    */                              // 0x04 - -x- -  Player 1
    /*    */                              // 0x06 - x-x -  Player 2
    /*    */                              // 0x15 x -x- x  Player 3
    /*    */                              // 0x1B x x-x x  Player 4
    /*    */                              // 0x1F x xxx x  Player 5* (Unconfirmed)
    /*    */                              //
    /*    */                              //                        // HW 0x03 // HW 0x04
    /*43.0*/ uint8_t PlayerLight1 : 1;    // x --- - // x --- x
    /*43.1*/ uint8_t PlayerLight2 : 1;    // - x-- - // - x-x -
    /*43.2*/ uint8_t PlayerLight3 : 1;    // - -x- - // - -x- -
    /*43.3*/ uint8_t PlayerLight4 : 1;    // - --x - // - x-x -
    /*43.4*/ uint8_t PlayerLight5 : 1;    // - --- x // x --- x
    /*43.5*/ uint8_t PlayerLightFade : 1; // if low player lights fade in, if high player lights instantly change
    /*43.6*/ uint8_t PlayerLightUNK : 2;
    /*    */
    /*    */ // RGB LED
    /*44  */ uint8_t LedRed;
    /*45  */ uint8_t LedGreen;
    /*46  */ uint8_t LedBlue;
    // Structure ends here though on BT there is padding and a CRC, see ReportOut31
} DualSense_USBSetStateData;

struct DualSense_ReportOut02
{
    uint8_t ReportID; // 0x02
    DualSense_USBSetStateData State;
};

struct DualSense_ReportOut31
{
    union
    {
        DualSense_BTCRC(78) CRC;
        struct
        {
            uint8_t ReportID;      // 0x31
            uint8_t UNK1 : 1;      // -+
            uint8_t EnableHID : 1; //  | - these 3 bits seem to act as an enum
            uint8_t UNK2 : 1;      // -+
            uint8_t UNK3 : 1;
            uint8_t SeqNo : 4; // increment for every write // we have no proof of this, need to see some PS5 captures
            struct DualSense_SetStateData State;
        } Data;
    };
};

/* ****** Feature Reports ****** */
/* Calibration */
/* Reading calibration is required to switch BT input reports from
 the truncated 0x01 report to the expanded 0x31 report. */

/* Linux hid-sony.c (does this apply to the DualSense?) */

struct DualSense_ReportFeatureInCalibrateBT
{
    union
    {
        DualSense_BTCRC(41) CRC;
        struct
        {
            uint8_t ReportID; // 0x05 // does this exist on USB? confirm
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
        } Data;
    };
};

struct DualSense_ReportFeatureInMacAll
{
    uint8_t ReportID;     // 0x09
    uint8_t ClientMac[6]; // Right to Left
    uint8_t Hard08;
    uint8_t Hard25;
    uint8_t Hard00;
    uint8_t HostMac[6]; // Right to Left
    uint8_t Pad[3];     // Size according to Linux driver
};

struct DualSense_ReportFeatureInVersion
{
    union
    {
        DualSense_BTCRC(64) CRC;
        struct
        {
            uint8_t ReportID;   // 0x20
            char BuildDate[11]; // string
            char BuildTime[8];  // string
            uint16_t FwType;
            uint16_t SwSeries;
            uint32_t HardwareInfo;    // 0x00FF0000 - Variation
                                      // 0x0000FF00 - Generation
                                      // 0x0000003F - Trial?
                                      // ^ Values tied to enumerations
            uint32_t FirmwareVersion; // 0xAABBCCCC AA.BB.CCCC
            char DeviceInfo[12];
            ////
            uint16_t UpdateVersion;
            char UpdateImageInfo;
            char UpdateUnk;
            ////
            uint32_t FwVersion1; // AKA SblFwVersion
                                 // 0xAABBCCCC AA.BB.CCCC
                                 // Ignored for FwType 0
                                 // HardwareVersion used for FwType 1
                                 // Unknown behavior if HardwareVersion < 0.1.38 for FwType 2 & 3
                                 // If HardwareVersion >= 0.1.38 for FwType 2 & 3
            uint32_t FwVersion2; // AKA VenomFwVersion
            uint32_t FwVersion3; // AKA SpiderDspFwVersion AKA BettyFwVer
                                 // May be Memory Control Unit for Non Volatile Storage
        };
    };
};

#endif
