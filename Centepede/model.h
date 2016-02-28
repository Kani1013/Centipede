#pragma once

#include <GL\glew.h>
#include <list>
#include "renderer.h"
#include "centipedeManager.h"
#include "player.h"
#include "bulletManager.h"
#include "mushroomGenerator.h"
#include "collisionHandler.h"


class Model
{
public:
	Model();
	~Model();

	void newGame();

	GLuint getGameState();
	void terminate();

	void update(GLfloat tpf);
	void reDraw(Renderer* renderer);

	void shoot();
	void push_front(GameObject *gameObject);
	void push_back(GameObject *gameObject);

	Player *player;

private:
	std::list<GameObject*> gameObjects;
	std::list<GameObject*>::iterator iterator;

	BulletManager* bulletmanager;
	CentipedeManager *centipedeManager;
	MushroomGenerator* mushroomManager;

	CollisionHandler* collisionHandler;

	void gameOver();
	
	GLuint gameState; //0 = terminated, 1= endscreen (game over), 2 = running

	GLboolean noCentipede;
};

