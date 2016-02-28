#pragma once

#include "GL\glew.h"
#include "gameObject.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	void draw(GameObject* gameObject);

private:

	static GLfloat vertices[];
	static GLuint indices[];
	GLuint VBO, VAO, EBO;
};

