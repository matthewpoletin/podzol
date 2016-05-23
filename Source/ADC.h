#ifndef __ADC_H__
#define __ADC_H__

#include <avr/io.h>
#include <util/delay.h>

class ADConv
{
public:
	ADConv();
	~ADConv();

	bool Init(void);

	uint8_t Read(unsigned char ch);

protected:
private:


};

#endif // __ADC_H__