
#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "../../maths/maths.h"
// base Camera class that handles generic functions, transforms are currently temp til 
// i inplement transform class

class Camera
{
private:
	Mat4 mViewMatrix;
	Mat4 mProjectionMatrix;
	Vec3 mUpVector;
	Vec3 mFocalPoint;
	float mFov;
	float mNearPlane;
	float mFarPlane;

public:
	Camera() {}
	Camera(const Mat4 projectionMatrix);
	bool onKeyBoard(int key);
	//setters
	void setUpVector(Vec3 upVector) { mUpVector = upVector; }
	void setFov(float fov) { mFov = fov; }
	void NearPlane(float near) { mNearPlane = near; }
	void FarPlane(float far) { mFarPlane = far; }
	void setViewMatrix(Mat4 matrix) { mViewMatrix = matrix; }
	void setPosition(Vec3 position) { mViewMatrix.setTranslation(position); }

	//getters
	Mat4 getViewMatrix() { return mViewMatrix; }
	Mat4 getProjectionMatrix() { return mProjectionMatrix; }
	Vec3 getPosition() { return mViewMatrix.getTranslation(); }
	Vec3 getFocalPoint() { return mFocalPoint; }
	Vec3 getUpVector() { return mUpVector; }
	float getFov() { return mFov; }
	float getNearPlane() { return mNearPlane; }
	float getFarPlane() { return mFarPlane; }

};
