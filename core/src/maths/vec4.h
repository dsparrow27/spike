/*Vector4 class for manipulating 2d transform
*/
#pragma once

#include <iostream>

struct Vec4
{
	// define the x, y values
	float x, y, z, w;
	//standard constructor
	Vec4() = default;
	// second constructor that accepts two floats
	Vec4(const float& x, const float& y, const float& z, const float& w);

	Vec4& add(const Vec4& other);
	Vec4& subtract(const Vec4& other);
	Vec4& multiply(const Vec4& other);
	Vec4& divide(const Vec4& other);
	// equality operators
	bool operator==(const Vec4& other);
	bool operator!=(const Vec4& other);

	Vec4& operator+(const Vec4& other);
	Vec4& operator-(const Vec4& other);
	Vec4& operator*(const Vec4& other);
	Vec4& operator*(float scalar);
	Vec4& operator/(const Vec4& other);
	Vec4& operator=(const Vec4& other);

	// standard math operators
	Vec4& operator+=(const Vec4& other);
	Vec4& operator-=(const Vec4& other);
	Vec4& operator*=(const Vec4& other);
	Vec4& operator/=(const Vec4& other);

	// str
	friend std::ostream& operator<<(std::ostream& stream, const Vec4 vector);
};
