
#if defined(ARDUINO)
#include "HAL/GPIO.h"

#include "Middleware/Log.h"
#include <Arduino.h>

namespace HAL_GPIO
{

    namespace
    {
        // GPIO状态结构
        struct GPIOState
        {
            PullMode pull = PullMode::DISABLE;
            IrqCallbackFunc irq_callback_func = nullptr;
        };

        // 全局状态数组
        std::array<GPIOState, HAL_GPIO_MAX_NUMBER> s_gpio_state_array = {};

        // 中断回调函数数组
        std::array<IrqCallbackFunc, HAL_GPIO_MAX_NUMBER> s_irq_callback_array = {};

        // 中断处理函数模板
        template <GPIONumber Pin>
        void ISRHandler()
        {
            if (s_irq_callback_array[Pin])
            {
                s_irq_callback_array[Pin](Pin);
            }
        }

        // 生成中断处理函数指针数组
        template <size_t... Indices>
        constexpr auto make_irq_handler_array(std::index_sequence<Indices...>)
        {
            return std::array<void (*)(), sizeof...(Indices)>{
                &ISRHandler<Indices>...};
        }

        // 中断处理函数指针数组
        constexpr auto s_irq_handler_array = make_irq_handler_array(
            std::make_index_sequence<HAL_GPIO_MAX_NUMBER>{});
    } // namespace

    ErrorCode Init(GPIONumber pin, const Config &config)
    {
        LOG_PRINTF(Log::INFO, "HAL_GPIO::Init - Start! Pin: %d\n", pin);

        // 设置引脚方向与上拉/下拉
        auto pin_mode = INPUT;
        if (config.dir == Direction::OUT)
        {
            pin_mode = OUTPUT;
        }
        else
        {
            switch (config.pull)
            {
            case PullMode::UP:
                pin_mode = INPUT_PULLUP;
                break;
            case PullMode::DOWN:
                pin_mode = INPUT_PULLDOWN;
                break;

            case PullMode::DISABLE:
            default:
                pin_mode = INPUT;
                break;
            }
        }
        pinMode(pin, pin_mode);

        // 保存GPIO状态
        s_gpio_state_array[pin].pull = config.pull;
        s_irq_callback_array[pin] = config.irq.irq_callback_func;

        // 中断配置
        if (config.irq.type != IrqType::DISABLE && config.irq.irq_callback_func)
        {
            // 检查引脚是否支持中断
            int interruptNum = digitalPinToInterrupt(pin);
            if (interruptNum != NOT_AN_INTERRUPT)
            {
                // 转换中断类型
                PinStatus irq_mode;
                switch (config.irq.type)
                {
                case IrqType::POSEDGE:
                    irq_mode = RISING;
                    break;
                case IrqType::NEGEDGE:
                    irq_mode = FALLING;
                    break;
                case IrqType::ANYEDGE:
                    irq_mode = CHANGE;
                    break;
                case IrqType::LOW_LEVEL:
                    irq_mode = LOW;
                    break;
                case IrqType::HIGH_LEVEL:
                    irq_mode = HIGH;
                    break;
                default:
                    return ERROR_CODE::GENERAL;
                }

                // 注册中断
                attachInterrupt(interruptNum, s_irq_handler_array[pin], irq_mode);
                LOG_PRINTF(Log::INFO, "HAL_GPIO::Init - Interrupt configured for pin %d\n", pin);
            }
            else
            {
                LOG_PRINTF(Log::WARNING, "HAL_GPIO::Init - Pin %d does not support interrupts\n", pin);
                return ERROR_CODE::GENERAL;
            }
        }

        LOG_PRINTF(Log::INFO, "HAL_GPIO::Init - End!\n");
        return ERROR_CODE::NONE;
    }

    ErrorCode Deinit(GPIONumber pin)
    {
        pinMode(pin, INPUT);
        return ERROR_CODE::NONE;
    }

    void SetDirection(GPIONumber pin, Direction dir)
    {
        auto pin_mode = INPUT;
        if (dir == Direction::OUT)
        {
            pin_mode = OUTPUT;
        }
        else
        {
            switch (s_gpio_state_array[pin].pull)
            {
            case PullMode::UP:
                pin_mode = INPUT_PULLUP;
                break;
            case PullMode::DOWN:
                pin_mode = INPUT_PULLDOWN;
                break;

            case PullMode::DISABLE:
            default:
                pin_mode = INPUT;
                break;
            }
        }
        pinMode(pin, pin_mode);
    }

    bool Get(GPIONumber pin)
    {
        return digitalRead(pin) == HIGH;
    }

    void Put(GPIONumber pin, bool level)
    {
        digitalWrite(pin, level ? HIGH : LOW);
    }

}
#endif
