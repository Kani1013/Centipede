#pragma once

#include "centipedesegment.h"
#include "mushroom.h"
#include "settings.h"

class Model;

class CentipedeManager
{
public:
	CentipedeManager(Model *model);
	~CentipedeManager();

	void update(GLfloat tpf);

	void spawnCentipede();
	void spawnMushroom(Vec position);

private:
	Model *model;

	CentipedeSegment *previous, *current;
	GLfloat timeUntilNextSpawn;

	CentipedeSegment::Direction direction = CentipedeSegment::LEFT;
};

