#include <stdint.h>

// 返回长度
uint16_t memory_copy(void *dest, const void *src, const uint16_t size)
{
    uint8_t *_dest = (uint8_t *)dest;
    const uint8_t *_src = (const uint8_t *)src;
    for (uint16_t i = 0; i < size; i++)
    {
        _dest[i] = _src[i];
    }
    return size;
}

uint8_t dpad_button_to_hat_switch_8(uint8_t up, uint8_t down, uint8_t left, uint8_t right)
{
    uint8_t hat_switch = 8;
    if (up)
    {
        if (right)
            hat_switch = 1; // NE
        else if (left)
            hat_switch = 7; // NW
        else
            hat_switch = 0; // N
    }
    if (right)
    {
        if (up)
            hat_switch = 1; // NE
        else if (down)
            hat_switch = 3; // SE
        else
            hat_switch = 2; // E
    }
    if (down)
    {
        if (right)
            hat_switch = 3; // SE
        else if (left)
            hat_switch = 5; // SW
        else
            hat_switch = 4; // S
    }
    if (left)
    {
        if (up)
            hat_switch = 7; // NW
        else if (down)
            hat_switch = 5; // SW
        else
            hat_switch = 6; // W
    }
    return hat_switch;
}

uint8_t dpad_button_to_hat_switch_0(uint8_t up, uint8_t down, uint8_t left, uint8_t right)
{
    uint8_t hat_switch = 0;
    if (up)
    {
        if (right)
            hat_switch = 2; // NE
        else if (left)
            hat_switch = 8; // NW
        else
            hat_switch = 1; // N
    }
    if (right)
    {
        if (up)
            hat_switch = 2; // NE
        else if (down)
            hat_switch = 4; // SE
        else
            hat_switch = 3; // E
    }
    if (down)
    {
        if (right)
            hat_switch = 4; // SE
        else if (left)
            hat_switch = 6; // SW
        else
            hat_switch = 5; // S
    }
    if (left)
    {
        if (up)
            hat_switch = 8; // NW
        else if (down)
            hat_switch = 6; // SW
        else
            hat_switch = 7; // W
    }
    return hat_switch;
}
