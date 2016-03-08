//Main window for spike 
#pragma once
#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

class Window
{
private:
	//windows settings
	int mWidth, mHeight; // window height/ width
	const char *mTitle; //window title
	GLFWwindow *mWindow; // window pointer
	bool mClosed; // is window closed
			
	bool mKeys[MAX_KEYS];
	bool mMouseButtons[MAX_BUTTONS];
	double mx, my;
public:
	Window(const char *name, int width, int height);
	~Window();
	bool closed() const; // for closing our window
	void clear() const;
	void update();
	// getters
	inline int getWidth() const { return mWidth; };
	inline int getHeight() const { return mHeight; };
	//getters for events
	bool isKeyPressed(unsigned int keycode) const;
	bool isMousePressed(unsigned int button) const;
	void getMousePosition(double& x, double& y) const;

private:
	bool init(); // initialize the window
	// set up callbacks
	friend static void key_callback(GLFWwindow* window, int key, int scanCode, int action, int mods);
	friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	friend static void cursor_position_callback(GLFWwindow* window, double xPos, double yPos);
};
