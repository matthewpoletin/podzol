#include "Extensions.h"

void* operator new(size_t count)
{
	return malloc(count);
}

void operator delete(void* ptr)
{
	free(ptr);
}

void delay_ms(int ms)
{
#ifdef DEBUG
	for (int i = 0; i < ms; i++)
	{
		_delay_ms(1);
	}
#endif
}

void delay_us(int delayTime)
{
#ifdef DEBUG
	for (int i = 0; i < delayTime; i++)
	{
		_delay_us(1);
	}
#endif
}