#pragma once

#include "GL\glew.h"
#include "gameObject.h"
#include "settings.h"

class CentipedeManager;

class CentipedeSegment: public GameObject
{
public:
	enum Type : GLuint {
		HEAD,
		BODY
	};

	enum Direction : GLuint {
		LEFT,
		RIGHT,
		DOWN,
		UP
	};

	CentipedeSegment(Vec position, CentipedeSegment *previous, CentipedeManager *centipedeManager, Direction direction);
	~CentipedeSegment();

	void update(GLfloat tpf);
	void updateBody(GLfloat tpf);

	CentipedeSegment* getPrevious();
	CentipedeSegment* getFollowing();
	void setFollowing(CentipedeSegment *following);

private:

	Direction direction, oldDirection;	//oldDirection is direction before direction change important for pathfinding
	Type type;

	void handleCollision(GameObject* collider);

	void updateTexCoord();
	//changes internal direction values
	void changeDirection(Direction newDirection);
	//checks which direction to go and performs position and direction adjustment
	void updateDirection();

	//Returns opposite direction of give direction
	Direction getOppositeDirection(Direction direction);

	CentipedeSegment *previous, *following;
	CentipedeManager *centipedeManager;
};

