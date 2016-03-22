#include "elementBuffer.h"


ElementBuffer::ElementBuffer(GLushort* data, GLsizei count)
	: mCount(count)
{

	glGenBuffers(1, &mBufferId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBufferId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
ElementBuffer::ElementBuffer(GLuint* data, GLsizei count)
	:mCount(count)
{
	glGenBuffers(1, &mBufferId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBufferId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}
ElementBuffer::~ElementBuffer()
{
	glDeleteBuffers(1, &mBufferId);
}
void ElementBuffer::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBufferId);

}
void ElementBuffer::unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}
