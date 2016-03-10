#pragma once
#include <GL/glew.h>
#include <vector>
#include "buffer.h"


namespace spike { 
	namespace graphics 
	{
		class VertexArray
		{
		private:
			GLuint mArrayId;
			std::vector<Buffer*> mBuffers;
		public:
			VertexArray();
			~VertexArray();
			void addBuffer(Buffer* buffer, GLuint index);
			void bind() const;
			void unBind() const;

		};
	}
}