#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/maths/maths.h"
#include <math.h>
int main()
{
	Window window("spike", 960, 540);
	glClearColor(0.25f, 0.25f, 0.25f, 1.0f);

	GLfloat vertices[] =
	{
		0, 0, 0,
		8, 0, 0,
		0, 3, 0,
		0, 3, 0,
		8, 3, 0,
		8, 0, 0
	};

	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindVertexArray(VAO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	Mat4 ortho = Mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", Mat4::translation(Vec3(4, 3, 0)));

	shader.setUniform2f("light_pos", Vec2(0.0f, 0.0f));
	shader.setUniform4f("colour", Vec4(0.2f, 1.0f, 1.0f, 1.0f));

	while (!window.closed())
	{
		window.clear();
		float currentTime = glfwGetTime();
		shader.setUniform2f("light_pos", Vec2(sin(0.5)*currentTime, 0.0));
		glDrawArrays(GL_TRIANGLES, 0, 6);
		window.update();
	}

	return 0;
}