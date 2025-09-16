#pragma once

#include "Library/common.h"
#include "Templates.h"

/* Interface Descriptor: */
#define XUSB_USB_INTERFACE_DESCRIPTOR(itf_idx)                \
    0x09,        /* bLength */                                \
        0x04,    /* bDescriptorType */                        \
        itf_idx, /* bInterfaceNumber */                       \
        0x00,    /* bAlternateSetting */                      \
        0x02,    /* bNumEndPoints */                          \
        0xFF,    /* bInterfaceClass      (Vendor specific) */ \
        0x5D,    /* bInterfaceSubClass    */                  \
        0x01,    /* bInterfaceProtocol    */                  \
        0x00     /* iInterface */

/* Unknown Descriptor: */
#define XUSB_USB_CLASS_SPECIFIC_DESCRIPTOR(in_ep_addr, out_ep_addr) \
    0x10, 0x21, 0x00, 0x01, 0x01, 0x24,                             \
        in_ep_addr, /* IN EndpointAddress */                        \
        0x14,                                                       \
        0x03, 0x00, 0x03, 0x13,                                     \
        out_ep_addr, /* OUT EndpointAddress */                      \
        0x00, 0x03, 0x00

/* Endpoint Descriptor: */
#define XUSB_USB_IN_ENDPOINT_DESCRIPTOR(ep_addr)                                                       \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        ep_addr,             /* bEndpointAddress  (IN endpoint 1) */                                   \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0020), /* wMaxPacketSize    (1 x 32 bytes) */                                    \
        0x01                 /* bInterval         (1 frames [raw is 4]) */

/* Endpoint Descriptor: */
#define XUSB_USB_OUT_ENDPOINT_DESCRIPTOR(ep_addr)                                                      \
    0x07,                    /* bLength */                                                             \
        0x05,                /* bDescriptorType */                                                     \
        ep_addr,             /* bEndpointAddress  (OUT endpoint 1) */                                  \
        0x03,                /* bmAttributes      (Transfer: Interrupt / Synch: None / Usage: Data) */ \
        U16_TO_BYTE(0x0020), /* wMaxPacketSize    (1 x 32 bytes) */                                    \
        0x08                 /* bInterval         (8 frames) */

/* Microsoft OS Descriptor: */
#define XUSB_USB_MSOS_STRING_DESCRIPTOR(vendor_code) \
    TEMPLATES_USB_MSOS_STRING_DESCRIPTOR_V1(vendor_code)

#define XUSB_USB_MSOS_COMPATIBLE_ID_DESCRIPTOR_SECTION(itf_idx) \
    itf_idx,                /* Interface index */               \
        0x01,               /* Reserved */                      \
        'X', 'U', 'S', 'B', /* Compat ID */                     \
        '1', '0', 0x00, 0x00,                                   \
        0x00, 0x00, 0x00, 0x00, /* Sub-compat ID. */            \
        0x00, 0x00, 0x00, 0x00,                                 \
        0x00, 0x00, 0x00, 0x00, /* Reserved */                  \
        0x00, 0x00              /* Reserved */
