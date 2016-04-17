#ifndef EXTENSIONS_H_
#define EXTENSIONS_H_

#include <stdlib.h>

//#define F_CPU 1000000
#include <util/delay.h>

void* operator new  (size_t count);
void operator delete(void * ptr);

void delay_ms(int ms);
void delay_us(int delayTime);

#endif /* EXTENSIONS_H_ */