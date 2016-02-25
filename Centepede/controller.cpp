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
	if (glfwGetKey(glfwGetCurrentContext(), CLOSE_GAME) == GLFW_PRESS)
		Controller::model->terminate();

	//Check for player movement
	GLfloat playerX = 0;
	GLfloat playerY = 0;
	if (glfwGetKey(glfwGetCurrentContext(), MOVE_LEFT) == GLFW_PRESS)
		playerX -= 1;
	if (glfwGetKey(glfwGetCurrentContext(), MOVE_RIGHT) == GLFW_PRESS)
		playerX += 1;
	if (glfwGetKey(glfwGetCurrentContext(), MOVE_UP) == GLFW_PRESS)
		playerY -= 1;
	if (glfwGetKey(glfwGetCurrentContext(), MOVE_DOWN) == GLFW_PRESS)
		playerY += 1;
	model->player->playerEventX = playerX;
	model->player->playerEventY = playerY;

	//Check for shooting
	if (glfwGetKey(glfwGetCurrentContext(), SHOOT) == GLFW_PRESS)
		model->shoot();
		
}