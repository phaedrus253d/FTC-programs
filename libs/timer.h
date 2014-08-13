#ifndef TIMER
#define TIMER

typedef struct // The basic timer struct
{
	TTimers timer; 	// The hardware timer used
	int lastTime;		// last time the timer was read
	int targetTime;	// the target of the timer
}LibTimer;

void createLibTimer(LibTimer &t, TTimers timer = T2)
{
	t.timer = timer;
	t.lastTime = time1[timer];
	t.targetTime = 0;
}

void clearLibTimer(LibTimer &t)				// clears the timer
{
	t.lastTime = time1[t.timer];	// all we do here is set the last time read to the current time
}

void setLibTimerTarget(LibTimer &t, int msec)	// sets the target of the timer
{
	t.targetTime = time1[t.timer] + msec;	// sets the target to the current time + target
	t.lastTime = time1[t.timer];						// sets last time to current time, so difference is the target
}

void addToLibTimerTarget(LibTimer &t, int msecToAdd)	// adds a number of msecs to the target
{
	t.targetTime += msecToAdd;
}

void subtractFromLibTimerTarget(LibTimer &t, int msecToSub) // removes a number of msecs from target
{
	t.targetTime -= msecToSub;
}

int getTimeFromLibTimer(LibTimer &t) // gets the difference in the current time and the last time read
{
	return time1[t.timer] - t.lastTime;
}

bool isLibTimerPastTarget(LibTimer &t) // checks to see if the timer is past the target
{
	return t.targetTime >= time1[t.timer];
}

bool isLibTimerBeforeTarget(LibTimer &t) // checks to see if the timer is before the target
{
	return t.targetTime < time1[t.timer];
}

#endif
