#include "model.h"

Model::Model()
{
	mushrooms = new Mushrooms(FIELDSIZE);
	player = new Player();
	shots = new Shots(player, mushrooms);
	centipede = new Centipede(mushrooms, shots);

	centipede->createCentipede(15, 7);
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
	//update shots
	shots->update(tpf);

	//update centipede position (destruction of segments gets updated through method calls of shots)
	centipede->update(tpf);

	//try to move player
	if (playerEventX != 0 || playerEventY != 0)
		player->move(playerEventX * tpf, playerEventY * tpf);


}

void Model::reDraw(Renderer* renderer)
{
	mushrooms->reDraw(renderer);
	centipede->reDraw(renderer);
	shots->reDraw(renderer);
	player->reDraw(renderer);
}

void Model::shoot()
{
	shots->shoot();
}