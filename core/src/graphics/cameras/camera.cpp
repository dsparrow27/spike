#include "camera.h"

Camera::Camera(const Mat4 projectionMatrix)
{
	mProjectionMatrix = projectionMatrix;
	mViewMatrix = Mat4(); // identity matrix
	mUpVector = Vec3(0.0, 1.0, 0.0);
	mFocalPoint = Vec3(0.0, 0.0, -1.0);
}
bool Camera::onKeyBoard(int key)
{
	bool result = false;
	Vec3 position = mViewMatrix.getTranslation();
	if (key	 == GLFW_KEY_UP)
	{	
		position -= (mFocalPoint * 0.05f);
		result = true;	
	}
	else if  (key == GLFW_KEY_DOWN)
	{
		position += (mFocalPoint * 0.05f) ;
		result = true;
	}
	else if (key == GLFW_KEY_LEFT)
	{
		Vec3 left = mFocalPoint.cross(mUpVector).normalized();
		left *= 0.05f;
		position += left;
		result = true;

	}
	else if (key == GLFW_KEY_RIGHT)
	{
		Vec3 right = mUpVector.cross(mFocalPoint).normalized();
		right *= 0.05f;
		position += right;
		result = true;
	}
	std::cout << position << std::endl;
	mViewMatrix.setTranslation(position);

	return result;
}

