#ifndef __POINT_H__
#define __POINT_H__

#include <math.h>

class Point
{
public:
	Point();
	Point(const float& x, const float& y, const float& z);

	~Point();

	Point& add(const Point& other);
	Point& subtract(const Point& other);
	Point& multiply(const Point& other);
	Point& divide(const Point& other);

	friend Point operator+(Point left, const Point& right);
	friend Point operator-(Point left, const Point& right);
	friend Point operator*(Point left, const Point& right);
	friend Point operator/(Point left, const Point& right);

	bool operator==(const Point& other);
	bool operator!=(const Point& other);

	Point& operator+=(const Point& other);
	Point& operator-=(const Point& other);
	Point& operator*=(const Point& other);
	Point& operator/=(const Point& other);

protected:
private:
	Point(const Point &c);
	Point& operator=(const Point &c);

public:
	float x, y, z;

};

#endif //__POINT_H__