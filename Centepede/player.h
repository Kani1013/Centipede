#pragma once

#include <GL\glew.h>
#include "gameObject.h"
#include "settings.h"

class Player: public GameObject
{
public:
	Player();
	virtual ~Player();

	void update(GLfloat tpf);

	virtual GLboolean checkCollidesWith(GameObject* collider);

	virtual void handleCollision(GameObject* collider);

	GLfloat playerEventX = 0;	// 0 do nothing, 1 move right, -1 move left
	GLfloat playerEventY = 0;	// 0 do nothing, 1 move down,  -1 move up

};