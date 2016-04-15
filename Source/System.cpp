#include "System.h"

System* g_system;

System::System()
{
	m_graphics = new Graphics();
	
	m_accelerometer = new ADXL335();

}

System::~System()
{
}

bool System::Init(void)
{
	this->m_graphics->Init();

	m_accelerometer->Init(0, 1, 2, 3.3f);

	return true;
}

Graphics* System::GetGraphics(void)
{
	return m_graphics;
}

ADXL335* System::GetAccelerometer(void)
{
	return m_accelerometer;
}