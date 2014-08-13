#ifndef MOTOR_CONTROL
#define MOTOR_CONTROL

<<<<<<< HEAD
#include "gyro.h"
#include "gearli pragmas.h"

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

void gyroTurn(LibGyro g, int numOfDegrees, int speed)
{
	motor[motorD] = -speed;
	motor[motorE] = speed;
	float x = 0;
	float heading = 0;
	while(heading < numOfDegrees)
	{
		float deltaTime = getTimeFromLibTimer(g.gyroTime);
		clearLibTimer(g.gyroTime);
		x+=(readGyro(g));

		float updateRatio = 1000 / deltaTime;
		heading = x / updateRatio;
		displayNumber(heading, 2);

		if(heading > (numOfDegrees - 60))
		{
			motor[motorD] = -15;
			motor[motorE] = 15;
		}
		if(heading > (numOfDegrees - 20))
		{
			motor[motorD] = -7;
			motor[motorE] = 7;
		}
		wait1Msec(5);
	}
	motor[motorD] = 0;
	motor[motorE] = 0;
}

#endif
