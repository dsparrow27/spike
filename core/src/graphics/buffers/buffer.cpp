#include "buffer.h"


Buffer::Buffer(GLfloat* data, GLsizei count, GLuint componentCount)
	:mComponentCount(componentCount)
{
	// setup the buffer			
	glGenBuffers(1, &mBufferId);
	glBindBuffer(GL_ARRAY_BUFFER, mBufferId);
	glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Buffer::~Buffer()
{
	glDeleteBuffers(1, &mBufferId);
}

void Buffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, mBufferId);

}
void Buffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}
