#include "centipedesegment.h"

#include <iostream>

CentipedeSegment::CentipedeSegment(GLfloat* position, Type type, GLfloat width, GLfloat height, Mushrooms* mushrooms, Shots* shots)
{
	this->type = type;
	this->xPos = position[0];
	this->yPos = position[1];
	this->width = width;
	this->height = height;
	this->mushrooms = mushrooms;
	this->shots = shots;
	if (type == HEAD) {
		prevDirection = RIGHT;
	}
	else {
		prevDirection = DOWN;
	}
	direction = DOWN;
}


CentipedeSegment::~CentipedeSegment()
{
}

CentipedeSegment::Direction CentipedeSegment::getDirection()
{
	return direction;
}

CentipedeSegment::Direction CentipedeSegment::getPrevDirection()
{
	return prevDirection;
}

GLuint CentipedeSegment::update(GLfloat tpf, CentipedeSegment* prev)
{
	GLfloat delta = 0;
	if (type == HEAD) {
		if (direction == LEFT)
		{
			delta = moveLeft(tpf * CENTIPEDE_SPEED);
			if (delta != 0) {
				if (collideX()) {
						changeDirection(checkY(), delta);
				}
				else {
					changeDirection(LEFT, delta);
				}
			}
		}
		else if (direction == RIGHT)
		{
			delta = moveRight(tpf * CENTIPEDE_SPEED);
			if (delta != 0) {
				if (collideX()) {
					changeDirection(checkY(), delta);
				}
				else {
					changeDirection(RIGHT, delta);
				}
			}
		}
		else if (direction == DOWN)
		{
			delta = moveDown(tpf * CENTIPEDE_SPEED);
			if (delta != 0) {
				if (prevDirection == LEFT) {
					changeDirection(RIGHT, delta);
				}
				else if (prevDirection == RIGHT) {
					changeDirection(LEFT, delta);
				}
			}
		}
		else if (direction == UP)
		{
			delta = moveUp(tpf * CENTIPEDE_SPEED);
			if (delta != 0) {
				if (prevDirection == LEFT) {
					changeDirection(RIGHT, delta);
				}
				else if (prevDirection == RIGHT) {
					changeDirection(LEFT, delta);
				}
			}
		}
	}
	else {

		if (direction == LEFT)
		{
			delta = moveLeft(tpf * CENTIPEDE_SPEED);
			if (delta != 0) {
				if ((GLint) prev->getCoords()[0] >= (GLint) xPos) {
					changeDirection(checkY(), delta);
				}
				else {
					changeDirection(LEFT, delta);
				}
			}
		}
		else if (direction == RIGHT)
		{
			delta = moveRight(tpf * CENTIPEDE_SPEED);
			if (delta != 0) {
				if ((GLint) prev->getCoords()[0] <= (GLint)xPos) {
					changeDirection(checkY(), delta);
				}
				else {
					changeDirection(RIGHT, delta);
				}
			}
		}
		else if (direction == DOWN)
		{
			delta = moveDown(tpf * CENTIPEDE_SPEED);
			if (delta != 0) {
				if (prevDirection == LEFT) {
					changeDirection(RIGHT, delta);
				}
				else if (prevDirection == RIGHT) {
					changeDirection(LEFT, delta);
				}
				else {
					changeDirection(prev->getPrevDirection(), delta);
				}
			}
		}
		else if (direction == UP)
		{
			delta = moveUp(tpf* CENTIPEDE_SPEED);
			if (delta != 0) {
				if (prevDirection == LEFT) {
					changeDirection(RIGHT, delta);
				}
				else if (prevDirection == RIGHT) {
					changeDirection(LEFT, delta);
				}
				else {
					changeDirection(prev->getPrevDirection(), delta);
				}
			}
		}
	}

	if (updateShots()) {
		updateTex();
		return 0;
	}
	else {
		
		return 1;
	}

}

void CentipedeSegment::turnIntoHead()
{
	type = HEAD;
}

GLfloat* CentipedeSegment::getCoords()
{
	GLfloat* coords = new GLfloat[4];
	coords[0] = xPos;
	coords[1] = yPos;
	coords[2] = xTex1;
	coords[3] = yTex1;
	coords[4] = xTex2;
	coords[5] = yTex2;

	return coords;
}

GLuint* CentipedeSegment::getField()
{
	GLuint* field = new GLuint[2];
	field[0] = (GLuint)xPos;
	field[1] = (GLuint)yPos;

	//for mushroom creation only yet
	if (direction == RIGHT && field[0] < 30) field[0] += 1;

	return field;
}

GLfloat CentipedeSegment::moveRight(GLfloat movement)
{
	GLfloat newX = xPos + width + movement;
	GLfloat currentX = xPos + width;

	if ((GLint)currentX == (GLint)newX) {
		xPos += movement;
		return 0.0f;
	}
	else {
		GLfloat canMove = ((GLint)newX) - currentX;
		xPos += canMove;
		return movement - canMove;
	}
}

GLfloat CentipedeSegment::moveLeft(GLfloat movement)
{
	GLfloat newX = xPos - movement;
	GLfloat currentX = xPos;

	if (newX > 0.0f && (GLint)currentX == (GLint)newX) {
		xPos -= movement;
		return 0.0f;
	}
	else {
		if (newX <= 0.0f) {
			xPos = 0;
			return (movement - currentX);
		}
		else {
			GLfloat canMove = currentX - ((GLint)currentX);
			xPos -= canMove;
			return movement - canMove;
		}
	}
}

GLfloat CentipedeSegment::moveUp(GLfloat movement)
{
	GLfloat newY = yPos + movement;
	GLfloat currentY = yPos;

	if (newY > 0 && (GLint)currentY == (GLint)newY) {
		yPos -= movement;
		return 0.0f;
	}
	else {
		GLfloat canMove =  currentY - ((GLint)currentY);
		yPos -= canMove;
		return movement - canMove;
	}
}

GLfloat CentipedeSegment::moveDown(GLfloat movement)
{
	GLfloat newY = yPos + height + movement;
	GLfloat currentY = yPos + height;

	if ((GLint)currentY == (GLint)newY) {
		yPos += movement;
		return 0.0f;
	}
	else {
		GLfloat canMove = ((GLint)newY) - currentY;
		yPos += canMove;
		return movement - canMove;
	}
}

GLboolean CentipedeSegment::collideX()
{
	GLint newX = (GLint)(xPos - 1);
	if (direction == RIGHT) {
		newX = (GLint)(xPos + 1);
	} 

	if (newX > 30 || newX < 0) {
		return true;
	}

	GLuint* field = new GLuint[2];
	field[0] = newX;
	field[1] = (GLuint)yPos;
	
	return (mushrooms->hasMushroom(field) > 0);
}

GLboolean CentipedeSegment::collideY()
{
	return false;
}

CentipedeSegment::Direction CentipedeSegment::checkY()
{
	GLint newY = (GLint)(yPos + 1);

	if (newY > 30) {
		return UP;
	}
	return DOWN;
}

void CentipedeSegment::changeDirection(Direction direction, GLfloat delta) {
	prevDirection = this->direction;
	this->direction = direction;

	if (direction == DOWN) {
		yPos += delta;
	}
	else if (direction == LEFT) {
		xPos -= delta;
	}
	else if (direction == RIGHT) {
		xPos += delta;
	}
	else if (direction == UP) {
		yPos -= delta;
		std::cout << delta << "\n";
	}
}

GLboolean CentipedeSegment::updateShots()
{/*
	GLuint index = shots->getBulletCount(), i = 0;
	GLboolean hitMe = GL_FALSE;

	while (hitMe == GL_FALSE && i < index)
	{
		GLfloat* bulletPosition = shots->getPosition(i);

		if ((bulletPosition[0] + BULLET_WIDTH > xPos)
			&& (bulletPosition[0]				< xPos + width)
			&& (bulletPosition[1]				> yPos)
			&& (bulletPosition[1] < yPos + height)
			)
		{
			hitMe = GL_TRUE;
			shots->destroyBullet(i);
		}
		else {
			i++;
		}
	}

	return !hitMe;*/
	return GL_FALSE;
}

void CentipedeSegment::updateTex()
{
	if (type == HEAD) {
		xTex1 = 0;
		yTex1 = 0;
		xTex2 = 7;
		yTex2 = 8;
	}
	else {
		xTex1 = 0;
		yTex1 = 16;
		xTex2 = 7;
		yTex2 = 24;
	}
	
	if (direction == RIGHT) {
		GLfloat help;
		help = xTex1;
		xTex1 = xTex2;
		xTex2 = help;
		help = yTex1;
		yTex1 = yTex2;
		yTex2 = help;
	}
}