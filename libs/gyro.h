#ifndef GYRO
#define GYRO

typedef struct Gyro
{
	float offset;
	int lastReading;
	tSensors port;
} Gyro;

void createGyro(Gyro &g, tSensors gyroPort)
{
	g.offset = 0;
	g.lastReading = 0;
	g.port = gyroPort;
}

void calibrateGyro(Gyro &g, int numberOfTests = 50)
{
	float average = 0;
	for(int i = 0; i < numberOfTests; i++)
	{
		average += SensorValue(g.port);
	}
	average /= numberOfTests;
	g.offset = average;
}

int readGyro(Gyro &g)
{
	int value = SensorValue(g.port) - g.offset;
	g.lastReading = value;
	return value;
}

#endif
