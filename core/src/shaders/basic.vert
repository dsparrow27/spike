#version 330 core

layout (location = 0) in vec4 position;


out vec4 pos;

void main()
{
	gl_Position = vec4(position.x, position.y, position.z, position.w);
}