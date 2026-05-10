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

uint16_t dis_FL;
uint16_t dis_FR;
uint16_t dis_L;
uint16_t dis_R;

const int NOM_FORWARD = 200;
const int NOM_DIAGONAL = 100;

const int CAL_FL = 368;
const int CAL_L = 494;
const int CAL_FR = 370;
const int CAL_R = 493;

const float SCALE_FL    = (float)NOM_DIAGONAL / CAL_FL;
const float SCALE_FR    = (float)NOM_DIAGONAL / CAL_FR;
const float SCALE_L     = (float)NOM_FORWARD  / CAL_L;
const float SCALE_R     = (float)NOM_FORWARD  / CAL_L;

static void ADC1_Select_CH4(void);
static void ADC1_Select_CH5(void);
static void ADC1_Select_CH8(void);
static void ADC1_Select_CH9(void);

uint16_t measure_dist(dist_t dist);

#endif