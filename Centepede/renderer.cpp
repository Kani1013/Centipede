#include "renderer.h"

GLfloat Renderer::vertices[] = {
	//Position			//Texture Coords
	0.0f,  0.0f,         0.0f, 0.0f,   // Top Left
	0.0f,  0.0f,         0.0f, 0.0f,   // Top Right
	0.0f,  0.0f,         0.0f, 8.0f,   // Bottom Right
	0.0f,  0.0f,         0.0f, 8.0f    // Bottom Left
};

GLuint Renderer::indices[] = {
	0, 1, 3, // First Triangle
	1, 2, 3  // Second Triangle
};

void Renderer::draw(GLfloat posX1, GLfloat posY1, GLfloat posX2, GLfloat posY2, GLfloat texX1, GLfloat texY1, GLfloat texX2, GLfloat texY2)
{
	//coordinates
	vertices[0] = posX1;
	vertices[1] = posY1;
	vertices[4] = posX2;
	vertices[5] = posY1;
	vertices[8] = posX2;
	vertices[9] = posY2;
	vertices[12] = posX1;
	vertices[13] = posY2;
	//texture coordinates
	vertices[2] = texX1;
	vertices[3] = texY1;
	vertices[6] = texX2;
	vertices[7] = texY1;
	vertices[10] = texX2;
	vertices[11] = texY2;
	vertices[14] = texX1;
	vertices[15] = texY2;
	//draw
	glBindVertexArray(this->VAO);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)(2 * sizeof(GLfloat)));
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

Renderer::Renderer()
{

	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(this->VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// TexCoord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)(2 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0); // Unbind VAO
}


Renderer::~Renderer()
{
}
