#pragma once

#include "GL\glew.h"
#include "GLFW\glfw3.h"

#include "model.h"


class Controller
{
public:
	Controller(Model* model);
	~Controller();

	void pollEvents();

private:
	Model* model;
};

