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
	delay_us(delayTimeUS * 2);
	u8g_SetPinLevel(m_pinLatch, 0);

	char output = 0x00;
	for (int i = 0; i < 8; i++)
	{
		output |= u8g_GetPinLevel(m_pinData) << i;
		u8g_SetPinLevel(m_pinClock, 1);
		delay_us(delayTimeUS);
		u8g_SetPinLevel(m_pinClock, 0);
		delay_us(delayTimeUS);
	}
	m_data = output;
}