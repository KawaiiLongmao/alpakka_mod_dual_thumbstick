#pragma once

#include <stdint.h>

#pragma pack(push, 1)

/* HID input report id */
#define GENERIC_INPUT_ID 0x03

#define GENERIC_REPORT_MAP                                           \
    0x05, 0x01,                 /* USAGE_PAGE (Generic Desktop) */   \
        0x09, 0x05,             /* USAGE (Game Pad) */               \
        0xa1, 0x01,             /* COLLECTION (Application) */       \
        0x85, GENERIC_INPUT_ID, /*   REPORT_ID (1) */                \
        0x05, 0x01,             /*   USAGE_PAGE (Generic Desktop) */ \
        0x09, 0x30,             /*   USAGE (X) */                    \
        0x09, 0x31,             /*   USAGE (Y) */                    \
        0x09, 0x33,             /*   USAGE (Rx) */                   \
        0x09, 0x34,             /*   USAGE (Ry) */                   \
        0x09, 0x32,             /*   USAGE (Z) */                    \
        0x09, 0x35,             /*   USAGE (Rz) */                   \
        0x16, 0x01, 0x80,       /*   LOGICAL_MINIMUM (-32767) */     \
        0x26, 0xff, 0x7f,       /*   LOGICAL_MAXIMUM (32767) */      \
        0x95, 0x06,             /*   REPORT_COUNT (6) */             \
        0x75, 0x10,             /*   REPORT_SIZE (16) */             \
        0x81, 0x02,             /*   INPUT (Data,Var,Abs) */         \
        0x05, 0x09,             /*   USAGE_PAGE (Button) */          \
        0x19, 0x01,             /*   USAGE_MINIMUM (Button 1) */     \
        0x29, 0x20,             /*   USAGE_MAXIMUM (Button 32) */    \
        0x15, 0x00,             /*   LOGICAL_MINIMUM (0) */          \
        0x25, 0x01,             /*   LOGICAL_MAXIMUM (1) */          \
        0x95, 0x20,             /*   REPORT_COUNT (32) */            \
        0x75, 0x01,             /*   REPORT_SIZE (1) */              \
        0x81, 0x02,             /*   INPUT (Data,Var,Abs) */         \
        0xc0                    /* END_COLLECTION */

typedef struct
{
    int16_t lx;
    int16_t ly;
    int16_t rx;
    int16_t ry;
    int16_t lz;
    int16_t rz;
    uint32_t buttons;
} generic_input_report_t;
