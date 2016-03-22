#version 330 core
layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 texCoord;
uniform mat4 projMatrix;
uniform mat4 viewMatrix  = mat4(1.0);
uniform mat4 modelMatrix  = mat4(1.0);
out vec4 ourColor;
out vec2 TexCoord;

void main()
{
    gl_Position = projMatrix * viewMatrix * modelMatrix * position;;
    ourColor = color;
    TexCoord = texCoord;
}