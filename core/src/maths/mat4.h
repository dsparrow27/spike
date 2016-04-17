#pragma once

#include "Vec3.h"
#include "Vec4.h"
#include "mathsFunc.h"
#include <iostream>

/*
	This matrix 4x4 class is for use in right hand coordinate spaces with y up.
	A column is a sequential memory positions (elements[0][0], elements[0][1], elements[0][2], elements[0][3]).
	A row is in stride positions (elements[0][0], elements[1][0], elements[2][0], elements[3][0]).
	
	Translations are stored in the last column
	hmm should write this as a 1Dimension array so that opengl etc is fully compatible
*/
struct Mat4
{
	union
	{
		float elements[4][4];
		Vec4 column[4];
	};
	float mArray[16]; // temp
	//constructors
	Mat4() { asIdentity(); }
	Mat4(float diagonal);
	Mat4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33);
	Mat4(const Mat4& m);
	Mat4(const Vec3& forward, const Vec3& vecUp, const Vec3& vecRight, const Vec3& vecPosition = Vec3(0, 0, 0));
	Mat4(const Vec4& forward, const Vec4& vecUp, const Vec4& vecRight, const Vec4& vecPosition = Vec4(0, 0, 0, 1));
	//methods
	bool isIdentity() const;
	Mat4 inverse();

	static Mat4 projectOrthographic(float left, float right, float top, float bottom, float near, float far);
	static Mat4 projectPerspective(float fov, float aspectRatio, float near, float far);
	static Mat4 projectFrustum(float fov, float aspectRatio, float near, float far);
	static Mat4 projectFrustum(float left, float right, float bottom, float top, float near, float far);
	static Mat4 constructCameraView(const Vec3& position, const Vec3& direction, const Vec3& upVector);
	Mat4 addTranslation(const Vec3 v);
	Mat4 addScale(const Vec3 v);
	Mat4 addReflection(const Vec3 v);
	Vec3 transformDirection(const Vec3 v) const;
	Mat4 transposed() const ;

	//getters
	Vec4 getColumn(int index) const;
	Vec4 getRow(int index) const;
	Vec3 getForwardVector() { return Vec3(elements[0][0], elements[0][1], elements[0][2]); }
	Vec3 getUpVector() { return Vec3(elements[1][0], elements[1][1], elements[1][2]); }
	Vec3 getRightVector() { return Vec3(elements[2][0], elements[2][1], elements[2][2]);}
	Vec3 getTranslation() const;
	Vec3 getScale() const;
	void getAsArray(); //temp
	//setters
	Mat4& asIdentity();
	void setColumn(int i, const Vec3& column);
	void setColumn(int i, const Vec4& column);
	void setTranslation(const Vec3& translation);
	void setTranslation(const Vec4& translation);
	void setRotation(float angle, const Vec3& axis);
	void setScale(const Vec3& scale);
	void setForwardVector(const Vec3& forward);
	void setForwardVector(const Vec4& forward);
	void setUpVector(const Vec4& upVector);
	void setUpVector(const Vec3& upVector);
	void setRightVector(const Vec4& right);
	void setRightVector(const Vec3& right);
	void setReflection(const Vec3& planeNormal);

	//operators
	
	bool operator==(const Mat4& other);
	bool operator!=(const Mat4& other);
	Mat4& operator=(const Mat4& other);
	Mat4& operator*=(const Mat4& other);
	Mat4& operator+=(const Vec3& other);
	Mat4& operator-=(const Vec3& other);
	Mat4 operator*(const Mat4& other) const;
	Mat4 operator*(float f) const;
	Vec3 operator*(const Vec3& other) const;
	Vec4 operator*(const Vec4& other) const;
	Mat4 operator+(const Mat4& other) const;
	Mat4 operator+(const Vec3& other) const;
	Mat4 operator-(const Mat4& other) const;
	Mat4 operator-(const Vec3& other) const;
};
