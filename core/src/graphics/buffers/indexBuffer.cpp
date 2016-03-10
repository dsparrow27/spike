#include "indexBuffer.h"


namespace spike {
	namespace graphics
	{
		IndexBuffer::IndexBuffer(GLushort* data, GLsizei count)
			: mCount(count)
		{

			glGenBuffers(1, &mBufferId);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBufferId);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
		void IndexBuffer::bind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBufferId);

		}
		void IndexBuffer::unBind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		}
	}
}