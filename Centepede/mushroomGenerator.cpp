#include "mushroomGenerator.h"

MushroomGenerator::MushroomGenerator()
{
	srand((GLuint) time(NULL));
	GLuint chance = DENSITY;
	Vec position;
	Mushroom* mushroom = nullptr;

	for (int col = 0; col < FIELDSIZE; col++) {
		position.x = (GLfloat) col;
		//don't generate mushrooms in players area initially
		for (int row = 0; row < FIELDSIZE; row++) {
			position.y = (GLfloat) row;
			if (row > 0 && row < FIELDSIZE - 4)  //AREA
			{
				if (chance > 0 && (rand() % 100) < (GLint) chance) {
					mushroom = new Mushroom(position);
					mushrooms.push_back(mushroom);
				}
			}
		}
	}

}

std::list<GameObject*> MushroomGenerator::getMushrooms() {
	return mushrooms;
}

MushroomGenerator::~MushroomGenerator()
{
}