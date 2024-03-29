#ifndef GYRO
#define GYRO

#include "Timer.h"

typedef struct Gyro
{
	float offset;				// the offset of the sensor, used for calibration
	tSensors port;			// port of the sensor
	LibTimer gyroTime;
} LibGyro;

void createLibGyro(LibGyro &g, tSensors gyroPort) // creates a gyro struct and inits variables
{
	g.offset = 0;
	g.port = gyroPort;
	createLibTimer(g.gyroTime);
}

void calibrateLibGyro(LibGyro &g, int numberOfTests = 50) // calibrates the gyroscopic sensor
{
	float average = 0;
	for(int i = 0; i < numberOfTests; i++)
	{
		average += SensorValue(g.port);
		wait1Msec(2);
	}
	average /= numberOfTests;
	g.offset = average; // sets the offset to the average of the numOfTests
}

long readLibGyro(LibGyro &g) // reads the gyroSensor
{
	return SensorValue(g.port) - g.offset;
}

float capTo360(float number) // should move to math utils
{
	if(number > 360)
		return number - 360;
	if(number < 0)
		return number + 360;
	return number;
}
#endif
