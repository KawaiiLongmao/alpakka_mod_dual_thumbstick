#pragma once

#include "Library/cstd_lib.h"
#include "Library/Type.h"
#include "Library/ErrorCode.h"

#define UINT_18_MAX 262143
#define UINT_17_MAX 131071
#define UINT_16_MAX 65535
#define UINT_15_MAX 32767
#define UINT_14_MAX 16383
#define UINT_12_MAX 4095
#define UINT_11_MAX 2047
#define UINT_10_MAX 1023
#define UINT_8_MAX 255
#define UINT_7_MAX 127

#define INT_16_MAX 32767
#define INT_16_MIN -32768
#define INT_12_MAX 2047
#define INT_12_MIN -2048

#define LO_UINT16(u16_val) ((uint8_t)(u16_val & 0xFF))
#define HI_UINT16(u16_val) ((uint8_t)(((u16_val) >> 8) & 0xFF))
#define U16_TO_BYTE(u16_val) LO_UINT16(u16_val), HI_UINT16(u16_val)
#define U24_TO_BYTE(u24_val) LO_UINT16(u24_val), HI_UINT16(u24_val), ((uint8_t)(((u24_val) >> 16) & 0xFF))

#ifdef __cplusplus
inline constexpr Float32 PI_32 = (Float32)3.14159265358979323846;
inline constexpr Float64 PI_64 = (Float64)3.14159265358979323846;
#endif

// #include "usb_config.h"
// #include "common/usb_util.h"
// #define DMA_ALIGNX USB_MEM_ALIGNX

#if defined(__CC_ARM)
#ifndef __USED
#define __USED __attribute__((used))
#endif
#ifndef __WEAK
#define __WEAK __attribute__((weak))
#endif
#ifndef __PACKED
#define __PACKED __attribute__((packed))
#endif
#ifndef __PACKED_STRUCT
#define __PACKED_STRUCT __packed struct
#endif
#ifndef __PACKED_UNION
#define __PACKED_UNION __packed union
#endif
#ifndef __ALIGNED
#define __ALIGNED(x) __attribute__((aligned(x)))
#endif
#elif defined(__GNUC__)
#ifndef __USED
#define __USED __attribute__((used))
#endif
#ifndef __WEAK
#define __WEAK __attribute__((weak))
#endif
#ifndef __PACKED
#define __PACKED __attribute__((packed, aligned(1)))
#endif
#ifndef __PACKED_STRUCT
#define __PACKED_STRUCT struct __attribute__((packed, aligned(1)))
#endif
#ifndef __PACKED_UNION
#define __PACKED_UNION union __attribute__((packed, aligned(1)))
#endif
#ifndef __ALIGNED
#define __ALIGNED(x) __attribute__((aligned(x)))
#endif
#elif defined(__ICCARM__) || defined(__ICCRX__) || defined(__ICCRISCV__)
#if (__VER__ >= 8000000)
#define __ICCARM_V8 1
#else
#define __ICCARM_V8 0
#endif

#ifndef __USED
#if defined(__ICCARM_V8) || defined(__ICCRISCV__)
#define __USED __attribute__((used))
#else
#define __USED __root
#endif
#endif

#ifndef __WEAK
#if defined(__ICCARM_V8) || defined(__ICCRISCV__)
#define __WEAK __attribute__((weak))
#else
#define __WEAK _Pragma("__weak")
#endif
#endif

#ifndef __PACKED
#if defined(__ICCARM_V8) || defined(__ICCRISCV__)
#define __PACKED __attribute__((packed, aligned(1)))
#else
/* Needs IAR language extensions */
#define __PACKED __packed
#endif
#endif

#ifndef __PACKED_STRUCT
#if defined(__ICCARM_V8) || defined(__ICCRISCV__)
#define __PACKED_STRUCT struct __attribute__((packed, aligned(1)))
#else
/* Needs IAR language extensions */
#define __PACKED_STRUCT __packed struct
#endif
#endif

#ifndef __PACKED_UNION
#if defined(__ICCARM_V8) || defined(__ICCRISCV__)
#define __PACKED_UNION union __attribute__((packed, aligned(1)))
#else
/* Needs IAR language extensions */
#define __PACKED_UNION __packed union
#endif
#endif

#ifndef __ALIGNED
#if defined(__ICCARM_V8) || defined(__ICCRISCV__)
#define __ALIGNED(x) __attribute__((aligned(x)))
#elif (__VER__ >= 7080000)
/* Needs IAR language extensions */
#define __ALIGNED(x) __attribute__((aligned(x)))
#else
#warning No compiler specific solution for __ALIGNED.__ALIGNED is ignored.
#define __ALIGNED(x)
#endif
#endif

#endif
