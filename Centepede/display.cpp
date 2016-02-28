#include "display.h"


Display::Display(int width, int height, const std::string& title)
{

	if (glfwInit() == false)
	{
		std::cerr << "GLFW failed to initialize!" << std::endl;
	}

	glfwWindowHint(GLFW_SAMPLES, 0); //AA
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWmonitor *monitor = NULL;
	if (FULLSCREEN != 0) monitor = glfwGetPrimaryMonitor();


	window = glfwCreateWindow(width, height, title.c_str(), monitor, NULL);	
	if (!window)
	{
		std::cerr << "Window failed to create!" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);

	
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Glew failed to initialize!" << std::endl;
		glfwTerminate();
	}

	
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	
	windowIsClosed = false;
}


Display::~Display()
{
	glfwTerminate();
}

void Display::Clear(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);

}

void Display::Close() {
	windowIsClosed = true;
}

bool Display::isClosed() {
	return windowIsClosed;
}

void Display::Update()
{
	glfwSwapBuffers(window);
	Clear(0, 0, 0, 1);

	glfwPollEvents();
	if (glfwWindowShouldClose(window))
		windowIsClosed = true;
}