#include "vec3.h"

Vec3::Vec3()
{
	//default constructor
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}
Vec3::Vec3(const float& x, const float& y, const float& z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
float Vec3::length()
{
	return sqrt(this->x * this->x + this->y* this->y + this->z * this->z);
}
Vec3& Vec3::normalize()
{
	float vlength = length();
	this->x /= vlength;
	this->y /= vlength;
	this->z /= vlength;
	return *this;
}
bool Vec3::operator==(const Vec3& other)
{
	return this->x == other.x && this->y == other.y && this->z == other.z;
}

bool Vec3::operator!=(const Vec3& other)
{
	return !(*this == other);
}

Vec3& Vec3::operator=(const Vec3& other)
{
	if (*this != other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;

		return *this;
	}
	return *this;
}

Vec3& Vec3::operator+(const Vec3& other)
{
	return add(other);
}

Vec3& Vec3::operator-(const Vec3& other)
{
	return subtract(other);
}

Vec3& Vec3::operator*(const Vec3& other)
{
	return multiply(other);
}

Vec3& Vec3::operator/(const Vec3& other)
{
	return divide(other);
}

Vec3& Vec3::operator+=(const Vec3& other)
{
	return add(other);
}

Vec3& Vec3::operator-=(const Vec3& other)
{
	return subtract(other);
}

Vec3& Vec3::operator*=(const Vec3& other)
{
	return multiply(other);
}

Vec3& Vec3::operator/=(const Vec3& other)
{
	return divide(other);
}

Vec3& Vec3::add(const Vec3& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	return *this;
}

Vec3& Vec3::subtract(const Vec3& other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	return *this;
}

Vec3& Vec3::multiply(const Vec3& other)
{
	this->x *= other.x;
	this->y *= other.y;
	this->z *= other.z;
	return *this;
}

Vec3& Vec3::divide(const Vec3& other)
{
	this->x /= other.x;
	this->y /= other.y;
	this->z /= other.z;
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const Vec3& vector)
{
	//create a string version of vector
	stream << "Vec3 ::(" << "," << vector.x << "," << vector.y << "," << vector.z << ")";
	return stream;
}
