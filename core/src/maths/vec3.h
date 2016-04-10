/*Vector3 class for manipulating 3d transform
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
	Vec3(const Vec3& vector);
	float length() const ;
	float lengthSqrt() const;
	void normalize();
	Vec3 normalized() const;
	Vec3 cross(const Vec3& other) const;
	float dot(const Vec3& other) const;
	
	Vec3 operator+(const Vec3& other) const;
	Vec3 operator-(const Vec3& other) const;
	Vec3 operator-() const;
	Vec3 operator*(const Vec3& other) const;
	Vec3 operator*(float scalar) const;
	Vec3 operator/(const Vec3& other) const;
	Vec3 operator/(float other) const;
	// equality operators
	bool operator==(const Vec3& other);
	bool operator!=(const Vec3& other);
	// standard math operators
	Vec3& operator=(const Vec3& other);
	Vec3& operator+=(const Vec3& other);
	Vec3& operator-=(const Vec3& other);
	Vec3& operator*=(const Vec3& other);
	Vec3& operator/=(const Vec3& other);
	
	// str
	friend std::ostream& operator<<(std::ostream& stream, const Vec3& vector);

};
inline const Vec3 operator*(float s, const Vec3& v)
{
	return Vec3(s*v.x, s*v.y, s*v.z);
}
inline const Vec3 operator/(float s, const Vec3& v)
{
	return Vec3(s/v.x, s/v.y, s/v.z);
}