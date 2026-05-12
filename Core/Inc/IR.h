#ifndef IR_H
#define IR_H
#include <stdint.h>
#include <main.h>

typedef enum {
	DIST_FL = 0,
	DIST_L = 1,
	DIST_R = 2,
	DIST_FR = 3
} dist_t;

void ADC1_Select_CH4(void);
void ADC1_Select_CH5(void);
void ADC1_Select_CH8(void);
void ADC1_Select_CH9(void);

uint16_t measure_dist(dist_t dist);

#endif
