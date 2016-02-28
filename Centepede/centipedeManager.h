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

	void spawnMushroom(Vec position);

private:
	void spawnCentipede();
	Model *model;

	CentipedeSegment *previous, *current;
	GLfloat timeUntilNextSpawn;
};

