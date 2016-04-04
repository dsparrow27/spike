#include "quaternion.h"


Quaternion::Quaternion()
	:x(0), y(0), z(0), w(1)
{
}
Quaternion::Quaternion(const Quaternion& quaternion)
{
	this->x = quaternion.x;
	this->y = quaternion.y;
	this->z = quaternion.z;
	this->w = quaternion.w;

}
Quaternion::Quaternion(float x, float y, float z, float w)
	:x(x), y(y), z(z), w(w)
{
}
Quaternion::Quaternion(Vec4 xyzw)
{
	this->x = xyzw.x;
	this->y = xyzw.y;
	this->z = xyzw.z;
	this->w = xyzw.w;
}
// The magnitude or length of a quaternion
float Quaternion::length()
{
	return  sqrt((x*x + y*y + z*z + w*w));
}
float Quaternion::dot(const Quaternion& other)
{
	float result = (x * other.x);
	result += (y*other.y);
	result += (z*other.z);
	result += (w*other.w);
	return result;
}
// normalizes the quaternion
void Quaternion::normalize()
{
}
Quaternion Quaternion::identity()
{
	return Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
}
// returns the conjugate of the quaternion aka.inverse
Quaternion Quaternion::Conjugate() const
{
	return Quaternion(-x, -y, -z, w);
}

float Quaternion::roll()
{
	return atan2(2.0f * x * y + z * w, 
				x * x + w * w - y * y - z * z);

}float Quaternion::pitch()
{
	return atan2(2.0f * y * z + w * x,
			w * w - x * x - y * y + z * z);
}
float Quaternion::yaw()
{
	return asin(-2.0f * (x * z - w * y));
}
//returns the euler angles from the quaternion
Vec3 Quaternion::toEuler()
{
	return Vec3(this->roll(),
		this->pitch(),
		this->yaw());
}
// returns a quaternion from 
Quaternion Quaternion::fromEuler(const Vec3& angles)
{
	Quaternion pitch(1.0, 0.0, 0.0, angles.x);
	Quaternion yaw(0.0, 1.0, 0.0, angles.y);
	Quaternion roll(0.0, 0.0, 1.0, angles.z);
	return pitch * yaw * roll;
}

bool const Quaternion::operator==(const Quaternion& other)
{
	return (this->x == other.x) && (this->y == other.y) && (this->z == other.z) && (this->w == other.w);
}
bool const Quaternion::operator!=(const Quaternion& other)
{
	return !(*this == other);
}
Quaternion& Quaternion::operator=(const Quaternion& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	this->w = other.w;
	return *this;
}
Quaternion& Quaternion::operator*=(const Quaternion& other)
{
	*this = *this * other;
	return *this;
}
Quaternion& Quaternion::operator*=(const float other)
{
	*this = *this * other;
	return *this;
}
Quaternion& Quaternion::operator/=(const Quaternion& other)
{
	*this = *this / other;
	return *this;
}
Quaternion& Quaternion::operator+=(const Quaternion& other)
{
	*this = *this + other;
	return *this;
}
Quaternion& Quaternion::operator-=(const Quaternion& other)
{
	*this = *this - other;
	return *this;
}
Quaternion& Quaternion::operator*(const Quaternion& other)
{
	Quaternion result;
	result.x = this->w * other.x + this->x * other.w + this->y * other.z - this->z * other.y;
	result.y = this->w * other.y - this->x * other.z + this->y * other.w + this->z * other.x;
	result.z = this->w * other.z + this->x * other.y - this->y * other.x + this->z * other.w;
	result.w = this->w * other.w - this->x * other.x - this->y * other.y - this->z * other.z;
	return result;
}
Quaternion& Quaternion::operator*(const float other)
{
	return Quaternion(x * other, y * other, z * other, w * other);
}
Quaternion& Quaternion::operator/(const Quaternion& other)
{
	return Quaternion(x / other.x, y / other.y, z / other.z, w / other.w);
}
Quaternion& Quaternion::operator-(const Quaternion& other)
{
	return Quaternion(x - other.x, y - other.y, z - other.z, w - other.w);
}
Quaternion& Quaternion::operator-()
{
	return Quaternion(-x, -y, -z, -w);
}
Quaternion& Quaternion::operator+(const Quaternion& other)
{
	return Quaternion(x + other.x, y + other.y, z + other.z, w + other.w);
}
