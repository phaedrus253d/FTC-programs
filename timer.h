#ifndef TIMER
#define TIMER

typedef struct 
{
	TTimers timer;
	int lastTime;
	int targetTime;
}Timer;

void createTimer(Timer &t, TTimers timer = T2, int target)
{
	t.timer = timer;
	t.lastTime = time1[timer];
	t.targetTime = target;
}

void createTimer(Timer &t, TTimers timer = T2)
{
	createTimer(t, timer, 0);
}

#endif
