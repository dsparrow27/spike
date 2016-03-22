
#include "camera.h"

Camera::Camera(const Mat4& projectionMatrix)
	:mProjectionMatrix(projectionMatrix), mViewMatrix(Mat4::identity()), mPosition(Vec3()), mRotation(Vec3())
{
}