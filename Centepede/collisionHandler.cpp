#pragma once

#include "collisionHandler.h"

CollisionHandler::CollisionHandler(std::list<GameObject*>* gameObjects)
{
	this->gameObjects = gameObjects;
}

CollisionHandler::~CollisionHandler()
{
}

void CollisionHandler::doCollisionDetection()
{
	for (iteratorOuter = gameObjects->begin(); iteratorOuter != gameObjects->end(); ++iteratorOuter)
	{
		//Check if current GameObject is static. Only moving GameObjects check for collision. (Huge Performance Increase)
		if ( ((*iteratorOuter)->getIsStatic() == GL_FALSE) ) {

			for (iteratorInner = gameObjects->begin(); iteratorInner != gameObjects->end(); ++iteratorInner)
			{
				if (iteratorInner != iteratorOuter) {
					//Check if current GameObjects can collide (Performance increase)
					if ((*iteratorInner)->checkCollidesWith(*iteratorOuter) == GL_TRUE) {

						if (isColliding(*iteratorOuter, *iteratorInner))
						{
							(*iteratorInner)->handleCollision(*iteratorOuter);
							(*iteratorOuter)->handleCollision(*iteratorInner);
						}

					}
				}
			}

		}
	}

}

GLboolean CollisionHandler::isColliding(GameObject* objA, GameObject* objB)
{
	Rect A = objA->getAABB();
	Rect B = objB->getAABB();

	return !(
		A.x2 < B.x1 ||
		B.x2 < A.x1 ||
		A.y2 < B.y1 ||
		B.y2 < A.y1
		);
}