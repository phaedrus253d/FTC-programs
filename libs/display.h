#ifndef DISPLAY
#define DISPLAY

void displayText(string text, int lineNumber)
{
	nxtDisplayTextLine(lineNumber, text);
}

void displayNumber(int data, int lineNumber)
{
	nxtDisplayTextLine(lineNumber, "%d", data);
}

void displayNumber(float data, int lineNumber)
{
	nxtDisplayTextLine(lineNumber, "%f", data);
}

int getChoice(const string text, const string option1, const string option2) // op1 is for the right button, op2 is for the left button
{
	int choice=3;
	while (choice == 3)
	{
		while (nNxtButtonPressed==-1)
		{
			nxtDisplayTextLine(0, text);
			nxtDisplayTextLine(1, "      ");
			nxtDisplayTextLine(2, "Right Button:");
			nxtDisplayTextLine(3, option1);
			nxtDisplayTextLine(4, "      ");
			nxtDisplayTextLine(5, "Left Button:");
			nxtDisplayTextLine(6, option2);
			nxtDisplayTextLine(7, "       ");
		}
		choice = nNxtButtonPressed;
	}
	while (nNxtButtonPressed!=-1)
	{
	}
	wait1Msec(250);
	return choice-1; // shifts so right button = 0 and left button = 1
}

#endif
