#include "../maths/maths.h"
/*
	Base class for all cameras , inherented camera should override focusPoint and update
*/
class Camera
{
public:
	//members
	Mat4 mViewMatrix, mProjectionMatrix;
	Vec3 mPosition, mRotation, mFocalPoint, mWorldUp;
	float mYaw, mPitch, mMovementSpeed, mSensitivity, mZoom;

public:
	
	Camera();
	Camera(const Mat4& projectionMatrix);

	void focusPoint();
	void update();
	void zoom(float delta);
	//getter methods
	inline const Vec3& getPosition() const { return mPosition; }
	inline const Vec3& getRotation() const { return mRotation; }
	inline const Vec3& getFocalPoint() const { return mFocalPoint; }
	inline const Mat4& getViewMatrix() const { return mViewMatrix; }

	Vec3 getUpDirection();
	Vec3 getRightDirection();
	Vec3 getLeftDirection();

	//setter methods
	inline void setPosition(const Vec3 position) { mPosition = position; }
	inline void setRotation(const Vec3 rotation) { mRotation = rotation; }

	//modifiers
	inline void translate(const Vec3& translation) { mPosition += translation; }
	inline void rotate(const Vec3& rotation) { mRotation += rotation; }
	inline void translate(float x, float y, float z) { mPosition += Vec3(x,y,z); }
	inline void rotate(float x, float y, float z) { mRotation += Vec3(x,y,z); }

};