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
}
void VertexArray::addBuffer(Buffer* buffer, GLuint index)
{
	bind();
	buffer->bind();
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);
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
