#include "ShiftRegister.h"

ShiftRegister::ShiftRegister()
{
}

ShiftRegister::~ShiftRegister()
{
}

bool ShiftRegister::Init(uint8_t pinData, uint8_t pinLatch, uint8_t pinClock)
{
	m_pinData = pinData;
	m_pinLatch = pinLatch;
	m_pinClock = pinClock;

	u8g_SetPinInput(m_pinData);
	u8g_SetPinOutput(m_pinLatch);
	u8g_SetPinOutput(m_pinClock);

	return true;
}

void ShiftRegister::Update(int delayTimeUS)
{
	u8g_SetPinLevel(m_pinLatch, 1);
	delay_us(20);
	u8g_SetPinLevel(m_pinLatch, 0);

	int temp = 0;
	int pinState;
	unsigned char data = 0;

	for(unsigned int i = 0; i != 8; i++)
	{
		u8g_SetPinLevel(m_pinClock, 0);
		_delay_us(0.2);
		temp = u8g_GetPinLevel(m_pinData);
		if (temp)
		{
			pinState = 1;
			data |= (1<<i);
		}
		else
		{
			pinState = 0;

		}
		u8g_SetPinLevel(m_pinClock, 1);
	}

	u8g_SetPinLevel(m_pinClock, 0);

	m_data = data;
}