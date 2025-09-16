#pragma once

#include "Library/cstd_lib.h"
#include "Library/common.h"

#define GENERIC_GAMEPAD_HID_REPORT_DESCRIPTOR(input_id)        \
    0x05, 0x01,           /* USAGE_PAGE (Generic Desktop) */   \
        0x09, 0x05,       /* USAGE (Game Pad) */               \
        0xa1, 0x01,       /* COLLECTION (Application) */       \
        0x85, input_id,   /*   REPORT_ID (1) */                \
        0x05, 0x01,       /*   USAGE_PAGE (Generic Desktop) */ \
        0x09, 0x30,       /*   USAGE (X) */                    \
        0x09, 0x31,       /*   USAGE (Y) */                    \
        0x09, 0x33,       /*   USAGE (Rx) */                   \
        0x09, 0x34,       /*   USAGE (Ry) */                   \
        0x09, 0x32,       /*   USAGE (Z) */                    \
        0x09, 0x35,       /*   USAGE (Rz) */                   \
        0x16, 0x01, 0x80, /*   LOGICAL_MINIMUM (-32767) */     \
        0x26, 0xff, 0x7f, /*   LOGICAL_MAXIMUM (32767) */      \
        0x95, 0x06,       /*   REPORT_COUNT (6) */             \
        0x75, 0x10,       /*   REPORT_SIZE (16) */             \
        0x81, 0x02,       /*   INPUT (Data,Var,Abs) */         \
        0x05, 0x09,       /*   USAGE_PAGE (Button) */          \
        0x19, 0x01,       /*   USAGE_MINIMUM (Button 1) */     \
        0x29, 0x20,       /*   USAGE_MAXIMUM (Button 32) */    \
        0x15, 0x00,       /*   LOGICAL_MINIMUM (0) */          \
        0x25, 0x01,       /*   LOGICAL_MAXIMUM (1) */          \
        0x95, 0x20,       /*   REPORT_COUNT (32) */            \
        0x75, 0x01,       /*   REPORT_SIZE (1) */              \
        0x81, 0x02,       /*   INPUT (Data,Var,Abs) */         \
        0xc0              /* END_COLLECTION */

namespace GenericGamepadStruct
{
    struct __PACKED InputReport
    {
        uint8_t report_id;
        int16_t lx;
        int16_t ly;
        int16_t rx;
        int16_t ry;
        int16_t lz;
        int16_t rz;
        union
        {
            uint32_t mask;
            struct
            {
                uint32_t btn1 : 1;
                uint32_t btn2 : 1;
                uint32_t btn3 : 1;
                uint32_t btn4 : 1;
                uint32_t l1 : 1;
                uint32_t r1 : 1;
                uint32_t l3 : 1;
                uint32_t r3 : 1;
                uint32_t left : 1;
                uint32_t right : 1;
                uint32_t up : 1;
                uint32_t down : 1;
                uint32_t select : 1;
                uint32_t start : 1;
                uint32_t home : 1;
                uint32_t : 17;
            };
        } buttons;
    };
    static_assert(sizeof(InputReport) == 17, "Expected size error");
}
