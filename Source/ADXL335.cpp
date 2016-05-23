#include "ADXL335.h"

#include <math.h>

#include <u8glib/u8g.h>

#include "System.h"
extern System* g_system;

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

float ADXL335::GetGravity(int reading)
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
	return geta3d(m_xg, m_yg, m_zg);
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
	return m_xg == 0.0 && m_yg == 0.0 && m_zg == 0.0;
}

float ADXL335::getRho()
{
	return _getRho(m_xg,m_yg,m_zg);
}

float ADXL335::getPhi()
{
	return _getPhi(m_xg,m_yg,m_zg);
}

float ADXL335::getTheta()
{
	return _getTheta(m_xg,m_yg,m_zg);
}

void ADXL335::Update()
{
	m_xg = g_system->GetADC()->Read(m_pin_x);
	m_yg = g_system->GetADC()->Read(m_pin_y);
	m_zg = g_system->GetADC()->Read(m_pin_z);
}