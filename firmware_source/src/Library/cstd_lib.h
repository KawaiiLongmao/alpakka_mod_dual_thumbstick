#pragma once

#if defined(ARDUINO)
#if defined(ARDUINO_ARCH_AVR) ||     \
    defined(ARDUINO_ARCH_MEGAAVR) || \
    defined(ARDUINO_ARCH_SAM) ||     \
    defined(ARDUINO_ARCH_NRF52840)
#include <Cpp_Standard_Library.h>
#endif
#endif

#ifdef __cplusplus
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cstdarg>
#include <cinttypes>
#include <cmath>
#include <algorithm>
#include <memory>
#include <array>
#include <vector>
#include <unordered_map>
#include <string>
#include <utility>
#include <numeric>
#include <type_traits>
#include <stdexcept>
#include <limits>
#include <optional>
#include <functional>
// #include <stdfloat> // c++23
// #include <thread>
// #include <coroutine>
// #include <future>
#else
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <inttypes.h>
#include <math.h>
#endif
