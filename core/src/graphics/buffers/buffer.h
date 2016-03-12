#pragma once
#include <GL/glew.h>

class Buffer
{
	GLuint mBufferId;
	GLuint mComponentCount;
public:
	Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
	void bind() const;
	void unbind() const;

	GLuint getComponentCount() const { return mComponentCount; }
};
