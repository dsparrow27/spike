#pragma once

#define _USE_MATH_DEFINES
#include "maths.h"
#include "mathsFunc.h"
#include "vec3.h"


struct Mat4
{
	union
	{
		float elements[4 * 4];
		Vec4 columns[4];
	};

	Mat4();
	Mat4(float diagonal);

	Vec4 getColumn(int index)
	{
		index *= 4;
		return Vec4(elements[index], elements[index+1], elements[index + 2], elements[index + 3]);
	}

	static Mat4 identity();

	Mat4& multiply(const Mat4& other);

	static Mat4 orthographic(float left, float right, float top, float bottom, float near, float far);
	static Mat4 perspective(float fov, float aspectRatio, float near, float far);
	static Mat4 translation(const Vec3& translation);
	static Mat4 rotation(float angle, const Vec3& axis);
	static Mat4 scale(const Vec3& scale);

	bool operator==(const Mat4& other);
	bool operator!=(const Mat4& other);

	Mat4& operator*=(const Mat4& other);

	Mat4& operator*(const Mat4& other);


};
