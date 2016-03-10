#pragma once
#include <GL/glew.h>

namespace spike {
	namespace graphics
	{
		class IndexBuffer
		{
			GLuint mBufferId;
			GLuint mCount;
		public:
			IndexBuffer(GLushort* data, GLsizei count);
			void bind() const;
			void unBind() const;

			GLuint getCount() const { return mCount; }
		};
	}
}