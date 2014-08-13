#include "libs/gyro.h"
#include "libs/display.h"
#include "libs/Timer.h"
#include "libs/motor control.h"
task main()
{
	nxtDisplayCenteredTextLine(2, "REMOVE HAND");
	nxtDisplayCenteredTextLine(3, "FROM ROBOT");
	wait1Msec(2000);
	eraseDisplay();
	LibGyro g;

	createLibGyro(g, S4);

	calibrateLibGyro(g);
	//move(FORWARD, 100, 1000);
	gyroTurn(g, 90, 50);
}
