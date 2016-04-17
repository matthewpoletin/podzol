#include "adc.h"

void ADCInit(void)
{
	// Setup the reference source.
	ADMUX &= ~((1<<REFS1) | (1<<REFS0));
	ADMUX |= (1<<REFS0);

	ADMUX &= ~((1<<MUX3) | (1<<MUX2) | (1<<MUX1) | (1<<MUX0));

	//ADCSRA = (1<<ADEN)|(1<<ADSC)|(1<<ADATE)|(1<<ADPS2);
	ADCSRA = (1<<ADEN)|(1<<ADSC)|(0<<ADATE)|(0<<ADIF)|(0<<ADIE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	//SFIOR = 0x00;

	while (!(ADCSRA & ADIF));
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