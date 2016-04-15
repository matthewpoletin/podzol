#include "adc.h"

void ADCInit(void)
{
	ADCSRA = (1<<ADEN)|(1<<ADSC)|(1<<ADATE)|(1<<ADPS2);
	SFIOR = 0x00;
}

int AnalogRead(unsigned char channel)
{
	int adc_value;
	unsigned char temp;
	ADMUX = (1 << REFS0) | channel;
	_delay_ms(1);
	temp = ADCL;
	adc_value = ADCH;
	adc_value = (adc_value << 8) | temp;
	return adc_value;
}