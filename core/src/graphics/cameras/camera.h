/*
#pragma once

#include "../../maths/maths.h"


class Camera
{
	
	Mat4 mViewMatrix;
	Mat4 mProjectionMatrix;
	Vec3 mPosition; // this is more of a temp solution
	Vec3 mRotation;
	Vec3 mUpVector;
	Vec3 mFocalPoint;
	float mFov;
	float mNearPlane;
	float mFarPlane;

public:
	Camera(const Mat4 projectionMatrix);
	virtual void update() {} // meant to be overriden
	//setters
	void setUpVector(Vec3 upVector) { mUpVector = upVector; }
	void setFov(float fov) { mFov = fov; }
	void NearPlane(float near) { mNearPlane = near; }
	void FarPlane(float far) { mFarPlane = far; }
	void setViewMatrix(Mat4 matrix) { mViewMatrix = matrix; }
	void setPostion(Vec3 position) { mPosition = position; }
	void setRotation(Vec3 rotation) { mRotation = rotation; }
	//getters
	Mat4 getViewMatrix() { return mViewMatrix; }
	Mat4 getProjectionmatrix() { return mProjectionMatrix; }
	Vec3 getFocalPoint() { return mFocalPoint; }
	Vec3 getPosition() { return mPosition; }
	Vec3 getRotation() { return mRotation; }
	Vec3 getUpVector() { return mUpVector; }
	float getFov() { return mFov; }
	float getNearPlane() { return mNearPlane; }
	float getFarPlane() { return mFarPlane; }

};
*/