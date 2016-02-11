#include "player.h"

void Player::initPosition() {
	posX = fieldSize / 2;
	posY = fieldSize - AREA / 2;
	posX1 = posX - PLAYER_WIDTH / 2;
	posY1 = posY - PLAYER_HEIGHT / 2;
	posX2 = posX + PLAYER_WIDTH / 2;
	posY2 = posY + PLAYER_HEIGHT / 2;
	texX1 = 0.0f;
	texY1 = 80.0f;
	texX2 = 7.0f;
	texY2 = 88.0f;
};

Player::Player(GLuint fieldSize, Mushrooms* mushrooms)
{
	this->fieldSize = (GLfloat) fieldSize;
	this->mushrooms = mushrooms;
	initPosition();
}


Player::~Player()
{
}

GLfloat* Player::getPosition()
{
	GLfloat* position = new GLfloat[2];
	position[0] = posX;
	position[1] = posY;
	return position;
}

void Player::reDraw(Renderer* renderer)
{
	renderer->draw(posX1, posY1, posX2, posY2, texX1, texY1, texX2, texY2);
}

void Player::move(GLfloat x, GLfloat y)
{
	GLfloat movementX = collideX(x * MOVEMENT_SPEED);
	GLfloat movementY = collideY(y * MOVEMENT_SPEED);

	posX += movementX;
	posY += movementY;
	posX1 += movementX;
	posY1 += movementY;
	posX2 += movementX;
	posY2 += movementY;
}

GLfloat Player::collideX(GLfloat movement)
{
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
	else return 0;
}

GLfloat Player::collideY(GLfloat movement)
{
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
	else return 0;
}