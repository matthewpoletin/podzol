#ifndef __ADXL__
#define __ADXL__

#include "ADC.h"

class ADXL335
{
public:
	ADXL335();
	~ADXL335();

	bool Init(int pin_x, int pin_y, int pin_z, float aref);

	void SetThreshold(float deadzone);
	bool getFreefall();
	inline int GetX() { return m_xg; }
	inline int GetY() { return m_yg; }
	inline int GetZ() { return m_zg; }
	float getRho();
	float getPhi();
	float getTheta();
	void Update();

private:
	float geta2d(float gx, float gy);
	float geta3d(float gx, float gy, float gz);
	void processDeadzone(float* gv);
	float GetGravity(int reading);
	float _getRho(float ax, float ay, float az);
	float _getPhi(float ax, float ay, float az);
	float _getTheta(float ax, float ay, float az);

	int m_pin_x;
	int m_pin_y;
	int m_pin_z;
	float _bias;
	int m_xg;
	int m_yg;
	int m_zg;
	float m_aref;
	float _mvG;
	float _deadzone;
	float _rad2deg;

};

#endif // ADXL