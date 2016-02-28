#pragma once

#include <GL\glew.h>
#include <wtypes.h>
#include <SOIL\SOIL.h>

#include "model.h"

#include "shader.h"
#include "display.h"
#include "renderer.h"
#include "settings.h"

class View
{
public:
	View(Model* model);
	~View();


	void rePaint();
	bool isClosed();

private:
	Renderer* renderer;
	Model* model;
	Display* display;
	Shader* shader;

	GLuint texture;
	int TextureWidth, TextureHeight;

	void loadSpriteSheet();
};

