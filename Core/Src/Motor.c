#include "Motor.h"
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