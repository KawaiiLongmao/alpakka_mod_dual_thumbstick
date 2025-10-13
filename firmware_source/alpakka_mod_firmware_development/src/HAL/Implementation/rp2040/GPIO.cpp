
#if defined(__has_include)
#if __has_include(<pico/version.h>)
#include <pico/version.h>
#endif
#endif

#if defined(PICO_SDK_VERSION_STRING) && !defined(ARDUINO)
#include "HAL/GPIO.h"

#include "Middleware/Log.h"
#include <hardware/gpio.h>

namespace HAL_GPIO
{

    namespace
    {
        std::array<HAL_GPIO::IrqCallbackFunc, HAL_GPIO_MAX_NUMBER> s_gpio_irq_cb_array = {};
        void gpio_irq_cb_bus(uint gpio, uint32_t event_mask)
        {
            (void)event_mask;
            s_gpio_irq_cb_array[gpio](static_cast<GPIONumber>(gpio));
        }
    }

    ErrorCode Init(GPIONumber pin, const Config &config)
    {
        LOG_PRINTF(Log::INFO, "HAL_GPIO::Init - Start! Pin: %d\n", pin);

        gpio_init(pin);
        gpio_set_dir(pin, static_cast<bool>(config.dir));
        switch (config.pull)
        {
        case PullMode::UP:
            gpio_set_pulls(pin, true, false);
            break;
        case PullMode::DOWN:
            gpio_set_pulls(pin, false, true);
            break;

        case PullMode::DISABLE:
        default:
            gpio_set_pulls(pin, false, false);
            break;
        }

        if (config.irq.type != IrqType::DISABLE && config.irq.irq_callback_func)
        {
            uint8_t events = 0;
            switch (config.irq.type)
            {
            case IrqType::POSEDGE:
                events |= GPIO_IRQ_EDGE_RISE;
                break;
            case IrqType::NEGEDGE:
                events |= GPIO_IRQ_EDGE_FALL;
                break;
            case IrqType::ANYEDGE:
                events |= GPIO_IRQ_EDGE_RISE;
                events |= GPIO_IRQ_EDGE_FALL;
                break;
            case IrqType::LOW_LEVEL:
                events |= GPIO_IRQ_LEVEL_LOW;
                break;
            case IrqType::HIGH_LEVEL:
                events |= GPIO_IRQ_LEVEL_HIGH;
                break;
            default:
                return ERROR_CODE::GENERAL;
            }
            s_gpio_irq_cb_array[pin] = config.irq.irq_callback_func;
            gpio_set_irq_enabled_with_callback(
                pin, events, true, gpio_irq_cb_bus);
        }

        LOG_PRINTF(Log::INFO, "HAL_GPIO::Init - End!\n");
        return ERROR_CODE::NONE;
    }

    ErrorCode Deinit(GPIONumber pin)
    {
        gpio_deinit(pin);
        return ERROR_CODE::NONE;
    }

    void SetDirection(GPIONumber pin, Direction dir)
    {
        gpio_set_dir(pin, static_cast<bool>(dir));
    }

    bool Get(GPIONumber pin)
    {
        return gpio_get(pin);
    }

    void Put(GPIONumber pin, bool level)
    {
        gpio_put(pin, level);
    }

} // namespace HAL_GPIO
#endif
