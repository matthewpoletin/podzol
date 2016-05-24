#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include "Extensions.h"
#include "Graphics/Graphics.h"
#include "ADXL335.h"
#include "Controller.h"
#include "ADC.h"

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
	inline ADConv* GetADC(void) { return m_pADC; }
	inline Controller* GetController(void) { return m_pController; }
protected:
private:
	System(const System &c);
	System& operator=(const System &c);

	Graphics* m_pGraphics;
	ADConv* m_pADC;
	ADXL335* m_pAccelerometer;
	Controller* m_pController;

};

#endif //__SYSTEM_H__
