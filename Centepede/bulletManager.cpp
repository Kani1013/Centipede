#include "bulletManager.h"



BulletManager::BulletManager(GameObject* player)
{
	this->player = player;
}


BulletManager::~BulletManager()
{
}

GameObject* BulletManager::shoot()
{
	bullet = nullptr;
	if (timeUntilNextShot <= 0.0f) {
		timeUntilNextShot = COOLDOWN;
		bullet = new Bullet(player->getCenter());
	}
	return bullet;
}

void BulletManager::update(GLfloat tpf)
{
	timeUntilNextShot -= tpf;
}