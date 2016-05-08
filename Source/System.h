#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include "Extensions.h"
#include "Graphics/Graphics.h"
#include "ADXL335.h"
#include "ShiftRegister.h"

class System;

extern System* g_system;

class System
{
public:
	System();
	~System();

	bool Init(void);

	inline Graphics* GetGraphics(void) { return m_pGraphics; }
	inline ADXL335* GetAccelerometer(void) { return m_pAccelerometer; }
	inline ShiftRegister* GetSR(void) { return m_pSR; }

protected:
private:
	System(const System &c);
	System& operator=(const System &c);

	Graphics* m_pGraphics;
	ADXL335* m_pAccelerometer;
	ShiftRegister* m_pSR;
};

#endif //__SYSTEM_H__
