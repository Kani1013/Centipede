#pragma once

#include "GL\glew.h"
#include "renderer.h"
#include "mushroomGenerator.h"
#include "bullet.h"
#include "settings.h"

class CentipedeSegment
{
public:
	enum Type : GLuint {
		HEAD,
		BODY
	};

	enum Direction : GLuint {
		LEFT,
		RIGHT,
		DOWN,
		UP
	};

	CentipedeSegment(GLfloat* position, Type type, GLfloat width, GLfloat height, MushroomGenerator* mushrooms);
	~CentipedeSegment();

	Direction getDirection();
	Direction getPrevDirection();

	GLuint update(GLfloat tpf, CentipedeSegment* prev);
	GLfloat* getCoords();
	void turnIntoHead();

	GLuint* getField();

private:

	Direction direction, prevDirection;
	Type type;
	GLfloat xPos, yPos, width, height, xTex1 = 0, yTex1 = 0, xTex2 = 0, yTex2 = 0;

	MushroomGenerator* mushrooms;


	//Return 0 if movement was in same field. If entering new field it returns the movement distance remaining to move in new field which may be another direction
	GLfloat moveRight(GLfloat movement);
	GLfloat moveLeft(GLfloat movement);
	GLfloat moveUp(GLfloat movement);
	GLfloat moveDown(GLfloat movement);

	//return true if not hit by a shot, false when hit
	GLboolean updateShots();

	void changeDirection(Direction direction, GLfloat delta);

	GLboolean collideX();
	GLboolean collideY();
	Direction checkY();

	void updateTex();
};

