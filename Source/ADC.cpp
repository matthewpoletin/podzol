#include "adc.h"

 ADConv::ADConv()
{
}

 ADConv::~ADConv()
{
}

bool ADConv::Init(void)
{
	ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); // frequency
	ADMUX |= 1<<ADLAR;	// representation
	ADMUX |= (1<<REFS0)|(1<<REFS1);	// refference avcc
	ADCSRA |= 1<<ADATE;	// ? enable adc interrupts
	ADCSRA |= 1<<ADEN;	// enable adc
	//ADCSRA |= 1<<ADSC;	// enable adc

	return true;
}

uint8_t ADConv::Read(unsigned char ch)
{
	ADMUX &= ~((1<<MUX3) | (1<<MUX2) | (1<<MUX1) | (1<<MUX0)); // clear channel
	ADMUX |= ch;
	
	//Start Single conversion
	ADCSRA|=(1<<ADSC);
	//Wait for conversion to complete
	while(!(ADCSRA & (1<<ADIF)));
	//Clear ADIF by writing one to it
	//Note you may be wondering why we have write one to clear it
	//This is standard way of clearing bits in io as said in datasheets.
	//The code writes '1' but it result in setting bit to '0' !!!
	ADCSRA|=(1<<ADIF);

	return ADCH;
}
