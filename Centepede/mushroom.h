#pragma once

#include "gameObject.h"

class Mushroom: public GameObject
{

public:
	Mushroom(Vec fieldPosition);
	Mushroom(Vec fieldPosition, GLuint state);

	~Mushroom();

	virtual void handleCollision(GameObject* collider);

private:
	GLuint state; // 0 - 4

	void updateTexCoord();

	void init(Vec fieldPosition, GLuint State);
};

