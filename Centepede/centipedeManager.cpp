#include "centipedeManager.h"
#include "model.h"


CentipedeManager::CentipedeManager(Model *model)
{
	this->model = model;
}

void CentipedeManager::spawnCentipede()
{
	if (CENTIPEDE_LENGTH < 1) return;

	Vec spawnpoint;
	spawnpoint.x = (GLuint)(FIELDSIZE / 2);
	spawnpoint.y = -1;
	current = nullptr;
	CentipedeSegment::Direction direction = CentipedeSegment::LEFT;

	//Start creating segments
	for (GLuint i = 0; i < CENTIPEDE_LENGTH; i++) {
		previous = current;
		current = new CentipedeSegment(spawnpoint, previous, this, direction);
		if (previous != nullptr) previous->setFollowing(current);
		model->push_back(current);
		spawnpoint.y -= 1;

		switch (direction)
		{
		case CentipedeSegment::LEFT:
			direction = CentipedeSegment::RIGHT;
			break;
		default:
			direction = CentipedeSegment::LEFT;
			break;
		}
	}

	current->setFollowing(nullptr);
}

CentipedeManager::~CentipedeManager()
{
}

void CentipedeManager::update(GLfloat tpf)
{
	timeUntilNextSpawn -= tpf;
	if (timeUntilNextSpawn <= 0) {
		spawnCentipede();
		timeUntilNextSpawn = CENTI_SPAWN_INTERVAL_S;
	}
}

void CentipedeManager::spawnMushroom(Vec position) {
	if (position.y < 1 || position.y > FIELDSIZE) return;
	//GLuint x = position.x;
	//GLuint y = position.y;
	model->push_back(new Mushroom(position));
}
