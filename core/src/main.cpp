#include <iostream>
// Other includes
#include "graphics\window.h"
#include "graphics/shader.h"
#include "graphics/model.h"

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;
Vec3 lightPos(3.0,5.0,0.0);

int main()
{
	Window window("spike", WIDTH, HEIGHT);
	window.enableDepth();
	// Build and compile our shader program
	Shader lightingShader("src/shaders/phong.vert", "src/shaders/phong.frag");
	Shader lampShader("src/shaders/lamp.vert", "src/shaders/lamp.frag");
	Model nanoModel("D:/spike/resources/nanosuit/nanosuit.obj");
	Model lightModel("D:/spike/resources/lightCube.obj");

	Mat4 position;
	Mat4 position1;
	position1.addTranslation(lightPos);
	Mat4 viewMatrix;
	viewMatrix.addTranslation(Vec3(0.0f, -10, 25.0f));
	Mat4 persp = Mat4::projectPerspective(45.0f, 16.0f / 9.0f, -1.0f, 1.0f);

	// Game loop
	float rotation = 0.0;
	while (!window.closed())
	{
		window.clear();
		position1.addTranslation(Vec3(0.0, 0.001, 0.0));
		position.setRotation(rotation, Vec3(0.0, 1.0, 0.0));
		lightingShader.enable();
		lightingShader.setUniform3f("lightPos", position1.getTranslation());
		lightingShader.setUniform3f("objectColor", Vec3(1.0, 1.0, 0.31));
		lightingShader.setUniform3f("lightColor", Vec3(1.0, 0.5, 1.0));
		lightingShader.setUniform3f("viewPos", Vec3(0.0, 0.0, 0.0));

		lightingShader.setUniformMat4("view", viewMatrix);
		lightingShader.setUniformMat4("projection", persp);
		lightingShader.setUniformMat4("model", position);
		nanoModel.draw();
		lampShader.enable();
		lampShader.setUniformMat4("view", viewMatrix);
		lampShader.setUniformMat4("projection", persp);
		lampShader.setUniformMat4("model", position1);
		lightModel.draw();
		window.update();
		rotation += 0.01;
	}
	return 0;
}
