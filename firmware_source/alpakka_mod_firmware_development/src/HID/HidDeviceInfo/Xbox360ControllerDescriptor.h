#pragma once

#include "Library/common.h"

#define XUSB_DESC_TYPE_RESERVED 0x21
#define XUSB_SECURITY_DESC_TYPE_RESERVED 0x41

/* Device Descriptor: */
#define XBOX_360_CONTROLLER_USB_DEVICE_DESCRIPTOR                      \
    0x12,                    /* bLength */                             \
        0x01,                /* bDescriptorType */                     \
        U16_TO_BYTE(0x0200), /* bcdUSB */                              \
        0xFF,                /* bDeviceClass      (Vendor specific) */ \
        0xFF,                /* bDeviceSubClass    */                  \
        0xFF,                /* bDeviceProtocol    */                  \
        0x08,                /* bMaxPacketSize0   (8 bytes) */         \
        U16_TO_BYTE(0x045E), /* idVendor */                            \
        U16_TO_BYTE(0x028E), /* idProduct */                           \
        U16_TO_BYTE(0x0114), /* bcdDevice */                           \
        0x01,                /* iManufacturer */                       \
        0x02,                /* iProduct      */                       \
        0x03,                /* iSerialNumber */                       \
        0x01                 /* bNumConfigurations */

/* Configuration Descriptor: */
#define XBOX_360_CONTROLLER_USB_CONFIGURATION_DESCRIPTOR                              \
    0x09,                    /* bLength */                                            \
        0x02,                /* bDescriptorType */                                    \
        U16_TO_BYTE(0x0099), /* wTotalLength   (153 bytes) */                         \
        0x04,                /* bNumInterfaces */                                     \
        0x01,                /* bConfigurationValue */                                \
        0x00,                /* iConfiguration */                                     \
        0xA0,                /* bmAttributes   (Bus-powered Device, Remote-Wakeup) */ \
        0xFA                 /* bMaxPower      (500 mA) */

// Control Interface (0x5D 0xFF)
#define XBOX_360_CONTROLLER_USB_ITF0_INTERFACE_DESCRIPTOR  \
    0x09,     /* bLength */                                \
        0x04, /* bDescriptorType */                        \
        0x00, /* bInterfaceNumber */                       \
        0x00, /* bAlternateSetting */                      \
        0x02, /* bNumEndPoints */                          \
        0xFF, /* bInterfaceClass      (Vendor specific) */ \
        0x5D, /* bInterfaceSubClass    */                  \
        0x01, /* bInterfaceProtocol    */                  \
        0x00  /* iInterface */

// Gamepad Descriptor
#define XBOX_360_CONTROLLER_USB_ITF0_CLASS_SPECIFIC_DESCRIPTOR                               \
    0x11,                             /* bLength */                                          \
        0x21,                         /* bDescriptorType (HID) */                            \
        0x00, 0x01,                   /* bcdHID 1.00 */                                      \
        0x01,                         /* SUB_TYPE */                                         \
        0x25,                         /* reserved2 */                                        \
        0x81,                         /* DEVICE_EPADDR_IN */                                 \
        0x14,                         /* bMaxDataSizeIn */                                   \
        0x00, 0x00, 0x00, 0x00, 0x13, /* reserved3 */                                        \
        0x02,                         /* DEVICE_EPADDR_OUT is this right? (0x01 or 0x02?) */ \
        0x08,                         /* bMaxDataSizeOut */                                  \
        0x00, 0x00                    /* reserved4 */

/* Endpoint Descriptor: */
#define XBOX_360_CONTROLLER_USB_ITF0_IN_ENDPOINT_DESCRIPTOR                                            \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x81,                /* bEndpointAddress  (IN endpoint 1) */                                   \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0020), /* wMaxPacketSize    (1 x 32 bytes) */                                    \
        0x01                 /* bInterval         (1 frames) */

/* Endpoint Descriptor: */
#define XBOX_360_CONTROLLER_USB_ITF0_OUT_ENDPOINT_DESCRIPTOR                                           \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x01,                /* bEndpointAddress  (OUT endpoint 1) */                                  \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0020), /* wMaxPacketSize    (1 x 32 bytes) */                                    \
        0x08                 /* bInterval         (8 frames) */

// Interface Audio
#define XBOX_360_CONTROLLER_USB_ITF1_INTERFACE_DESCRIPTOR  \
    0x09,     /* bLength */                                \
        0x04, /* bDescriptorType */                        \
        0x01, /* bInterfaceNumber */                       \
        0x00, /* bAlternateSetting */                      \
        0x04, /* bNumEndPoints */                          \
        0xFF, /* bInterfaceClass      (Vendor specific) */ \
        0x5D, /* bInterfaceSubClass    */                  \
        0x03, /* bInterfaceProtocol    */                  \
        0x00  /* iInterface */

// Audio Descriptor
#define XBOX_360_CONTROLLER_USB_ITF1_CLASS_SPECIFIC_DESCRIPTOR \
    0x1B, /* bLength */                                        \
        0x21, 0x00, 0x01, 0x01, 0x01,                          \
        0x83, /* XINPUT_MIC_IN (0x82 or 0x83?) */              \
        0x40, 0x01,                                            \
        0x04, /* XINPUT_AUDIO_OUT (0x02 or 0x04?) */           \
        0x20, 0x16,                                            \
        0x85, /* XINPUT_UNK_IN (0x83 or 0x85?) */              \
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16,              \
        0x06, /* XINPUT_UNK_OUT (0x03 or 0x06?) */             \
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00

/* Endpoint Descriptor: */
#define XBOX_360_CONTROLLER_USB_ITF1_EP0_IN_ENDPOINT_DESCRIPTOR                                        \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x82,                /* bEndpointAddress  (IN endpoint 2) */                                   \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0020), /* wMaxPacketSize    (1 x 32 bytes) */                                    \
        0x02                 /* bInterval         (2 frames) */

/* Endpoint Descriptor: */
#define XBOX_360_CONTROLLER_USB_ITF1_EP0_OUT_ENDPOINT_DESCRIPTOR                                       \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x02,                /* bEndpointAddress  (OUT endpoint 2) */                                  \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0020), /* wMaxPacketSize    (1 x 32 bytes) */                                    \
        0x04                 /* bInterval         (4 frames) */

/* Endpoint Descriptor: */
#define XBOX_360_CONTROLLER_USB_ITF1_EP1_IN_ENDPOINT_DESCRIPTOR                                        \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x83,                /* bEndpointAddress  (IN endpoint 3) */                                   \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0020), /* wMaxPacketSize    (1 x 32 bytes) */                                    \
        0x40                 /* bInterval         (64 frames) */

/* Endpoint Descriptor: */
#define XBOX_360_CONTROLLER_USB_ITF1_EP1_OUT_ENDPOINT_DESCRIPTOR                                       \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x03,                /* bEndpointAddress  (OUT endpoint 3) */                                  \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0020), /* wMaxPacketSize    (1 x 32 bytes) */                                    \
        0x10                 /* bInterval         (16 frames) */

// Interface Plugin Module
#define XBOX_360_CONTROLLER_USB_ITF2_INTERFACE_DESCRIPTOR  \
    0x09,     /* bLength */                                \
        0x04, /* bDescriptorType */                        \
        0x02, /* bInterfaceNumber */                       \
        0x00, /* bAlternateSetting */                      \
        0x01, /* bNumEndPoints */                          \
        0xFF, /* bInterfaceClass      (Vendor specific) */ \
        0x5D, /* bInterfaceSubClass    */                  \
        0x02, /* bInterfaceProtocol    */                  \
        0x00  /* iInterface */

// PluginModuleDescriptor :
#define XBOX_360_CONTROLLER_USB_ITF2_CLASS_SPECIFIC_DESCRIPTOR \
    0x09,           /* bLength */                              \
        0x21,       /* bDescriptorType */                      \
        0x00, 0x01, /* version 1.00 */                         \
        0x01, 0x22,                                            \
        0x86, /* XINPUT_PLUGIN_MODULE_IN (0x84 or 0x86?) */    \
        0x03, /* ?? (0x07 or 0x03?) */                         \
        0x00

/* Endpoint Descriptor: */
#define XBOX_360_CONTROLLER_USB_ITF2_IN_ENDPOINT_DESCRIPTOR                                            \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x84,                /* bEndpointAddress  (IN endpoint 4) */                                   \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0020), /* wMaxPacketSize    (1 x 32 bytes) */                                    \
        0x10                 /* bInterval         (16 frames) */

// Interface Security
#define XBOX_360_CONTROLLER_USB_ITF3_INTERFACE_DESCRIPTOR  \
    0x09,     /* bLength */                                \
        0x04, /* bDescriptorType */                        \
        0x03, /* bInterfaceNumber */                       \
        0x00, /* bAlternateSetting */                      \
        0x00, /* bNumEndPoints */                          \
        0xFF, /* bInterfaceClass      (Vendor specific) */ \
        0xFD, /* bInterfaceSubClass    */                  \
        0x13, /* bInterfaceProtocol    */                  \
        0x04  /* iInterface */

// SecurityDescriptor (XSM3)
#define XBOX_360_CONTROLLER_USB_ITF3_CLASS_SPECIFIC_DESCRIPTOR \
    0x06,     /* bLength */                                    \
        0x41, /* bDescriptType (Xbox 360) */                   \
        0x00, 0x01, 0x01, 0x03

/* String Descriptor Table */
#define XBOX_360_CONTROLLER_USB_STRING_DESCRIPTOR_0 (const char[]){0x09, 0x04}
#define XBOX_360_CONTROLLER_USB_STRING_DESCRIPTOR_1 "©Microsoft Corporation"
#define XBOX_360_CONTROLLER_USB_STRING_DESCRIPTOR_2 "Controller"
#define XBOX_360_CONTROLLER_USB_STRING_DESCRIPTOR_3 "04B229A"
#define XBOX_360_CONTROLLER_USB_STRING_DESCRIPTOR_4 "Xbox Security Method 3, Version 1.00, © 2005 Microsoft Corporation. All rights reserved."
