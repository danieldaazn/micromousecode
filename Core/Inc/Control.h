#ifndef CONTROL_H
#define CONTROL_H
#include "main.h"

#define PI 3.1415926

struct position{
	float x;
	float y;
	float theta;
};

struct velocity{
	float velocityX;
	float velocityY;
	float theta

};

float calculateDeltaTheta(int distanceL, int distanceR);
float calculateDistance(int distanceL, int distanceR);
float calculateDeltaX(float distance, float theta);
float calculateDeltaY(float distance, float theta);

struct position updatePosition(struct position currentPos, int distanceL, int distanceR);

#endif
