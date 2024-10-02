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

const uint8_t rts_x_adc_channel = 3;
const uint8_t rts_y_adc_channel = 2;

const float CUT4 = 45;
const float CUT8 = 22.5;

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

void right_thumbstick_report_mouse_move(uint8_t action, float thumbstick_value, int response_curve, int sensitivity_level)
{
    if (response_curve < 1 || response_curve > 3)
        response_curve = LINEAR;
    if (sensitivity_level < 1 || sensitivity_level > 10)
        sensitivity_level = 1;

    double mouse_move_value = 0;
    const double regular_value = BIT_7 / 10;
    static uint8_t once_timer = 0;
    if (response_curve == LINEAR)
    {
        mouse_move_value = thumbstick_value * regular_value * sensitivity_level;
    }
    else if (response_curve == TRADITIONAL_CURVE)
    {
        mouse_move_value = pow(1 + sensitivity_level / 10.0, thumbstick_value * 7);
    }
    else if (response_curve == CONSTANT)
    {
        if (thumbstick_value > 0)
            mouse_move_value = sensitivity_level;
    }
    // else if (response_curve == ONCE)
    // {
    //     if (thumbstick_value != 0)
    //     {
    //         if (once_timer < sensitivity_level)
    //         {
    //             mouse_move_value = 2;
    //             once_timer++;
    //         }
    //     }
    //     else
    //     {
    //         once_timer = 0;
    //     }
    // }
    int16_t value = constrain(mouse_move_value, -BIT_7, BIT_7);
    if (action == MOUSE_X)
        hid_mouse_move(value, 0);
    else if (action == MOUSE_Y)
        hid_mouse_move(0, value);
    else if (action == MOUSE_X_NEG)
        hid_mouse_move(-value, 0);
    else if (action == MOUSE_Y_NEG)
        hid_mouse_move(0, -value);
}

uint8_t right_thumbstick_get_direction(RThumbstick *self, float angle)
{
    // UP_RIGHT
    if (is_between(angle, CUT8 * 1, CUT8 * 3))
    {
        if (self->up_right.actions[0] != 0)
            return DIR8_MASK_UP_RIGHT;
    }
    // DOWN_RIGHT
    else if (is_between(angle, CUT8 * 5, CUT8 * 7))
    {
        if (self->down_right.actions[0] != 0)
            return DIR8_MASK_DOWN_RIGHT;
    }
    // DOWN_LEFT
    else if (is_between(angle, -CUT8 * 7, -CUT8 * 5))
    {
        if (self->down_left.actions[0] != 0)
            return DIR8_MASK_DOWN_LEFT;
    }
    // UP_LEFT
    else if (is_between(angle, -CUT8 * 3, -CUT8 * 1))
    {
        if (self->up_left.actions[0] != 0)
            return DIR8_MASK_UP_LEFT;
    }
    float a = CUT4 * (1 - self->overlap);
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

void right_thumbstick_report_axial(
    RThumbstick *self,
    ThumbstickPosition pos)
{
    // Evaluate virtual buttons.
    if (pos.radius > CFG_THUMBSTICK_ADDITIONAL_DEADZONE_FOR_BUTTONS)
    {
        uint8_t direction = right_thumbstick_get_direction(self, pos.angle);
        if (direction & DIR4_MASK_LEFT)
            self->left.virtual_press = true;
        if (direction & DIR4_MASK_RIGHT)
            self->right.virtual_press = true;
        if (direction & DIR4_MASK_UP)
            self->up.virtual_press = true;
        if (direction & DIR4_MASK_DOWN)
            self->down.virtual_press = true;
        if (direction & DIR8_MASK_UP_LEFT)
            self->up_left.virtual_press = true;
        if (direction & DIR8_MASK_UP_RIGHT)
            self->up_right.virtual_press = true;
        if (direction & DIR8_MASK_DOWN_LEFT)
            self->down_left.virtual_press = true;
        if (direction & DIR8_MASK_DOWN_RIGHT)
            self->down_right.virtual_press = true;
    }
    // Report directional virtual buttons or axis.
    bool report_mouse_move = false;
    //// Left.
    if (hid_is_axis(self->left.actions[0]))
        right_thumbstick_report_axis(self->left.actions[0], -constrain(pos.x, -1, 0));
    else if (hid_is_mouse_move(self->left.actions[0]))
    {
        right_thumbstick_report_mouse_move(self->left.actions[0],
                                           -constrain(pos.x, -1, 0),
                                           self->up_left.actions[0] - 29,
                                           self->down_left.actions[0] - 29);
        report_mouse_move = true;
    }
    else
        self->left.report(&self->left);
    //// Right.
    if (hid_is_axis(self->right.actions[0]))
        right_thumbstick_report_axis(self->right.actions[0], constrain(pos.x, 0, 1));
    else if (hid_is_mouse_move(self->right.actions[0]))
    {
        right_thumbstick_report_mouse_move(self->right.actions[0],
                                           constrain(pos.x, 0, 1),
                                           self->up_left.actions[0] - 29,
                                           self->down_left.actions[0] - 29);
        report_mouse_move = true;
    }
    else
        self->right.report(&self->right);
    //// Up.
    if (hid_is_axis(self->up.actions[0]))
        right_thumbstick_report_axis(self->up.actions[0], -constrain(pos.y, -1, 0));
    else if (hid_is_mouse_move(self->up.actions[0]))
    {
        right_thumbstick_report_mouse_move(self->up.actions[0],
                                           -constrain(pos.y, -1, 0),
                                           self->up_left.actions[0] - 29,
                                           self->down_right.actions[0] - 29);
        report_mouse_move = true;
    }
    else
        self->up.report(&self->up);
    //// Down.
    if (hid_is_axis(self->down.actions[0]))
        right_thumbstick_report_axis(self->down.actions[0], constrain(pos.y, 0, 1));
    else if (hid_is_mouse_move(self->down.actions[0]))
    {
        right_thumbstick_report_mouse_move(self->down.actions[0],
                                           constrain(pos.y, 0, 1),
                                           self->up_left.actions[0] - 29,
                                           self->down_right.actions[0] - 29);
        report_mouse_move = true;
    }
    else
        self->down.report(&self->down);
    //// DIR8_MASK
    if (!report_mouse_move)
    {
        if (!hid_is_axis(self->up_left.actions[0]))
            self->up_left.report(&self->up_left);
        if (!hid_is_axis(self->up_right.actions[0]))
            self->up_right.report(&self->up_right);
        if (!hid_is_axis(self->down_left.actions[0]))
            self->down_left.report(&self->down_left);
        if (!hid_is_axis(self->down_right.actions[0]))
            self->down_right.report(&self->down_right);
    }
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
    right_thumbstick_report_axial(self, pos);
}

void RThumbstick__reset(RThumbstick *self)
{
    self->left.reset(&self->left);
    self->right.reset(&self->right);
    self->up.reset(&self->up);
    self->down.reset(&self->down);
    self->push.reset(&self->push);
    self->up_left.reset(&self->up_left);
    self->up_right.reset(&self->up_right);
    self->down_left.reset(&self->down_left);
    self->down_right.reset(&self->down_right);
}

RThumbstick RThumbstick_(
    Button left,
    Button right,
    Button up,
    Button down,
    Button push,
    Button up_left,
    Button up_right,
    Button down_left,
    Button down_right,
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
    rThumbstick.up_left = up_left;
    rThumbstick.up_right = up_right;
    rThumbstick.down_left = down_left;
    rThumbstick.down_right = down_right;
    rThumbstick.deadzone_override = deadzone_override;
    rThumbstick.deadzone = deadzone;
    rThumbstick.antideadzone = antideadzone;
    rThumbstick.overlap = overlap;
    return rThumbstick;
}
