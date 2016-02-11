#pragma once

#include <GL\glew.h>
#include "mushrooms.h"

#define MOVEMENTSPEED -20.0f

class Bullet
{
public:
	Bullet(GLfloat* position, GLfloat width, Mushrooms* mushrooms);
	~Bullet();

	//returns bullet state (0 moving, -1 reached end of screen, more to come... 
	GLint update(GLfloat tpf);

	GLfloat* getPosition();

private:
	GLfloat* position;
	GLuint* fieldPosition;
	GLuint* fieldPosition2;

	GLfloat width;

	Mushrooms* mushrooms;
};

