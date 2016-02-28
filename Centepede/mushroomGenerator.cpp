#include "mushroomGenerator.h"
#include "model.h"

MushroomGenerator::MushroomGenerator(Model *model)
{
	this->model = model;
}

void MushroomGenerator::generateMushrooms() {
	srand((GLuint)time(NULL));
	GLuint chance = DENSITY;
	Vec position;
	Mushroom* mushroom = nullptr;

	for (int col = 0; col < FIELDSIZE; col++) {
		position.x = (GLfloat)col;
		//don't generate mushrooms in players area initially
		for (int row = 0; row < FIELDSIZE; row++) {
			position.y = (GLfloat)row;
			if (row > 0 && row < FIELDSIZE - AREA)
			{
				if (chance > 0 && (rand() % 100) < (GLint)chance) {
					mushroom = new Mushroom(position);
					model->push_back(mushroom);
				}
			}
		}
	}
}

void MushroomGenerator::generateEndScreen()
{
	Vec position;     //
	GLfloat absX = (FIELDSIZE - 21) / 2;
	GLfloat absY = (FIELDSIZE - 12) / 2;

	GLuint gameOver[12][21] = {
		{ 0,1,1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,1,1,1 },
		{ 1,0,0,0,0,0,1,0,1,0,0,1,1,0,1,1,0,1,0,0,0 },
		{ 1,0,1,1,0,0,1,0,1,0,0,1,0,1,0,1,0,1,1,1,0 },
		{ 1,0,0,1,0,1,1,1,1,1,0,1,0,0,0,1,0,1,0,0,0 },
		{ 0,1,1,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,1,1,1 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,1,1,0,0,1,0,0,0,1,0,1,1,1,1,0,1,1,1,0,0 },
		{ 1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,1,0 },
		{ 1,0,0,1,0,1,0,0,0,1,0,1,1,1,0,0,1,1,1,0,0 },
		{ 1,0,0,1,0,0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,0 },
		{ 0,1,1,0,0,0,0,1,0,0,0,1,1,1,1,0,1,0,0,1,0 },
	};

	for (GLuint row = 0; row < 12; row++) {
		position.y = row + absY;
		for (GLuint col = 0; col < 21; col++) {
			position.x = col + absX;
			if (gameOver[row][col] == 1) model->push_back(new Mushroom(position));
		}
	}
}