#pragma once

#include "Library/cstd_lib.h"
#include "Library/common.h"

/* HID input report id */
#define HORI_POKKEN_HID_INPUT_ID 0x00
/* HID output report id */
#define HORI_POKKEN_HID_OUTPUT_ID 0x00

/* Device Descriptor: */
#define HORI_POKKEN_USB_DEVICE_DESCRIPTOR                                                            \
    0x12,                    /* bLength */                                                           \
        0x01,                /* bDescriptorType (Device) */                                          \
        U16_TO_BYTE(0x0200), /* bcdUSB 2.00 */                                                       \
        0x00,                /* bDeviceClass (Use class information in the Interface Descriptors) */ \
        0x00,                /* bDeviceSubClass */                                                   \
        0x00,                /* bDeviceProtocol */                                                   \
        0x40,                /* bMaxPacketSize0 64 */                                                \
        U16_TO_BYTE(0x0F0D), /* idVendor 0x0F0D */                                                   \
        U16_TO_BYTE(0x0092), /* idProduct 0x92 */                                                    \
        U16_TO_BYTE(0x0100), /* bcdDevice 2.00 */                                                    \
        0x01,                /* iManufacturer (String Index) */                                      \
        0x02,                /* iProduct (String Index) */                                           \
        0x00,                /* iSerialNumber (String Index) */                                      \
        0x01                 /* bNumConfigurations 1 */

/* Configuration Descriptor: */
#define HORI_POKKEN_USB_CONFIGURATION_DESCRIPTOR          \
    0x09,           /* bLength */                         \
        0x02,       /* bDescriptorType (Configuration) */ \
        0x29, 0x00, /* wTotalLength 41 */                 \
        0x01,       /* bNumInterfaces 1 */                \
        0x01,       /* bConfigurationValue */             \
        0x00,       /* iConfiguration (String Index) */   \
        0x80,       /* bmAttributes */                    \
        0xFA        /* bMaxPower 500mA */

/* Interface Descriptor: */
#define HORI_POKKEN_USB_INTERFACE_DESCRIPTOR    \
    0x09,     /* bLength */                     \
        0x04, /* bDescriptorType (Interface) */ \
        0x00, /* bInterfaceNumber 0 */          \
        0x00, /* bAlternateSetting */           \
        0x02, /* bNumEndpoints 2 */             \
        0x03, /* bInterfaceClass */             \
        0x00, /* bInterfaceSubClass */          \
        0x00, /* bInterfaceProtocol */          \
        0x00  /* iInterface (String Index) */

/* HID Descriptor: */
#define HORI_POKKEN_USB_HID_DESCRIPTOR             \
    0x09,           /* bLength */                  \
        0x21,       /* bDescriptorType (HID) */    \
        0x11, 0x01, /* bcdHID 1.11 */              \
        0x00,       /* bCountryCode */             \
        0x01,       /* bNumDescriptors */          \
        0x22,       /* bDescriptorType[0] (HID) */ \
        0x56, 0x00  /* wDescriptorLength[0] 86 */

/* Endpoint Descriptor: */
#define HORI_POKKEN_USB_OUT_ENDPOINT_DESCRIPTOR      \
    0x07,           /* bLength */                    \
        0x05,       /* bDescriptorType (Endpoint) */ \
        0x02,       /* bEndpointAddress (OUT/H2D) */ \
        0x03,       /* bmAttributes (Interrupt) */   \
        0x40, 0x00, /* wMaxPacketSize 64 */          \
        0x01        /* bInterval 1 (unit depends on device speed) */

/* Endpoint Descriptor: */
#define HORI_POKKEN_USB_ENDPOINT_IN_DESCRIPTOR       \
    0x07,           /* bLength */                    \
        0x05,       /* bDescriptorType (Endpoint) */ \
        0x81,       /* bEndpointAddress (IN/D2H) */  \
        0x03,       /* bmAttributes (Interrupt) */   \
        0x40, 0x00, /* wMaxPacketSize 64 */          \
        0x01        /* bInterval 1 (unit depends on device speed) */

/* String Descriptor Table */
#define HORI_POKKEN_USB_STRING_DESCRIPTOR_0 (const char[]){0x09, 0x04}
#define HORI_POKKEN_USB_STRING_MANUFACTURER "HORI CO.,LTD."
#define HORI_POKKEN_USB_STRING_PRODUCT "POKKEN CONTROLLER"

#define HORI_POKKEN_HID_REPORT_DESCRIPTOR                                                                            \
    0x05, 0x01,           /* Usage Page (Generic Desktop Ctrls) */                                                   \
        0x09, 0x05,       /* Usage (Game Pad) */                                                                     \
        0xA1, 0x01,       /* Collection (Application) */                                                             \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                \
        0x25, 0x01,       /*   Logical Maximum (1) */                                                                \
        0x35, 0x00,       /*   Physical Minimum (0) */                                                               \
        0x45, 0x01,       /*   Physical Maximum (1) */                                                               \
        0x75, 0x01,       /*   Report Size (1) */                                                                    \
        0x95, 0x10,       /*   Report Count (16) */                                                                  \
        0x05, 0x09,       /*   Usage Page (Button) */                                                                \
        0x19, 0x01,       /*   Usage Minimum (0x01) */                                                               \
        0x29, 0x10,       /*   Usage Maximum (0x10) */                                                               \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */               \
        0x05, 0x01,       /*   Usage Page (Generic Desktop Ctrls) */                                                 \
        0x25, 0x07,       /*   Logical Maximum (7) */                                                                \
        0x46, 0x3B, 0x01, /*   Physical Maximum (315) */                                                             \
        0x75, 0x04,       /*   Report Size (4) */                                                                    \
        0x95, 0x01,       /*   Report Count (1) */                                                                   \
        0x65, 0x14,       /*   Unit (System: English Rotation, Length: Centimeter) */                                \
        0x09, 0x39,       /*   Usage (Hat switch) */                                                                 \
        0x81, 0x42,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,Null State) */                     \
        0x65, 0x00,       /*   Unit (None) */                                                                        \
        0x95, 0x01,       /*   Report Count (1) */                                                                   \
        0x81, 0x01,       /*   Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position) */            \
        0x26, 0xFF, 0x00, /*   Logical Maximum (255) */                                                              \
        0x46, 0xFF, 0x00, /*   Physical Maximum (255) */                                                             \
        0x09, 0x30,       /*   Usage (X) */                                                                          \
        0x09, 0x31,       /*   Usage (Y) */                                                                          \
        0x09, 0x32,       /*   Usage (Z) */                                                                          \
        0x09, 0x35,       /*   Usage (Rz) */                                                                         \
        0x75, 0x08,       /*   Report Size (8) */                                                                    \
        0x95, 0x04,       /*   Report Count (4) */                                                                   \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */               \
        0x06, 0x00, 0xFF, /*   Usage Page (Vendor Defined 0xFF00) */                                                 \
        0x09, 0x20,       /*   Usage (0x20) */                                                                       \
        0x95, 0x01,       /*   Report Count (1) */                                                                   \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */               \
        0x0A, 0x21, 0x26, /*   Usage (0x2621) */                                                                     \
        0x95, 0x08,       /*   Report Count (8) */                                                                   \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0xC0              /* End Collection */

namespace HoriPokkenStruct
{
    enum Direction : uint8_t
    {
        North = 0,
        NorthEast,
        East,
        SouthEast,
        South,
        SouthWest,
        West,
        NorthWest,
        None = 8
    };

    struct __PACKED InputReport
    {
        uint8_t ReportID;
        union
        {
            uint16_t Mask;
            struct
            {
                uint16_t Y : 1;
                uint16_t B : 1;
                uint16_t A : 1;
                uint16_t X : 1;
                uint16_t L : 1;
                uint16_t R : 1;
                uint16_t ZL : 1;
                uint16_t ZR : 1;
                uint16_t Minus : 1;
                uint16_t Plus : 1;
                uint16_t LS : 1;
                uint16_t RS : 1;
                uint16_t Home : 1;
                uint16_t Capture : 1;
                uint16_t btn15 : 1;
                uint16_t btn16 : 1;
            };
        } buttons;
        Direction DPad : 4;
        Direction : 4;
        uint8_t LeftStickX;
        uint8_t LeftStickY;
        uint8_t RightStickX;
        uint8_t RightStickY;
        uint8_t unknown;
    };
    static_assert(sizeof(InputReport) == 9, "Expected size error");

    struct __PACKED OutputReport
    {
        uint8_t report_id;
        uint8_t unknown[8];
    };
    static_assert(sizeof(InputReport) == 9, "Expected size error");
}
