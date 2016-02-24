#pragma once

#include <GL\glew.h>
#include "gameObject.h"
#include "renderer.h"
#include "settings.h"

class Player: public GameObject
{
public:
	Player();
	virtual ~Player();

	void move(GLfloat x, GLfloat y);

private:
	void initPosition();

	//Checks for movementBorder
	GLfloat collideX(GLfloat movement);
	//Checks for movementBorder
	GLfloat collideY(GLfloat movement);
};