#include <stdint.h>
#include <math.h>
#include "switch_pro.h"

//0.0~1.0
float calcRumbleAmp(const rumble_data_t *rumble)
{
    if (rumble->freq_h == 0 && rumble->freq_h_amp == 0x01 && rumble->freq_l == 0x40 && rumble->freq_l_amp == 0x40)
        return 0;

    // ESP_LOGI(TAG, "Rumble %02x %02x %02x %02x", rumble->freq_h, rumble->freq_h_amp, rumble->freq_l, rumble->freq_l_amp);
    //老外的逆向工程文档看不懂，直接用excel表拟合他提供是数据表格
    float a; //0.0~1.0
    uint8_t ea = rumble->freq_h_amp >> 1;
    if (ea <= 1)
        a = 0.007843f * ea;
    else if (ea <= 14)
        a = 0.0084f * exp(0.1733f * ea);
    else if (ea <= 30)
        a = 0.0587f * exp(0.0433f * ea);
    else
        a = 0.115f * exp(0.0217f * ea);

    // 频率用不上直接注释掉
    // float f;
    // if (rumble->freq_h_amp & 0x01)
    // 	f = 320 * exp(0.0054f * rumble->freq_h);
    // else
    // 	f = 40 * exp(0.0217f * (rumble->freq_l & 0x7F));

    return a;
}

