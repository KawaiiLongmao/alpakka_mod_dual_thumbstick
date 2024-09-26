// SPDX-License-Identifier: GPL-2.0-only
// Copyright (C) 2022, Input Labs Oy.

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <pico/time.h>
#include <hardware/adc.h>
#include "config.h"
#include "pin.h"
#include "button.h"
#include "hid.h"
#include "led.h"
#include "thumbstick.h"
#include "right_thumbstick.h"
#include "common.h"
#include "profile.h"
#include "logging.h"
#include "webusb.h"

const uint8_t rts_x_adc_channel = PIN_RIGHT_THUMBSTICK_X - 26;
const uint8_t rts_y_adc_channel = PIN_RIGHT_THUMBSTICK_Y - 26;

float rts_offset_x = 0;
float rts_offset_y = 0;
float rts_config_deadzone = 0;

float right_thumbstick_adc(uint8_t adc_index, float offset)
{
    adc_select_input(adc_index);
    float value = (float)adc_read() - BIT_11;
    value = value / BIT_11 * CFG_THUMBSTICK_SATURATION;
    return constrain(value - offset, -1, 1);

    // static uint8_t x=20;
    // static uint8_t y=20;
    // static uint32_t t=0;
    // static uint8_t b=1;
    // float r=0;
    // if(t < 250*5)
    // {
    //     t++;
    // }
    // else
    // {
    //     if(b == 1)
    //     {
    //         x--;
    //         if(x == 0) b=2;
    //     }
    //     else if(b == 2)
    //     {
    //         y--;
    //         if(y == 0) b=3;
    //     }
    //     else if(b == 3)
    //     {
    //         x++;
    //         if(x == 20) b=4;
    //     }
    //     else if(b == 4)
    //     {
    //         y++;
    //         if(y == 20) b=1;
    //     }
    //     if(adc_index == rts_x_adc_channel)
    //     {
    //         r = (x-10)/10.0f;
    //     }
    //     else if(adc_index == rts_y_adc_channel)
    //     {
    //         r = (y-10)/10.0f;
    //     }
    // }
    // return constrain(r, -1, 1);
}

void right_thumbstick_update_offsets()
{
    Config *config = config_read();
    rts_offset_x = config->offset_rts_x;
    rts_offset_y = config->offset_rts_y;
}

void right_thumbstick_update_deadzone()
{
    uint8_t preset = config_get_deadzone_preset();
    rts_config_deadzone = config_get_deadzone_value(preset);
}

void right_thumbstick_init()
{
    info("INIT: Right_Thumbstick\n");
    adc_init();
    adc_gpio_init(PIN_RIGHT_THUMBSTICK_X);
    adc_gpio_init(PIN_RIGHT_THUMBSTICK_Y);
    right_thumbstick_update_offsets();
    right_thumbstick_update_deadzone();
}

void right_thumbstick_calibrate()
{
    info("Right_Thumbstick: calibrating...\n");
    float x = 0;
    float y = 0;
    for (uint32_t i = 0; i < CFG_CALIBRATION_SAMPLES_THUMBSTICK; i++)
    {
        if (!(i % CFG_CALIBRATION_BLINK_FREQ))
            led_show_cycle_step();
        x += right_thumbstick_adc(rts_x_adc_channel, 0.0);
        y += right_thumbstick_adc(rts_y_adc_channel, 0.0);
    }
    x /= CFG_CALIBRATION_SAMPLES_THUMBSTICK;
    y /= CFG_CALIBRATION_SAMPLES_THUMBSTICK;
    info("Right_Thumbstick: calibration x=%f y=%f\n", x, y);
    config_set_right_thumbstick_offset(x, y);
    right_thumbstick_update_offsets();
}

void right_thumbstick_report_axis(uint8_t axis, float value)
{
    if (axis == GAMEPAD_AXIS_LX)
        hid_gamepad_lx(value);
    else if (axis == GAMEPAD_AXIS_LY)
        hid_gamepad_ly(value);
    else if (axis == GAMEPAD_AXIS_RX)
        hid_gamepad_rx(value);
    else if (axis == GAMEPAD_AXIS_RY)
        hid_gamepad_ry(value);
    else if (axis == GAMEPAD_AXIS_LX_NEG)
        hid_gamepad_lx(-value);
    else if (axis == GAMEPAD_AXIS_LY_NEG)
        hid_gamepad_ly(-value);
    else if (axis == GAMEPAD_AXIS_RX_NEG)
        hid_gamepad_rx(-value);
    else if (axis == GAMEPAD_AXIS_RY_NEG)
        hid_gamepad_ry(-value);
    else if (axis == GAMEPAD_AXIS_LZ)
        hid_gamepad_lz(value);
    else if (axis == GAMEPAD_AXIS_RZ)
        hid_gamepad_rz(value);
}

uint8_t right_thumbstick_get_direction(float angle, float overlap)
{
    float a = 45 * (1 - overlap);
    float b = 180 - a;
    uint8_t mask = 0;
    if (is_between(angle, -b, -a))
        mask += DIR4_MASK_LEFT;
    if (is_between(angle, a, b))
        mask += DIR4_MASK_RIGHT;
    if (fabs(angle) <= (90 - a))
        mask += DIR4_MASK_UP;
    if (fabs(angle) >= (90 + a))
        mask += DIR4_MASK_DOWN;
    return mask;
}

void RThumbstick__report_axial(
    RThumbstick *self,
    ThumbstickPosition pos)
{
    // Evaluate virtual buttons.
    if (pos.radius > CFG_THUMBSTICK_ADDITIONAL_DEADZONE_FOR_BUTTONS)
    {
        uint8_t direction = right_thumbstick_get_direction(pos.angle, self->overlap);
        if (direction & DIR4_MASK_LEFT)
            self->left.virtual_press = true;
        if (direction & DIR4_MASK_RIGHT)
            self->right.virtual_press = true;
        if (direction & DIR4_MASK_UP)
            self->up.virtual_press = true;
        if (direction & DIR4_MASK_DOWN)
            self->down.virtual_press = true;
    }
    // Report directional virtual buttons or axis.
    //// Left.
    if (!hid_is_axis(self->left.actions[0]))
        self->left.report(&self->left);
    else
        right_thumbstick_report_axis(self->left.actions[0], -constrain(pos.x, -1, 0));
    //// Right.
    if (!hid_is_axis(self->right.actions[0]))
        self->right.report(&self->right);
    else
        right_thumbstick_report_axis(self->right.actions[0], constrain(pos.x, 0, 1));
    //// Up.
    if (!hid_is_axis(self->up.actions[0]))
        self->up.report(&self->up);
    else
        right_thumbstick_report_axis(self->up.actions[0], -constrain(pos.y, -1, 0));
    //// Down.
    if (!hid_is_axis(self->down.actions[0]))
        self->down.report(&self->down);
    else
        right_thumbstick_report_axis(self->down.actions[0], constrain(pos.y, 0, 1));
    // Report push.
    self->push.report(&self->push);
}

void RThumbstick__report(RThumbstick *self)
{
    // Do not report if not calibrated.
    if (rts_offset_x == 0 && rts_offset_y == 0)
        return;
    // Get values from ADC.
    float x = right_thumbstick_adc(rts_x_adc_channel, rts_offset_x);
    float y = right_thumbstick_adc(rts_y_adc_channel, rts_offset_y);
    // Get correct deadzone.
    float deadzone = self->deadzone_override ? self->deadzone : rts_config_deadzone;
    // Calculate trigonometry.
    float angle = atan2(x, -y) * (180 / M_PI);
    float radius = sqrt(powf(x, 2) + powf(y, 2));
    radius = constrain(radius, 0, 1);
    if (radius < deadzone)
    {
        radius = 0;
    }
    else
    {
        radius = ramp_low(radius, deadzone);
        radius = ramp_inv(radius, self->antideadzone);
    }
    x = sin(radians(angle)) * radius;
    y = -cos(radians(angle)) * radius;
    ThumbstickPosition pos = {x, y, angle, radius};
    // Report.
    RThumbstick__report_axial(self, pos);
}

void RThumbstick__reset(RThumbstick *self)
{
    if (self->mode == THUMBSTICK_MODE_4DIR)
    {
        self->left.reset(&self->left);
        self->right.reset(&self->right);
        self->up.reset(&self->up);
        self->down.reset(&self->down);
        self->push.reset(&self->push);
    }
}

RThumbstick RThumbstick_(
    Button left,
    Button right,
    Button up,
    Button down,
    Button push,
    bool deadzone_override,
    float deadzone,
    float antideadzone,
    float overlap)
{
    RThumbstick rThumbstick;
    rThumbstick.report = RThumbstick__report;
    rThumbstick.reset = RThumbstick__reset;
    rThumbstick.left = left;
    rThumbstick.right = right;
    rThumbstick.up = up;
    rThumbstick.down = down;
    rThumbstick.push = push;
    rThumbstick.deadzone_override = deadzone_override;
    rThumbstick.deadzone = deadzone;
    rThumbstick.antideadzone = antideadzone;
    rThumbstick.overlap = overlap;
    return rThumbstick;
}
