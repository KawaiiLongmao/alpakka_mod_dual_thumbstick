
#if defined(ARDUINO)
#include "HAL/Time.h"

#include <Arduino.h>

namespace HAL_Time
{

    uint32_t GetTime_us_32bit()
    {
        return micros();
    }

    uint32_t GetTime_ms_32bit()
    {
        return millis();
    }

    void Delay_us(uint32_t us)
    {
        delayMicroseconds(us);
    }

    void Delay_ms(uint32_t ms)
    {
        delay(ms);
    }

}
#endif
