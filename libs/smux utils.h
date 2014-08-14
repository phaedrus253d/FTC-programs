#ifndef SMUX
#define SMUX

#include "drivers/hitechnic-sensormux.h"

bool isSmuxBatteryOn(tSensors SMUXPort)
{
	byte result = HTSMUXreadStatus(SMUXPort);
	return !(result & HTSMUX_STAT_ERROR) == HTSMUX_STAT_ERROR;
}

bool isSMUXReady(tSensors SMUXPort)
{
	byte result = HTSMUXreadStatus(SMUXPort);
	return (result & HTSMUX_STAT_NORMAL) == HTSMUX_STAT_NORMAL || (result & HTSMUX_STAT_HALT) == HTSMUX_STAT_HALT;
}

bool prepairSMUX(tSensors SMUXPort, bool runBefore = false)
{
	if (!isSMUXBatteryOn(SMUXPort) && !runBefore)
	{
		PlaySound(soundException);
		wait1Msec(100);
		time1[T1] = 0;
		while (time1[T1]<10000 && !isSMUXBatteryOn(SMUXPort))
		{
			if (time1[T1] % 1000 > 975)
			{
				PlaySound(soundBlip);
			}
			nxtDisplayBigTextLine(1, "TURN ON");
			nxtDisplayBigTextLine(3, "SMUX");
			nxtDisplayBigTextLine(5, "BATTERY!!!");
		}
		eraseDisplay();
		return prepairSMUX(SMUXPort, true);
	}

	bool result = HTSMUXsendCommand(SMUXPort, HTSMUX_CMD_HALT);
	wait1Msec(50);
	result &= HTSMUXsendCommand(SMUXPort, HTSMUX_CMD_RUN);
	return result;
}

const tMUXSensor smuxSensorPortIndex[4][4] = {
	{
		msensor_S1_1,
		msensor_S1_2,
		msensor_S1_3,
		msensor_S1_4,
	},
	{
		msensor_S2_1,
		msensor_S2_2,
		msensor_S2_3,
		msensor_S2_4,
	},
	{
		msensor_S3_1,
		msensor_S3_2,
		msensor_S3_3,
		msensor_S3_4,
	},
	{
		msensor_S4_1,
		msensor_S4_2,
		msensor_S4_3,
		msensor_S4_4,
	}
};

tMUXSensor getSensor(int nxtPortNumber, int smuxPortNumber)
{
	return smuxSensorPortIndex[nxtPortNumber - 1][smuxPortNumber - 1];
}

#endif
