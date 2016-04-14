#include "System.h"

System* g_system;

System::System()
{
}

System::~System()
{
}

bool System::Init(void)
{
	m_graphics = new Graphics();
	m_graphics->Init();

	m_accelerometer = new Accelerometer();
	m_accelerometer->Init();

	return true;
}

Graphics* System::GetGraphics(void)
{
	return m_graphics;
}

Accelerometer* System::GetAccelerometer(void)
{
	return m_accelerometer;
}