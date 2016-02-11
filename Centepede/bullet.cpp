#include "bullet.h"

Bullet::Bullet(GLfloat* position, GLfloat width, Mushrooms* mushrooms)
{
	Bullet::width = width;
	Bullet::mushrooms = mushrooms;
	//initPosition
	Bullet::position = position;
	Bullet::position[0] -= width / 2;
	//left top corner of shot
	fieldPosition = new GLuint[2];
	fieldPosition[0] = (GLuint) position[0];
	fieldPosition[1] = (GLuint) position[1];
	//right top corner of bullet
	fieldPosition2 = new GLuint[2];
	fieldPosition2[0] = (GLuint) (position[0] + width);
	fieldPosition2[1] = (GLuint) position[1];
}


Bullet::~Bullet()
{
}

GLfloat* Bullet::getPosition() {
	return position;
}

GLint Bullet::update(GLfloat tpf)
{
	GLfloat movement = MOVEMENTSPEED * tpf;
	
	position[1] += movement;

	//reached end of screen
	if (position[1] < 0)
	{
		return -1;
	}
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
	}
	else {
		return 0;
	}
}