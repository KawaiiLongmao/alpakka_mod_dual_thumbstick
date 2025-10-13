#pragma once

#include "Library/cstd_lib.h"

#define HAL_GPIO_MAX_NUMBER 40

using GPIONumber = uint8_t;

// 定义未使用的GPIO引脚状态
inline constexpr GPIONumber GPIO_UNUSED = -1;
