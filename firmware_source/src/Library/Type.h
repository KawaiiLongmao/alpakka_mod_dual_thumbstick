#pragma once

#ifdef __cplusplus
#include <cstdint>
// #include <stdfloat> // c++23
#else
#include <stdint.h>
#endif

#ifdef __cplusplus
using Float32 = float;
using Float64 = double;
// using Float128 = std::float128_t;

#if defined(__FPU__)
using Float = Float64;
#else
using Float = Float32;
#endif

using Uint1 = bool;
using Uint8 = uint8_t;
using Uint16 = uint16_t;
using Uint32 = uint32_t;
using Uint64 = uint64_t;
using Uint = unsigned int;

using Int8 = int8_t;
using Int16 = int16_t;
using Int32 = int32_t;
using Int64 = int64_t;
using Int = int;
#endif
