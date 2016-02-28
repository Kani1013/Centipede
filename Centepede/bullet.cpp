#include "bullet.h"

Bullet::Bullet(Vec spawn)
{
	Position.x1 = spawn.x - BULLET_WIDTH / 2;
	Position.y1 = spawn.y - BULLET_HEIGHT;
	Position.x2 = Position.x1 + BULLET_WIDTH;
	Position.y2 = spawn.y;

	TexCoords.x1 = 16.0f;
	TexCoords.y1 = 0.0f;
	TexCoords.x2 = 18.0f;
	TexCoords.y2 = 8.0f;

	AABB = Position;

	isStatic = GL_FALSE;
	isAlive = GL_TRUE;
	isVisible = GL_TRUE;
	colliders.mushroom = GL_TRUE;
	colliders.centipede = GL_TRUE;
	ID = 1;
}


Bullet::~Bullet()
{
}

void Bullet::update(GLfloat tpf)
{
	GLfloat movement = BULLET_SPEED * tpf;
	
	Position.y1 += movement;
	Position.y2 = Position.y1 + BULLET_HEIGHT;

	AABB = Position;
	
	//reached end of screen
	if (Position.y1 < 0) isAlive = GL_FALSE;
}

void Bullet::handleCollision(GameObject* collider)
{
	isAlive = GL_FALSE;
}