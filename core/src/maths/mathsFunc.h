#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include "Vec3.h"
/*This header file contains common math functions
*/

float toRadians(float degrees)
{
	//Converts degrees to radians
	return degrees * float(M_PI / 180);
}

float toDegrees(float radians)
{
	//converts radians to degreess
	return (float)(radians * (180.0f / M_PI));
}

double rSqrt(float value)
{
	return 1.0f / sqrt(value);
}

float min(float value, float minium)
{
	return (value < minium) ? minium : value;
}

float max(float value, float maxium)
{
	return (value < maxium) ? maxium : value;
}

float clamp(float value, float min, float max)
{
	return (value > min) ? (value < max) ? value : max : min;
}
const Vec3 rotateVectorAroundAxisAngle(const Vec3& n, float angle, const Vec3& v)
{
	float a = toRadians(angle);
	return v*cos(a) + (v.dot(n)*n*(1 - cos(a))) + (n.cross(v)*sin(a));
}