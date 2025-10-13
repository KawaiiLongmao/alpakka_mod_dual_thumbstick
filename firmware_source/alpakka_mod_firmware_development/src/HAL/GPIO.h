#pragma once

#include "Library/common.h"
#include "hal_public.h"

namespace HAL_GPIO
{

    enum class Direction : uint8_t
    {
        IN,
        OUT,
    };

    enum class PullMode : uint8_t
    {
        DISABLE, // 禁用上下拉
        UP,      // 使能上拉电阻
        DOWN     // 使能下拉电阻
    };

    enum class IrqType : uint8_t
    {
        DISABLE,    // 禁用
        POSEDGE,    // 上升沿触发(rising edge)（从低电平变高电平）
        NEGEDGE,    // 下降沿触发(falling edge)（从高电平变低电平）
        ANYEDGE,    // 上升沿 + 下降沿
        LOW_LEVEL,  //  低电平持续触发（电平敏感模式）
        HIGH_LEVEL, //  高电平持续触发（电平敏感模式）
    };

    using IrqCallbackFunc = std::function<void(GPIONumber)>;

    // GPIO通用配置
    struct Config
    {
        Direction dir = Direction::IN;     // 输入/输出
        PullMode pull = PullMode::DISABLE; // 上拉/下拉
        struct
        {
            IrqType type = IrqType::DISABLE;
            IrqCallbackFunc irq_callback_func = nullptr;
        } irq;
    };

    ErrorCode Init(GPIONumber pin, const Config &config);

    ErrorCode Deinit(GPIONumber pin);

    void SetDirection(GPIONumber pin, Direction dir);

    bool Get(GPIONumber pin);

    void Put(GPIONumber pin, bool level);

}
