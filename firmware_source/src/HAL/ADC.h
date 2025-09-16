#pragma once

#include "Library/common.h"
#include "hal_public.h"

namespace HAL_ADC
{

    // 初始化指定引脚 ADC 通道
    void Init(GPIONumber pin, uint8_t resolution_bit = 12);

    // 读取 ADC 原始值
    uint16_t Read(GPIONumber pin);

    // 设置 ADC 分辨率（位）
    void SetResolution(uint8_t resolution_bit);

    // 获取 ADC 分辨率（位）
    uint8_t GetResolution();

    // 读取 ADC 电压值（伏特）
    inline float ReadVoltage(GPIONumber pin)
    {
        return Read(pin) * (3.3f / (1 << GetResolution()));
    }

}
