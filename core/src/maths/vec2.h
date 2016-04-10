/*Vector2 class for manipulating 3d transform
*/
#pragma once

#include <iostream>

struct Vec2
{
	// define the x, y values
	float x, y, z;
	//standard constructor
	Vec2();
	// second constructor that accepts two floats
	Vec2(const float& x, const float& y);
	Vec2(const Vec2& vector);
	float length() const;
	float lengthSqrt() const;
	void normalize();
	Vec2 normalized() const;

	Vec2 operator+(const Vec2& other);
	Vec2 operator-(const Vec2& other);
	Vec2 operator-() const;
	Vec2 operator*(const Vec2& other);
	Vec2 operator*(float scalar);
	Vec2 operator/(const Vec2& other);
	Vec2 operator/(float other) const;
	// equality operators
	bool operator==(const Vec2& other);
	bool operator!=(const Vec2& other);
	// standard math operators
	Vec2& operator=(const Vec2& other);
	Vec2& operator+=(const Vec2& other);
	Vec2& operator-=(const Vec2& other);
	Vec2& operator*=(const Vec2& other);
	Vec2& operator/=(const Vec2& other);

	// str
	friend std::ostream& operator<<(std::ostream& stream, const Vec2& vector);

};
