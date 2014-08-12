#ifndef MOTOR_CONTROL
#define MOTOR_CONTROL

#include "math utils.h"

typedef enum // this enum is used to denote different movement directions, only for the simple movement below
{
	FORWARD, BACKWARD, RIGHT, LEFT
} SimpleMoveDirections;

void move(SimpleMoveDirections direction, int speed, int duration)
{
	//capNumber(&speed, -100, 100);
	switch(direction) // decides what combination of motors to move
	{
	case FORWARD: // forward
		motor[motorD] = speed;
		motor[motorE] = speed;
		break;
	case BACKWARD: // backward
		motor[motorD] = -speed;
		motor[motorE] = -speed;
		break;
	case RIGHT: // right
		motor[motorD] = -speed;
		motor[motorE] = speed;
		break;
	case LEFT: // take a guess
		motor[motorD] = speed;
		motor[motorE] = -speed;
		break;
	default:
		break;
	}
	wait1Msec(duration);	// waits the duration in msecs, should probably use the timer file for this
	motor[motorD] = 0; 		// kills the motors
	motor[motorE] = 0;
}
#endif
