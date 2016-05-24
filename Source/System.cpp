#include "System.h"

System* g_system;

System::System()
{
	m_pGraphics = new Graphics();
	
	m_pADC = new ADConv();
	m_pAccelerometer = new ADXL335();

	m_pController = new Controller();

}

System::~System()
{
}

bool System::Init(void)
{
	this->m_pGraphics->Init();

	m_pADC->Init();

	m_pAccelerometer->Init(0, 1, 2, 3.3f);

	m_pController ->Init();

	return true;
}