#pragma once
#define _USE_MATH_DEFINES

#include <math.h>
#include "vec3.h"
#include "vec4.h"

class Quaternion
{
public:
	float x, y, z, w;
	Quaternion();
	Quaternion(const Quaternion& quaternion);
	Quaternion(float x, float y, float z, float w);
	Quaternion(Vec4 xyzw);
	Quaternion identity();
	// The magnitude or length of a quaternion
	float length();
	float dot(const Quaternion& other);
	// normalizes the quaternion
	void normalize();
	// returns the conjugate of the quaternion aka.inverse
	Quaternion Conjugate() const;
	//returns the euler angles from the quaternion
	Vec3 toEuler();
	// returns a quaternion from euler angles
	static Quaternion fromEuler(const Vec3& angles);
	float roll();
	float pitch();
	float yaw();

	bool const operator==(const Quaternion& other);
	bool const operator!=(const Quaternion& other);

	Quaternion& operator=(const Quaternion& other);
	Quaternion& operator*=(const Quaternion& other);
	Quaternion& operator*=(const float other);
	Quaternion& operator/=(const Quaternion& other);
	Quaternion& operator+=(const Quaternion& other);
	Quaternion& operator-=(const Quaternion& other);

	Quaternion& operator*(const float other);
	Quaternion& operator*(const Quaternion& other);
	Quaternion& operator/(const Quaternion& other);
	Quaternion& operator-(const Quaternion& other);
	Quaternion& operator+(const Quaternion& other);
	Quaternion& operator-();

};