#include "mat4.h"

//constructors

Mat4::Mat4(const Mat4& m)
{
	memcpy(&elements[0 + 0 * 4], &m.elements[0 + 0 * 4], sizeof(float) * 16);
}

Mat4::Mat4(const Vec3& forward, const Vec3& vecUp, const Vec3& vecRight, const Vec3& vecPosition = Vec3(0, 0, 0))
{
	setForwardVector(forward);
	setUpVector(vecUp);
	setRightVector(forward);
	setTranslation(forward);
}
//methods
Mat4 Mat4::identity()
{
	return Mat4(1.0f);
}
Mat4& Mat4::asIdentity()
{
	for (int i = 0; i < 4 * 4; i++)
	{
		elements[i] = 0.0f;
	}
	elements[0 + 0 * 4] = 1.0;
	elements[1 + 1 * 4] = 1.0;
	elements[2 + 2 * 4] = 1.0;
	elements[3 + 3 * 4] = 1.0;
	return *this;
}
bool Mat4::isIdentity() const
{
	if (!(elements[0 + 0 * 4] == 1 && elements[1 + 1 * 4] == 1 && elements[2 + 2 * 4] == 1 && elements[3 + 3 * 4] == 1))
	{
		return false;
	}
	if (!(elements[0 + 1 * 4] == 0) && elements[0 + 2 * 4] == 0 && elements[0 + 3 * 4] == 0)
	{
		return false;
	}
	if (!(elements[1 + 0 * 4] == 0) && elements[1 + 2 * 4] == 0 && elements[1 + 3 * 4] == 0)
	{
		return false;
	}
	if (!(elements[2 + 0 * 4] == 0) && elements[2 + 1 * 4] == 0 && elements[2 + 3 * 4] == 0)
	{
		return false;
	}
	if (!(elements[3 + 0 * 4] == 0) && elements[3 + 1 * 4] == 0 && elements[3 + 2 * 4] == 0)
	{
		return false;
	}
}
Mat4 Mat4::operator=(const Mat4& other)
{
	if (*this != other)
	{
		for (int i = 0; i < 4*4; i++)
		{
			this->elements[i] = other.elements[i];
		}
	}
	return *this;
}
bool Mat4::operator==(const Mat4& other)
{
	//column
	for (int col = 0; col < 4; col++)
	{
		//row
		for (int row = 0; row < 4; row++)
		{
			if (elements[col + row * 4] != other.elements[col + row * 4])
			{
				return false;
			}
		}
	}
	return true;
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
Vec3 Mat4::operator*(const Vec3& other)
{
	return this->multiply(other);
}

Mat4& Mat4::multiply(const Mat4& other)
{
	float data[16];
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
			data[x + y * 4] = sum;
		}
	}
	memcpy(elements, data, 4 * 4 * sizeof(float));
	return *this;
}
Vec3 Mat4::multiply(const Vec3& other)
{
	return Vec3(
		columns[0].x * other.x + columns[1].x * other.y + columns[2].x * other.z + columns[3].x,
		columns[0].y * other.x + columns[1].y * other.y + columns[2].y * other.z + columns[3].y, 
		columns[0].z * other.x + columns[1].z * other.y + columns[2].z * other.z + columns[3].z);
}
Mat4 Mat4::projectOrthographic(float left, float right, float bottom, float top, float near, float far)
{
	Mat4 result(1.0f);
	//diagonal
	result.elements[0 + 0 * 4] = 2.0f / (right - left);
	result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
	result.elements[2 + 2 * 4] = -2.0f / (far - near);

	result.elements[0 + 3 * 4] = -((right + left) / (right - left));
	result.elements[1 + 3 * 4] = -((top + bottom) / (top - bottom));
	result.elements[2 + 3 * 4] = -((far + near) / (far - near));

	return result;

}

Mat4 Mat4::projectPerspective(float fov, float aspectRatio, float near, float far)
{
	Mat4 result(1.0f);
	float q = 1.0f / tan(toRadians(0.5f * fov));
	float a = q / aspectRatio;
	result.elements[0 + 0 * 4] = a;
	result.elements[1 + 1 * 4] = q;
	result.elements[2 + 2 * 4] = ((far + near) / (near - far));
	result.elements[2 + 3 * 4] = -((2.0f * near * far) / (near - far));
	result.elements[3 + 2 * 4] = 1.0f;
	result.elements[3 + 3 * 4] = 0.0f;

	return result;
}
Mat4 Mat4::projectFrustum(float fov, float aspectRatio, float near, float far)
{
	
}
Mat4 Mat4::projectFrustum(float left, float right, float bottom, float top, float near, float far)
{
	Mat4 m(1.0f);
	float fxd = right - left;
	float fyd = top - bottom;
	float fzd = far - near;
	m.elements[0 + 0 * 4] = (2 * near) / fxd;
	m.elements[1 + 1 * 4] = (2 * near) / fyd;

	m.elements[0 + 0 * 4] = (right * left) / fxd;
	m.elements[2 + 1 * 4] = (top * bottom) / fyd;
	m.elements[2 + 2 * 4] = (far * near) / fzd;
	m.elements[2 + 3 * 4] = -1;

	m.elements[3 + 2 * 4] = -(2 * far * near) / fzd;
	m.elements[3 + 3 * 4] = 0;
	return m;
}
Mat4 Mat4::constructCameraView(const Vec3& position, const Vec3& direction, const Vec3& upVector)
{
	Vec3 camDir = direction;
	Vec3 camRight = camDir.cross(upVector).normalize();
	Vec3 camUp = camRight.cross(direction).normalize();
	return Mat4(camRight, camUp, -camDir, position);
}
//getters
Vec4 Mat4::getColumn(int index) const
{
	index *= 4;
	return Vec4(elements[index], elements[index + 1], elements[index + 2], elements[index + 3]);
}
//setters
void setColumn(int i) const;
void setColumn(int i, const Vec3& column) const;
void setColumn(int i, const Vec4& column) const;
void Mat4::setTranslation(const Vec3& translation)
{
	elements[0 + 3 * 4] = translation.x;
	elements[1 + 3 * 4] = translation.y;
	elements[2 + 3 * 4] = translation.z;
}

void Mat4::setRotation(float angle, const Vec3& axis)
{
	float r = toRadians(angle);
	float c = cos(r);
	float s = sin(r);
	float omc = 1.0f - c;

	//row 1 
	elements[0 + 0 * 4] = axis.x * omc + c;
	elements[0 + 1 * 4] = (axis.y * axis.x) * omc + (axis.z * s);
	elements[0 + 2 * 4] = (axis.x * axis.z) * omc - (axis.y * s);
	//row 2
	elements[1 + 0 * 4] = (axis.x * axis.y) * omc - (axis.z * s);
	elements[1 + 1 * 4] = axis.y * omc + c;
	elements[1 + 2 * 4] = (axis.y * axis.z) * omc + (axis.x * s);
	//row 3
	elements[2 + 0 * 4] = (axis.x * axis.z) * omc + (axis.y * s);
	elements[2 + 1 * 4] = (axis.y * axis.z) * omc - (axis.x * s);
	elements[2 + 2 * 4] = axis.z * omc + c;


}

void Mat4::setScale(const Vec3& scale)
{
	elements[0 + 0 * 4] = scale.x;
	elements[1 + 1 * 4] = scale.y;
	elements[2 + 2 * 4] = scale.z;
}
void Mat4::setReflection(const Vec3& planeNormal)
{
	fabs(planeNormal.lengthSqrt() - 1) < 0.000001f;
	elements[0 + 0 * 4] = 1 - 2 * planeNormal.x*planeNormal.x;
	elements[1 + 1 * 4] = 1 - 2 * planeNormal.y*planeNormal.y;
	elements[2 + 2 * 4] = 1 - 2 * planeNormal.z*planeNormal.z;
	elements[1 + 0 * 4] = elements[0 + 1 * 4] = -2 * planeNormal.x*planeNormal.y;
	elements[2 + 0 * 4] = elements[0 + 2 * 4] = -2 * planeNormal.x*planeNormal.z;
	elements[1 + 2 * 4] = elements[2 + 1 * 4] = -2 * planeNormal.y*planeNormal.z;

}

Mat4& Mat4::inverse()
{
	//
	double temp[16];
	temp[0] = elements[5] * elements[10] * elements[15] -
			elements[5] * elements[11] * elements[14] -
			elements[9] * elements[6] * elements[15] +
			elements[9] * elements[7] * elements[14] +
			elements[13] * elements[6] * elements[11] -
			elements[13] * elements[7] * elements[10];

	temp[4] = -elements[4] * elements[10] * elements[15] +
			elements[4] * elements[11] * elements[14] +
			elements[8] * elements[6] * elements[15] -
			elements[8] * elements[7] * elements[14] -
			elements[12] * elements[6] * elements[11] +
			elements[12] * elements[7] * elements[10];

	temp[8] = elements[4] * elements[9] * elements[15] -
			elements[4] * elements[11] * elements[13] -
			elements[8] * elements[5] * elements[15] +
			elements[8] * elements[7] * elements[13] +
			elements[12] * elements[5] * elements[11] -
			elements[12] * elements[7] * elements[9];

	temp[12] = -elements[4] * elements[9] * elements[14] +
			elements[4] * elements[10] * elements[13] +
			elements[8] * elements[5] * elements[14] -
			elements[8] * elements[6] * elements[13] -
			elements[12] * elements[5] * elements[10] +
			elements[12] * elements[6] * elements[9];

	temp[1] = -elements[1] * elements[10] * elements[15] +
			elements[1] * elements[11] * elements[14] +
			elements[9] * elements[2] * elements[15] -
			elements[9] * elements[3] * elements[14] -
			elements[13] * elements[2] * elements[11] +
			elements[13] * elements[3] * elements[10];

	temp[5] = elements[0] * elements[10] * elements[15] -
			elements[0] * elements[11] * elements[14] -
			elements[8] * elements[2] * elements[15] +
			elements[8] * elements[3] * elements[14] +
			elements[12] * elements[2] * elements[11] -
			elements[12] * elements[3] * elements[10];

	temp[9] = -elements[0] * elements[9] * elements[15] +
			elements[0] * elements[11] * elements[13] +
			elements[8] * elements[1] * elements[15] -
			elements[8] * elements[3] * elements[13] -
			elements[12] * elements[1] * elements[11] +
			elements[12] * elements[3] * elements[9];

	temp[13] = elements[0] * elements[9] * elements[14] -
			elements[0] * elements[10] * elements[13] -
			elements[8] * elements[1] * elements[14] +
			elements[8] * elements[2] * elements[13] +
			elements[12] * elements[1] * elements[10] -
			elements[12] * elements[2] * elements[9];

	temp[2] = elements[1] * elements[6] * elements[15] -
			elements[1] * elements[7] * elements[14] -
			elements[5] * elements[2] * elements[15] +
			elements[5] * elements[3] * elements[14] +
			elements[13] * elements[2] * elements[7] -
			elements[13] * elements[3] * elements[6];

	temp[6] = -elements[0] * elements[6] * elements[15] +
			elements[0] * elements[7] * elements[14] +
			elements[4] * elements[2] * elements[15] -
			elements[4] * elements[3] * elements[14] -
			elements[12] * elements[2] * elements[7] +
			elements[12] * elements[3] * elements[6];

	temp[10] = elements[0] * elements[5] * elements[15] -
			elements[0] * elements[7] * elements[13] -
			elements[4] * elements[1] * elements[15] +
			elements[4] * elements[3] * elements[13] +
			elements[12] * elements[1] * elements[7] -
			elements[12] * elements[3] * elements[5];

	temp[14] = -elements[0] * elements[5] * elements[14] +
			elements[0] * elements[6] * elements[13] +
			elements[4] * elements[1] * elements[14] -
			elements[4] * elements[2] * elements[13] -
			elements[12] * elements[1] * elements[6] +
			elements[12] * elements[2] * elements[5];

	temp[3] = -elements[1] * elements[6] * elements[11] +
			elements[1] * elements[7] * elements[10] +
			elements[5] * elements[2] * elements[11] -
			elements[5] * elements[3] * elements[10] -
			elements[9] * elements[2] * elements[7] +
			elements[9] * elements[3] * elements[6];

	temp[7] = elements[0] * elements[6] * elements[11] -
			elements[0] * elements[7] * elements[10] -
			elements[4] * elements[2] * elements[11] +
			elements[4] * elements[3] * elements[10] +
			elements[8] * elements[2] * elements[7] -
			elements[8] * elements[3] * elements[6];

	temp[11] = -elements[0] * elements[5] * elements[11] +
			elements[0] * elements[7] * elements[9] +
			elements[4] * elements[1] * elements[11] -
			elements[4] * elements[3] * elements[9] -
			elements[8] * elements[1] * elements[7] +
			elements[8] * elements[3] * elements[5];

	temp[15] = elements[0] * elements[5] * elements[10] -
			elements[0] * elements[6] * elements[9] -
			elements[4] * elements[1] * elements[10] +
			elements[4] * elements[2] * elements[9] +
			elements[8] * elements[1] * elements[6] -
			elements[8] * elements[2] * elements[5];

	double determin = elements[0] * temp[0] + elements[1] * temp[4] + elements[2] * temp[8] + elements[3] * temp[12];
	determin = 1.0 / determin;

	for (int i = 0; i < 16; i++)
	{
		elements[i] = temp[i] * determin;
	}
	return *this;
}
