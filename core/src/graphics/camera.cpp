#include "camera.h"

Camera::Camera(const Mat4& projectionMatrix)
	:mProjectionMatrix(projectionMatrix)
{
	mViewMatrix = Mat4::identity();
	mPosition = Vec3();
	mRotation = Vec3();
	mWorldUp = Vec3(0.0, 1.0, 0.0);
	mYaw = -90.0f;
	mPitch = 0.0f;
	mSensitivity = 0.25f;
	mMovementSpeed = 3.0f;
	
}

void Camera::update()
{

}

void Camera::zoom(float delta)
{
	if (this->mZoom >= 1.0f)
	{
		this->mZoom -= delta;
	}
	if (this->mZoom <= 1.0f)
	{
		this->mZoom = 1.0;
	}
}

Vec3 Camera::getUpDirection()
{

}

Vec3 Camera::getRightDirection()
{

}

Vec3 Camera::getLeftDirection()
{

}