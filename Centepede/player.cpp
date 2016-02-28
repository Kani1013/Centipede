#include "player.h"

Player::Player()
{
	Position.x1 = (FIELDSIZE / 2);
	Position.y1 = (FIELDSIZE - (AREA / 2)) - (PLAYER_HEIGHT / 2);
	Position.x2 = Position.x1 + PLAYER_WIDTH;
	Position.y2 = Position.y1 + PLAYER_HEIGHT;

	TexCoords.x1 = 0.0f;
	TexCoords.y1 = 0.0f;
	TexCoords.x2 = 16.0f;
	TexCoords.y2 = 16.0f;

	AABB = Position;

	isStatic = GL_FALSE;
	isAlive = GL_TRUE;
	isVisible = GL_TRUE;
	colliders.mushroom = GL_TRUE;
	colliders.centipede = GL_TRUE;
	ID = 3;
}


Player::~Player()
{
}

void Player::update(GLfloat tpf)
{
	GLfloat movementX = playerEventX * MOVEMENT_SPEED * tpf;
	GLfloat movementY = playerEventY * MOVEMENT_SPEED * tpf;

	Position.x1 += movementX;
	if (playerEventX < 0 && Position.x1 < 0) Position.x1 = 0;
	else if (playerEventX > 0 && Position.x1 > FIELDSIZE - PLAYER_WIDTH) Position.x1 = FIELDSIZE - PLAYER_WIDTH;

	Position.y1 += movementY;
	if (playerEventY < 0 && Position.y1 < FIELDSIZE - AREA) Position.y1 = FIELDSIZE - AREA;
	else if (playerEventY > 0 && Position.y1 > FIELDSIZE - PLAYER_HEIGHT) Position.y1 = FIELDSIZE - PLAYER_HEIGHT;

	Position.x2 = Position.x1 + PLAYER_WIDTH;
	Position.y2 = Position.y1 + PLAYER_HEIGHT;

	AABB = Position;
}

void Player::handleCollision(GameObject* collider)
{
	if (collider->ID == 2) {
		isAlive = GL_FALSE;
	}
	else if (collider->ID == 0) {
		//Mushroom collision
		Rect colPos = collider->getPosition();
		GLfloat overlapX = 0;					//Movement does only get restricted in one direction. We have to be able to move along an edge without jumping to the corner!
		GLfloat overlapY = 0;					//Therefore we calculate the smallest overlap and correct it.
		GLfloat deltaX = 0;						//Delta = correction distance. For Error Correction the correction will be ignored if delta is higher than [value]
		GLfloat deltaY = 0;						//This applies when moving along an edge or over a corner.

		//Check Axes:
		overlapX = Position.x2 - colPos.x1;
		if (overlapX > 1) overlapX = colPos.x2 - Position.x1;
		overlapY = Position.y2 - colPos.y1;
		if (overlapY > 1)  overlapY = colPos.y2 - Position.y1;

		if (overlapX < overlapY) {								//Correct X
			if (playerEventX > 0) deltaX = colPos.x1 - PLAYER_WIDTH - Position.x1;
			else				  deltaX = colPos.x2 - Position.x1;

			if (deltaX > -0.4 && deltaX < 0.4) {
				Position.x1 += deltaX;
				Position.x2 = Position.x1 + PLAYER_WIDTH;
			}
		}
		else {													//Correct Y
			if (playerEventY > 0) deltaY = colPos.y1 - PLAYER_HEIGHT - Position.y1;
			else				  deltaY = colPos.y2 - Position.y1;

			if (deltaY > -0.4 && deltaY < 0.4) {
				Position.y1 += deltaY;
				Position.y2 = Position.y1 + PLAYER_HEIGHT;
			}
		}

		//Align AABB
		AABB = Position;
	}
}

GLboolean Player::checkCollidesWith(GameObject* collider)
{
	GLboolean result;
	switch (collider->ID) {
	case 0:
		result = colliders.mushroom;
		if (colliders.mushroom == GL_TRUE) result = (collider->getPosition().y2 > FIELDSIZE - AREA); //Mushrooms beyond players movement area dont need to be checked -> Performance increase
		break;
	case 1:
		result = colliders.bullet;
		break;
	case 2:
		result = colliders.centipede;
		break;
	case 3:
		result = colliders.player;
		break;
	default:
		result = GL_FALSE;
	}
	return result;
}