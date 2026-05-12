#include "Motor.h"

int16_t directionMask = 16;

int16_t leftDirection = 0;
int16_t rightDirection = 0;

uint16_t volatile enc_left = 0;
uint16_t volatile enc_right = 0;

int32_t volatile s_enc_left = 0; 	//signed enc left value to prevent overflow
int32_t volatile s_enc_right = 0;	//signed enc right value to prevent overflow

int32_t cm_enc_left = 0;
int32_t cm_enc_right = 0;

const float WHEEL_DIAMETER = 3.2; // wheel diameter is in cm
const float GEAR_RATIO = 50;
const float ENCODER_PULSES = 12;
const float TICKS_PER_REV = GEAR_RATIO * ENCODER_PULSES;
const float CM_PER_TICK = ((2 * 3.14159265358979323846264338) * (WHEEL_DIAMETER / 2)) / TICKS_PER_REV;

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) {
	if(htim->Instance == TIM3){
		leftDirection = (TIM3->CR1 & directionMask);
		enc_left = __HAL_TIM_GET_COUNTER(htim);
		s_enc_left = leftDirection ? s_enc_left - 1 : s_enc_left + 1;
		cm_enc_left = 2 * s_enc_left * CM_PER_TICK;
	}
	if(htim->Instance == TIM4){
		rightDirection = (TIM4->CR1 & directionMask);
		enc_right = __HAL_TIM_GET_COUNTER(htim);
		s_enc_right = rightDirection ? s_enc_right - 1 : s_enc_right + 1;
		cm_enc_right = 2 * s_enc_right * CM_PER_TICK;
		}
}
