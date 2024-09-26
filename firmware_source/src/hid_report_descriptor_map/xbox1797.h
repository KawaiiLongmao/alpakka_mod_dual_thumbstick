#pragma once

#include <stdint.h>

#pragma pack(push, 1)

/* HID input report id */
#define XBOX_1797_HID_REPORT_INPUT_ID01 0x01
#define XBOX_1797_HID_REPORT_INPUT_ID02 0x02
#define XBOX_1797_HID_REPORT_INPUT_ID04 0x04
#define XBOX_1797_HID_REPORT_INPUT_ID05 0x05
#define XBOX_1797_HID_REPORT_INPUT_ID0A 0x0A
/* HID output report id */
#define XBOX_1797_HID_REPORT_OUTPUT_ID03 0x03
/* HID feature report id */
#define XBOX_1797_HID_REPORT_FEATURE_ID06 0x06
#define XBOX_1797_HID_REPORT_FEATURE_ID07 0x07
#define XBOX_1797_HID_REPORT_FEATURE_ID08 0x08
#define XBOX_1797_HID_REPORT_FEATURE_ID09 0x09
#define XBOX_1797_HID_REPORT_FEATURE_ID0B 0x0B

#define XBOX_1797_BT_REPORT_MAP                                                                                                                    \
    0x05, 0x01,                       /* Usage Page (Generic Desktop Ctrls) */                                                                     \
        0x09, 0x05,                   /* Usage (Game Pad) */                                                                                       \
        0xA1, 0x01,                   /* Collection (Application) */                                                                               \
        0x85, 0x01,                   /*   Report ID (1) */                                                                                        \
        0x09, 0x01,                   /*   Usage (Pointer) */                                                                                      \
        0xA1, 0x00,                   /*   Collection (Physical) */                                                                                \
        0x09, 0x30,                   /*     Usage (X) */                                                                                          \
        0x09, 0x31,                   /*     Usage (Y) */                                                                                          \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x27, 0xFF, 0xFF, 0x00, 0x00, /*     Logical Maximum (65534) */                                                                            \
        0x95, 0x02,                   /*     Report Count (2) */                                                                                   \
        0x75, 0x10,                   /*     Report Size (16) */                                                                                   \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0xC0,                         /*   End Collection */                                                                                       \
        0x09, 0x01,                   /*   Usage (Pointer) */                                                                                      \
        0xA1, 0x00,                   /*   Collection (Physical) */                                                                                \
        0x09, 0x32,                   /*     Usage (Z) */                                                                                          \
        0x09, 0x35,                   /*     Usage (Rz) */                                                                                         \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x27, 0xFF, 0xFF, 0x00, 0x00, /*     Logical Maximum (65534) */                                                                            \
        0x95, 0x02,                   /*     Report Count (2) */                                                                                   \
        0x75, 0x10,                   /*     Report Size (16) */                                                                                   \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0xC0,                         /*   End Collection */                                                                                       \
        0x05, 0x02,                   /*   Usage Page (Sim Ctrls) */                                                                               \
        0x09, 0xC5,                   /*   Usage (Brake) */                                                                                        \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                                                  \
        0x26, 0xFF, 0x03,             /*   Logical Maximum (1023) */                                                                               \
        0x95, 0x01,                   /*   Report Count (1) */                                                                                     \
        0x75, 0x0A,                   /*   Report Size (10) */                                                                                     \
        0x81, 0x02,                   /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                                 \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                                                  \
        0x25, 0x00,                   /*   Logical Maximum (0) */                                                                                  \
        0x75, 0x06,                   /*   Report Size (6) */                                                                                      \
        0x95, 0x01,                   /*   Report Count (1) */                                                                                     \
        0x81, 0x03,                   /*   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                                \
        0x05, 0x02,                   /*   Usage Page (Sim Ctrls) */                                                                               \
        0x09, 0xC4,                   /*   Usage (Accelerator) */                                                                                  \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                                                  \
        0x26, 0xFF, 0x03,             /*   Logical Maximum (1023) */                                                                               \
        0x95, 0x01,                   /*   Report Count (1) */                                                                                     \
        0x75, 0x0A,                   /*   Report Size (10) */                                                                                     \
        0x81, 0x02,                   /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                                 \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                                                  \
        0x25, 0x00,                   /*   Logical Maximum (0) */                                                                                  \
        0x75, 0x06,                   /*   Report Size (6) */                                                                                      \
        0x95, 0x01,                   /*   Report Count (1) */                                                                                     \
        0x81, 0x03,                   /*   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                                \
        0x05, 0x01,                   /*   Usage Page (Generic Desktop Ctrls) */                                                                   \
        0x09, 0x39,                   /*   Usage (Hat switch) */                                                                                   \
        0x15, 0x01,                   /*   Logical Minimum (1) */                                                                                  \
        0x25, 0x08,                   /*   Logical Maximum (8) */                                                                                  \
        0x35, 0x00,                   /*   Physical Minimum (0) */                                                                                 \
        0x46, 0x3B, 0x01,             /*   Physical Maximum (315) */                                                                               \
        0x66, 0x14, 0x00,             /*   Unit (System: English Rotation, Length: Centimeter) */                                                  \
        0x75, 0x04,                   /*   Report Size (4) */                                                                                      \
        0x95, 0x01,                   /*   Report Count (1) */                                                                                     \
        0x81, 0x42,                   /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,Null State) */                                       \
        0x75, 0x04,                   /*   Report Size (4) */                                                                                      \
        0x95, 0x01,                   /*   Report Count (1) */                                                                                     \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                                                  \
        0x25, 0x00,                   /*   Logical Maximum (0) */                                                                                  \
        0x35, 0x00,                   /*   Physical Minimum (0) */                                                                                 \
        0x45, 0x00,                   /*   Physical Maximum (0) */                                                                                 \
        0x65, 0x00,                   /*   Unit (None) */                                                                                          \
        0x81, 0x03,                   /*   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                                \
        0x05, 0x09,                   /*   Usage Page (Button) */                                                                                  \
        0x19, 0x01,                   /*   Usage Minimum (0x01) */                                                                                 \
        0x29, 0x0F,                   /*   Usage Maximum (0x0F) */                                                                                 \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                                                  \
        0x25, 0x01,                   /*   Logical Maximum (1) */                                                                                  \
        0x75, 0x01,                   /*   Report Size (1) */                                                                                      \
        0x95, 0x0F,                   /*   Report Count (15) */                                                                                    \
        0x81, 0x02,                   /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                                 \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                                                  \
        0x25, 0x00,                   /*   Logical Maximum (0) */                                                                                  \
        0x75, 0x01,                   /*   Report Size (1) */                                                                                      \
        0x95, 0x01,                   /*   Report Count (1) */                                                                                     \
        0x81, 0x03,                   /*   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                                \
        0x05, 0x0C,                   /*   Usage Page (Consumer) */                                                                                \
        0x0A, 0x24, 0x02,             /*   Usage (AC Back) */                                                                                      \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                                                  \
        0x25, 0x01,                   /*   Logical Maximum (1) */                                                                                  \
        0x95, 0x01,                   /*   Report Count (1) */                                                                                     \
        0x75, 0x01,                   /*   Report Size (1) */                                                                                      \
        0x81, 0x02,                   /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                                 \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                                                  \
        0x25, 0x00,                   /*   Logical Maximum (0) */                                                                                  \
        0x75, 0x07,                   /*   Report Size (7) */                                                                                      \
        0x95, 0x01,                   /*   Report Count (1) */                                                                                     \
        0x81, 0x03,                   /*   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                                \
        0x05, 0x0C,                   /*   Usage Page (Consumer) */                                                                                \
        0x09, 0x01,                   /*   Usage (Consumer Control) */                                                                             \
        0xA1, 0x01,                   /*   Collection (Application) */                                                                             \
        0x0A, 0x81, 0x00,             /*     Usage (Assign Selection) */                                                                           \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x04,                   /*     Report Size (4) */                                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x25, 0x00,                   /*     Logical Maximum (0) */                                                                                \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x04,                   /*     Report Size (4) */                                                                                    \
        0x81, 0x03,                   /*     Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                              \
        0x0A, 0x84, 0x00,             /*     Usage (Enter Channel) */                                                                              \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x04,                   /*     Report Size (4) */                                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x25, 0x00,                   /*     Logical Maximum (0) */                                                                                \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x04,                   /*     Report Size (4) */                                                                                    \
        0x81, 0x03,                   /*     Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                              \
        0x0A, 0x85, 0x00,             /*     Usage (Order Movie) */                                                                                \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x0A, 0x99, 0x00,             /*     Usage (Media Select Security) */                                                                      \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x04,                   /*     Report Size (4) */                                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x25, 0x00,                   /*     Logical Maximum (0) */                                                                                \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x04,                   /*     Report Size (4) */                                                                                    \
        0x81, 0x03,                   /*     Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                              \
        0x0A, 0x9E, 0x00,             /*     Usage (Media Select SAP) */                                                                           \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x0A, 0xA1, 0x00,             /*     Usage (Once) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x0A, 0xA2, 0x00,             /*     Usage (Daily) */                                                                                      \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x0A, 0xA3, 0x00,             /*     Usage (Weekly) */                                                                                     \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x0A, 0xA4, 0x00,             /*     Usage (Monthly) */                                                                                    \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x0A, 0xB9, 0x00,             /*     Usage (Random Play) */                                                                                \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x0A, 0xBA, 0x00,             /*     Usage (Select Disc) */                                                                                \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x0A, 0xBB, 0x00,             /*     Usage (Enter Disc) */                                                                                 \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x0A, 0xBE, 0x00,             /*     Usage (Track Normal) */                                                                               \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x0A, 0xC0, 0x00,             /*     Usage (Frame Forward) */                                                                              \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x0A, 0xC1, 0x00,             /*     Usage (Frame Back) */                                                                                 \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x0A, 0xC2, 0x00,             /*     Usage (Mark) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x0A, 0xC3, 0x00,             /*     Usage (Clear Mark) */                                                                                 \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x0A, 0xC4, 0x00,             /*     Usage (Repeat From Mark) */                                                                           \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x0A, 0xC5, 0x00,             /*     Usage (Return To Mark) */                                                                             \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x0A, 0xC6, 0x00,             /*     Usage (Search Mark Forward) */                                                                        \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x0A, 0xC7, 0x00,             /*     Usage (Search Mark Backwards) */                                                                      \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x0A, 0xC8, 0x00,             /*     Usage (Counter Reset) */                                                                              \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0xC0,                         /*   End Collection */                                                                                       \
        0x05, 0x0C,                   /*   Usage Page (Consumer) */                                                                                \
        0x09, 0x01,                   /*   Usage (Consumer Control) */                                                                             \
        0x85, 0x02,                   /*   Report ID (2) */                                                                                        \
        0xA1, 0x01,                   /*   Collection (Application) */                                                                             \
        0x05, 0x0C,                   /*     Usage Page (Consumer) */                                                                              \
        0x0A, 0x23, 0x02,             /*     Usage (AC Home) */                                                                                    \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x25, 0x01,                   /*     Logical Maximum (1) */                                                                                \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x75, 0x01,                   /*     Report Size (1) */                                                                                    \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x25, 0x00,                   /*     Logical Maximum (0) */                                                                                \
        0x75, 0x07,                   /*     Report Size (7) */                                                                                    \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x81, 0x03,                   /*     Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                              \
        0xC0,                         /*   End Collection */                                                                                       \
        0x05, 0x0F,                   /*   Usage Page (PID Page) */                                                                                \
        0x09, 0x21,                   /*   Usage (0x21) */                                                                                         \
        0x85, 0x03,                   /*   Report ID (3) */                                                                                        \
        0xA1, 0x02,                   /*   Collection (Logical) */                                                                                 \
        0x09, 0x97,                   /*     Usage (0x97) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x25, 0x01,                   /*     Logical Maximum (1) */                                                                                \
        0x75, 0x04,                   /*     Report Size (4) */                                                                                    \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x91, 0x02,                   /*     Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */                 \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x25, 0x00,                   /*     Logical Maximum (0) */                                                                                \
        0x75, 0x04,                   /*     Report Size (4) */                                                                                    \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x91, 0x03,                   /*     Output (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */                \
        0x09, 0x70,                   /*     Usage (0x70) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x25, 0x64,                   /*     Logical Maximum (100) */                                                                              \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x95, 0x04,                   /*     Report Count (4) */                                                                                   \
        0x91, 0x02,                   /*     Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */                 \
        0x09, 0x50,                   /*     Usage (0x50) */                                                                                       \
        0x66, 0x01, 0x10,             /*     Unit (System: SI Linear, Time: Seconds) */                                                            \
        0x55, 0x0E,                   /*     Unit Exponent (-2) */                                                                                 \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x91, 0x02,                   /*     Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */                 \
        0x09, 0xA7,                   /*     Usage (0xA7) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x91, 0x02,                   /*     Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */                 \
        0x65, 0x00,                   /*     Unit (None) */                                                                                        \
        0x55, 0x00,                   /*     Unit Exponent (0) */                                                                                  \
        0x09, 0x7C,                   /*     Usage (0x7C) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x91, 0x02,                   /*     Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */                 \
        0xC0,                         /*   End Collection */                                                                                       \
        0x05, 0x06,                   /*   Usage Page (Generic Dev Ctrls) */                                                                       \
        0x09, 0x20,                   /*   Usage (Battery Strength) */                                                                             \
        0x85, 0x04,                   /*   Report ID (4) */                                                                                        \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                                                  \
        0x26, 0xFF, 0x00,             /*   Logical Maximum (255) */                                                                                \
        0x75, 0x08,                   /*   Report Size (8) */                                                                                      \
        0x95, 0x01,                   /*   Report Count (1) */                                                                                     \
        0x81, 0x02,                   /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                                 \
        0x06, 0x00, 0xFF,             /*   Usage Page (Vendor Defined 0xFF00) */                                                                   \
        0x09, 0x01,                   /*   Usage (0x01) */                                                                                         \
        0xA1, 0x02,                   /*   Collection (Logical) */                                                                                 \
        0x85, 0x06,                   /*     Report ID (6) */                                                                                      \
        0x09, 0x01,                   /*     Usage (0x01) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x25, 0x64,                   /*     Logical Maximum (100) */                                                                              \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0xB1, 0x02,                   /*     Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */                \
        0x09, 0x02,                   /*     Usage (0x02) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x25, 0x64,                   /*     Logical Maximum (100) */                                                                              \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0xB1, 0x02,                   /*     Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */                \
        0x09, 0x03,                   /*     Usage (0x03) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0xB1, 0x02,                   /*     Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */                \
        0x09, 0x04,                   /*     Usage (0x04) */                                                                                       \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x95, 0x3C,                   /*     Report Count (60) */                                                                                  \
        0xB2, 0x02, 0x01,             /*     Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile,Buffered Bytes) */ \
        0xC0,                         /*   End Collection */                                                                                       \
        0x06, 0x00, 0xFF,             /*   Usage Page (Vendor Defined 0xFF00) */                                                                   \
        0x09, 0x02,                   /*   Usage (0x02) */                                                                                         \
        0xA1, 0x02,                   /*   Collection (Logical) */                                                                                 \
        0x85, 0x07,                   /*     Report ID (7) */                                                                                      \
        0x09, 0x05,                   /*     Usage (0x05) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x25, 0x64,                   /*     Logical Maximum (100) */                                                                              \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0xB1, 0x02,                   /*     Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */                \
        0x09, 0x06,                   /*     Usage (0x06) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x25, 0x64,                   /*     Logical Maximum (100) */                                                                              \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0xB1, 0x02,                   /*     Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */                \
        0x09, 0x07,                   /*     Usage (0x07) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x25, 0x64,                   /*     Logical Maximum (100) */                                                                              \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0xB1, 0x02,                   /*     Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */                \
        0xC0,                         /*   End Collection */                                                                                       \
        0x06, 0x00, 0xFF,             /*   Usage Page (Vendor Defined 0xFF00) */                                                                   \
        0x09, 0x03,                   /*   Usage (0x03) */                                                                                         \
        0xA1, 0x02,                   /*   Collection (Logical) */                                                                                 \
        0x85, 0x08,                   /*     Report ID (8) */                                                                                      \
        0x09, 0x08,                   /*     Usage (0x08) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x25, 0x64,                   /*     Logical Maximum (100) */                                                                              \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0xB1, 0x02,                   /*     Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */                \
        0x09, 0x09,                   /*     Usage (0x09) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x25, 0x64,                   /*     Logical Maximum (100) */                                                                              \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0xB1, 0x02,                   /*     Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */                \
        0x09, 0x0A,                   /*     Usage (0x0A) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0xB1, 0x02,                   /*     Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */                \
        0xC0,                         /*   End Collection */                                                                                       \
        0x06, 0x00, 0xFF,             /*   Usage Page (Vendor Defined 0xFF00) */                                                                   \
        0x09, 0x04,                   /*   Usage (0x04) */                                                                                         \
        0xA1, 0x01,                   /*   Collection (Application) */                                                                             \
        0x85, 0x09,                   /*     Report ID (9) */                                                                                      \
        0x09, 0x0B,                   /*     Usage (0x0B) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x25, 0x64,                   /*     Logical Maximum (100) */                                                                              \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0xB1, 0x02,                   /*     Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */                \
        0x09, 0x0C,                   /*     Usage (0x0C) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x25, 0x64,                   /*     Logical Maximum (100) */                                                                              \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0xB1, 0x02,                   /*     Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */                \
        0x09, 0x0D,                   /*     Usage (0x0D) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x25, 0x64,                   /*     Logical Maximum (100) */                                                                              \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0xB1, 0x02,                   /*     Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */                \
        0x09, 0x0E,                   /*     Usage (0x0E) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0xB1, 0x02,                   /*     Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */                \
        0x09, 0x0F,                   /*     Usage (0x0F) */                                                                                       \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x95, 0x3C,                   /*     Report Count (60) */                                                                                  \
        0xB2, 0x02, 0x01,             /*     Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile,Buffered Bytes) */ \
        0xC0,                         /*   End Collection */                                                                                       \
        0x06, 0x00, 0xFF,             /*   Usage Page (Vendor Defined 0xFF00) */                                                                   \
        0x09, 0x05,                   /*   Usage (0x05) */                                                                                         \
        0xA1, 0x01,                   /*   Collection (Application) */                                                                             \
        0x85, 0x0A,                   /*     Report ID (10) */                                                                                     \
        0x09, 0x10,                   /*     Usage (0x10) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x27, 0xFF, 0xFF, 0xFF, 0x7F, /*     Logical Maximum (2147483646) */                                                                       \
        0x75, 0x20,                   /*     Report Size (32) */                                                                                   \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x09, 0x11,                   /*     Usage (0x11) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x27, 0xFF, 0xFF, 0xFF, 0x7F, /*     Logical Maximum (2147483646) */                                                                       \
        0x75, 0x20,                   /*     Report Size (32) */                                                                                   \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x09, 0x12,                   /*     Usage (0x12) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x95, 0x02,                   /*     Report Count (2) */                                                                                   \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0x09, 0x13,                   /*     Usage (0x13) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x26, 0xFF, 0x00,             /*     Logical Maximum (255) */                                                                              \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0x81, 0x02,                   /*     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0xC0,                         /*   End Collection */                                                                                       \
        0x06, 0x00, 0xFF,             /*   Usage Page (Vendor Defined 0xFF00) */                                                                   \
        0x09, 0x06,                   /*   Usage (0x06) */                                                                                         \
        0xA1, 0x02,                   /*   Collection (Logical) */                                                                                 \
        0x85, 0x0B,                   /*     Report ID (11) */                                                                                     \
        0x09, 0x14,                   /*     Usage (0x14) */                                                                                       \
        0x15, 0x00,                   /*     Logical Minimum (0) */                                                                                \
        0x25, 0x64,                   /*     Logical Maximum (100) */                                                                              \
        0x75, 0x08,                   /*     Report Size (8) */                                                                                    \
        0x95, 0x01,                   /*     Report Count (1) */                                                                                   \
        0xB1, 0x02,                   /*     Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */                \
        0xC0,                         /*   End Collection */                                                                                       \
        0xC0,                         /* End Collection */                                                                                         \
        0x05, 0x01,                   /* Usage Page (Generic Desktop Ctrls) */                                                                     \
        0x09, 0x06,                   /* Usage (Keyboard) */                                                                                       \
        0xA1, 0x01,                   /* Collection (Application) */                                                                               \
        0x85, 0x05,                   /*   Report ID (5) */                                                                                        \
        0x05, 0x07,                   /*   Usage Page (Kbrd/Keypad) */                                                                             \
        0x19, 0xE0,                   /*   Usage Minimum (0xE0) */                                                                                 \
        0x29, 0xE7,                   /*   Usage Maximum (0xE7) */                                                                                 \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                                                  \
        0x25, 0x01,                   /*   Logical Maximum (1) */                                                                                  \
        0x75, 0x01,                   /*   Report Size (1) */                                                                                      \
        0x95, 0x08,                   /*   Report Count (8) */                                                                                     \
        0x81, 0x02,                   /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                                 \
        0x95, 0x01,                   /*   Report Count (1) */                                                                                     \
        0x75, 0x08,                   /*   Report Size (8) */                                                                                      \
        0x81, 0x03,                   /*   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                                \
        0x95, 0x06,                   /*   Report Count (6) */                                                                                     \
        0x75, 0x08,                   /*   Report Size (8) */                                                                                      \
        0x15, 0x00,                   /*   Logical Minimum (0) */                                                                                  \
        0x25, 0x65,                   /*   Logical Maximum (101) */                                                                                \
        0x05, 0x07,                   /*   Usage Page (Kbrd/Keypad) */                                                                             \
        0x19, 0x00,                   /*   Usage Minimum (0x00) */                                                                                 \
        0x29, 0x65,                   /*   Usage Maximum (0x65) */                                                                                 \
        0x81, 0x00,                   /*   Input (Data,Array,Abs,No Wrap,Linear,Preferred State,No Null Position) */                               \
        0xC0,                         /* End Collection */
// 1037 bytes

enum Xbox1797_Direction
{
    Xbox1797_Direction_None = 0,
    Xbox1797_Direction_North,
    Xbox1797_Direction_NorthEast,
    Xbox1797_Direction_East,
    Xbox1797_Direction_SouthEast,
    Xbox1797_Direction_South,
    Xbox1797_Direction_SouthWest,
    Xbox1797_Direction_West,
    Xbox1797_Direction_NorthWest = 8
};

typedef struct
{
    // uint8_t  reportId;                                 // Report ID = 0x01 (1)
    // Collection: CA:GamePad CP:Pointer
    uint16_t X;                                               // Usage 0x00010030: X, Value = 0 to 65535
    uint16_t Y;                                               // Usage 0x00010031: Y, Value = 0 to 65535
    uint16_t Z;                                               // Usage 0x00010032: Z, Value = 0 to 65535
    uint16_t Rz;                                              // Usage 0x00010035: Rz, Value = 0 to 65535
                                                              // Collection: CA:GamePad
    uint16_t Brake : 10;                                      // Usage 0x000200C5: Brake, Value = 0 to 1023
    uint8_t : 6;                                              // Pad
    uint16_t Accelerator : 10;                                // Usage 0x000200C4: Accelerator, Value = 0 to 1023
    uint8_t : 6;                                              // Pad
    enum Xbox1797_Direction HatSwitch : 4;                    // Usage 0x00010039: Hat switch, Value = 1 to 8, Physical = (Value - 1) x 45 in degrees
    uint8_t : 4;                                              // Pad
    uint8_t ButtonA : 1;                                      // Usage 0x00090001: Button 1 Primary/trigger, Value = 0 to 1
    uint8_t ButtonB : 1;                                      // Usage 0x00090002: Button 2 Secondary, Value = 0 to 1
    uint8_t Button3 : 1;                                      // Usage 0x00090003: Button 3 Tertiary, Value = 0 to 1
    uint8_t ButtonX : 1;                                      // Usage 0x00090004: Button 4, Value = 0 to 1
    uint8_t ButtonY : 1;                                      // Usage 0x00090005: Button 5, Value = 0 to 1
    uint8_t Button6 : 1;                                      // Usage 0x00090006: Button 6, Value = 0 to 1
    uint8_t ButtonLB : 1;                                     // Usage 0x00090007: Button 7, Value = 0 to 1
    uint8_t ButtonRB : 1;                                     // Usage 0x00090008: Button 8, Value = 0 to 1
    uint8_t Button9 : 1;                                      // Usage 0x00090009: Button 9, Value = 0 to 1
    uint8_t Button10 : 1;                                     // Usage 0x0009000A: Button 10, Value = 0 to 1
    uint8_t ButtonBack : 1;                                   // Usage 0x0009000B: Button 11, Value = 0 to 1
    uint8_t ButtonStart : 1;                                  // Usage 0x0009000C: Button 12, Value = 0 to 1
    uint8_t ButtonXbox : 1;                                   // Usage 0x0009000D: Button 13, Value = 0 to 1
    uint8_t ButtonLS : 1;                                     // Usage 0x0009000E: Button 14, Value = 0 to 1
    uint8_t ButtonRS : 1;                                     // Usage 0x0009000F: Button 15, Value = 0 to 1
    uint8_t : 1;                                              // Pad
    uint8_t CD_GamePadAcBack : 1;                             // Usage 0x000C0224: AC Back, Value = 0 to 1
    uint8_t : 7;                                              // Pad
                                                              // Collection: CA:GamePad CA:ConsumerControl
    uint8_t CD_GamePadConsumerControlAssignSelection : 4;     // Usage 0x000C0081: Assign Selection, Value = 0 to 255
    uint8_t : 4;                                              // Pad
    uint8_t CD_GamePadConsumerControlEnterChannel : 4;        // Usage 0x000C0084: Enter Channel, Value = 0 to 255
    uint8_t : 4;                                              // Pad
    uint8_t CD_GamePadConsumerControlOrderMovie;              // Usage 0x000C0085: Order Movie, Value = 0 to 255
    uint8_t CD_GamePadConsumerControlMediaSelectSecurity : 4; // Usage 0x000C0099: Media Select Security, Value = 0 to 255
    uint8_t : 4;                                              // Pad
    uint8_t CD_GamePadConsumerControlMediaSelectSap;          // Usage 0x000C009E: Media Select SAP, Value = 0 to 255
    uint8_t CD_GamePadConsumerControlOnce;                    // Usage 0x000C00A1: Once, Value = 0 to 255
    uint8_t CD_GamePadConsumerControlDaily;                   // Usage 0x000C00A2: Daily, Value = 0 to 255
    uint8_t CD_GamePadConsumerControlWeekly;                  // Usage 0x000C00A3: Weekly, Value = 0 to 255
    uint8_t CD_GamePadConsumerControlMonthly;                 // Usage 0x000C00A4: Monthly, Value = 0 to 255
    uint8_t CD_GamePadConsumerControlRandomPlay;              // Usage 0x000C00B9: Random Play, Value = 0 to 255
    uint8_t CD_GamePadConsumerControlSelectDisc;              // Usage 0x000C00BA: Select Disc, Value = 0 to 255
    uint8_t CD_GamePadConsumerControlEnterDisc;               // Usage 0x000C00BB: Enter Disc, Value = 0 to 255
    uint8_t CD_GamePadConsumerControlTrackNormal;             // Usage 0x000C00BE: Track Normal, Value = 0 to 255
    uint8_t CD_GamePadConsumerControlFrameForward;            // Usage 0x000C00C0: Frame Forward, Value = 0 to 255
    uint8_t CD_GamePadConsumerControlFrameBack;               // Usage 0x000C00C1: Frame Back, Value = 0 to 255
    uint8_t CD_GamePadConsumerControlMark;                    // Usage 0x000C00C2: Mark, Value = 0 to 255
    uint8_t CD_GamePadConsumerControlClearMark;               // Usage 0x000C00C3: Clear Mark, Value = 0 to 255
    uint8_t CD_GamePadConsumerControlRepeatFromMark;          // Usage 0x000C00C4: Repeat From Mark, Value = 0 to 255
    uint8_t CD_GamePadConsumerControlReturnToMark;            // Usage 0x000C00C5: Return To Mark, Value = 0 to 255
    uint8_t CD_GamePadConsumerControlSearchMarkForward;       // Usage 0x000C00C6: Search Mark Forward, Value = 0 to 255
    uint8_t CD_GamePadConsumerControlSearchMarkBackwards;     // Usage 0x000C00C7: Search Mark Backwards, Value = 0 to 255
    uint8_t CD_GamePadConsumerControlCounterReset;            // Usage 0x000C00C8: Counter Reset, Value = 0 to 255
} xbox1797BtInputReport01_t;

typedef struct
{
    uint8_t reportId;                            // Report ID = 0x02 (2)
                                                 // Collection: CA:GamePad CA:ConsumerControl
    uint8_t CD_GamePadConsumerControlAcHome : 1; // Usage 0x000C0223: AC Home, Value = 0 to 1
    uint8_t : 7;                                 // Pad
} xbox1797BtInputReport02_t;

typedef struct
{
    uint8_t reportId;            // Report ID = 0x06 (6)
                                 // Collection: CA:GamePad CL:
    uint8_t VEN_GamePad0001;     // Usage 0xFF000001: , Value = 0 to 100
    uint8_t VEN_GamePad0002;     // Usage 0xFF000002: , Value = 0 to 100
    uint8_t VEN_GamePad0003;     // Usage 0xFF000003: , Value = 0 to 255
    uint8_t VEN_GamePad0004[60]; // Usage 0xFF000004: , Value = 0 to 255
} xbox1797BtFeatureReport06_t;

typedef struct
{
    uint8_t reportId;        // Report ID = 0x07 (7)
                             // Collection: CA:GamePad CL:
    uint8_t VEN_GamePad0005; // Usage 0xFF000005: , Value = 0 to 100
    uint8_t VEN_GamePad0006; // Usage 0xFF000006: , Value = 0 to 100
    uint8_t VEN_GamePad0007; // Usage 0xFF000007: , Value = 0 to 100
} xbox1797BtFeatureReport07_t;

typedef struct
{
    uint8_t reportId;        // Report ID = 0x08 (8)
                             // Collection: CA:GamePad CL:
    uint8_t VEN_GamePad0008; // Usage 0xFF000008: , Value = 0 to 100
    uint8_t VEN_GamePad0009; // Usage 0xFF000009: , Value = 0 to 100
    uint8_t VEN_GamePad000A; // Usage 0xFF00000A: , Value = 0 to 255
} xbox1797BtFeatureReport08_t;

typedef struct
{
    uint8_t reportId;            // Report ID = 0x09 (9)
                                 // Collection: CA:GamePad CA:
    uint8_t VEN_GamePad000B;     // Usage 0xFF00000B: , Value = 0 to 100
    uint8_t VEN_GamePad000C;     // Usage 0xFF00000C: , Value = 0 to 100
    uint8_t VEN_GamePad000D;     // Usage 0xFF00000D: , Value = 0 to 100
    uint8_t VEN_GamePad000E;     // Usage 0xFF00000E: , Value = 0 to 255
    uint8_t VEN_GamePad000F[60]; // Usage 0xFF00000F: , Value = 0 to 255
} xbox1797BtFeatureReport09_t;

typedef struct
{
    uint8_t reportId;                   // Report ID = 0x04 (4)
                                        // Collection: CA:GamePad
    uint8_t GDC_GamePadBatteryStrength; // Usage 0x00060020: Battery Strength, Value = 0 to 255
} xbox1797BtInputReport04_t;

typedef struct
{
    uint8_t reportId;                                        // Report ID = 0x03 (3)
                                                             // Collection: CA:GamePad CL:SetEffectReport
    uint8_t PID_GamePadSetEffectReportDcEnableActuators : 4; // Usage 0x000F0097: DC Enable Actuators, Value = 0 to 1
    uint8_t : 4;                                             // Pad
    uint8_t PID_GamePadSetEffectReportMagnitude[4];          // Usage 0x000F0070: Magnitude, Value = 0 to 100
    uint8_t PID_GamePadSetEffectReportDuration;              // Usage 0x000F0050: Duration, Value = 0 to 255, Physical = Value in 10⁻² s units
    uint8_t PID_GamePadSetEffectReportStartDelay;            // Usage 0x000F00A7: Start Delay, Value = 0 to 255, Physical = Value in 10⁻² s units
    uint8_t PID_GamePadSetEffectReportLoopCount;             // Usage 0x000F007C: Loop Count, Value = 0 to 255
} xbox1797BtOutputReport03_t;

typedef struct
{
    uint8_t reportId;           // Report ID = 0x0A (10)
                                // Collection: CA:GamePad CA:
    uint32_t VEN_GamePad0010;   // Usage 0xFF000010: , Value = 0 to 2147483647
    uint32_t VEN_GamePad0011;   // Usage 0xFF000011: , Value = 0 to 2147483647
    uint8_t VEN_GamePad0012[2]; // Usage 0xFF000012: , Value = 0 to 255
    uint8_t VEN_GamePad0013;    // Usage 0xFF000013: , Value = 0 to 255
} xbox1797BtInputReport0A_t;

typedef struct
{
    uint8_t reportId;        // Report ID = 0x0B (11)
                             // Collection: CA:GamePad CL:
    uint8_t VEN_GamePad0014; // Usage 0xFF000014: , Value = 0 to 100
} xbox1797BtFeatureReport0B_t;

typedef struct
{
    uint8_t reportId;                            // Report ID = 0x05 (5)
                                                 // Collection: CA:Keyboard
    uint8_t KB_KeyboardKeyboardLeftControl : 1;  // Usage 0x000700E0: Keyboard Left Control, Value = 0 to 1
    uint8_t KB_KeyboardKeyboardLeftShift : 1;    // Usage 0x000700E1: Keyboard Left Shift, Value = 0 to 1
    uint8_t KB_KeyboardKeyboardLeftAlt : 1;      // Usage 0x000700E2: Keyboard Left Alt, Value = 0 to 1
    uint8_t KB_KeyboardKeyboardLeftGui : 1;      // Usage 0x000700E3: Keyboard Left GUI, Value = 0 to 1
    uint8_t KB_KeyboardKeyboardRightControl : 1; // Usage 0x000700E4: Keyboard Right Control, Value = 0 to 1
    uint8_t KB_KeyboardKeyboardRightShift : 1;   // Usage 0x000700E5: Keyboard Right Shift, Value = 0 to 1
    uint8_t KB_KeyboardKeyboardRightAlt : 1;     // Usage 0x000700E6: Keyboard Right Alt, Value = 0 to 1
    uint8_t KB_KeyboardKeyboardRightGui : 1;     // Usage 0x000700E7: Keyboard Right GUI, Value = 0 to 1
    uint8_t pad_2;                               // Pad
    uint8_t Keyboard[6];                         // Value = 0 to 101
} xbox1797BtInputReport05_t;
