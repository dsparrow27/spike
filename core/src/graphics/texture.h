#pragma once
#include <string>
#include <GL/glew.h>
#include "../utils/fileUtils.h"

class Texture
{
private:
	std::string mFileName;
	GLsizei mWidth, mHeight;

public:
	GLuint mTID; // texture id for graphics
	Texture(const std::string& fileName);
	~Texture();
	void bind();
	void unbind();
	void activate();
	inline const unsigned int getWidth() const { return mWidth; };
	inline const unsigned int getHeight() const { return mHeight; };

private:
	GLuint load();


};