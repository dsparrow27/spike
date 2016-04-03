#include "window.h"


void windowResize(GLFWwindow * window, int width, int height);
Window::Window(const char *name, int width, int height)
	:mTitle(name), mWidth(width), mHeight(height)
{
	/*Window constructor calls on inital method*/
	if (!init())
	{
		glfwTerminate();
	}
	// initialise the keys buttons to false
	for (int i = 0; i < MAX_KEYS; i++)
	{
		mKeys[i] = false;
	}
	for (int i = 0; i < MAX_BUTTONS; i++)
	{
		mMouseButtons[i] = false;
	}
}
		
Window::~Window()
{
	//terminate the window
	glfwTerminate();
}
bool Window::init()
{
	/*
	Creates the window
	*/
	if (!glfwInit())
	{
		std::cout << "Failed to initalize GLFW" << std::endl;
		return false;
	}

	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	
	// create the window
	mWindow = glfwCreateWindow(mWidth, mHeight, mTitle, NULL, NULL);
	if (!mWindow)
	{
		std::cout << "Could not load GLFW window" << std::endl;
		return false;
	}
	glewExperimental = GL_TRUE;
	glfwMakeContextCurrent(mWindow);
	glfwSetWindowUserPointer(mWindow, this);
	glfwSetWindowSizeCallback(mWindow, windowResize);
	glfwSetKeyCallback(mWindow, key_callback);
	glfwSetMouseButtonCallback(mWindow, mouse_button_callback);
	glfwSetCursorPosCallback(mWindow, cursor_position_callback);
	glfwSwapInterval(0.0);
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Could not initialize GLEW" << std::endl;
		return false;
	}
	return true;
}
// settings
void Window::enableDepth()
{
	glEnable(GL_DEPTH_TEST);
}
void Window::drawWireframe(bool state)
{
	if (state)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	else
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}
void Window::setCamera(Camera camera)
{
	mCamera = camera;
}
void Window::setResizeable(bool state)
{
	if (state)
	{
		glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	}
	else
	{
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	}
	mIsResizeable = state;
}

bool Window::isResizable(bool state)
{
	return mIsResizeable;
}
void Window::setCullingType(const char* cullType) const
{
	if (cullType == "back")
	{
		glCullFace(GL_BACK);
	}
	else
	{
		glCullFace(GL_FRONT);
	}
}
bool Window::isKeyPressed(unsigned int keycode) const
{
	/*Returns a bool, if the keycode is less than or equal to the MAX_KEYS count return false 
	param keyCode , unsigned int

	*/
	if (keycode >= MAX_KEYS)
	{
		return false;
	}
	return mKeys[keycode];
}
bool Window::isMousePressed(unsigned int button) const
{
	/* Returns a bool, if the button is less than or equal to the MAX_BUTTONS return false
	param button, unsigned int
	return bool
	*/
	if (button >= MAX_BUTTONS)
	{
		return false;
	}
	return mMouseButtons[button];
}
void Window::getMousePosition(double&x, double& y) const
{
	x = mx;
	y = my;
}

void Window::clear() const
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//glClearColor(0.5f, 0.5f, 0.8f, 1.0f);
}
void Window::update()
{
	glfwPollEvents();
	glfwSwapBuffers(mWindow);
}
bool Window::closed() const
{
	return glfwWindowShouldClose(mWindow) == 1;
}
void windowResize(GLFWwindow *window, int width, int height)
{
	//resize the viewport to the width and height, gets called by callback
	glViewport(0, 0, width, height);
}

//////////////////
//   callbacks
//////////////////
void key_callback(GLFWwindow* window, int key, int scanCode, int action, int mods)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->mKeys[key] = action != GLFW_RELEASE;

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			win->mKeys[key] = true;
		else if (action == GLFW_RELEASE)
			win->mKeys[key] = false;
	}
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->mMouseButtons[button] = action != GLFW_RELEASE;
}

void cursor_position_callback(GLFWwindow* window, double xPos, double yPos)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->mx = xPos;
	win->my = yPos;
}
