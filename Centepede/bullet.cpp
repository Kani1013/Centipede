#include "bullet.h"

Bullet::Bullet(Vec spawn)
{
	Position.x1 = spawn.x - BULLET_WIDTH / 2;
	Position.y1 = spawn.y;
	Position.x2 = Position.x1 + BULLET_WIDTH;
	Position.y2 = Position.y1 + BULLET_HEIGHT;

	TexCoords.x1 = 11.0f;
	TexCoords.y1 = 82.0f;
	TexCoords.x2 = 12.0f;
	TexCoords.y2 = 86.0f;

	AABB = Position;
}


Bullet::~Bullet()
{
}

GLint Bullet::move(GLfloat tpf)
{
	GLfloat movement = BULLET_SPEED * tpf;
	
	Position.y1 += movement;
	Position.y2 = Position.y1 + BULLET_HEIGHT;

	AABB = Position;
	

	//reached end of screen
	if (Position.y1 < 0)
	{
		return -1;
	}

	return 0;



	/*
	//is on new field (check for mushroom hit)
	else if ((GLuint) position[1] != fieldPosition[1])
	{
		fieldPosition[1] = (GLuint) position[1];
		if (mushrooms->hasMushroom(fieldPosition) > 0) {//check left corner of bullet for hit
			mushrooms->hitMushroom(fieldPosition);
			return 1;
		}
		else if (fieldPosition2[0] != fieldPosition[0] ) {		//if left corner of bullet didn't hit mushroom then maybe the right corner still could
			fieldPosition2[1] = fieldPosition[1];
			if (mushrooms->hasMushroom(fieldPosition2) > 0) {
				mushrooms->hitMushroom(fieldPosition2);
				return 1;
			}
			//didn't hit a mushroom
			return 0;
		}
		else { //left and right corner are in the same tile
			return 0;
		}
	}*/

}