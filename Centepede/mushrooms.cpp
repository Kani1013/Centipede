#include "mushrooms.h"

Mushrooms::Mushrooms(GLuint fieldsize)
{
	mushrooms = std::vector< std::vector<GLuint> >(fieldsize, std::vector<GLuint> (fieldsize, 0) );
	srand(time(NULL));
	GLuint chance = DENSITY;

	for (int col = 0; col < fieldsize; col++) {
		//don't generate mushrooms in players area initially
		for (int row = 0; row < fieldsize; row++) {
			if (row > 0 && row < fieldsize - 4)  //AREA
			{
				if (chance > 0 && (rand() % 100) < chance) {
					mushrooms[col][row] = 4;
				}
			}
		}
	}
}

GLuint Mushrooms::hasMushroom(GLuint* field)
{
	return mushrooms[field[0]][field[1]];
}

void Mushrooms::hitMushroom(GLuint* field)
{
	mushrooms[field[0]][field[1]]--;
}

void Mushrooms::createMushroom(GLuint* field)
{
	if (field[0] > 0 && field[0] < FIELDSIZE && field[1] > 1 && field[1] < FIELDSIZE)
	{
		mushrooms[field[0]][field[1]] = 4;
	}
}

Mushrooms::~Mushrooms()
{
}

void Mushrooms::reDraw(Renderer* renderer)
{
	for (int col = 0; col < mushrooms.size(); col++) {
		for (int row = 0; row < mushrooms[0].size(); row++) {
			GLuint mushroom = mushrooms[col][row];
			if (mushroom > 0) {
				//coordinates
				posX1 = col;
				posY1 = row;
				posX2 = col + 1;
				posY2 = row + 1;
				//texture coordinates
				texX = 96;
				texY = 0;
				texX1 = texX - (mushroom * 8);
				texY1 = texY;
				texX2 = texX - (mushroom * 8) + 8;
				texY2 = texY + 8;
				//draw
				renderer->draw(posX1, posY1, posX2, posY2, texX1, texY1, texX2, texY2);
			}
		}
	}
}
