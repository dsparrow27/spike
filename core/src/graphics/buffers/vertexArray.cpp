#include "vertexArray.h"


VertexArray::VertexArray()
{
	glGenVertexArrays(1, &mArrayId);
}
VertexArray::~VertexArray()
{
	for (int i = 0; i < mBuffers.size(); i++)
	{
		delete mBuffers[i];
	}
	glDeleteVertexArrays(1, &mArrayId);
}
void VertexArray::addBuffer(Buffer* buffer, GLuint index)
{
	//index == shader index eg. position = 0, color == 1 etc
	bind();
	buffer->bind();
	glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(index);
	buffer->unbind();
	unbind();
}
void VertexArray::bind() const
{
	glBindVertexArray(mArrayId);
}
void VertexArray::unbind() const
{
	glBindVertexArray(0);
}
