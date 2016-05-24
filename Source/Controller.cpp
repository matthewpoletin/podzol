#include "Controller.h"

Controller::Controller()
{
	m_pSR = new ShiftRegister();
}

Controller::~Controller()
{
}

bool Controller::Init(void)
{
	m_pSR->Init(PN(2,0), PN(2,2), PN(2,1));
}

void Controller::Update(void)
{
	unsigned char srData = m_pSR->GetData();
	m_pSR->Update(1000);
	for (unsigned int butCounter = 0; butCounter < 8; butCounter++)
	{
		m_bKeys[butCounter] = false;
		if(!((srData >> butCounter) & 1))
		{
			m_bKeys[butCounter] = true;
		}
	}

}

bool Controller::IsKeyClicked(unsigned int keyNum)
{
	return m_bKeys[keyNum];
}
