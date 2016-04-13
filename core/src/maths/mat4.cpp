#include "mat4.h"
//constructors
Mat4::Mat4(float diagonal)
{
	memset(this, 0, sizeof(Mat4));

	elements[0][0] = elements[1][1] = elements[2][2] = elements[3][3] = diagonal;
}
Mat4::Mat4(float m00, float m01, float m02, float m03,
		   float m10, float m11, float m12, float m13,
	       float m20, float m21, float m22, float m23,
		   float m30, float m31, float m32, float m33)
{
	elements[0][0] = m00; elements[0][1] = m01; elements[0][2] = m02; elements[0][3] = m03;
	elements[1][0] = m10; elements[1][1] = m11; elements[1][2] = m12; elements[1][3] = m13;
	elements[2][0] = m20; elements[2][1] = m21; elements[2][2] = m22; elements[2][3] = m23;
	elements[3][0] = m30; elements[3][1] = m31; elements[3][2] = m32; elements[3][3] = m33;
}
Mat4::Mat4(const Mat4& m)
{
	memcpy(&elements[0][0], &m.elements[0][0], sizeof(float) * 16);
}
Mat4::Mat4(const Vec3& forward, const Vec3& vecUp, const Vec3& vecRight, const Vec3& vecPosition)
{
	setForwardVector(forward);
	setUpVector(vecUp);
	setRightVector(vecRight);
	setTranslation(vecPosition);
}
Mat4::Mat4(const Vec4& forward, const Vec4& vecUp, const Vec4& vecRight, const Vec4& vecPosition)
{
	setForwardVector(forward);
	setUpVector(vecUp);
	setRightVector(vecRight);
	setTranslation(vecPosition);
}
//methods
Mat4& Mat4::asIdentity()
{
	memset(this, 0, sizeof(Mat4));

	elements[0][0] = elements[1][1] = elements[2][2] = elements[3][3] = 1.0f;
	return *this;
}
bool Mat4::isIdentity() const
{
	if (!(elements[0][0] == 1 && elements[1][1] == 1 && elements[2][2] == 1 && elements[3][3] == 1))
	{
		return false;
	}
	if (!(elements[0][1] == 0) && elements[0][2] == 0 && elements[0][3] == 0)
	{
		return false;
	}
	if (!(elements[1][0] == 0) && elements[1][2] == 0 && elements[1][3] == 0)
	{
		return false;
	}
	if (!(elements[2][0] == 0) && elements[2][1] == 0 && elements[2][3] == 0)
	{
		return false;
	}
	if (!(elements[3][0] == 0) && elements[3][1] == 0 && elements[3][2] == 0)
	{
		return false;
	}
	return true;
}
Mat4 Mat4::inverse()
{
	Mat4 newMat;
	for (int i = 0; i < 3; i++)
		for (int j = 0; i < 3; i++)
		{
			newMat.elements[i][j] = elements[j][i];
		}
	newMat.setTranslation(-(newMat*getTranslation()));
	return newMat;
}

Mat4 Mat4::projectOrthographic(float left, float right, float top, float bottom, float near, float far)
{
	Mat4 m;
	m.asIdentity();

	float xd = right - left;
	float yd = top - bottom;
	float zd = far - near;

	m.elements[0][0] = 2.0f / xd;
	m.elements[1][1] = 2.0f / yd;
	m.elements[2][2] = -2.0f / zd;

	m.elements[3][0] = -(right + left) / xd;
	m.elements[3][0] = -(top + bottom) / yd;
	m.elements[3][0] = -(far + near) / zd;
	return m;
}
Mat4 Mat4::projectPerspective(float fov, float aspectRatio, float near, float far)
{
	float tanThetaOver = tan(toRadians(fov));
	Mat4 m;
	m.asIdentity();
	//xy scale
	m.elements[0][0] = 1 / tanThetaOver;
	m.elements[1][1] = aspectRatio / tanThetaOver;

	//z makes z-1 for the rear plane and +1 for the far plane
	m.elements[2][2] = (near + far) / (near - far);
	m.elements[3][2] = -((2 * near * far) / (near - far));
	// w=-1 so that [xyz-z], homogenous vector that becomes [-x/z -y/z -1] after division by w
	m.elements[2][3] = 1;
	//zero out
	m.elements[3][3] = 0;

	return m;
}
Mat4 Mat4::projectFrustum(float fov, float aspectRatio, float near, float far)
{
	float right = near * tan(toRadians(fov));
	float left = -right;

	float bottom = left / aspectRatio;
	float top = right / aspectRatio;
	return projectFrustum(left, right, bottom, top, near, far);
}
Mat4 Mat4::projectFrustum(float left, float right, float bottom, float top, float near, float far)
{
	Mat4 m;
	m.asIdentity();

	float xd = right - left;
	float yd = top - bottom;
	float zd = far - near;

	m.elements[0][0] = (2 * near) / xd;
	m.elements[1][1] = (2 * near) / yd;

	m.elements[2][0] = (right + left) / xd;
	m.elements[2][1] = (top + bottom) / yd;
	m.elements[2][2] = (far + near) / zd;
	m.elements[2][3] = -1;
	m.elements[3][2] = -(2 * far * near) / zd;
	m.elements[3][3] = 0;
	return m;
}
Mat4 Mat4::constructCameraView(const Vec3& position, const Vec3& direction, const Vec3& upVector)
{
	Vec3 vecRight = direction.cross(upVector).normalized();
	Vec3 vecCameraUp = vecRight.cross(direction);

	return Mat4(vecRight, vecCameraUp, -direction, position).inverse();
}
Mat4 Mat4::addTranslation(const Vec3 v)
{
	Mat4 m;
	m.setTranslation(v);
	*this *= m;
	return *this;
}
Mat4 Mat4::addScale(const Vec3 v)
{
	Mat4 m;
	m.setScale(v);
	*this *= m;
	return *this;
}
Mat4 Mat4::addReflection(const Vec3 v)
{
	Mat4 m;
	m.setReflection(v);
	*this = m; 
	return *this;
}
Vec3 Mat4::transformDirection(const Vec3 v) const
{
	Vec3 result;
	result.x = elements[0][0] * v.x + elements[1][0] * v.y + elements[2][0] * v.z;
	result.x = elements[0][1] * v.x + elements[1][1] * v.y + elements[2][1] * v.z;
	result.x = elements[0][2] * v.x + elements[1][2] * v.y + elements[2][2] * v.z;
	return result;
}
Mat4 Mat4::transposed() const
{
	Mat4 result;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result.elements[i][j] = elements[j][i];
		}
	}
	return result;
}
//getter
Vec4 Mat4::getColumn(int index) const
{
	return Vec4(elements[index][0], elements[index][1], elements[index][2], elements[index][3]);
}
Vec4 Mat4::getRow(int index) const
{
	return Vec4(elements[0][index], elements[1][index], elements[2][index], elements[3][index]);
}
Vec3 Mat4::getTranslation() const
{
	return Vec3(elements[3][0], elements[3][1], elements[3][2]);
}
Vec3 Mat4::getScale() const
{
	return Vec3(elements[0][0], elements[1][1], elements[2][2]);
}
void Mat4::getAsArray()
{
	int index = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mArray[index] = elements[i][j];
			index++;
		}
	}
}
//setters
void Mat4::setColumn(int i, const Vec3& column)
{
	elements[i][0] = column.x;
	elements[i][1] = column.y;
	elements[i][2] = column.z;
}
void Mat4::setColumn(int i, const Vec4& column)
{
	elements[i][0] = column.x;
	elements[i][1] = column.y;
	elements[i][2] = column.z;
	elements[i][3] = column.w;
}
void Mat4::setTranslation(const Vec3& translation)
{
	this->setColumn(3, translation);
}
void Mat4::setTranslation(const Vec4& translation)
{
	this->setColumn(3, translation);
}
void Mat4::setRotation(float angle, const Vec3& axis)
{
	float x = axis.x;
	float y = axis.y;
	float z = axis.z;

	float c = cos(toRadians(angle));
	float s = sin(toRadians(angle));
	float t = 1 - c;

	elements[0][0] = x*x*t + c;
	elements[1][0] = x*y*t - z*s;
	elements[2][0] = x*z*t + y*s;

	elements[0][1] = y*x*t + z*s;
	elements[1][1] = y*y*t + c;
	elements[2][1] = y*z*t - x*s;

	elements[0][2] = z*x*t - y*s;
	elements[1][2] = z*y*t + x*s;
	elements[2][2] = z*z*t + c;
}
void Mat4::setScale(const Vec3& scale)
{
	elements[0][0] = scale.x;
	elements[1][1] = scale.y;
	elements[2][2] = scale.y;
}
void Mat4::setForwardVector(const Vec3& forward)
{
	this->setColumn(0, forward);
}
void Mat4::setForwardVector(const Vec4& forward)
{
	this->setColumn(0, forward);
}
void Mat4::setUpVector(const Vec4& upVector)
{
	this->setColumn(1, upVector);
}
void Mat4::setUpVector(const Vec3& upVector)
{
	this->setColumn(1, upVector);
}
void Mat4::setRightVector(const Vec4& right)
{
	this->setColumn(2, right);
}
void Mat4::setRightVector(const Vec3& right)
{
	this->setColumn(2, right);
}
void Mat4::setReflection(const Vec3& planeNormal)
{
	elements[0][0] = 1 - 2 * planeNormal.x * planeNormal.x;
	elements[1][1] = 1 - 2 * planeNormal.y * planeNormal.y;
	elements[2][2] = 1 - 2 * planeNormal.z * planeNormal.z;
	elements[1][0] = elements[0][1] = -2 * planeNormal.x * planeNormal.y;
	elements[2][0] = elements[0][2] = -2 * planeNormal.x * planeNormal.z;
	elements[1][2] = elements[2][1] = -2 * planeNormal.y * planeNormal.z;
}
//operators
bool Mat4::operator==(const Mat4& other)
{
	float ep = 0.000001f;
	//column
	for (int col = 0; col < 4; col++)
	{
		//row
		for (int row = 0; row < 4; row++)
		{
			if (fabs(elements[col][row] - other.elements[col][row]) > ep)
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
Mat4& Mat4::operator=(const Mat4& other)
{
	memcpy(&elements[0][0], &other.elements[0][0], sizeof(float) * 16);
	return *this;
}
Mat4& Mat4::operator*=(const Mat4& other)
{
	*this = *this * other;
	return *this;
}
Mat4& Mat4::operator+=(const Vec3& other)
{
	elements[3][0] += other.x;
	elements[3][1] += other.x;
	elements[3][2] += other.x;
	return *this;
}
Mat4 Mat4::operator*(const Mat4& other) const
{
	Mat4 result;
	for (int c = 0; c < 4; c++)
	{
		for (int r = 0; r < 4; r++)
		{
			result.elements[c][r] = elements[0][r] * other.elements[c][0] + elements[1][r] * other.elements[c][1] + elements[2][r] * other.elements[c][2] + elements[3][r] * other.elements[c][3];
		}
	}
	return result;
}
Mat4 Mat4::operator*(float f) const
{
	Mat4 result;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result.elements[i][j] = elements[i][j] * f;
		}
	}
	return result;
}
Vec3 Mat4::operator*(const Vec3& other) const
{
	Vec3 result;
	result.x = elements[0][0] * other.x + elements[1][0] * other.y + elements[2][0] * other.z + elements[3][0];
	result.y = elements[0][1] * other.x + elements[1][1] * other.y + elements[2][1] * other.z + elements[3][1];
	result.z = elements[0][2] * other.x + elements[1][2] * other.y + elements[2][2] * other.z + elements[3][2];
	return result;
}
Vec4 Mat4::operator*(const Vec4& other) const
{
	Vec4 result;
	result.x = elements[0][0] * other.x + elements[1][0] * other.y + elements[2][0] * other.z + elements[3][0] * other.w;
	result.y = elements[0][1] * other.x + elements[1][1] * other.y + elements[2][1] * other.z + elements[3][1] * other.w;
	result.z = elements[0][2] * other.x + elements[1][2] * other.y + elements[2][2] * other.z + elements[3][2] * other.w;
	result.w = elements[0][3] * other.x + elements[1][3] * other.y + elements[2][3] * other.z + elements[3][3] * other.w;
	return result;
}
Mat4 Mat4::operator+(const Mat4& other) const
{
	Mat4 result;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result.elements[i][j] = elements[i][j] + other.elements[i][j];
		}
	}
	return result;
}
Mat4 Mat4::operator-(const Mat4& other) const
{
	Mat4 result;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result.elements[i][j] = elements[i][j] - other.elements[i][j];
		}
	}
	return result;
}
Mat4 Mat4::operator-(const Vec3& other) const
{
	Mat4 result = *this;
	result.elements[3][0] -= other.x;
	result.elements[3][1] -= other.y;
	result.elements[3][2] -= other.z;
	return result;
}
