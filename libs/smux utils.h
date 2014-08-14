#ifndef SMUX
#define SMUX

#define SMUX_CMD_HALT 0x00
#define SMUX_CMD_AUTODETECT 0x01
#define SMUX_CMD_RUN 0x02

void smuxSendCmd(tSensors smux, char command)
{
	char sendMsg[4];

	sendMsg[0] = 3;					//size of i2c message
	sendMsg[1] = 0x10;			//address of smux
	sendMsg[2] = 0x20;			//command register
	sendMsg[3] = command;		//Command to send

	sendI2CMsg(smux, sendMsg, 0);
	if(command == SMUX_CMD_AUTODETECT)
		wait1Msec(500);
	if(command == SMUX_CMD_HALT)
		wait1Msec(50);
}

#endif
