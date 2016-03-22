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
	
	
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	// create the window
	mWindow = glfwCreateWindow(mWidth, mHeight, mTitle, NULL, NULL);
	if (!mWindow)
	{
		std::cout << "Could not load GLFW window" << std::endl;
		return false;
	}
			
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
}
void Window::update()
{
	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		std::cout << "Open GL Window Error" << error << std::endl;
	}
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
