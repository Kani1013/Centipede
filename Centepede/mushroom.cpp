#include "mushroom.h"

Mushroom::Mushroom(Vec fieldPosition)
{
	init(fieldPosition, 4);
}

Mushroom::Mushroom(Vec fieldPosition, GLuint state)
{
	init(fieldPosition, state);
}

void Mushroom::init(Vec fieldPosition, GLuint state)
{
	Position.x1 = (GLfloat)((GLuint) fieldPosition.x);
	Position.y1 = (GLfloat)((GLuint) fieldPosition.y);
	Position.x2 = Position.x1 + 1;
	Position.y2 = Position.y1 + 1;

	AABB = Position;

	this->state = state;

	updateTexCoord();

	isStatic = GL_TRUE;
	isAlive = GL_TRUE;
	colliders.player = GL_TRUE;
	colliders.centipede = GL_TRUE;
	colliders.bullet = GL_TRUE;
	ID = 0;
}


Mushroom::~Mushroom()
{
}

void Mushroom::updateTexCoord()
{
	if (state == 0) isVisible = GL_FALSE;
	else {
		isVisible = GL_TRUE;

		TexCoords.x1 = (GLfloat) 64 - (state * 16);
		TexCoords.y1 = 16;
		TexCoords.x2 = (GLfloat) 80 - (state * 16);
		TexCoords.y2 = 32;
	}
}


void Mushroom::handleCollision(GameObject* collider)
{
	if (collider->ID == 1 && collider->getIsAlive()) {
		state -= 1;
		updateTexCoord();

		if (state == 0) isAlive = GL_FALSE;
	}
}