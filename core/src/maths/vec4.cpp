#include "vec4.h"

Vec4::Vec4(const float& x, const float& y, const float& z, const float& w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

bool Vec4::operator==(const Vec4& other)
{
	return this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w;
}

bool Vec4::operator!=(const Vec4& other)
{
	return !(*this == other);
}

Vec4& Vec4::operator=(const Vec4& other)
{
	if (*this != other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
		this->w = other.w;

		return *this;
	}
	return *this;
}

Vec4& Vec4::operator+(const Vec4& other)
{
	return add(other);
}

Vec4& Vec4::operator-(const Vec4& other)
{
	return subtract(other);
}

Vec4& Vec4::operator*(const Vec4& other)
{
	return multiply(other);
}
Vec4& Vec4::operator*(float scalar)
{
	scalar * this->x;
	scalar * this->y;
	scalar * this->z;
	scalar * this->w;
	return *this;
}
Vec4& Vec4::operator/(const Vec4& other)
{
	return divide(other);
}

Vec4& Vec4::operator+=(const Vec4& other)
{
	return add(other);
}

Vec4& Vec4::operator-=(const Vec4& other)
{
	return subtract(other);
}

Vec4& Vec4::operator*=(const Vec4& other)
{
	return multiply(other);
}

Vec4& Vec4::operator/=(const Vec4& other)
{
	return divide(other);
}

Vec4& Vec4::add(const Vec4& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	this->w += other.w;
	return *this;
}

Vec4& Vec4::subtract(const Vec4& other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	this->w -= other.w;
	return *this;
}

Vec4& Vec4::multiply(const Vec4& other)
{
	this->x *= other.x;
	this->y *= other.y;
	this->z *= other.z;
	this->w *= other.w;
	return *this;
}

Vec4& Vec4::divide(const Vec4& other)
{
	this->x /= other.x;
	this->y /= other.y;
	this->z /= other.z;
	this->w /= other.w;
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const Vec4& vector)
{
	//create a string version of vector
	stream << "Vec4 ::(" <<","<< vector.x << "," << vector.y << "," << vector.z << "," << vector.w <<")";
	return stream;
}
