#pragma once

#include <GL\glew.h>
#include "gameObject.h"
#include "mushrooms.h"
#include "settings.h"

class Bullet: public GameObject
{
public:
	Bullet(Vec spawn);
	~Bullet();

	//returns bullet state (0 moving, -1 reached end of screen, more to come... 
	GLint move(GLfloat tpf);
private:
};

