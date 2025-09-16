
#if defined(__has_include)
#if __has_include(<pico/version.h>)
#include <pico/version.h>
#endif
#endif

#if defined(PICO_SDK_VERSION_STRING) && !defined(ARDUINO)
#include "HAL/ADC.h"

#include <hardware/gpio.h>
#include <hardware/adc.h>

namespace HAL_ADC
{

    // 当前分辨率设置
    static uint8_t s_adc_resolution = 12;
    static bool s_init_state = false;

    void Init(GPIONumber pin, uint8_t resolution_bit)
    {
        (void)resolution_bit;
        if (!s_init_state)
        {
            s_init_state = true;
            adc_init();
        }
        adc_gpio_init(pin);
    }

    uint16_t Read(GPIONumber pin)
    {
        adc_select_input(pin - 26);
        return adc_read();
    }

    void SetResolution(uint8_t resolution_bit)
    {
        (void)resolution_bit;
    }

    uint8_t GetResolution()
    {
        return s_adc_resolution;
    }

} // namespace HAL_ADC
#endif
