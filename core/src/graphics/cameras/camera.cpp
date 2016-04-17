#include "camera.h"

Camera::Camera(const Mat4 projectionMatrix)
{
	mProjectionMatrix = projectionMatrix;
	mViewMatrix = Mat4(); // identity matrix
	mUpVector = Vec3(0.0, 1.0, 0.0);
	mFocalPoint = Vec3(0.0, 0.0, -1.0);
	movementSensivity = 0.02f;
}
bool Camera::onKeyBoard(int key)
{
	bool result = false;
	Vec3 position = mViewMatrix.getTranslation();
	if (key	 == GLFW_KEY_W)
	{	
		position -= (mFocalPoint * movementSensivity);
		result = true;	
	}
	else if  (key == GLFW_KEY_S)
	{
		position += (mFocalPoint * movementSensivity) ;
		result = true;
	}
	else if (key == GLFW_KEY_A)
	{
		Vec3 left = mFocalPoint.cross(mUpVector).normalized();
		left *= movementSensivity;
		position += left;
		result = true;

	}
	else if (key == GLFW_KEY_D)
	{
		Vec3 right = mUpVector.cross(mFocalPoint).normalized();
		right *= movementSensivity;
		position += right;
		result = true;
	}
	std::cout << position << std::endl;
	mViewMatrix.setTranslation(position);

	return result;
}

