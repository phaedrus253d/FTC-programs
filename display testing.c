#include "libs/display.h"

task main()
{
	if(getChoice("What pitch?", "Low", "High") == 0)
	{
		PlayImmediateTone(440, 100);
	}else{
		PlayTone(880, 100);
	}
	wait1Msec(1000);
}
