
#if defined(ARDUINO) &&              \
    !defined(ARDUINO_ARCH_RP2040) && \
    !defined(ARDUINO_ARCH_ESP32)
#include "HAL/PWM.h"

#include "Middleware/Log.h"
#include <Arduino.h>

namespace HAL_PWM
{

    static uint8_t s_resolution_bit = 8;
    static uint32_t s_frequency_hz = 1000;

    void Init(GPIONumber pin, uint8_t resolution_bit, uint32_t frequency_hz)
    {
        pinMode(pin, OUTPUT);
        analogWrite(pin, 0);
        SetPWMConfig(pin, resolution_bit, frequency_hz);
    }

    void Deinit(GPIONumber pin)
    {
        analogWrite(pin, 0);
        pinMode(pin, INPUT);
    }

    void SetPWMConfig(GPIONumber pin, uint8_t resolution_bit, uint32_t frequency_hz)
    {
        if (resolution_bit)
        {
#if defined(ARDUINO_ARCH_ESP32)
            analogWriteResolution(pin, resolution_bit);
#else
            analogWriteResolution(resolution_bit);
#endif
            s_resolution_bit = resolution_bit;
        }
        if (frequency_hz)
        {
#if defined(ARDUINO_ARCH_ESP32)
            analogWriteFrequency(pin, frequency_hz);
#else
            analogWriteFrequency(frequency_hz);
#endif
            s_frequency_hz = frequency_hz;
        }
    }

    void SetDutyCompareCount(GPIONumber pin, uint16_t duty_compare_count)
    {
        analogWrite(pin, duty_compare_count);
    }

    uint8_t GetResolution(GPIONumber pin)
    {
        (void)pin;
        return s_resolution_bit;
    }

    uint32_t GetFrequency(GPIONumber pin)
    {
        (void)pin;
        return s_frequency_hz;
    }

}
#endif
