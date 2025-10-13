
#if defined(__has_include)
#if __has_include(<pico/version.h>)
#include <pico/version.h>
#endif
#endif

#if defined(PICO_SDK_VERSION_STRING) && !defined(ARDUINO)
#include "HAL/MCU.h"

#include <stdlib.h>
#include <pico/time.h>
#include <pico/bootrom.h>
#include <hardware/clocks.h>
#include <hardware/vreg.h>
#include <hardware/watchdog.h>

namespace HAL_MCU
{
    // void SetSystemClockFrequency(uint32_t clk_khz, bool increase_voltage)
    // {
    //     if (clk_khz == 0)
    //         return;
    //     if (clk_khz == 125 * 1000) // pico默认频率
    //         return;
    //     if (increase_voltage)
    //     {
    //         vreg_set_voltage(VREG_VOLTAGE_1_30); // 大概超过270MHz就需要调电压，建议直接1.3V
    //     }
    //     if (!set_sys_clock_khz(clk_khz, true))
    //     {
    //         SimpleEvents::MCU_SetSystemClockFrequency_Error();
    //     }
    // }

    // uint32_t GetTime_us_32bit()
    // {
    //     return time_us_32();
    // }

    // uint64_t GetTime_us_64bit()
    // {
    //     return time_us_64();
    // }

    // uint32_t GetTime_ms_32bit()
    // {
    //     return (uint32_t)(GetTime_us_64bit() / 1000);
    // }

    // void Delay_us(uint32_t us)
    // {
    //     sleep_us(us);
    // }

    // void Shutdown()
    // {
    //     exit(1);
    // }

    void Reboot()
    {
        watchdog_enable(1, false);
        sleep_ms(10);
    }

    // void Bootsel()
    // {
    //     reset_usb_boot(0, 0);
    // }
}
#endif
