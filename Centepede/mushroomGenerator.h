#pragma once

#include <time.h>
#include <GL\glew.h>
#include <list>
#include "gameObject.h"
#include "mushroom.h"
#include "settings.h"


class MushroomGenerator
{
public:
	MushroomGenerator();
	~MushroomGenerator();

	std::list<GameObject*> getMushrooms();

private:

	std::list<GameObject*> mushrooms;
};

