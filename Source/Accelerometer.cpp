#include "Accelerometer.h"

Accelerometer::Accelerometer()
{
}

Accelerometer::~Accelerometer()
{
}

bool Accelerometer::Init(void)
{
	adc_init();

	m_position = new Point();

	return true;
}

void Accelerometer::UpdatePosition(void)
{
	m_position->x = read_adxl335_x_value(0);
	m_position->y = read_adxl335_y_value(1);
	m_position->z = read_adxl335_z_value(2);
}
