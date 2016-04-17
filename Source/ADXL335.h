#ifndef __ADXL335_H__
#define __ADXL335_h__

#include "ADC.h"

class ADXL335
{
public:
	ADXL335();
	~ADXL335();

	bool Init(int pin_x, int pin_y, int pin_z, float aref);

	void SetThreshold(float deadzone);
	bool getFreefall();
	float GetX();
	float GetY();
	float GetZ();
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
	float _xg;
	float _yg;
	float _zg;
	float m_aref;
	float _mvG;
	float _deadzone;
	float _rad2deg;

};

#endif