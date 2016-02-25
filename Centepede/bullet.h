#pragma once

#include <GL\glew.h>
#include "gameObject.h"
#include "settings.h"

class Bullet: public GameObject
{
public:
	Bullet(Vec spawn);
	~Bullet();

	void update(GLfloat tpf);

	virtual void handleCollision(GameObject* collider);

private:
};

