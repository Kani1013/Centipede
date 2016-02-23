#pragma once

#include <stdlib.h>
#include <time.h>
#include <GL\glew.h>
#include <vector>
#include "renderer.h"
#include "settings.h"


class Mushrooms
{
public:
	Mushrooms(GLuint fieldsize);
	~Mushrooms();

	void reDraw(Renderer* renderer);

	GLuint hasMushroom(GLuint* field);
	void hitMushroom(GLuint* field);
	void createMushroom(GLuint* field);

private:

	std::vector< std::vector<GLuint> > mushrooms;

	GLfloat posX1, posX2, posY1, posY2, texX, texX1, texX2, texY, texY1, texY2;
};

