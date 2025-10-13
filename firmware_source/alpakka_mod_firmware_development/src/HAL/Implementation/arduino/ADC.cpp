
#if defined(ARDUINO)
#include "HAL/ADC.h"

#include <Arduino.h>

namespace HAL_ADC
{

    // 当前分辨率设置
    static uint8_t s_adc_resolution = 12;

    void Init(GPIONumber pin, uint8_t resolution_bit)
    {
        (void)pin;
        // 设置分辨率
        SetResolution(resolution_bit);
        s_adc_resolution = resolution_bit;
    }

    uint16_t Read(GPIONumber pin)
    {
        // 直接使用 analogRead 读取指定引脚
        return analogRead(pin);
    }

    void SetResolution(uint8_t resolution_bit)
    {
        analogReadResolution(resolution_bit);
        s_adc_resolution = resolution_bit;
    }

    uint8_t GetResolution()
    {
        return s_adc_resolution;
    }

} // namespace HAL_ADC
#endif
