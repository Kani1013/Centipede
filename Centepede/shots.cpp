#include "shots.h"

Shots::Shots(Player* player, Mushrooms* mushrooms)
{
	this->player = player;
	this->mushrooms = mushrooms;
}


Shots::~Shots()
{
}

GLuint Shots::update(GLfloat tpf)
{
	timeUntilNextShot -= tpf;

	iterator = bullets.begin();
	while (iterator != bullets.end())
	{
		GLint state = (*iterator)->update(tpf);
		if (state != 0)
		{
			iterator = bullets.erase(iterator);
		}
		else {
			iterator++;
		}
	}

	return 0;
}

GLuint Shots::getBulletCount()
{
	return bullets.size();
}

GLfloat* Shots::getPosition(GLuint index)
{
	iterator = bullets.begin();
	std::advance(iterator, index);
	return (*iterator)->getPosition();
}

void Shots::destroyBullet(GLuint index)
{
	iterator = bullets.begin();
	std::advance(iterator, index);
	bullets.erase(iterator);
}

void Shots::reDraw(Renderer* renderer)
{
	GLfloat* position;

	for (iterator = bullets.begin(); iterator != bullets.end(); ++iterator)
	{
		position = (*iterator)->getPosition();
		renderer->draw(position[0], position[1], position[0] + SHOT_WIDTH, position[1] + SHOT_HEIGHT, texX1, texY1, texX2, texY2);
	}
}

void Shots::shoot()
{
	if (timeUntilNextShot <= 0.0f) {
		timeUntilNextShot = COOLDOWN;
		b = new Bullet(player->getPosition(), SHOT_WIDTH, mushrooms);
		bullets.push_front(b);
	}
}
