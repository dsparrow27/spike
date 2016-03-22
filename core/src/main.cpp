#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "graphics\shader.h"
#include "graphics\texture.h"
#include "graphics\window.h"
#include "maths/maths.h"
#include "graphics/buffers/buffer.h"
#include "graphics/buffers/elementBuffer.h"
#include "graphics/buffers/vertexarray.h"
#include "graphics/texture.h"

int main()
{
	GLfloat vertices[] = {
		0.5f,  0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	GLfloat colors[] = {
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 1.0f, 
		1.0f, 1.0f, 0.0f, 1.0f };
	GLfloat texCoords[] =
	{
		1.0, 1.0,
		1.0, 0.0,
		0.0, 0.0,
		0.0, 1.0
	};

	GLushort indices[] = { 0,1,2,2,3,0 };

	Window window("spike!", 960, 540);

	Mat4 ortho = Mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);// left, right, bottom, top, distance near and far
	VertexArray VAO;
	ElementBuffer EBO(indices, 6);

	VAO.addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	VAO.addBuffer(new Buffer(colors, 4 * 4, 4), 1);
	VAO.addBuffer(new Buffer(texCoords, 2 * 4, 2), 2);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	
	shader.setUniformMat4("projMatrix", ortho);
	shader.setUniformMat4("modelMatrix", Mat4::translation(Vec3(8,3,0)));

	Texture texture("");
	texture.activate();
	while (!window.closed())
	{
		window.clear();
		
		VAO.bind();
		EBO.bind();
		glDrawElements(GL_TRIANGLES, EBO.getCount(), GL_UNSIGNED_SHORT, 0);
		EBO.bind();
		VAO.unbind();

		window.update();
	}

	return 0;
}
/*

// The MAIN function, from here we start the application and run the game loop
int main()
{
	Window ourWindow("learning stuff", 800, 600);
	// Build and compile our shader program
	Shader ourShader("src/shaders/basic.vert", "src/shaders/basic.frag");


	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
		// Positions          // Colors           // Texture Coords
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // Top Right
		0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   1.0f, 0.0f, // Bottom Right
		-0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 1.0f,  0.0f, 0.0f, // Bottom Left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,  0.0f, 1.0f  // Top Left 
	};
	GLuint indices[] = {  // Note that we start from 0!
		0, 1, 3, // First Triangle
		1, 2, 3  // Second Triangle
	};
	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO


						  // Load and create a texture 
	Texture texture = Texture("D:/spike/core/src/wall.jpg");
	texture.bind();
	// Bind Textures using texture units
	texture.activate();

	// Activate shader
	ourShader.setUniform1i("ourTexture1", 0);
	Mat4 ortho = Mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	ourShader.enable();
	ourShader.setUniformMat4("projMatrix", ortho);

	// Game loop
	while (!ourWindow.closed())
	{
		ourWindow.clear();
		// Draw container
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		ourWindow.update();
	}
	return 0;
}
*/