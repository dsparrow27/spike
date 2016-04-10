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
Vec3::Vec3(const Vec3& vector)
{
	this->x = vector.x;
	this->y = vector.y;
	this->z = vector.z;
}
float Vec3::length() const
{
	return sqrt(this->x * this->x + this->y* this->y + this->z * this->z);
}
float Vec3::lengthSqrt() const
{
	return (this->x * this->x + this->y* this->y + this->z * this->z);
}
Vec3 Vec3::normalized() const
{
	return *this / length();
}
void Vec3::normalize()
{
	*this = *this / length();
}
Vec3 Vec3::cross(const Vec3& other) const
{
	Vec3 c;
	c.x = y*other.z - z*other.y;
	c.y = z*other.x - x*other.z;
	c.z = x*other.y - y*other.x;
	return c;
}
float Vec3::dot(const Vec3& other) const
{
	return x * other.x + y * other.y + z * other.z;
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

Vec3 Vec3::operator+(const Vec3& other) const
{
	return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::operator-(const Vec3& other) const
{
	return Vec3(x - other.x, y - other.y, z - other.z);
}
Vec3 Vec3::operator-() const
{
	return Vec3(-x, -y, -z);
}
Vec3 Vec3::operator*(const Vec3& other) const
{
	return Vec3(x * other.x, y * other.y, z * other.z);
}
Vec3 Vec3::operator*(float scalar) const
{
	return Vec3(x*scalar, y*scalar, z*scalar);
}
Vec3 Vec3::operator/(const Vec3& other) const
{
	return Vec3(x/other.z, y/other.y, z/other.z);
}
Vec3 Vec3::operator/(float other) const
{
	return Vec3(x / other, y / other, z / other);
}
Vec3& Vec3::operator+=(const Vec3& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	return *this;
}

Vec3& Vec3::operator-=(const Vec3& other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	return *this;
}

Vec3& Vec3::operator*=(const Vec3& other)
{
	this->x *= other.x;
	this->y *= other.y;
	this->z *= other.z;
	return *this;
}

Vec3& Vec3::operator/=(const Vec3& other)
{
	this->x /= other.x;
	this->y /= other.y;
	this->z /= other.z;
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const Vec3& vector)
{
	//create a string version of vector
	stream << "Vec3 ::(" << vector.x << "," << vector.y << "," << vector.z << ")";
	return stream;
}
