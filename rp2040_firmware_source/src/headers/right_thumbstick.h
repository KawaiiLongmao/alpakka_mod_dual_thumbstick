// SPDX-License-Identifier: GPL-2.0-only
// Copyright (C) 2022, Input Labs Oy.

#pragma once

enum RESPONSE_CURVE
{
    LINEAR = 1,
    TRADITIONAL_CURVE,
    CONSTANT,
    ONCE,
};

typedef struct RThumbstick_struct RThumbstick;
struct RThumbstick_struct
{
    void (*report)(RThumbstick *self);
    void (*reset)(RThumbstick *self);
    // Real buttons.
    Button left;
    Button right;
    Button up;
    Button down;
    Button push;
    Button up_left;
    Button up_right;
    Button down_left;
    Button down_right;

    // ThumbstickMode mode;
    // ThumbstickDistance distance_mode;
    bool deadzone_override;
    float deadzone;
    float antideadzone;
    float overlap;
};

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
    float overlap);

void right_thumbstick_init();
void right_thumbstick_calibrate();
void right_thumbstick_update_deadzone();
