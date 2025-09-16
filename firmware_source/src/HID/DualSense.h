#pragma once

#include "Library/cstd_lib.h"
// #include "Library/Utils/Utils.h"
#include "Middleware/Log.h"
// #include "Application/HID/DeviceInputOutput.h"
// #include "Application/HID/hid_config.h"
// #include "HidDeviceSetting.h"
// #include "HidDevicePublic.h"

inline uint8_t dpad_button_to_hat_switch_none8(uint8_t up, uint8_t down, uint8_t left, uint8_t right)
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

class DualSense
{
public:
    static void USB_Init();
    static void USB_Process();
};
