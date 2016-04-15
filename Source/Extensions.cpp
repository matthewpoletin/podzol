#include "Extensions.h"

// Implementation
void * operator new(size_t size)
{
	return malloc(size);
}

void operator delete(void * ptr)
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