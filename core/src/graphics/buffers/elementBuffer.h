#pragma once
#include <GL/glew.h>


class ElementBuffer
{
	GLuint mBufferId;
	GLuint mCount;
public:
	ElementBuffer(GLushort* data, GLsizei count);
	void bind() const;
	void unbind() const;

	GLuint getCount() const { return mCount; }
};
