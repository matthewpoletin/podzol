#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "ShiftRegister.h"

class Controller
{
public:
	Controller();
	~Controller();

	bool Init(void);

	void Update(void);

	inline ShiftRegister* GetSR(void) { return m_pSR; }

	bool IsKeyClicked(unsigned int keyNum);

protected:
private:
	Controller(const Controller &c);
	Controller& operator=( const Controller &c );

	ShiftRegister* m_pSR;

	bool m_bKeys[8];

};

#endif //__CONTROLLER_H__
