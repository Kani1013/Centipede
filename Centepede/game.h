#pragma once

#include <GL\glew.h>

#include "model.h"
#include "view.h"
#include "controller.h"

class Game
{

public:
	Game();
	virtual ~Game();

	bool isRunning();
	void Update(GLfloat tpf);

	void Terminate();

private:
	Game(const Game& other) {}
	void operator=(const Game& other) {}

	Model* model;
	View* view;
	Controller* controller;

	bool shouldClose = false;
};