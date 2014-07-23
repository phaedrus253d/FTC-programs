#ifndef MOTOR_CONTROL
#define MOTOR_CONTROL

#include "math utils.h"

typedef enum {
	FORWARD, BACKWARD, RIGHT, LEFT
} MoveDirections;

void move(MoveDirections direction, int speed, int duration)
{
	//capNumber(&speed, -100, 100);
	switch(direction){
	case FORWARD:
		motor[motorD] = speed;
		motor[motorE] = speed;
		break;
	case BACKWARD:
		motor[motorD] = -speed;
		motor[motorE] = -speed;
		break;
	case RIGHT:
		motor[motorD] = -speed;
		motor[motorE] = speed;
		break;
	case LEFT:
		motor[motorD] = speed;
		motor[motorE] = -speed;
		break;
	default:
		break;
	}
	wait1Msec(duration);
	motor[motorD] = 0;
	motor[motorE] = 0;
}
#endif
