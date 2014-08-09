#ifndef GYRO
#define GYRO

typedef struct Gyro
{
	float offset;				// the offset of the sensor, used for calibration
	tSensors port;			// port of the sensor
} Gyro;

void createGyro(Gyro &g, tSensors gyroPort) // creates a gyro struct and inits variables
{
	g.offset = 0;
	g.port = gyroPort;
}

void calibrateGyro(Gyro &g, int numberOfTests = 50) // calibrates the gyroscopic sensor
{
	float average = 0;
	for(int i = 0; i < numberOfTests; i++)
	{
		average += SensorValue(g.port);
	}
	average /= numberOfTests;
	g.offset = average; // sets the offset to the average of the numOfTests
}

int readGyro(Gyro &g) // reads the gyroSensor
{
	return SensorValue(g.port) - g.offset;
}

#endif
