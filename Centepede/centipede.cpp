#include "centipede.h"
#include <iostream>


Centipede::Centipede()
{
}


Centipede::~Centipede()
{
}

	/*
void Centipede::createCentipede(GLuint xPos, GLuint length)
{
	GLfloat* position = new GLfloat[2];
	position[0] = (GLfloat)xPos;
	position[1] = 0.0f;

	segments.push_front(
		new CentipedeSegment(position, CentipedeSegment::HEAD, CENTISEGMENT_WIDTH, CENTISEGMENT_HEIGHT, mushrooms)
	);
	position[1] += 1;

	for (GLuint i = 1; i <= length; i++) {
		position[1] = (float) i;
		position[1] *= -1;
		segments.push_back(
			new CentipedeSegment(position, CentipedeSegment::BODY, CENTISEGMENT_WIDTH, CENTISEGMENT_HEIGHT, mushrooms)
		);
	}
}

GLuint Centipede::update(GLfloat tpf)
{
	/*
	iterator = segments.begin();
	CentipedeSegment* centiseg = nullptr;
	while (iterator != segments.end())
	{
		GLint state = (*iterator)->update(tpf, centiseg);
		centiseg = (*iterator);
		if (state != 0)
		{
			//was hit: create mushroom
//			mushrooms->createMushroom((*iterator)->getField());
			iterator = segments.erase(iterator);
			if (iterator != segments.end())	(*iterator)->turnIntoHead();
			centiseg = nullptr;

			if (segments.size() == 0) {
				createCentipede(15, 7);
			}
		}
		else {
			iterator++;
		}
	}
	return 0;
}
	*/