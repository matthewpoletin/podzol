#include "System.h"

System* g_system;

System::System()
{
	m_pGraphics = new Graphics();
	
	//m_pAccelerometer = new ADXL335();

	m_pSR = new ShiftRegister();
}

System::~System()
{
}

bool System::Init(void)
{
	this->m_pGraphics->Init();

	//m_pAccelerometer->Init(0, 1, 2, 3.3f);

	//m_pSR->Init(PN(1,5), PN(1,6), PN(1,7));
	m_pSR->Init(PN(2,0), PN(2,2), PN(2,1));

	return true;
}