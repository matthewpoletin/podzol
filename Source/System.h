#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include "Extensions.h"
#include "Graphics.h"
#include "Accelerometer.h"

class System;

extern System* g_system;

class System
{
public:
	System();
	~System();

	bool Init(void);

	Graphics* GetGraphics();
	Accelerometer* GetAccelerometer();

protected:
private:
	System(const System &c);
	System& operator=(const System &c);

	Graphics* m_graphics;
	Accelerometer* m_accelerometer;

};

#endif //__SYSTEM_H__
