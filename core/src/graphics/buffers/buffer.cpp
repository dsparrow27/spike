#include "buffer.h"


namespace spike {
	namespace graphics
	{
		Buffer::Buffer(GLfloat* data, GLsizei count, GLuint componentCount)
			:mComponentCount(componentCount)
		{
			
			glGenBuffers(1, &mBufferId);
			glBindBuffer(GL_ARRAY_BUFFER, mBufferId);
			glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
		void Buffer::bind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, mBufferId);

		}
		void Buffer::unBind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);

		}
	}
}