#pragma once

#include <stdint.h>

#pragma pack(push, 1)

/* HID input report id */
#define KEYBRD_INPUT_ID 0x42

#define KEYBRD_REPORT_MAP                                                                    \
    0x05, 0x01,                /* Usage Page (Generic Desktop) */                            \
        0x09, 0x06,            /* Usage (Keyboard) */                                        \
        0xA1, 0x01,            /* Collection (Application) */                                \
        0x85, KEYBRD_INPUT_ID, /* Report Id (1) */                                           \
        0x05, 0x07,            /* Usage Page (Keyboard) */                                   \
        0x19, 0xE0,            /* Usage Minimum (Keyboard Left Control) */                   \
        0x29, 0xE7,            /* Usage Maximum (Keyboard Right GUI) */                      \
        0x15, 0x00,            /* Logical minimum (0) */                                     \
        0x25, 0x01,            /* Logical maximum (1) */                                     \
        0x75, 0x01,            /* Report Size (1) */                                         \
        0x95, 0x08,            /* Report Count (8) */                                        \
        0x81, 0x02,            /* Input (data,Value,Absolute,Bit Field) */                   \
        0x95, 0x05,            /* Report Count (5) */                                        \
        0x05, 0x08,            /* Usage Page (LEDs) */                                       \
        0x19, 0x01,            /* Usage Minimum (Num Lock) */                                \
        0x29, 0x05,            /* Usage Maximum (Kana) */                                    \
        0x91, 0x02,            /* Output (data,Value,Absolute,Non-volatile,Bit Field) */     \
        0x95, 0x01,            /* Report Count (1) */                                        \
        0x75, 0x03,            /* Report Size (3) */                                         \
        0x91, 0x01,            /* Output (Constant,Array,Absolute,Non-volatile,Bit Field) */ \
        0x95, 0x06,            /* Report Count (6) */                                        \
        0x75, 0x08,            /* Report Size (8) */                                         \
        0x15, 0x00,            /* Logical minimum (0) */                                     \
        0x26, 0xA4, 0x00,      /* Logical maximum (164) */                                   \
        0x05, 0x07,            /* Usage Page (Keyboard) */                                   \
        0x19, 0x00,            /* Usage Minimum (No event indicated) */                      \
        0x2A, 0xA4, 0x00,      /* Usage Maximum (Keyboard ExSel) */                          \
        0x81, 0x00,            /* Input (data,Array,Absolute,Bit Field) */                   \
        0xC0                   /* End Collection */

#define KEYBRD_REPORT_MAP_COMPATIBLE                                                 \
    0x05, 0x01,                /* USAGE_PAGE (Generic Desktop) */                    \
        0x09, 0x06,            /* USAGE (Keyboard) */                                \
        0xa1, 0x01,            /* COLLECTION (Application) */                        \
        0x85, KEYBRD_INPUT_ID, /*   REPORT_ID (1) */                                 \
        0x05, 0x07,            /*   USAGE_PAGE (Keyboard) */                         \
        0x19, 0xe0,            /*   USAGE_MINIMUM (Keyboard LeftControl) */          \
        0x29, 0xe7,            /*   USAGE_MAXIMUM (Keyboard Right GUI) */            \
        0x15, 0x00,            /*   LOGICAL_MINIMUM (0) */                           \
        0x25, 0x01,            /*   LOGICAL_MAXIMUM (1) */                           \
        0x75, 0x01,            /*   REPORT_SIZE (1) */                               \
        0x95, 0x08,            /*   REPORT_COUNT (8) */                              \
        0x81, 0x02,            /*   INPUT (Data,Var,Abs) */                          \
        0x95, 0x01,            /*   REPORT_COUNT (1) */                              \
        0x75, 0x08,            /*   REPORT_SIZE (8) */                               \
        0x81, 0x03,            /*   INPUT (Cnst,Var,Abs) */                          \
        0x95, 0x05,            /*   REPORT_COUNT (5) */                              \
        0x75, 0x01,            /*   REPORT_SIZE (1) */                               \
        0x05, 0x08,            /*   USAGE_PAGE (LEDs) */                             \
        0x19, 0x01,            /*   USAGE_MINIMUM (Num Lock) */                      \
        0x29, 0x05,            /*   USAGE_MAXIMUM (Kana) */                          \
        0x91, 0x02,            /*   OUTPUT (Data,Var,Abs) */                         \
        0x95, 0x01,            /*   REPORT_COUNT (1) */                              \
        0x75, 0x03,            /*   REPORT_SIZE (3) */                               \
        0x91, 0x03,            /*   OUTPUT (Cnst,Var,Abs) */                         \
        0x95, 0x06,            /*   REPORT_COUNT (6) */                              \
        0x75, 0x08,            /*   REPORT_SIZE (8) */                               \
        0x15, 0x00,            /*   LOGICAL_MINIMUM (0) */                           \
        0x25, 0x65,            /*   LOGICAL_MAXIMUM (101) */                         \
        0x05, 0x07,            /*   USAGE_PAGE (Keyboard) */                         \
        0x19, 0x00,            /*   USAGE_MINIMUM (Reserved (no event indicated)) */ \
        0x29, 0x65,            /*   USAGE_MAXIMUM (Keyboard Application) */          \
        0x81, 0x00,            /*   INPUT (Data,Ary,Abs) */                          \
        0xc0                   /* END_COLLECTION */

typedef struct
{
    // uint8_t report_id;
    uint8_t special_key;
    uint8_t key[6];
} keyboard_input_report_t;

typedef struct
{
    // uint8_t report_id;
    uint8_t special_key;
    uint8_t reserved;
    uint8_t key[6];
} keyboard_compatible_input_report_t;
