#include "texture.h"

Texture::Texture(const std::string& fileName)
	:mFileName(fileName)
{
	mTID = load();
}

Texture::~Texture()
{

	glDeleteTextures(1, &mTID);
}

GLuint Texture::load()
{
	BYTE* pixels = FileUtils::loadImage(mFileName.c_str(), &mWidth, &mHeight);
	GLuint result;
	glGenTextures(1, &result);
	glBindTexture(GL_TEXTURE_2D, result);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, mWidth, mHeight, 0, GL_BGR, GL_UNSIGNED_BYTE, pixels);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);

	return result;
}
void Texture::activate()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mTID);
}
void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, mTID);
}

void Texture::unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

