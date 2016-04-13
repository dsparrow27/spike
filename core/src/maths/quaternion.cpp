#include "quaternion.h"

Quaternion::Quaternion(const Vec3& xyz, float w)
{
	float a = toRadians(w);
	w = cos(a / 2);
	vector = xyz * sin(a);
}
Quaternion Quaternion::inverted() const
{
	Quaternion q;
	q.w = w;
	q.vector = -vector;
	return q;
}
Quaternion Quaternion::slerp(const Quaternion& other, float t) const
{
	const Quaternion& q = *this;
	Quaternion r = other;
	return ((r * q.inverted()) ^ t) * q;
}
void Quaternion::toAxisAngle(Vec3& axis, float& angle) const
{
	// convert the quaternion to axis/angle
	if (vector.length() < 0.0001f)
	{
		axis = Vec3(1, 0, 0);
	}
	else
	{
		axis = vector.normalized();
	}
	angle = acos(w) * 2;
	angle *= 360 / ((float)M_PI * 2);
}
Quaternion Quaternion::operator*(const Quaternion& q) const
{
	//combines the two rotations
	Quaternion newQuat;
	newQuat.w = w * q.w - vector.dot(q.vector);
	newQuat.vector = vector * newQuat.w + q.vector * w + vector.cross(q.vector);
	return newQuat;
}
Vec3 Quaternion::operator*(const Vec3& p) const
{
	Vec3 vcV = vector.cross(p);
	return p + vcV * (2 * w) + vector.cross(vcV) * 2;
}

Quaternion Quaternion::operator^(float q) const
{
	float axis;
	Vec3 angle;

	toAxisAngle(angle, axis);

	float at = axis*q;
	return Quaternion(angle, at);
}
