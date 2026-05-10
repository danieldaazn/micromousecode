#include "IR.h"

ADC_ChannelConfTypeDef sConfig = {0};

ADC_ChannelConfTypeDef sConfig = {0};

//far left
static void ADC1_Select_CH4(void){
	sConfig.Channel = ADC_CHANNEL_4;
	sConfig.Rank = ADC_REGULAR_RANK_1;
	sConfig.SamplingTime = ADC_SAMPLETIME_7CYCLES_5;

	if(HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK){
		Error_Handler();
	}
};

//right
static void ADC1_Select_CH5(void){
	sConfig.Channel = ADC_CHANNEL_5;
	sConfig.Rank = ADC_REGULAR_RANK_1;
	sConfig.SamplingTime = ADC_SAMPLETIME_7CYCLES_5;

	if(HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK){
		Error_Handler();
	}
};

//left
static void ADC1_Select_CH8(void){
	sConfig.Channel = ADC_CHANNEL_8;
	sConfig.Rank = ADC_REGULAR_RANK_1;
	sConfig.SamplingTime = ADC_SAMPLETIME_7CYCLES_5;

	if(HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK){
		Error_Handler();
	}
};

//far right
static void ADC1_Select_CH9(void){
	sConfig.Channel = ADC_CHANNEL_9;
	sConfig.Rank = ADC_REGULAR_RANK_1;
	sConfig.SamplingTime = ADC_SAMPLETIME_7CYCLES_5;

	if(HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK){
		Error_Handler();
	}
};

uint16_t measure_dist(dist_t dist){
	GPIO_TypeDef* emitter_port;
	uint16_t emitter_pin;
	GPIO_TypeDef* receiver_port;
	uint16_t receiver_pin;

	switch(dist){
	case DIST_FL:
		emitter_port 	= EMIT_FL_GPIO_Port;
		emitter_pin 	= EMIT_FL_Pin;
		receiver_port	= RECIV_FL_GPIO_Port;
		receiver_pin	= RECIV_FL_Pin;
		ADC1_Select_CH9();
		break;
	case DIST_L:
		emitter_port 	= EMIT_L_GPIO_Port;
		emitter_pin 	= EMIT_L_Pin;
		receiver_port	= RECIV_L_GPIO_Port;
		receiver_pin	= RECIV_L_Pin;
		ADC1_Select_CH8();
		break;
	case DIST_FR:
		emitter_port 	= EMIT_FR_GPIO_Port;
		emitter_pin 	= EMIT_FR_Pin;
		receiver_port	= RECIV_FR_GPIO_Port;
		receiver_pin	= RECIV_FR_Pin;
		ADC1_Select_CH4();
		break;
	case DIST_R:
		emitter_port 	= EMIT_R_GPIO_Port;
		emitter_pin 	= EMIT_R_Pin;
		receiver_port	= RECIV_R_GPIO_Port;
		receiver_pin	= RECIV_R_Pin;
		ADC1_Select_CH5();
		break;

	}
	HAL_GPIO_WritePin(emitter_port, emitter_pin, GPIO_PIN_SET);
	HAL_Delay(5);

	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	uint16_t adc_val = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);


	HAL_GPIO_WritePin(emitter_port, emitter_pin, GPIO_PIN_RESET);


	return adc_val;
}