#ifndef __ACCELEROMETER_H__
#define __ACCELEROMETER_H__ 1

#include "ADC/adc.h"
#include "ADXL335/adxl335.h"

#include "Point.h"

class Accelerometer
{
public:
	Accelerometer();
	~Accelerometer();

	bool Init(void);

	void UpdatePosition(void);

protected:
private:
	Accelerometer(const Accelerometer &c);
	Accelerometer& operator=(const Accelerometer &c);

	Point* m_position;

};

#endif //__ACCELEROMETER_H__
