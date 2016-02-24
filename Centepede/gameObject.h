#pragma once

#include <GL\glew.h>

class Renderer;

struct Rect
{
	//Top Left Corner
	GLfloat x1;
	GLfloat y1;

	//Bottom Right Corner
	GLfloat x2;
	GLfloat y2;
};

struct Vec
{
	GLfloat x;
	GLfloat y;
};

class GameObject
{
	public:
		Rect getAABB()
		{
			return AABB;
		}

		Rect getPosition()
		{
			return Position;
		}

		Rect getTexCoords()
		{
			return TexCoords;
		}

		Vec getCenter() {
			Vec center;
			center.x = Position.x1 + (Position.x2 - Position.x1) / 2;
			center.y = Position.y1 + (Position.y2 - Position.y1) / 2;
			return center;
		}

		void reDraw(Renderer* renderer);

	protected:
		Rect AABB;
		Rect Position;  //propably will be the same as AABB
		Rect TexCoords;

		GLboolean isVisible;
};