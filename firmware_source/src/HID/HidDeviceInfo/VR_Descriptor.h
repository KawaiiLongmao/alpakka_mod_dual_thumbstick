#pragma once

#include "Library/cstd_lib.h"

#define VR_CONTROLS_HID_REPORT_DESCRIPTOR(feature_id)                                 \
    0x05, 0x03,                                       /* Usage Page (VR Controls) */  \
        0x09, 0x01,                                   /* Usage (Head Tracker) */      \
        0xA1, 0x01,                                   /* Collection (Application) */  \
        0x09, 0x30,                                   /* Usage (X) */                 \
        0x09, 0x31,                                   /* Usage (Y) */                 \
        0x09, 0x32,                                   /* Usage (Z) */                 \
        0x16, 0x00, 0x80,                             /* Logical Minimum (-32768) */  \
        0x26, 0xFF, 0x7F,                             /* Logical Maximum (32767) */   \
        0x55, 0x0D,                                   /* Unit Exponent (-3 → 毫米) */ \
        0x65, 0x21, /* 位置（3轴，有符号毫米）*/      /* Unit (厘米，实际为毫米) */   \
        0x75, 0x10,                                   /* Report Size (16 bits) */     \
        0x95, 0x03,                                   /* Report Count (3) */          \
        0x81, 0x02,                                   /* Input (Data, Absolute) */    \
        0x09, 0x33,                                   /* Usage (QX) */                \
        0x09, 0x34,                                   /* Usage (QY) */                \
        0x09, 0x35,                                   /* Usage (QZ) */                \
        0x09, 0x36,                                   /* Usage (QW) */                \
        0x16, 0x00, 0x80,                             /* Logical Minimum (-32768) */  \
        0x26, 0xFF, 0x7F,                             /* Logical Maximum (32767) */   \
        0x65, 0x00, /* 四元数（16位有符号，无量纲）*/ /* Unit (None) */               \
        0x75, 0x10,                                   /* Report Size (16 bits) */     \
        0x95, 0x04,                                   /* Report Count (4) */          \
        0x81, 0x02,                                   /* Input (Data, Absolute) */    \
        0xC0,                                         /* End Collection */

// #pragma pack(push, 1)
// struct VR_ControlsReport
// {
//     uint8_t report_id;
//     uint8_t data[63];
// };
// #pragma pack(pop)
