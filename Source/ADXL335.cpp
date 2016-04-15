#include "ADXL335.h"

#include <math.h>

ADXL335::ADXL335()
{
}

 ADXL335::~ADXL335()
{
}

bool ADXL335::Init(int pin_x, int pin_y, int pin_z, float aref)
{
	m_aref = aref;
	m_pin_x = pin_x;
	m_pin_y = pin_y;
	m_pin_z = pin_z;
	_mvG = aref / 10.0;
	_bias = aref / 2.0;
	_rad2deg = 180.0 / M_PI;

	ADCInit();

	DDRA |= (1<<PA0)|(1<<PA1)|(1<<PA2);

	return true;
}

float ADXL335::geta2d(float gx, float gy)
{
	float a;
	
	a = gx * gx;
	a = fma(gy, gy, a);
	
	return sqrt(a);
}

//gets the magnitude of the 3d vector
//the formula is a^2 = x^2 + y^2 + z^2
float ADXL335::geta3d(float gx, float gy, float gz)
{
	float a;
	
	//use floating point multiply-add cpu func
	//sometimes we get better precision
	a = gx * gx;
	a = fma(gy,gy,a);
	a = fma(gz,gz,a);
	
	return sqrt(a);
}

void ADXL335::processDeadzone(float* gv)
{
	if (*gv < _deadzone && *gv > -_deadzone)
	{
		*gv = 0.0;
	}
}

float ADXL335::getGravity(int reading)
{  
	float voltage = reading * m_aref;
	voltage /= 1024.0;

	//minus the zero g bias 
	//then divide by mv/g
	//which when Vs = 3.3V, V/g = 0.330
	float gv = (voltage - _bias) / _mvG;
	
	//minus the null zone
	processDeadzone(&gv);
	
	return gv;
}

float ADXL335::_getRho(float ax, float ay, float az)
{
	return geta3d(_xg,_yg,_zg);
}

float ADXL335::_getPhi(float ax, float ay, float az)
{
	return atan2(ay, ax) * _rad2deg;  
}

float ADXL335::_getTheta(float ax, float ay, float az)
{
	float rho = _getRho(ax, ay, az);
	
	if (rho == 0.0)
	return NAN;
	else
	return acos(az / rho) * _rad2deg;
}

void ADXL335::SetThreshold(float deadzone)
{
	_deadzone = deadzone;
}

//gets whether the device is in free fall
bool ADXL335::getFreefall()
{
	//if all three vectors read zero then return true, otherwise; false.
	return _xg == 0.0 && _yg == 0.0 && _zg == 0.0;
}

float ADXL335::GetX()
{
	return _xg;
}

float ADXL335::GetY()
{
	return _yg;
}

float ADXL335::GetZ()
{
	return _zg;
}

float ADXL335::getRho()
{
	return _getRho(_xg,_yg,_zg);
}

float ADXL335::getPhi()
{
	return _getPhi(_xg,_yg,_zg);
}

float ADXL335::getTheta()
{
	return _getTheta(_xg,_yg,_zg);
}

void ADXL335::Update()
{
	_xg = getGravity(AnalogRead(m_pin_x));
	_yg = getGravity(AnalogRead(m_pin_y));
	_zg = getGravity(AnalogRead(m_pin_z));
}