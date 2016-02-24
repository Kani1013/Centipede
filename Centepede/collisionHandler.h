#pragma once

#include <GL\glew.h>
#include "gameObject.h"

class CollisionHandler
{
	public:

		void doCollisionDetection();


	private:

		GLboolean isColliding(GameObject* objA, GameObject* objB)
		{
			Rect A = objA->getAABB();
			Rect B = objB->getAABB();

			return !(
						A.x2 < B.x1 ||
						B.x2 < A.x1 ||
						A.y2 < B.y1 ||
						B.y2 < A.y1
					);
		};

};