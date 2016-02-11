#include "controller.h"

Controller::Controller(Model* model)
{
	Controller::model = model;
}

Controller::~Controller()
{
}

void Controller::pollEvents()
{
	glfwPollEvents();

	//window closed
	if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		Controller::model->terminate();

	//Check for player movement
	GLfloat playerX = 0;
	GLfloat playerY = 0;
	if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_LEFT) == GLFW_PRESS)
		playerX -= 1;
	if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_RIGHT) == GLFW_PRESS)
		playerX += 1;
	if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_UP) == GLFW_PRESS)
		playerY -= 1;
	if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_DOWN) == GLFW_PRESS)
		playerY += 1;
	model->playerEventX = playerX;
	model->playerEventY = playerY;

	//Check for shooting
	if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_SPACE) == GLFW_PRESS)
		model->shoot();
		
}