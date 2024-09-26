#pragma once

#include <stdint.h>

#define LO_UINT16(_uint16) ((uint8_t)(_uint16) & 0xFF)
#define HI_UINT16(_uint16) ((uint8_t)(((_uint16) >> 8) & 0xFF))
#define U16_TO_BYTE(_uint16) LO_UINT16(_uint16), HI_UINT16(_uint16)
#define U24_TO_BYTE(_uint24) LO_UINT16(_uint16), HI_UINT16(_uint16), ((uint8_t)(((_uint16) >> 16) & 0xFF))

uint16_t memory_copy(void *dest, const void *src, uint16_t size);
uint8_t dpad_button_to_hat_switch_8(uint8_t up, uint8_t down, uint8_t left, uint8_t right);
uint8_t dpad_button_to_hat_switch_0(uint8_t up, uint8_t down, uint8_t left, uint8_t right);
