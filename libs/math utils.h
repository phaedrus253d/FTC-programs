#ifndef MATH_UTILS
#define MATH_UTILS

void capNumber(int *i, int max, int min) //NOT WORKING, DONT USE IT
{
	if(*i > max)
		*i = max;
	if(*i < min)
		*i = min;
}

#endif
