#ifndef SMUX
#define SMUX

void smuxHalt(tSensors smux)
{
	ubyte sendMsg[4];

	sendMsg[0] = 3;		//size of i2c message
	sendMsg[1] = 0x10;	//address of smux
	sendMsg[2] = 0x20;	//command register
	sendMsg[3] = 0;		//Command to send (HALT)

	sendI2CMsg(smux, sendMsg, 0);
	wait1Msec(50);
}

#endif