#pragma once
#include <GL/glew.h>

namespace spike{
	namespace graphics
	{
		class Buffer
		{
			GLuint mBufferId;
			GLuint mComponentCount;
		public:
			Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
			void bind() const;
			void unBind() const;

			GLuint getComponentCount() const { return mComponentCount; }
		};
	}
}