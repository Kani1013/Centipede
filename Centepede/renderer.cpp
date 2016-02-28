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


void Renderer::draw(GameObject* gameObject)
{
	Rect position = gameObject->getPosition();
	Rect texCoords = gameObject->getTexCoords();

	//coordinates
	vertices[0] = position.x1;
	vertices[1] = position.y1;
	vertices[4] = position.x2;
	vertices[5] = position.y1;
	vertices[8] = position.x2;
	vertices[9] = position.y2;
	vertices[12] = position.x1;
	vertices[13] = position.y2;
	//texture coordinates
	vertices[2] = texCoords.x1;
	vertices[3] = texCoords.y1;
	vertices[6] = texCoords.x2;
	vertices[7] = texCoords.y1;
	vertices[10] = texCoords.x2;
	vertices[11] = texCoords.y2;
	vertices[14] = texCoords.x1;
	vertices[15] = texCoords.y2;
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
