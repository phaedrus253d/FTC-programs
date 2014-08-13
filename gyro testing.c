#include "libs/gyro.h"
#include "libs/display.h"
task main()
{
	wait1Msec(1000);
	LibGyro g;
	createLibGyro(g, S4);
	calibrateLibGyro(g);
	float x = 0;
	float heading = 0;
	while(true)
	{
		float deltaTime = getTimeFromLibTimer(g.gyroTime);
		clearLibTimer(g.gyroTime);
		x = readLibGyro(g);

		float updateRatio = 1000 / deltaTime;
		heading += x / updateRatio;
		displayLibNumber(heading, 2);

		wait1Msec(2);

	}
}
