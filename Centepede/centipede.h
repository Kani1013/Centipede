#pragma once

#include "GL\glew.h"
#include <list>
#include "renderer.h"
#include "mushrooms.h"
#include "shots.h"
#include "centipedesegment.h"
#include "settings.h"

class Centipede
{
public:
	Centipede(Mushrooms* mushrooms, Shots* shots);
	~Centipede();

	GLuint update(GLfloat tpf);

	void reDraw(Renderer* renderer);

	void createCentipede(GLuint xPos, GLuint length);

private:
	std::list< CentipedeSegment* > segments;
	std::list< CentipedeSegment* >::iterator iterator;

	Mushrooms* mushrooms;
	Shots* shots;
};

