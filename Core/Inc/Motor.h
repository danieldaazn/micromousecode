#ifndef MOTOR_H
#define MOTOR_H
#include <stdint.h>
#include "main.h"

int16_t directionMask = 16;

int16_t leftDirection = 0;
int16_t rightDirection = 0;

uint16_t volatile enc_left = 0;
uint16_t volatile enc_right = 0;

int32_t volatile s_enc_left = 0;
int32_t volatile s_enc_right = 0;

int32_t cm_enc_left = 0;
int32_t cm_enc_right = 0;

uint16_t hardware_error_FL;
uint16_t hardware_error_L;
uint16_t hardware_error_FR;
uint16_t hardware_error_R;

const float WHEEL_DIAMETER = 3.2; // wheel diameter is in cm
const float GEAR_RATIO = 50;
const float ENCODER_PULSES = 12;
const float TICKS_PER_REV = GEAR_RATIO * ENCODER_PULSES;
const float CM_PER_TICK = ((2 * 3.14159265358979323846264338) * (WHEEL_DIAMETER / 2)) / TICKS_PER_REV;

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);

#endif