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
		GLint state = (*iterator)->move(tpf);
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

/*GLfloat* Shots::getPosition(GLuint index)
{
	iterator = bullets.begin();
	std::advance(iterator, index);
	return (*iterator)->getPosition();
}*/

void Shots::destroyBullet(GLuint index)
{
	iterator = bullets.begin();
	std::advance(iterator, index);
	bullets.erase(iterator);
}

void Shots::reDraw(Renderer* renderer)
{
	for (iterator = bullets.begin(); iterator != bullets.end(); ++iterator)
	{
		renderer->draw((*iterator));
	}
}

void Shots::shoot()
{
	if (timeUntilNextShot <= 0.0f) {
		timeUntilNextShot = COOLDOWN;
		b = new Bullet(player->getCenter());
		bullets.push_front(b);
	}
}
