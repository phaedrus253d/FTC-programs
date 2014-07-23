#ifndef MOTOR_CONTROL
#define MOTOR_CONTROL

#include "math utils.h"

typedef enum {
	FORWARD, BACKWARD, RIGHT, LEFT
} MoveDirections;

void move(MoveDirections direction, int speed, int duration)
{
	//capNumber(&speed, -100, 100);
	if(direction == FORWARD)
	{
		motor[motorD] = speed;
		motor[motorE] = speed;
	}
	if(direction == BACKWARD)
	{
		motor[motorD] = -speed;
		motor[motorE] = -speed;
	}
	if(direction == RIGHT)
	{
		motor[motorD] = -speed;
		motor[motorE] = speed;
	}
	if(direction == LEFT)
	{
		motor[motorD] = speed;
		motor[motorE] = -speed;
	}
	wait1Msec(duration);
	motor[motorD] = 0;
	motor[motorE] = 0;
}
#endif
