#ifndef SMUX
#define SMUX

#include "drivers/hitechnic-sensormux.h"

bool isSmuxBatteryOn(tSensors SMUXPort)
{
	byte result = HTSMUXreadStatus(SMUXPort);
	return !(result & HTSMUX_STAT_ERROR) == HTSMUX_STAT_ERROR;
}

#endif
