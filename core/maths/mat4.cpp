#include "mat4.h"

Mat4::Mat4()
{
	for (int i = 0; i < 4 * 4; i++)
		elements[i] = 0.0f;
}
Mat4::Mat4(float diagonal)
{
	for (int i = 0; i < 4 * 4; i++)
	{
		elements[i] = 0.0f;
	}
	elements[0 + 0 * 4] = diagonal;
	elements[1 + 1 * 4] = diagonal;
	elements[2 + 2 * 4] = diagonal;
	elements[3 + 3 * 4] = diagonal;
}
Mat4 Mat4::identity()
{
	return Mat4(1.0f);
}

bool Mat4::operator==(const Mat4& other)
{
	return this->elements == other.elements;
}

bool Mat4::operator!=(const Mat4& other)
{
	return this->elements != other.elements;
}

Mat4& Mat4::operator*=(const Mat4& other)
{
	return multiply(other);
}

Mat4& Mat4::operator*(const Mat4& other)
{
	return this->multiply(other);
}

Mat4& Mat4::multiply(const Mat4& other)
{
	//column
	for (int y = 0; y < 4; y++)
	{
		//row
		for (int x = 0; x < 4; x++)
		{
			float sum = 0.0f;
			for (int e = 0; e < 4; e++)
			{
				sum += elements[x + e * 4] * other.elements[e + y * 4];
			}
			elements[x + y * 4] = sum;
		}
	}
	return *this;
}

Mat4 Mat4::orthographic(float left, float right, float top, float bottom, float near, float far)
{
	Mat4 result(1.0f);
	//diagonal
	result.elements[0 + 0 * 4] = 2.0f / (right - left);
	result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
	result.elements[2 + 2 * 4] = 2.0f / (far - near);

	result.elements[0 + 3 * 4] = ((left + right) / (left - right));
	result.elements[1 + 3 * 4] = ((bottom + top) / (bottom - top));
	result.elements[2 + 3 * 4] = ((far + near) / (far - near));

	return result;

}

Mat4 Mat4::perspective(float fov, float aspectRatio, float near, float far)
{
	Mat4 result(1.0f);
	float q = 1.0f / tan(toRadians(0.5f * fov));
	float a = q / aspectRatio;
	result.elements[0 + 0 * 4] = a;
	result.elements[1 + 1 * 4] = q;
	result.elements[2 + 2 * 4] = ((far + near) / (near - far));
	result.elements[2 + 3 * 4] = ((2.0f * near * far) / (near - far));
	result.elements[3 + 2 * 4] = 1.0f;
	result.elements[3 + 3 * 4] = 0.0f;

	return result;


	return result;
}

Mat4 Mat4::translation(const Vec3& translation)
{
	Mat4 result(1.0f);
	result.elements[0 + 3 * 4] = translation.x;
	result.elements[1 + 3 * 4] = translation.y;
	result.elements[2 + 3 * 4] = translation.z;
	return result;
}

Mat4 Mat4::rotation(float angle, const Vec3& axis)
{
	Mat4 result(1.0f);
	float r = toRadians(angle);
	float c = cos(r);
	float s = sin(r);
	float omc = 1.0f - c;

	//row 1 
	result.elements[0 + 0 * 4] = axis.x * omc + c;
	result.elements[0 + 1 * 4] = (axis.x * axis.y) * omc - (axis.z * s);
	result.elements[0 + 2 * 4] = (axis.x * axis.z) * omc + (axis.y * s);
	//row 2
	result.elements[1 + 0 * 4] = (axis.x * axis.y) * omc + (axis.z * s);
	result.elements[1 + 1 * 4] = axis.y * omc + c;
	result.elements[1 + 2 * 4] = (axis.y * axis.z) * omc - (axis.x * s);
	//row 3
	result.elements[2 + 0 * 4] = (axis.x * axis.x) * omc - (axis.y * s);
	result.elements[2 + 1 * 4] = (axis.y * axis.z) * omc + (axis.x * s);
	result.elements[2 + 2 * 4] = axis.z * omc + c;

	return result;

}

Mat4 Mat4::scale(const Vec3& scale)
{
	Mat4 result(1.0f);
	result.elements[0 + 0 * 4] = scale.x;
	result.elements[1 + 1 * 4] = scale.y;
	result.elements[2 + 2 * 4] = scale.z;
	return result;
}
