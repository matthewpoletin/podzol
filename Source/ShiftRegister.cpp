#include "ShiftRegister.h"

ShiftRegister::ShiftRegister()
{
}

ShiftRegister::~ShiftRegister()
{
}

bool ShiftRegister::Init(uint8_t pinInput, uint8_t pinLatch, uint8_t pinClock)
{
	m_pinInput = pinInput;
	m_pinLatch = pinLatch;
	m_pinClock = pinClock;

	u8g_SetPinInput(m_pinInput);
	u8g_SetPinOutput(m_pinLatch);
	u8g_SetPinOutput(m_pinClock);

	return true;
}

char ShiftRegister::Update(int delayTime)
{
	u8g_SetPinLevel(m_pinLatch, 1);
	delay_us(delayTime * 2);
	u8g_SetPinLevel(m_pinLatch, 0);

	char output = 0x00;
	for (int i = 0; i < 8; i++)
	{
		output |= u8g_GetPinLevel(m_pinInput) << i;
		u8g_SetPinLevel(m_pinClock, 1);
		delay_us(delayTime);
		u8g_SetPinLevel(m_pinClock, 0);
		delay_us(delayTime);
	}
	m_data = output;
	return output;
}

char ShiftRegister::GetData(void)
{
	return m_data;
}