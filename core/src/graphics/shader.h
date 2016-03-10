#pragma once
/*
Shader class that loads a vert and frag shader and optional geometry shader
*/

#include <GL/glew.h>
#include <string>
#include <iostream>
#include "../utils/fileUtils.h"
#include "../maths/maths.h"

class Shader
{
private:
	GLuint mShaderId;
	const char* mVertPath;
	const char* mFragPath;
	const char* mGeometryPath;
	GLuint program;
public:
	Shader(const char* vertPath, const char* fragPath, const char* geometryPath = nullptr);
	~Shader();
	
	void setUniform1f(const GLchar* name, float value);
	void setUniform1i(const GLchar* name, int value);
	void setUniform2f(const GLchar* name, const Vec2& vector);
	void setUniform3f(const GLchar* name, const Vec3& vector);
	void setUniform4f(const GLchar* name, const Vec4& vector);
	void setUniformMat4(const GLchar* name, const Mat4& matrix);

	void enable() const;
	void disable() const;

	
private:
	GLuint load();
	void checkCompileErrors(GLuint shader, std::string type);
	GLuint getUniformLocation(const GLchar* name);
	
};