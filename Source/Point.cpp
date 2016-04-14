#include "Point.h"

Point::Point(const float& x, const float& y, const float& z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Point::Point()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Point::~Point()
{
}

Point& Point::add(const Point& other)
{
	x += other.x;
	y += other.y;
	z += other.z;

	return *this;
}

Point& Point::subtract(const Point& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;

	return *this;
}

Point& Point::multiply(const Point& other)
{
	x *= other.x;
	y *= other.y;
	z *= other.z;

	return *this;
}

Point& Point::divide(const Point& other)
{
	x /= other.x;
	y /= other.y;
	z /= other.z;

	return *this;
}

Point operator+(Point left, const Point& right)
{
	return left.add(right);
}

Point operator-(Point left, const Point& right)
{
	return left.subtract(right);
}

Point operator*(Point left, const Point& right)
{
	return left.multiply(right);
}

Point operator/(Point left, const Point& right)
{
	return left.divide(right);
}

Point& Point::operator+=(const Point& other)
{
	return add(other);
}

Point& Point::operator-=(const Point& other)
{
	return subtract(other);
}

Point& Point::operator*=(const Point& other)
{
	return multiply(other);
}

Point& Point::operator/=(const Point& other)
{
	return divide(other);
}

bool Point::operator==(const Point& other)
{
	return x == other.x && y == other.y && z == other.z;
}

bool Point::operator!=(const Point& other)
{
	return !(*this == other);
}

//std::ostream& operator<<(std::ostream& stream, const Point& vector)
//{
	//stream << "Vec3f: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
	//return stream;
//}
