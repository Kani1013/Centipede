#pragma once

#include <GL\glew.h>
#include <wtypes.h>
#include <SOIL\SOIL.h>

#include "model.h"

#include "shader.h"
#include "display.h"
#include "renderer.h"

#define SCREEN_WIDTH GetSystemMetrics(SM_CXSCREEN)
#define SCREEN_HEIGHT GetSystemMetrics(SM_CYSCREEN)
#define VERTEX_SHADER "vertex.shader"
#define FRAGMENT_SHADER "fragment.shader"
#define SPRITE_SHEET "centipedeSprites.jpg"

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

