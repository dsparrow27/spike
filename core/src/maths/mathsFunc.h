#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
/*This header file contains common math functions 
all functions are inline functions
*/

inline float toRadians(float degrees)
{
	//Converts degrees to radians
	return degrees * float(M_PI / 180);
}

inline float toDegrees(float radians)
{
	//converts radians to degreess
	return (float)(radians * (180.0f / M_PI));
}

inline double rSqrt(float value)
{
	return 1.0f / ::sqrt(value);
}

inline float min(float value, float minium)
{
	return (value < minium) ? minium : value;
}

inline float max(float value, float maxium)
{
	return (value < maxium) ? maxium : value;
}

inline float clamp(float value, float min, float max)
{
	return (value > min) ? (value < max) ? value : max : min;
}
