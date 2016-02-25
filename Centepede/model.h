#pragma once

#include <GL\glew.h>
#include <list>
#include "renderer.h"
#include "centipede.h"
#include "player.h"
#include "bulletManager.h"
#include "mushroomGenerator.h"
#include "collisionHandler.h"


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

	Player* player;

private:
	std::list<GameObject*> gameObjects;
	std::list<GameObject*>::iterator iterator;
	BulletManager* bulletmanager;

	Centipede* centipede;
	MushroomGenerator* mushroomManager;

	CollisionHandler* collisionHandler;

	bool shouldTerminate = false;
};

