#pragma once

#include "GL\glew.h"
#include "renderer.h"
#include "player.h"
#include "mushrooms.h"
#include "bullet.h"
#include <list>

class Shots
{
public:
	Shots(Player* player, Mushrooms* mushrooms);
	~Shots();

	// updates all shots and returns amount of points that were scored in this update cycle
	GLuint update(GLfloat tpf);

	void reDraw(Renderer* renderer);
	GLuint getBulletCount();
	//GLfloat* getPosition(GLuint index);
	void destroyBullet(GLuint index);

	void shoot();

private:

	Player* player;
	Mushrooms* mushrooms;

	GLfloat texX1 = 11.0f, texY1 = 82.0f, texX2 = 12.0f, texY2 = 86.0f;

	GLfloat* bulletSize;
	Bullet* b;
	std::list<Bullet*> bullets;
	std::list<Bullet*>::iterator iterator;

	GLfloat timeUntilNextShot = 0.0;
};

