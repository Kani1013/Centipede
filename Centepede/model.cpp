#include "model.h"

Model::Model()
{
	newGame();
}

Model::~Model()
{
}

GLuint Model::getGameState()
{
	return gameState;
}

void Model::terminate()
{
	gameState = 0;
}

void Model::update(GLfloat tpf)
{
	if (gameState != 2) return;
	if (player->getIsAlive() == GL_FALSE) {
		gameOver();
	}

	noCentipede = GL_TRUE;

	bulletmanager->update(tpf);
	centipedeManager->update(tpf);

	iterator = gameObjects.begin();
	while (iterator != gameObjects.end())
	{
		if ((*iterator)->getIsAlive() == GL_FALSE) {
			iterator = gameObjects.erase(iterator);
		}
		else {
			if ((*iterator)->ID == 2) noCentipede = GL_FALSE;
			(*iterator)->update(tpf);
			iterator++;
		}
	}

	collisionHandler->doCollisionDetection();

	if (noCentipede == GL_TRUE) centipedeManager->spawnCentipede();
}

void Model::reDraw(Renderer *renderer)
{
	for (iterator = gameObjects.begin(); iterator != gameObjects.end(); ++iterator)
	{
		(*iterator)->reDraw(renderer);
	}
}

void Model::shoot()
{
	if (player->getIsAlive() == GL_FALSE) return;

	GameObject *bullet = bulletmanager->shoot();
	if (bullet != nullptr) gameObjects.push_front(bullet);
}


void Model::push_front(GameObject *gameObject)
{
	gameObjects.push_front(gameObject);
}

void Model::push_back(GameObject *gameObject)
{
	gameObjects.push_back(gameObject);
}

void Model::gameOver()
{
	gameState = 1;
	gameObjects.clear();
	mushroomManager->generateEndScreen();
}

void Model::newGame()
{
	gameState = 2;
	gameObjects.clear();

	mushroomManager = new MushroomGenerator(this);
	mushroomManager->generateMushrooms();

	player = new Player();
	gameObjects.push_back(player);

	centipedeManager = new CentipedeManager(this);

	bulletmanager = new BulletManager(player);
	collisionHandler = new CollisionHandler(&gameObjects);
}