#include "Control.h"
#include <math.h>


const float R_CENTER_TO_WHEEL = 4.1275; //4.1275cm from center to wheel

float calculateDeltaTheta(int distanceL, int distanceR){
	float deltaTheta = (float)(distanceL - distanceR) / (2.0 * R_CENTER_TO_WHEEL);
	return deltaTheta;
}

float calculateDistance(int distanceL, int distanceR){
	float deltaDistance = ((float)distanceL - (float)distanceR) / 2.0;
	return deltaDistance;
}

float calculateDeltaX(float distance, float theta){
	float radians = (2 * PI * theta) / 360.0;
	return distance * cos(radians);
}

float calculateDeltaY(float distance, float theta){
	float radians = (2 * PI * theta) / 360.0;
	return distance * sin(radians);
}

struct position updatePosition(struct position currentPos, int distanceL, int distanceR){
	float deltaTheta, distance, deltaX, deltaY;
	struct position newPos;

	distance = calculateDistance(distanceL, distanceR);
	deltaX = calculateDeltaX(distance, pos.theta);
	deltaY = calculateDeltaY(distance, pos.theta);
	deltaTheta = calculateDeltaTheta(distanceL, distanceR);

	newPos.x = currentPos.x + deltaX;
	newPos.y = currentPos.y + deltaY;
	newPos.theta = currentPos.theta + deltaTheta;
}

struct velocity updateVelocity(struct velocity vel){

}
