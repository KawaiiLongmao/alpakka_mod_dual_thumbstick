#pragma once

#include "Library/cstd_lib.h"
#include "Library/common.h"

#define CONSUMER_CONTROL_HID_REPORT_DESCRIPTOR(input_id)       \
    0x05, 0x0c,           /* USAGE_PAGE (Consumer Devices) */  \
        0x09, 0x01,       /* USAGE (Consumer Control) */       \
        0xa1, 0x01,       /* COLLECTION (Application) */       \
        0x85, input_id,   /*   REPORT_ID (1) */                \
        0x19, 0x00,       /*   USAGE_MINIMUM (Unassigned) */   \
        0x2a, 0x08, 0x01, /*   USAGE_MAXIMUM (Police Alarm) */ \
        0x15, 0x00,       /*   LOGICAL_MINIMUM (0) */          \
        0x26, 0x08, 0x01, /*   LOGICAL_MAXIMUM (264) */        \
        0x75, 0x10,       /*   REPORT_SIZE (16) */             \
        0x95, 0x01,       /*   REPORT_COUNT (1) */             \
        0x81, 0x00,       /*   INPUT (Data,Ary,Abs) */         \
        0xc0              /* END_COLLECTION */

#define CUSTOM_CONTROL_HID_REPORT_DESCRIPTOR(input_id, feature_id)   \
    0x05, 0x0c,           /* USAGE_PAGE (Consumer Devices) */        \
        0x09, 0x01,       /* USAGE (Consumer Control) */             \
        0xa1, 0x01,       /* COLLECTION (Application) */             \
        0x85, input_id,   /*   REPORT_ID (1) */                      \
        0x19, 0x00,       /*   USAGE_MINIMUM (Unassigned) */         \
        0x2a, 0x08, 0x01, /*   USAGE_MAXIMUM (Police Alarm) */       \
        0x15, 0x00,       /*   LOGICAL_MINIMUM (0) */                \
        0x26, 0x08, 0x01, /*   LOGICAL_MAXIMUM (264) */              \
        0x75, 0x10,       /*   REPORT_SIZE (16) */                   \
        0x95, 0x01,       /*   REPORT_COUNT (1) */                   \
        0x81, 0x00,       /*   INPUT (Data,Ary,Abs) */               \
        0x06, 0x00, 0xff, /*   USAGE_PAGE (Vendor Defined Page 1) */ \
        0x09, 0x01,       /*   USAGE (Vendor Usage 1) */             \
        0x85, feature_id, /*   REPORT_ID (2) */                      \
        0x75, 0x08,       /*   REPORT_SIZE (8) */                    \
        0x95, 0x3f,       /*   REPORT_COUNT (63) */                  \
        0xb1, 0x02,       /*   FEATURE (Data,Var,Abs) */             \
        0xc0              /* END_COLLECTION */

enum class ConsumerControlKey : uint16_t
{
    POWER = 0x0030,
    SLEEP = 0x0032,
    PLAY = 0x00B0,
    STOP = 0x00B1,
    NEXT_TRACK = 0x00B5,
    PREV_TRACK = 0x00B6,
    MUTE = 0x00E2,
    VOLUME_UP = 0x00E9,
    VOLUME_DOWN = 0x00EA,
};

namespace ConsumerControlStruct
{
    struct __PACKED InputReport
    {
        uint8_t report_id;
        ConsumerControlKey key;
    };
    static_assert(sizeof(InputReport) == 3, "Expected size error");

    struct __PACKED FeatureReport
    {
        uint8_t report_id;
        uint8_t data[63];
    };
    static_assert(sizeof(FeatureReport) == 64, "Expected size error");
}
