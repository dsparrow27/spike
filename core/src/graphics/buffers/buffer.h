#pragma once
#include <GL/glew.h>

class Buffer
{
	GLuint mBufferId;
	GLuint mComponentCount; // how many positions in the array for the buffer
public:
	// should the data be a struct?
	Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
	~Buffer();
	// bind the buffer array
	void bind() const;
	// unbind the buffer array
	void unbind() const;
	// returns the component count
	GLuint getComponentCount() const { return mComponentCount; }
};
