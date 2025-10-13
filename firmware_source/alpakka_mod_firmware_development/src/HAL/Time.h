#pragma once

#include "Library/cstd_lib.h"

namespace HAL_Time
{

    // 获取32位微秒时间
    uint32_t GetTime_us_32bit();

    // 获取32位毫秒时间
    uint32_t GetTime_ms_32bit();

    // 微秒级延迟
    void Delay_us(uint32_t us);

    // 毫秒级延迟
    void Delay_ms(uint32_t ms);

}
