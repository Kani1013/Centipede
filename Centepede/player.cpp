#include "player.h"

void Player::initPosition() {
	Position.x1 = (FIELDSIZE / 2) - (PLAYER_WIDTH / 2);
	Position.y1 = (FIELDSIZE - (AREA / 2)) - (PLAYER_HEIGHT / 2);
	Position.x2 = Position.x1 + PLAYER_WIDTH;
	Position.y2 = Position.y1 + PLAYER_HEIGHT;

	TexCoords.x1 = 0.0f;
	TexCoords.y1 = 80.0f;
	TexCoords.x2 = 7.0f;
	TexCoords.y2 = 88.0f;

	AABB = Position;
};

Player::Player()
{
	initPosition();
}


Player::~Player()
{
}

void Player::move(GLfloat x, GLfloat y)
{
	GLfloat movementX = x * MOVEMENT_SPEED;
	GLfloat movementY = y * MOVEMENT_SPEED;

	Position.x1 += movementX;
	if (x < 0 && Position.x1 < 0) Position.x1 = 0;
	else if (x > 0 && Position.x1 > FIELDSIZE - PLAYER_WIDTH) Position.x1 = FIELDSIZE - PLAYER_WIDTH;

	Position.y1 += movementY;
	if (y < 0 && Position.y1 < FIELDSIZE - AREA) Position.y1 = FIELDSIZE - AREA;
	else if (y > 0 && Position.y1 > FIELDSIZE - PLAYER_HEIGHT) Position.y1 = FIELDSIZE - PLAYER_HEIGHT;

	Position.x2 = Position.x1 + PLAYER_WIDTH;
	Position.y2 = Position.y1 + PLAYER_HEIGHT;

	AABB = Position;
}

GLfloat Player::collideX(GLfloat movement)
{
	/*
	GLuint mushroom = 0;
	GLuint* field = new GLuint[2];
	//check right
	if (movement > 0)
	{
		GLfloat newPosX2 = posX2 + movement;
		//1. check for Fieldborder
		if (newPosX2 > fieldSize) return fieldSize - posX2 - 0.0001;
		//2. check for centipede
		//3. check for mushrooms
		else if ((GLuint)newPosX2 > (GLuint)posX2) {
			field[0] = (GLuint)newPosX2;
			field[1] = (GLuint)posY1;
			mushroom += mushrooms->hasMushroom(field);
			field[1] = (GLuint)posY2;
			mushroom += mushrooms->hasMushroom(field);
			if (mushroom > 0) return (GLuint)newPosX2 - posX2 - 0.0001;
		}
		//4. no collision
		return movement;
	}
	//check left
	else if (movement < 0)
	{
		GLfloat newPosX1 = posX1 + movement;
		//1. check for Fieldborder
		if (newPosX1 < 0) return - posX1;
		//2. check for centipede
		//3. check for mushrooms
		else if ((GLuint)newPosX1 < (GLuint)posX1) {
			field[0] = (GLuint)newPosX1;
			field[1] = (GLuint)posY1;
			mushroom += mushrooms->hasMushroom(field);
			field[1] = (GLuint)posY2;
			mushroom += mushrooms->hasMushroom(field);
			if (mushroom > 0) return (GLuint)posX1 - posX1;
		}
		//4. no collision
		return movement;
	}
	else return 0;*/
	return movement;
}

GLfloat Player::collideY(GLfloat movement)
{
	/*
	GLuint mushroom = 0;
	GLuint* field = new GLuint[2];
	//check bottom
	if (movement > 0)
	{
		GLfloat newPosY2 = posY2 + movement;
		//1. check for Fieldborder
		if (newPosY2 > fieldSize) return fieldSize - posY2 - 0.0001;
		//2. check for centipede
		//3. check for mushrooms
		else if ((GLuint)newPosY2 > (GLuint)posY2) {
			field[0] = (GLuint)posX1;
			field[1] = (GLuint)newPosY2;
			mushroom += mushrooms->hasMushroom(field);
			field[0] = (GLuint)posX2;
			mushroom += mushrooms->hasMushroom(field);
			if (mushroom > 0) return (GLuint) newPosY2 - posY2 - 0.0001;
		}
		//4. no collision
		return movement;
	}
	//check top
	else if (movement < 0)
	{
		GLfloat newPosY1 = posY1 + movement;
		//1. check for Fieldborder
		if (newPosY1 < fieldSize - AREA) return fieldSize - AREA - posY1;
		//2. check for centipede
		//3. check for mushrooms
		else if ((GLuint)newPosY1 < (GLuint)posY1) {
			field[0] = (GLuint)posX1;
			field[1] = (GLuint)newPosY1;
			mushroom += mushrooms->hasMushroom(field);
			field[0] = (GLuint)posX2;
			mushroom += mushrooms->hasMushroom(field);
			if (mushroom > 0) return (GLuint) posY1 - posY1;
		}
		//4. no collision
		return movement;
	}
	else return 0;*/
	return movement;
}