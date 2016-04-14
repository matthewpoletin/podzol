#include "adxl335.h"

int read_adxl335_x_value(unsigned char channel)
{
	int x_value;
	x_value = read_adc_channel(channel);
	return x_value;
}

int read_adxl335_y_value(unsigned char channel)
{
	int y_value;
	y_value = read_adc_channel(channel);
	return y_value;
}

int read_adxl335_z_value(unsigned char channel)
{
	int z_value;
	z_value = read_adc_channel(channel);
	return z_value;
}