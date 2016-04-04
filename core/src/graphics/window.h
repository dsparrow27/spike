//Main window for spike 
#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include "../maths/maths.h"
#define MAX_KEYS 1024
#define MAX_BUTTONS 32

class Window
{
private:
	//windows settings
	bool mClosed; // is window closed
	bool mKeys[MAX_KEYS];
	bool mMouseButtons[MAX_BUTTONS];
	bool mIsResizeable;

public:
	GLFWwindow *mWindow; // window pointer
	int mWidth, mHeight; // window height/ width
	const char *mTitle; //window title
	double mx, my; // xy positions of the window
	Window(const char *name, int width, int height);
	~Window();
	bool closed() const; // for closing our window
	void clear() const;
	void update();
	// setters
	void enableDepth();
	void drawWireframe(bool state);
	void setResizeable(bool state);
	void setCullingType(const char* cullType) const;
	void setTitle(const char *title);
	void setVisible(bool visible);
	void setPosition(const Vec2& position);
	void setSize(const Vec2& size);
	Vec2 getSize();
	// getters
	int getWidth() const { return mWidth; };
	int getHeight() const { return mHeight; };
	Vec2 getPosition();
	bool isResizable(bool state);
	//getters for events
	bool isKeyPressed(unsigned int keycode) const;
	bool isMousePressed(unsigned int button) const;
	void getMousePosition(double& x, double& y) const;

private:
	bool init(); // initialize the window
	// set up callbacks
	friend void key_callback(GLFWwindow* window, int key, int scanCode, int action, int mods);
	friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	friend void cursor_position_callback(GLFWwindow* window, double xPos, double yPos);
	//friend void mouse_scroll_callback(GLFWwindow* window, double xPos, double yPos) { mCamera.zoom(yPos); }
};
