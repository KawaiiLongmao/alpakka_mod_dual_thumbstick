
#if defined(__has_include)
#if __has_include(<pico/version.h>)
#include <pico/version.h>
#endif
#endif

#if defined(PICO_SDK_VERSION_STRING) && !defined(ARDUINO)
#include "HAL/Time.h"

#include <pico/time.h>

namespace HAL_Time
{

    uint32_t GetTime_us_32bit()
    {
        return time_us_32();
    }

    uint32_t GetTime_ms_32bit()
    {
        return (uint32_t)(time_us_64() / 1000);
    }

    void Delay_us(uint32_t us)
    {
        sleep_us(us);
    }

    void Delay_ms(uint32_t ms)
    {
        sleep_ms(ms);
    }

} // namespace HAL_Time
#endif
