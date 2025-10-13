
#include "HAL/PWM.h"
#include <hardware/gpio.h>

#if (DEVICE_ALPAKKA_V0) && (DEVICE_ALPAKKA_V0 == 2)
#define PIN_L 17
#define PIN_R 18
#else
#define PIN_L 0
#define PIN_R 1
#endif

inline void RumbleInit()
{
#if (CFG_USE_RUMBLE)
    HAL_PWM::Init(PIN_L, 8, 10 * 1000);
    HAL_PWM::SetDutyCompareCount(PIN_L, 0);
    HAL_PWM::Init(PIN_R, 8, 10 * 1000);
    HAL_PWM::SetDutyCompareCount(PIN_R, 0);
#endif
}

inline void RumbleDeinit()
{
#if (CFG_USE_RUMBLE)
    gpio_deinit(PIN_L);
    gpio_deinit(PIN_R);
    HAL_PWM::Deinit(PIN_L);
    HAL_PWM::Deinit(PIN_R);

    gpio_init(PIN_L);
    gpio_set_pulls(PIN_L, false, false);
    gpio_set_dir(PIN_L, GPIO_OUT);
    gpio_put(PIN_L, false);

    gpio_init(PIN_R);
    gpio_set_pulls(PIN_R, false, false);
    gpio_set_dir(PIN_R, GPIO_OUT);
    gpio_put(PIN_R, false);
#endif
}
