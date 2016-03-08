#include "vec2.h"


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

Vec2& Vec2::operator+(const Vec2& other)
{
	return add(other);
}

Vec2& Vec2::operator-(const Vec2& other)
{
	return subtract(other);
}

Vec2& Vec2::operator*(const Vec2& other)
{
	return multiply(other);
}

Vec2& Vec2::operator/(const Vec2& other)
{
	return divide(other);
}

Vec2& Vec2::operator+=(const Vec2& other)
{
	return add(other);
}

Vec2& Vec2::operator-=(const Vec2& other)
{
	return subtract(other);
}

Vec2& Vec2::operator*=(const Vec2& other)
{
	return multiply(other);
}

Vec2& Vec2::operator/=(const Vec2& other)
{
	return divide(other);
}

Vec2& Vec2::add(const Vec2& other)
{
	this->x += other.x;
	this->y += other.y;
	return *this;
}

Vec2& Vec2::subtract(const Vec2& other)
{
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

Vec2& Vec2::multiply(const Vec2& other)
{
	this->x *= other.x;
	this->y *= other.y;
	return *this;
}

Vec2& Vec2::divide(const Vec2& other)
{
	this->x /= other.x;
	this->y /= other.y;
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const Vec2& vector)
{
	//create a string version of vector
	stream << "Vec2 ::(" << vector.x << vector.y << ")";
	return stream;
}
