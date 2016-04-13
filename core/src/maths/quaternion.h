#pragma once
#include "mathsFunc.h"
#include "Vec3.h"


class Quaternion
{
public:
	float w;
	Vec3 vector;
public:
	Quaternion() {};
	Quaternion(const Vec3& xyz, float w);

public:
	Quaternion inverted() const;
	// spherical linear interpolation of a quaternion
	Quaternion slerp(const Quaternion& other, float t) const;
	void toAxisAngle(Vec3& axis, float& angle) const;
	//merges two quaternions together
	Quaternion operator*(const Quaternion& q) const;
	//The fraction of the rotation of the quaternion
	Quaternion operator^(float q) const;
	// rotates a vector by this quaternion
	Vec3 operator*(const Vec3& p) const;

};