#pragma once
#include <GL/glew.h>


class ElementBuffer
{
	GLuint mBufferId;
	GLuint mCount;
public:
	ElementBuffer(GLushort* data, GLsizei count);
	ElementBuffer(GLuint* data, GLsizei count);
	~ElementBuffer();
	void bind() const;
	void unbind() const;

	GLuint getCount() const { return mCount; }
};
