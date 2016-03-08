/*Vector2 class for manipulating 2d transform
*/
#pragma once

#include <iostream>

struct Vec2
{
	// define the x, y values
	float x, y;
	//standard constructor
	Vec2();
	// second constructor that accepts two floats
	Vec2(const float& x, const float& y);

	Vec2& add(const Vec2& other);
	Vec2& subtract(const Vec2& other);
	Vec2& multiply(const Vec2& other);
	Vec2& divide(const Vec2& other);
	// equality operators
	bool operator==(const Vec2& other);
	bool operator!=(const Vec2& other);

	Vec2& operator+(const Vec2& other);
	Vec2& operator-(const Vec2& other);
	Vec2& operator*(const Vec2& other);
	Vec2& operator/(const Vec2& other);
	Vec2& operator=(const Vec2& other);

	// standard math operators
	Vec2& operator+=(const Vec2& other);
	Vec2& operator-=(const Vec2& other);
	Vec2& operator*=(const Vec2& other);
	Vec2& operator/=(const Vec2& other);

	// str
	friend std::ostream& operator<<(std::ostream& stream, const Vec2& vector);
};
