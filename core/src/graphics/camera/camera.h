#pragma once

#include "../../maths/maths.h"

class Camera
{
protected:
	Mat4 mProjectionMatrix, mViewMatrix;
	Vec3 mPosition, mRotation, mScale, mFocalPoint;
public:
	Camera(const Mat4& projectionMatrix);
	virtual void update() {};
	// getter
	inline const Vec3& getPosition() const { return mPosition; }
	inline const Vec3& getRotation() const { return mRotation; }
	inline const Vec3& getScale() const { return mScale; }
	inline const Mat4& getprojectionMatrix() const { return mProjectionMatrix; }
	inline const Mat4& getViewMatrix() const { return mViewMatrix; }
	
	// setter
	inline void setPosition(const Vec3& position) { mPosition = position; }
	inline void setRotation(const Vec3& rotation) { mRotation = rotation; }
	inline void setScale(const Vec3& scale) { mScale = scale; }
	inline void setProjectionMatrix(const Mat4& projectionMatrix) { mProjectionMatrix = projectionMatrix; }
	inline void setViewMatrix(const Mat4& viewMatrix) { mViewMatrix = viewMatrix; }
	
	inline void translate(const Vec3& translation) { mPosition += translation; }
	inline void translate(float x, float y, float z) { mPosition += Vec3(x,y,z); }
	inline void rotation(const Vec3& rotation) { mRotation += rotation; }
	inline void rotation(float x, float y, float z) { mRotation += Vec3(x, y, z); }
	
	inline const Vec3 getFocalPoint() const { return mFocalPoint; }
	
};