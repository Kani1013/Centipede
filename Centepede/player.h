#pragma once

#include <GL\glew.h>
#include "renderer.h"
#include "mushrooms.h"
#include "settings.h"

class Player
{
public:
	Player(GLuint fieldSize, Mushrooms* mushrooms);
	virtual ~Player();

	void reDraw(Renderer* renderer);

	void move(GLfloat x, GLfloat y);

	//returns center top position (GLfloat x, GLfloat y) of the player
	GLfloat* getPosition();

private:
	Mushrooms* mushrooms;

	GLfloat fieldSize;
	GLfloat posX, posY, posX1, posX2, posY1, posY2, texX1, texX2, texY1, texY2;

	void initPosition();

	GLfloat collideX(GLfloat movement);
	GLfloat collideY(GLfloat movement);
};