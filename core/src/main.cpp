#include <iostream>
// Other includes
#include "graphics\window.h"
#include "graphics/shader.h"
#include "graphics/model.h"
// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;
Vec3 lightPos(3.0,5.0,3.0);

int main()
{
	Window window("spike", WIDTH, HEIGHT);
	window.enableDepth();
	// Build and compile our shader program
	Shader lightingShader("src/shaders/phong.vert", "src/shaders/phong.frag");
	Shader lampShader("src/shaders/lamp.vert", "src/shaders/lamp.frag");
	Model nanoModel("D:/spike/resources/nanosuit/nanosuit.obj");
	Model lightModel("D:/spike/resources/lightCube.obj");
	window.setCamera(Camera(Mat4::projectPerspective(45.0f, (float)WIDTH / (float)HEIGHT, -0.01f, 200.0f)));
	window.camera.setPosition(Vec3(0.0f, 10.0f, 10.0f));
	window.camera.setViewMatrix(Mat4::constructCameraView(window.camera.getPosition(), Vec3(0.0,0.0,-1.0), Vec3(0, 1, 0)));
	std::cout << window.camera.getViewMatrix().getTranslation() << std::endl;
	Mat4 position;
	Mat4 position1;
	position1.addTranslation(lightPos);
	// Game loop
	float rotation = 0.0;
	while (!window.closed())
	{
		window.clear();
		// temp
		if (window.mKeys[GLFW_KEY_UP])
		{
			window.camera.onKeyBoard(GLFW_KEY_UP);
		}
		else if (window.mKeys[GLFW_KEY_DOWN])
		{
			window.camera.onKeyBoard(GLFW_KEY_DOWN);
		}
		else if (window.mKeys[GLFW_KEY_LEFT])
		{
			window.camera.onKeyBoard(GLFW_KEY_LEFT);
		}
		else if (window.mKeys[GLFW_KEY_RIGHT])
		{
			window.camera.onKeyBoard(GLFW_KEY_RIGHT);
		}

		position.setRotation(rotation, Vec3(0.0, 1.0, 0.0));
		lightingShader.enable();
		lightingShader.setUniform3f("lightPos", position1.getTranslation());
		lightingShader.setUniform3f("objectColor", Vec3(1.0, 1.0, 0.31));
		lightingShader.setUniform3f("lightColor", Vec3(1.0, 0.5, 1.0));
		lightingShader.setUniform3f("viewPos", Vec3(0.0, 0.0, 0.0));
		
		lightingShader.setUniformMat4("view", window.camera.getViewMatrix());
		lightingShader.setUniformMat4("projection", window.camera.getProjectionMatrix());
		lightingShader.setUniformMat4("model", position);
		nanoModel.draw();
		lampShader.enable();
		lampShader.setUniformMat4("view", window.camera.getViewMatrix());
		lampShader.setUniformMat4("projection", window.camera.getProjectionMatrix());
		lampShader.setUniformMat4("model", position1);
		lightModel.draw();
		window.update();
		rotation += 0.01;
	}
	return 0;
}
