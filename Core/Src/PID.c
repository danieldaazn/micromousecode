#include "PID.h"
#include "Control.h"

extern float angleError;
extern float oldAngleError;
extern float distanceError;
extern float oldDistanceError;
extern float kPw;
extern float kDw;
extern float kPx;
extern float kDx;

void updatePID(int distanceL, int distanceR){
	int target = 0;
	float angleCorrection;
	float distanceCorrection;
	float leftMotorSpeed;
	float rightMotorSpeed;
	angleError = target - calculateDeltaTheta(distanceL, distanceR);
	angleCorrection = kPw * angleError + kDw * (angleError - oldAngleError);
	oldAngleError = angleError;

	distanceError = 0.4;
	distanceCorrection = distanceError * kPx + (distanceError - oldDistanceError) * kDx;
	oldDistanceError = distanceError;

	leftMotorSpeed = (distanceCorrection + angleCorrection) * 500;
	rightMotorSpeed = (distanceCorrection - angleCorrection) * 500;




}
