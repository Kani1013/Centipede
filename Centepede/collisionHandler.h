#pragma once

#include <GL\glew.h>
#include <list>
#include "gameObject.h"

class CollisionHandler
{
	public:

		CollisionHandler(std::list<GameObject*>* gameObjects);
		~CollisionHandler();

		void doCollisionDetection();


	private:

		GLboolean isColliding(GameObject* objA, GameObject* objB);

		std::list<GameObject*>* gameObjects;
		std::list<GameObject*>::iterator iteratorOuter;
		std::list<GameObject*>::iterator iteratorInner;
};