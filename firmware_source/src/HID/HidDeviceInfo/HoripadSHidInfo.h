#pragma once

#include "Library/cstd_lib.h"
#include "Library/common.h"

/* Device Descriptor: */
#define HORIPAD_S_USB_DEVICE_DESCRIPTOR             \
    0x12,                    /* .bLength */         \
        0x01,                /* .bDescriptorType */ \
        U16_TO_BYTE(0x0200), /* .bcdUSB */          \
        0x00,                /* .bDeviceClass */    \
        0x00,                /* .bDeviceSubClass */ \
        0x00,                /* .bDeviceProtocol */ \
        0x40,                /* .bMaxPacketSize0 */ \
        U16_TO_BYTE(0x0F0D), /* .idVendor */        \
        U16_TO_BYTE(0x00C1), /* .idProduct */       \
        U16_TO_BYTE(0x0572), /* .bcdDevice */       \
        0x01,                /* .iManufacturer */   \
        0x02,                /* .iProduct */        \
        0x00,                /* .iSerialNumber */   \
        0x01                 /* .bNumConfiguration */

/* Configuration Descriptor: */
#define HORIPAD_S_USB_CONFIGURATION_DESCRIPTOR                                        \
    0x09,                    /* bLength */                                            \
        0x02,                /* bDescriptorType */                                    \
        U16_TO_BYTE(0x0029), /* wTotalLength   (41 bytes) */                          \
        0x01,                /* bNumInterfaces */                                     \
        0x01,                /* bConfigurationValue */                                \
        0x00,                /* iConfiguration */                                     \
        0x80,                /* bmAttributes   (Bus-powered Device, Remote-Wakeup) */ \
        0xFA                 /* bMaxPower      (500 mA) */

/* Interface Descriptor: */
#define HORIPAD_S_USB_INTERFACE_DESCRIPTOR                              \
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
#define HORIPAD_S_USB_HID_DESCRIPTOR                                     \
    0x09,                    /* bLength */                               \
        0x21,                /* bDescriptorType */                       \
        U16_TO_BYTE(0x0111), /* bcdHID */                                \
        0x00,                /* bCountryCode */                          \
        0x01,                /* bNumDescriptors */                       \
        0x22,                /* bDescriptorType   (Report descriptor) */ \
        0x50                 /* bDescriptorLength */

/* Endpoint Descriptor: */
#define HORIPAD_S_USB_OUT_ENDPOINT_DESCRIPTOR                                                          \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x02,                /* bEndpointAddress  (OUT endpoint 2) */                                  \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x05                 /* bInterval         (8 frames) */

/* Endpoint Descriptor: */
#define HORIPAD_S_USB_IN_ENDPOINT_DESCRIPTOR                                                           \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        0x81,                /* bEndpointAddress  (IN endpoint 1) */                                   \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0040), /* wMaxPacketSize    (1 x 64 bytes) */                                    \
        0x05                 /* bInterval         (8 frames) */

/* String Descriptor Table */
#define HORIPAD_S_USB_STRING_DESCRIPTOR_0 (const char[]){0x09, 0x04}
#define HORIPAD_S_USB_STRING_MANUFACTURER "HORI CO.,LTD."
#define HORIPAD_S_USB_STRING_PRODUCT "HORIPAD S"

#define HORIPAD_S_USB_HID_REPORT_DESCRIPTOR                                        \
    0x05, 0x01,     /* Generic desktop controls */                                 \
        0x09, 0x05, /* Joystick */                                                 \
        0xA1, 0x01, /* Application */                                              \
        0x15, 0x00, /* button off state */                                         \
        0x25, 0x01, /* button on state */                                          \
        0x35, 0x00, /* button off state */                                         \
        0x45, 0x01, /* button on state */                                          \
        0x75, 0x01, /* 1 bit per report field */                                   \
        0x95, 0x0E, /* 14 report fields (14 buttons) */                            \
        0x05, 0x09, /* Buttons (section 12) */                                     \
        0x19, 0x01,                                                                \
        0x29, 0x0E,                                                                \
        0x81, 0x02,       /* Variable input */                                     \
        0x95, 0x02,       /* 2 report fields (empty 2 bits) */                     \
        0x81, 0x01,       /* Array input */                                        \
        0x05, 0x01,       /* Generic desktop controls */                           \
        0x25, 0x07,       /* 8 valid HAT states, sending 0x08 = nothing pressed */ \
        0x46, 0x3B, 0x01, /* HAT "rotation" */                                     \
        0x75, 0x04,       /* 4 bits per report field */                            \
        0x95, 0x01,                                                                \
        0x65, 0x14,       /* unit degrees */                                       \
        0x09, 0x39,       /* Hat switch (section 4.3) */                           \
        0x81, 0x42,       /* Variable input, null state */                         \
        0x65, 0x00,       /* No units */                                           \
        0x95, 0x01,       /* 1 report field (empty upper nibble) */                \
        0x81, 0x01,       /* Array input */                                        \
        0x26, 0xFF, 0x00, /* 0-255 for analog sticks */                            \
        0x46, 0xFF, 0x00,                                                          \
        0x09, 0x30, /* X (left X) */                                               \
        0x09, 0x31, /* Y (left Y) */                                               \
        0x09, 0x32, /* Z (right X) */                                              \
        0x09, 0x35, /* Rz (right Y) */                                             \
        0x75, 0x08, /* 1 byte per report field */                                  \
        0x95, 0x04,                                                                \
        0x81, 0x02, /* Variable input */                                           \
        0x75, 0x08, /* 1 byte per report field */                                  \
        0x95, 0x01, /* 1 report field */                                           \
        0x81, 0x01, /* Array input */                                              \
        0xC0
