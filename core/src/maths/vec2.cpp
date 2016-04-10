#include "Vec2.h"

Vec2::Vec2()
{
	//default constructor
	x = 0.0f;
	y = 0.0f;
}
Vec2::Vec2(const float& x, const float& y)
{
	this->x = x;
	this->y = y;
}
Vec2::Vec2(const Vec2& vector)
{
	this->x = vector.x;
	this->y = vector.y;
}
float Vec2::length() const
{
	return sqrt(this->x * this->x + this->y* this->y);
}
float Vec2::lengthSqrt() const
{
	return (this->x * this->x + this->y* this->y);
}
Vec2 Vec2::normalized() const
{
	return *this / length();
}
void Vec2::normalize()
{
	*this = *this / length();
}

bool Vec2::operator==(const Vec2& other)
{
	return this->x == other.x && this->y == other.y;
}

bool Vec2::operator!=(const Vec2& other)
{
	return !(*this == other);
}

Vec2& Vec2::operator=(const Vec2& other)
{
	if (*this != other)
	{
		this->x = other.x;
		this->y = other.y;

		return *this;
	}
	return *this;
}

Vec2 Vec2::operator+(const Vec2& other)
{
	return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::operator-(const Vec2& other)
{
	return Vec2(x - other.x, y - other.y);
}
Vec2 Vec2::operator-() const
{
	return Vec2(-x, -y);
}
Vec2 Vec2::operator*(const Vec2& other)
{
	return Vec2(x * other.x, y * other.y);
}
Vec2 Vec2::operator*(float scalar)
{
	return Vec2(x*scalar, y*scalar);
}
Vec2 Vec2::operator/(const Vec2& other)
{
	return Vec2(x / other.x, y / other.y);
}
Vec2 Vec2::operator/(float other) const
{
	return Vec2(x / other, y / other);
}
Vec2& Vec2::operator+=(const Vec2& other)
{
	this->x += other.x;
	this->y += other.y;
	return *this;
}

Vec2& Vec2::operator-=(const Vec2& other)
{
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

Vec2& Vec2::operator*=(const Vec2& other)
{
	this->x *= other.x;
	this->y *= other.y;
	return *this;
}

Vec2& Vec2::operator/=(const Vec2& other)
{
	this->x /= other.x;
	this->y /= other.y;
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const Vec2& vector)
{
	//create a string version of vector
	stream << "Vec2 ::(" << vector.x << "," << vector.y << ")";
	return stream;
}
