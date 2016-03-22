/*Vector3 class for manipulating 2d transform
*/
#pragma once

#include <iostream>

struct Vec3
{
	// define the x, y values
	float x, y, z;
	//standard constructor
	Vec3();
	// second constructor that accepts two floats
	Vec3(const float& x, const float& y, const float& z);
	float Vec3::length();
	Vec3& Vec3::normalize();

	Vec3& add(const Vec3& other);
	Vec3& subtract(const Vec3& other);
	Vec3& multiply(const Vec3& other);
	Vec3& divide(const Vec3& other);
	// equality operators
	bool operator==(const Vec3& other);
	bool operator!=(const Vec3& other);

	Vec3& operator+(const Vec3& other);
	Vec3& operator-(const Vec3& other);
	Vec3& operator*(const Vec3& other);
	Vec3& operator*(float scalar);
	Vec3& operator/(const Vec3& other);
	Vec3& operator=(const Vec3& other);

	// standard math operators
	Vec3& operator+=(const Vec3& other);
	Vec3& operator-=(const Vec3& other);
	Vec3& operator*=(const Vec3& other);
	Vec3& operator/=(const Vec3& other);

	// str
	friend std::ostream& operator<<(std::ostream& stream, const Vec3& vector);

};
