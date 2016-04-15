#ifndef __ADC_H__
#define __ADC_H__

#include <avr/io.h>
#include <util/delay.h>

void ADCInit(void);

int AnalogRead(unsigned char channel);

#endif