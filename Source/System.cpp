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

	return true;
}
