#pragma once

#include <GL\glew.h>

class Renderer;

struct CollidesWith
{
	GLboolean mushroom;
	GLboolean bullet;
	GLboolean centipede;
	GLboolean player;
};

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

		GLboolean getIsStatic()
		{
			return isStatic;
		}

		GLboolean getIsAlive()
		{
			return isAlive;
		}

		void reDraw(Renderer* renderer);

		virtual void update(GLfloat tpf)
		{
			return;
		}

		virtual GLboolean checkCollidesWith(GameObject* collider)
		{
			GLboolean result;
			switch (collider->ID) {
				case 0: 
					result = colliders.mushroom;
					break;
				case 1:
					result = colliders.bullet;
					break;
				case 2:
					result = colliders.centipede;
					break;
				case 3:
					result = colliders.player;
					break;
				default:
					result = GL_FALSE;
			}
			return result;
		}

		virtual void handleCollision(GameObject* collider)
		{
			return;
		}

		GLuint ID;		//Gameobject ID: 0=Mushroom, 1=Bullet, 2=Centipede, 3=Player

	protected:
		Rect AABB;
		Rect Position;  //propably will be the same as AABB
		Rect TexCoords;

		CollidesWith colliders;

		GLboolean isVisible;
		GLboolean isStatic;
		GLboolean isAlive;
		
};