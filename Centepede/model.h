#pragma once

#include <GL\glew.h>

#include "renderer.h"
#include "centipede.h"
#include "player.h"
#include "shots.h"
#include "mushrooms.h"


class Model
{
public:
	Model();
	~Model();

	bool isRunning();
	void terminate();

	void update(GLfloat tpf);
	void reDraw(Renderer* renderer);

	void shoot();

	GLfloat playerEventX = 0;	// 0 do nothing, 1 try move right, -1 try move left
	GLfloat playerEventY = 0;	// 0 do nothing, 1 try move down,  -1 try move up

private:
	Centipede* centipede;
	Player* player;
	Shots* shots;
	Mushrooms* mushrooms;

	bool shouldTerminate = false;
};

