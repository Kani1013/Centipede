#include "model.h"

Model::Model()
{
	mushroomManager = new MushroomGenerator();
	std::list<GameObject*> mushrooms = mushroomManager->getMushrooms();
	gameObjects.insert(gameObjects.end(), mushrooms.begin(), mushrooms.end());

	player = new Player();
	gameObjects.push_back(player);


	//centipede = new Centipede(mushroomManager, shots);

	//centipede->createCentipede(15, 7);

	bulletmanager = new BulletManager(player);
	collisionHandler = new CollisionHandler(&gameObjects);
}

Model::~Model()
{
}

bool Model::isRunning()
{
	return !shouldTerminate;
}

void Model::terminate()
{
	shouldTerminate = true;
}

void Model::update(GLfloat tpf)
{
	bulletmanager->update(tpf);

	//update centipede position (destruction of segments gets updated through method calls of shots)
	//centipede->update(tpf);

	for (iterator = gameObjects.begin(); iterator != gameObjects.end(); ++iterator)
	{
		(*iterator)->update(tpf);

		if ((*iterator)->getIsAlive() == GL_FALSE) {
			iterator = gameObjects.erase(iterator);
		}
	}

	collisionHandler->doCollisionDetection();
}

void Model::reDraw(Renderer *renderer)
{
	//centipede->reDraw(renderer);

	for (iterator = gameObjects.begin(); iterator != gameObjects.end(); ++iterator)
	{
		(*iterator)->reDraw(renderer);
	}
}

void Model::shoot()
{
	GameObject *bullet = bulletmanager->shoot();
	if (bullet != nullptr) gameObjects.push_front(bullet);
}