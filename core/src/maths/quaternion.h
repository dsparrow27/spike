#pragma once
#define _USE_MATH_DEFINES

#include <math.h>
#include "vec3.h"

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
	Quaternion slerp(const Quaternion& r, float t) const;
	Quaternion operator*(const Quaternion& q) const;
	Quaternion operator^(const Quaternion& q) const;
	Quaternion operator*(const Vec3& p) const;
	void toAxisAngle(Vec3& axis, float& angle) const;

};