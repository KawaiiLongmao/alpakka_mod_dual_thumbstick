#pragma once

#include <stdint.h>

#pragma pack(push, 1)

/* HID input report id */
#define MOUSE_INPUT_ID 0x43

#define CUSTOM_MOUSE_REPORT_MAP                                           \
    0x05, 0x01,               /* USAGE_PAGE (Generic Desktop) */          \
        0x09, 0x02,           /* USAGE (Mouse) */                         \
        0xa1, 0x01,           /* COLLECTION (Application) */              \
        0x85, MOUSE_INPUT_ID, /*   REPORT_ID (1) */                       \
        0x09, 0x01,           /*   USAGE (Pointer) */                     \
        0xa1, 0x00,           /*   COLLECTION (Physical) */               \
        0x05, 0x09,           /*     USAGE_PAGE (Button) */               \
        0x19, 0x01,           /*     USAGE_MINIMUM (Button 1) */          \
        0x29, 0x05,           /*     USAGE_MAXIMUM (Button 5) */          \
        0x15, 0x00,           /*     LOGICAL_MINIMUM (0) */               \
        0x25, 0x01,           /*     LOGICAL_MAXIMUM (1) */               \
        0x95, 0x05,           /*     REPORT_COUNT (5) */                  \
        0x75, 0x01,           /*     REPORT_SIZE (1) */                   \
        0x81, 0x02,           /*     INPUT (Data,Var,Abs) */              \
        0x95, 0x01,           /*     REPORT_COUNT (1) */                  \
        0x75, 0x03,           /*     REPORT_SIZE (3) */                   \
        0x81, 0x03,           /*     INPUT (Cnst,Var,Abs) */              \
        0x05, 0x01,           /*     USAGE_PAGE (Generic Desktop) */      \
        0x09, 0x30,           /*     USAGE (X) */                         \
        0x09, 0x31,           /*     USAGE (Y) */                         \
        0x16, 0x01, 0x80,     /*     LOGICAL_MINIMUM (-32767) */          \
        0x26, 0xff, 0x7f,     /*     LOGICAL_MAXIMUM (32767) */           \
        0x95, 0x02,           /*     REPORT_COUNT (2) */                  \
        0x75, 0x10,           /*     REPORT_SIZE (16) */                  \
        0x81, 0x06,           /*     INPUT (Data,Var,Rel) */              \
        0x09, 0x38,           /*     USAGE (Wheel) */                     \
        0x15, 0x81,           /*     LOGICAL_MINIMUM (-127) */            \
        0x25, 0x7f,           /*     LOGICAL_MAXIMUM (127) */             \
        0x95, 0x01,           /*     REPORT_COUNT (1) */                  \
        0x75, 0x08,           /*     REPORT_SIZE (8) */                   \
        0x81, 0x06,           /*     INPUT (Data,Var,Rel) */              \
        0x05, 0x0c,           /*     USAGE_PAGE (Consumer Devices) */     \
        0x0a, 0x38, 0x02,     /*     USAGE (HID_USAGE_CONSUMER_AC_PAN) */ \
        0x15, 0x81,           /*     LOGICAL_MINIMUM (-127) */            \
        0x25, 0x7f,           /*     LOGICAL_MAXIMUM (127) */             \
        0x95, 0x01,           /*     REPORT_COUNT (1) */                  \
        0x75, 0x08,           /*     REPORT_SIZE (8) */                   \
        0x81, 0x06,           /*     INPUT (Data,Var,Rel) */              \
        0xc0,                 /*   END_COLLECTION */                      \
        0xc0                  /* END_COLLECTION */

#define MOUSE_REPORT_MAP                                             \
    0x05, 0x01,               /* USAGE_PAGE (Generic Desktop) */     \
        0x09, 0x02,           /* USAGE (Mouse) */                    \
        0xa1, 0x01,           /* COLLECTION (Application) */         \
        0x85, MOUSE_INPUT_ID, /*   REPORT_ID (1) */                  \
        0x09, 0x01,           /*   USAGE (Pointer) */                \
        0xa1, 0x00,           /*   COLLECTION (Physical) */          \
        0x05, 0x09,           /*     USAGE_PAGE (Button) */          \
        0x19, 0x01,           /*     USAGE_MINIMUM (Button 1) */     \
        0x29, 0x03,           /*     USAGE_MAXIMUM (Button 3) */     \
        0x15, 0x00,           /*     LOGICAL_MINIMUM (0) */          \
        0x25, 0x01,           /*     LOGICAL_MAXIMUM (1) */          \
        0x95, 0x03,           /*     REPORT_COUNT (3) */             \
        0x75, 0x01,           /*     REPORT_SIZE (1) */              \
        0x81, 0x02,           /*     INPUT (Data,Var,Abs) */         \
        0x95, 0x01,           /*     REPORT_COUNT (1) */             \
        0x75, 0x05,           /*     REPORT_SIZE (5) */              \
        0x81, 0x03,           /*     INPUT (Cnst,Var,Abs) */         \
        0x05, 0x01,           /*     USAGE_PAGE (Generic Desktop) */ \
        0x09, 0x30,           /*     USAGE (X) */                    \
        0x09, 0x31,           /*     USAGE (Y) */                    \
        0x09, 0x38,           /*     USAGE (Wheel) */                \
        0x15, 0x81,           /*     LOGICAL_MINIMUM (-127) */       \
        0x25, 0x7f,           /*     LOGICAL_MAXIMUM (127) */        \
        0x95, 0x03,           /*     REPORT_COUNT (3) */             \
        0x75, 0x08,           /*     REPORT_SIZE (8) */              \
        0x81, 0x06,           /*     INPUT (Data,Var,Rel) */         \
        0xc0,                 /*   END_COLLECTION */                 \
        0xc0                  /* END_COLLECTION */

typedef struct
{
    // uint8_t report_id;
    uint8_t buttons;
    int8_t x;
    int8_t y;
    int8_t wheel;
} mouse_input_report_t;

typedef struct
{
    uint8_t buttons;
    int16_t x;
    int16_t y;
    int8_t vertical_wheel;
    int8_t horizontal_wheel;
} custom_mouse_input_report_t;
