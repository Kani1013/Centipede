#pragma once

#include "GL\glew.h"
#include "gameObject.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	void draw(GameObject* gameObject);
	void draw(GLfloat posX1, GLfloat posY1, GLfloat posX2, GLfloat posY2, GLfloat texX1, GLfloat texY1, GLfloat texX2, GLfloat texY2);

private:

	static GLfloat vertices[];
	static GLuint indices[];
	GLuint VBO, VAO, EBO;
};

