#include "shader.h"

Shader::Shader(const char* vertPath, const char* fragPath, const char* geometryPath)
	:mVertPath(vertPath), mFragPath(fragPath), mGeometryPath(geometryPath)
{
	/*Initializes the shader paths and calls load*/
	load();
}
Shader::~Shader()
{
	/*Deletes the shader program using the shaderId*/
	glDeleteProgram(this->program);
}
void Shader::enable() const
{
	glUseProgram(this->program);
}
void Shader::disable() const
{
	glUseProgram(0);
}
GLuint Shader::load()
{

	this->program = glCreateProgram();
	
	std::string vertShaderCode = FileUtils::readFile(mVertPath);
	std::string fragShaderCode = FileUtils::readFile(mFragPath);
	const char* vertSource = vertShaderCode.c_str();
	const char* fragSource = fragShaderCode.c_str();

	GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	
	// vertex shader 
	glShaderSource(vertShader, 1, &vertSource, NULL);
	glCompileShader(vertShader);
	checkCompileErrors(vertShader, "VERTEX");
	// fragment Shader
	glShaderSource(fragShader, 1, &fragSource, NULL);
	glCompileShader(fragShader);
	checkCompileErrors(vertShader, "FRAGMENT");
	// create program and attach shaders 
	glAttachShader(this->program, vertShader);
	glAttachShader(this->program, fragShader);

	// geometry shader
	if (mGeometryPath != nullptr)
	{
		GLuint geoShader;
		const char* geoShaderCode = FileUtils::readFile(mGeometryPath).c_str();
		geoShader = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(geoShader, 1, &geoShaderCode, NULL);
		glCompileShader(geoShader);
		checkCompileErrors(vertShader, "GEOMETRY");
		glAttachShader(this->program, geoShader);
		glDeleteShader(geoShader);
	}
	glLinkProgram(this->program);
	checkCompileErrors(this->program, "PROGRAM");
	
	// no longer need the shaders so delete them 
	glDeleteShader(vertShader);
	glDeleteShader(fragShader);

	return this->program;
}

void Shader::checkCompileErrors(GLuint shader, std::string type)
{
	/*Checks for compile errors for the shader program and the shader types*/
	GLint success;
	GLchar infoLog[512];
	if (type != "program")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "ERROR .. shader compilation error of type " << type << "\n" << infoLog << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			std::cout << "ERROR .. program linking error of type " << type << "\n" << infoLog << std::endl;
			glGetProgramInfoLog(shader, 512, NULL, infoLog);
		}
	}
}

GLint Shader::getUniformLocation(const GLchar* name)
{
	return glGetUniformLocation(this->program, name);
}

void Shader::setUniform1f(const GLchar* name, float value)
{
	return glUniform1f(getUniformLocation(name), value);
}

void Shader::setUniform1i(const GLchar* name, int value)
{
	return glUniform1f(getUniformLocation(name), value);
}

void Shader::setUniform2f(const GLchar* name, const Vec2& vector)
{
	return glUniform2f(getUniformLocation(name), vector.x, vector.y);
}

void Shader::setUniform3f(const GLchar* name, const Vec3& vector)
{
	return glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
}
void Shader::setUniform4f(const GLchar* name, const Vec4& vector)
{
	return glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
}
void Shader::setUniformMat4(const GLchar* name, const Mat4& matrix)
{
	return glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elements);
}
