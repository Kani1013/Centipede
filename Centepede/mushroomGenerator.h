#pragma once

#include <time.h>
#include <GL\glew.h>
#include "gameObject.h"
#include "mushroom.h"
#include "settings.h"

class Model;


class MushroomGenerator
{
public:
	MushroomGenerator(Model *model);
	~MushroomGenerator();

	void generateMushrooms();
	void generateEndScreen();

private:
	Model *model;
};

