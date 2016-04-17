#ifndef __SHIFTREGISTER_H__
#define __SHIFTREGISTER_H__

#include "u8glib/u8g.h"

#include "Extensions.h"

class ShiftRegister
{
public:
	ShiftRegister();
	~ShiftRegister();

	bool Init(uint8_t pinInput, uint8_t pinLatch, uint8_t pinClock);

	char Update(int delayTime);

	char GetData(void);

protected:
private:
	ShiftRegister( const ShiftRegister &c );
	ShiftRegister& operator=( const ShiftRegister &c );

	uint8_t m_pinInput;
	uint8_t m_pinLatch;
	uint8_t m_pinClock;

	char m_data;

};

#endif //__SHIFTREGISTER_H__
