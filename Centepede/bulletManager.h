#pragma once

#include "bullet.h"

class BulletManager
{
public:
	BulletManager(GameObject* player);
	~BulletManager();

	GameObject* shoot();

	void update(GLfloat tpf);

private:
	GameObject *player, *bullet;
	GLfloat timeUntilNextShot = 0.0;
};

