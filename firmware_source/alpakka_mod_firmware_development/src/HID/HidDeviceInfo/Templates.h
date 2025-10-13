#pragma once

#include "Library/common.h"

#define ADDR_NET_NOTIF 0x87
#define ADDR_NET_OUT 0x08
#define ADDR_NET_IN 0x88

#define TEMPLATES_USB_DEVICE_DESCRIPTOR(vid, pid, bcd, str3) \
  0x12,                    /* .bLength */                    \
      0x01,                /* .bDescriptorType */            \
      U16_TO_BYTE(0x0200), /* .bcdUSB */                     \
      0x00,                /* .bDeviceClass */               \
      0x00,                /* .bDeviceSubClass */            \
      0x00,                /* .bDeviceProtocol */            \
      0x40,                /* .bMaxPacketSize0 */            \
      U16_TO_BYTE(vid),    /* .idVendor */                   \
      U16_TO_BYTE(pid),    /* .idProduct */                  \
      U16_TO_BYTE(bcd),    /* .bcdDevice */                  \
      0x01,                /* .iManufacturer */              \
      0x02,                /* .iProduct */                   \
      str3 ? 0x03 : 0x00,  /* .iSerialNumber */              \
      0x01                 /* .bNumConfiguration */

#define TEMPLATES_USB_CONFIGURATION_DESCRIPTOR(wTotalLength, bNumInterfaces, bConfigurationValue, bmAttributes, bMaxPower) \
  0x09,                          /* bLength */                                                                             \
      0x02,                      /* bDescriptorType: configuration */                                                      \
      U16_TO_BYTE(wTotalLength), /* wTotalLength */                                                                        \
      bNumInterfaces,            /* bNumInterfaces */                                                                      \
      bConfigurationValue,       /* bConfigurationValue */                                                                 \
      0x00,                      /* iConfiguration */                                                                      \
      bmAttributes,              /* bmAttributes */                                                                        \
      bMaxPower                  /* bMaxPower */

#define TEMPLATES_USB_DEVICE_QUALIFIER_DESCRIPTOR(bcdUSB, bDeviceClass, bDeviceSubClass, bDeviceProtocol, bNumConfigurations) \
  0x0A,                    /* bLength */                                                                                      \
      0x06,                /* bDescriptorType */                                                                              \
      U16_TO_BYTE(bcdUSB), /* bcdUSB */                                                                                       \
      bDeviceClass,        /* bDeviceClass */                                                                                 \
      bDeviceSubClass,     /* bDeviceSubClass */                                                                              \
      bDeviceProtocol,     /* bDeviceProtocol */                                                                              \
      0x40,                /* bMaxPacketSize0   (64 bytes) */                                                                 \
      bNumConfigurations,  /* bNumConfigurations */                                                                           \
      0x00                 /* bReserved */

#define TEMPLATES_USB_OTHER_SPEED_CONFIG_DESCRIPTOR(wTotalLength, bNumInterfaces, bConfigurationValue, bmAttributes, bMaxPower) \
  0x09,                          /* bLength */                                                                                  \
      0x07,                      /* bDescriptorType */                                                                          \
      U16_TO_BYTE(wTotalLength), /* wTotalLength */                                                                             \
      bNumInterfaces,            /* bNumInterfaces */                                                                           \
      bConfigurationValue,       /* bConfigurationValue */                                                                      \
      0x00,                      /* iConfiguration */                                                                           \
      bmAttributes,              /* bmAttributes */                                                                             \
      bMaxPower                  /* bMaxPower */

#define TEMPLATES_USB_HID_DESCRIPTOR_ONLY_IN(itf_idx, str_idx, boot_protocol, rpt_desc_len, ep_in) \
  /* Interface */                  /**/                                                            \
  0x09,                            /* bLength: Interface Descriptor size */                        \
      0x04,                        /* bDescriptorType: Interface descriptor type */                \
      itf_idx,                     /* bInterfaceNumber: Number of Interface */                     \
      0x00,                        /* bAlternateSetting: Alternate setting */                      \
      0x01,                        /* bNumEndpoints */                                             \
      0x03,                        /* bInterfaceClass: HID */                                      \
      boot_protocol ? 0x01 : 0x00, /* bInterfaceSubClass : 1=BOOT, 0=no boot */                    \
      boot_protocol,               /* nInterfaceProtocol : 0=none, 1=keyboard, 2=mouse */          \
      str_idx,                     /* iInterface: Index of string descriptor */                    \
      /* HID descriptor */         /**/                                                            \
      0x09,                        /* bLength: HID Descriptor size */                              \
      0x21,                        /* bDescriptorType: HID */                                      \
      0x11,                        /* bcdHID: HID Class Spec release number */                     \
      0x01,                                                                                        \
      0x00,                      /* bCountryCode: Hardware target country */                       \
      0x01,                      /* bNumDescriptors: Number of HID class descriptors to follow */  \
      0x22,                      /* bDescriptorType */                                             \
      U16_TO_BYTE(rpt_desc_len), /* wItemLength: Total length of Report descriptor */              \
      /* Endpoint In */          /**/                                                              \
      0x07,                      /* bLength: Endpoint Descriptor size */                           \
      0x05,                      /* bDescriptorType: */                                            \
      ep_in,                     /* bEndpointAddress: Endpoint Address (IN) */                     \
      0x03,                      /* bmAttributes: Interrupt endpoint */                            \
      U16_TO_BYTE(64),           /* wMaxPacketSize: 4 Byte max */                                  \
      1                          /* bInterval: Polling Interval */

#define TEMPLATES_USB_HID_DESCRIPTOR_INOUT(itf_idx, str_idx, boot_protocol, rpt_desc_len, ep_in, ep_out)                                             \
  /************** Descriptor of Custom interface *****************/        /**/                                                                      \
  0x09,                                                                    /* bLength: Interface Descriptor size */                                  \
      0x04,                                                                /* bDescriptorType: Interface descriptor type */                          \
      itf_idx,                                                             /* bInterfaceNumber: Number of Interface */                               \
      0x00,                                                                /* bAlternateSetting: Alternate setting */                                \
      0x02,                                                                /* bNumEndpoints */                                                       \
      0x03,                                                                /* bInterfaceClass: HID */                                                \
      boot_protocol ? 0x01 : 0x00,                                         /* bInterfaceSubClass : 1=BOOT, 0=no boot */                              \
      boot_protocol,                                                       /* nInterfaceProtocol : 0=none, 1=keyboard, 2=mouse */                    \
      str_idx,                                                             /* iInterface: Index of string descriptor */                              \
      /******************** Descriptor of Custom HID ********************/ /**/                                                                      \
      0x09,                                                                /* bLength: HID Descriptor size */                                        \
      0x21,                                                                /* bDescriptorType: HID */                                                \
      0x11,                                                                /* bcdHID: HID Class Spec release number */                               \
      0x01,                                                                                                                                          \
      0x00,                                                                         /* bCountryCode: Hardware target country */                      \
      0x01,                                                                         /* bNumDescriptors: Number of HID class descriptors to follow */ \
      0x22,                                                                         /* bDescriptorType */                                            \
      U16_TO_BYTE(rpt_desc_len),                                                    /* wItemLength: Total length of Report descriptor */             \
      /******************** Descriptor of Custom in endpoint ********************/  /**/                                                             \
      0x07,                                                                         /* bLength: Endpoint Descriptor size */                          \
      0x05,                                                                         /* bDescriptorType: */                                           \
      ep_in,                                                                        /* bEndpointAddress: Endpoint Address (IN) */                    \
      0x03,                                                                         /* bmAttributes: Interrupt endpoint */                           \
      U16_TO_BYTE(64),                                                              /* wMaxPacketSize: 4 Byte max */                                 \
      1,                                                                            /* bInterval: Polling Interval */                                \
      /******************** Descriptor of Custom out endpoint ********************/ /**/                                                             \
      0x07,                                                                         /* bLength: Endpoint Descriptor size */                          \
      0x05,                                                                         /* bDescriptorType: */                                           \
      ep_out,                                                                       /* bEndpointAddress: Endpoint Address (IN) */                    \
      0x03,                                                                         /* bmAttributes: Interrupt endpoint */                           \
      U16_TO_BYTE(64),                                                              /* wMaxPacketSize: 4 Byte max */                                 \
      8                                                                             /* bInterval: Polling Interval */

#define TEMPLATES_USB_WINUSB_DESCRIPTOR(itf_idx, str_idx, ep_in, ep_out) \
  /* Interface */        /**/                                            \
  0x09,                  /* bLength */                                   \
      0x04,              /* bDescriptorType */                           \
      itf_idx,           /* bInterfaceNumber */                          \
      0x00,              /* bAlternateSetting */                         \
      0x02,              /* bNumEndpoints */                             \
      0xFF,              /* bInterfaceClass */                           \
      0xFF,              /* bInterfaceSubClass */                        \
      0x00,              /* bInterfaceProtocol */                        \
      str_idx,           /* iInterface */                                \
      /* Endpoint In */  /**/                                            \
      0x07,              /* bLength */                                   \
      0x05,              /* bDescriptorType */                           \
      ep_in,             /* bEndpointAddress */                          \
      0x02,              /* bmAttributes: Bulk */                        \
      U16_TO_BYTE(64),   /* wMaxPacketSize */                            \
      0,                 /* bInterval */                                 \
      /* Endpoint Out */ /**/                                            \
      0x07,              /* bLength */                                   \
      0x05,              /* bDescriptorType */                           \
      ep_out,            /* bEndpointAddress */                          \
      0x02,              /* bmAttributes: Bulk */                        \
      U16_TO_BYTE(64),   /* wMaxPacketSize */                            \
      0                  /* bInterval */

#define TEMPLATES_USB_MSOS_STRING_DESCRIPTOR_V1(vendor_code) \
  0x12,                     /* Length */                     \
      0x03,                 /* Descriptor type: string */    \
      'M', 0x00, 'S', 0x00, /* Signature */                  \
      'F', 0x00, 'T', 0x00,                                  \
      '1', 0x00, '0', 0x00,                                  \
      '0', 0x00,                                             \
      vendor_code, /* Vendor code */                         \
      0x00         /* Padding */

#define TEMPLATES_USB_MSOS_COMPATIBLE_ID_DESCRIPTOR_HEADER(section_quantity)              \
  (16 + 24 * section_quantity), 0x00, 0x00, 0x00, /* Length */                            \
      0x00, 0x01,                                 /* Version */                           \
      0x04, 0x00,                                 /* Descriptor type: Compatibility ID */ \
      section_quantity, 0x00,                     /* Sections */                          \
      0x00, 0x00, 0x00, 0x00,                     /* Reserved */                          \
      0x00, 0x00                                  /* Reserved */

#define TEMPLATES_USB_WINUSB_MSOS_COMPATIBLE_ID_DESCRIPTOR_SECTION(itf_idx) \
  itf_idx,                /* Interface index */                             \
      0x01,               /* Reserved */                                    \
      'W', 'I', 'N', 'U', /* Compat ID */                                   \
      'S', 'B', 0x00, 0x00,                                                 \
      0x00, 0x00, 0x00, 0x00, /* Sub-compat ID. */                          \
      0x00, 0x00, 0x00, 0x00,                                               \
      0x00, 0x00, 0x00, 0x00, /* Reserved */                                \
      0x00, 0x00              /* Reserved */

#define TEMPLATES_USB_WINUSB_MSOS_COMPATIBLE_ID_DESCRIPTOR \
  TEMPLATES_USB_MSOS_COMPATIBLE_ID_DESCRIPTOR_HEADER(1),   \
      TEMPLATES_USB_WINUSB_MSOS_COMPATIBLE_ID_DESCRIPTOR_SECTION(1)

#define WINUSB_GUID 'K', 0, '0', 0, '0', 0, '8', 0, '0', 0

#define TEMPLATES_USB_WINUSB_MSOS_EXTENDED_PROPERTIES_DESCRIPTOR      \
  0x8E, 0x00, 0x00, 0x00,     /* Length */                            \
      0x00, 0x01,             /* Version */                           \
      0x05, 0x00,             /* Descriptor type: Extented property*/ \
      0x01, 0x00,             /* Sections */                          \
      0x84, 0x00, 0x00, 0x00, /* Section size */                      \
      0x01, 0x00, 0x00, 0x00, /* Data type */                         \
      0x28, 0x00,             /* Property name size */                \
      /* Property name */     /**/                                    \
      'D', 0, 'e', 0, 'v', 0, 'i', 0, 'c', 0, 'e', 0, 'I', 0, 'n', 0, \
      't', 0, 'e', 0, 'r', 0, 'f', 0, 'a', 0, 'c', 0, 'e', 0, 'G', 0, \
      'U', 0, 'I', 0, 'D', 0, 0, 0,                                   \
      /* Data size */ /**/                                            \
      0x4E, 0x00, 0x00, 0x00,                                         \
      /* Data */ /**/                                                 \
      '{', 0, 'A', 0, '0', 0, '0', 0, '6', 0, 'C', 0, '7', 0, 'D', 0, \
      'A', 0, '-', 0, '8', 0, '8', 0, 'A', 0, '4', 0, '-', 0, '4', 0, \
      '7', 0, 'E', 0, 'E', 0, '-', 0, 'A', 0, '7', 0, '5', 0, '2', 0, \
      '-', 0, 'F', 0, 'B', 0, 'C', 0, '4', 0, '2', 0, '2', 0, '5', 0, \
      WINUSB_GUID,                                                    \
      '}', 0, 0, 0
