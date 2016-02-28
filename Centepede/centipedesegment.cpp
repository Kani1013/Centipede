#include "centipedesegment.h"
#include "centipedeManager.h"


CentipedeSegment::CentipedeSegment(Vec position, CentipedeSegment *previous, CentipedeManager *centipedeManager, Direction direction)
{
	Position.x1 = position.x;
	Position.y1 = position.y;
	Position.x2 = Position.x1 + CENTISEGMENT_WIDTH;
	Position.y2 = Position.y1 + CENTISEGMENT_HEIGHT;

	AABB = Position;

	isStatic = GL_FALSE;
	isAlive = GL_TRUE;
	colliders.mushroom = GL_TRUE;
	colliders.centipede = GL_TRUE;
	colliders.player = GL_TRUE;
	colliders.bullet = GL_TRUE;
	ID = 2;

	this->direction = DOWN;
	oldDirection = getOppositeDirection(direction);
	this->previous = previous;
	this->centipedeManager = centipedeManager;

	if (previous == nullptr) type = HEAD;
	else type = BODY;

	updateTexCoord();
}

CentipedeSegment::~CentipedeSegment()
{
}

void CentipedeSegment::update(GLfloat tpf)
{
	if (previous != nullptr && previous->isAlive == GL_FALSE) type = HEAD;

	if (type != HEAD) {
		updateBody(tpf);
		return;
	}

	GLfloat movement = CENTIPEDE_SPEED * tpf;
	switch (direction)
	{
		case LEFT:
			Position.x1 -= movement;
			if (Position.x1 < 0) updateDirection();
			break;
		case RIGHT:
			Position.x1 += movement;
			if (Position.x1 > FIELDSIZE - CENTISEGMENT_WIDTH) updateDirection();
			break;
		case UP:
			Position.y1 -= movement;
			if (getCenter().y < FIELDSIZE - 1 && (GLuint)Position.y1 != (GLuint)AABB.y1) updateDirection();
			break;
		case DOWN:
			Position.y1 += movement;
			if (getCenter().y > 1 && (GLuint)Position.y1 + CENTISEGMENT_HEIGHT != (GLuint)AABB.y2) updateDirection();
		default:
			break;
	}

	Position.x2 = Position.x1 + CENTISEGMENT_WIDTH;
	Position.y2 = Position.y1 + CENTISEGMENT_HEIGHT;

	AABB = Position;
}

void CentipedeSegment::updateBody(GLfloat tpf) {
	GLfloat movement = tpf * CENTIPEDE_SPEED;

	switch (direction)
	{
	case LEFT:
		Position.x1 -= movement;
		if (direction == previous->direction) {
			Position.y1 = previous->getPosition().y1;
		}
		else {
			if (getCenter().x < previous->getCenter().x) {
				Position.x1 = previous->getPosition().x1;
				if (getCenter().y < previous->getCenter().y) {
					changeDirection(DOWN);
					Position.y1 = previous->getPosition().y1 - CENTISEGMENT_HEIGHT;
				}
				else {
					changeDirection(UP);
					Position.y1 = previous->getPosition().y2;
				}
			}
		}
		break;

	case RIGHT:
		Position.x1 += movement;
		if (direction == previous->direction) {
			Position.y1 = previous->getPosition().y1;
		}
		else {
			if (getCenter().x > previous->getCenter().x) {
				Position.x1 = previous->getPosition().x1;
				if (getCenter().y < previous->getCenter().y) {
					changeDirection(DOWN);
					Position.y1 = previous->getPosition().y1 - CENTISEGMENT_HEIGHT;
				}
				else {
					changeDirection(UP);
					Position.y1 = previous->getPosition().y2 + SEGMENT_SPACING;
				}
			}
		}
		break;

	case UP:
		Position.y1 -= movement;
		if (getCenter().y < previous->getCenter().y) {
			Position.y1 = previous->getPosition().y1;
			if (getCenter().x < previous->getCenter().x) {
				changeDirection(RIGHT);
				Position.x1 = previous->getPosition().x1 - CENTISEGMENT_WIDTH - SEGMENT_SPACING;
			}
			else {
				changeDirection(LEFT);
				Position.x1 = previous->getPosition().x2 + SEGMENT_SPACING;
			}
		}
		break;

	case DOWN:
		Position.y1 += movement;
		if (getCenter().y > previous->getCenter().y) {
			Position.y1 = previous->getPosition().y1;
			if (getCenter().x < previous->getCenter().x) {
				changeDirection(RIGHT);
				Position.x1 = previous->getPosition().x1 - CENTISEGMENT_WIDTH - SEGMENT_SPACING;
			}
			else {
				changeDirection(LEFT);
				Position.x1 = previous->getPosition().x2 + SEGMENT_SPACING;
			}
		}
		break;
	default:
		break;
	}

	Position.x2 = Position.x1 + CENTISEGMENT_WIDTH;
	Position.y2 = Position.y1 + CENTISEGMENT_HEIGHT;

	AABB = Position;
}

void CentipedeSegment::changeDirection(Direction newDirection)
{
	oldDirection = direction;
	direction = newDirection;
	updateTexCoord();
}

void CentipedeSegment::updateDirection()
{
	Direction newDirection;
	
	switch (direction)
	{
	case LEFT:
		if ((GLuint)Position.y1 < FIELDSIZE - 1) newDirection = DOWN;
		else newDirection = UP;
		break;

	case RIGHT:
		if ((GLuint)Position.y1 < FIELDSIZE - 1) newDirection = DOWN;
		else newDirection = UP;
		break;

	case DOWN:
		newDirection = getOppositeDirection(oldDirection);
		Position.y1 = (GLfloat)((GLuint)getCenter().y); //Align to y axis
		Position.y2 = Position.y1 + CENTISEGMENT_HEIGHT;
		break;

	case UP:
		newDirection = getOppositeDirection(oldDirection);
		Position.y1 = (GLfloat)((GLuint)getCenter().y); //Align to y axis
		Position.y2 = Position.y1 + CENTISEGMENT_HEIGHT;
		break;

	default:
		break;
	}

	changeDirection(newDirection);
}

void CentipedeSegment::handleCollision(GameObject* collider)
{
	if (collider->ID == 0) {
		//check if mushroom is on same y axis due to collision when edges are aligned
		if ((GLuint)collider->getCenter().y == (GLuint)this->getCenter().y) {
			//check if mushroom is in moving direction-> fixes error when moving down along a mushrom which has a mushroom on the field under itself
			if (direction == LEFT && collider->getCenter().x < this->getPosition().x1 ||
				direction == RIGHT && collider->getCenter().x > this->getPosition().x2) {
					//change direction
					updateDirection();
			}	
		}
	}
	else if (collider->ID == 2) {
		//If I am not a HEAD -> Do nothing
		if (this->type != HEAD) return;

		//check if segment is from this centipede -> no collision to check
		GLboolean isFromMyself = GL_FALSE;
		CentipedeSegment *follower =  following;
		if (follower != nullptr) {
			while (isFromMyself != GL_TRUE) {
				if (collider == follower) isFromMyself = GL_TRUE;

				follower = follower->getFollowing();
				if (follower == nullptr) break;
			}
		}
		if (isFromMyself == GL_TRUE) return;

		//check if centipede is on same y axis due to collision when edges are aligned
		if ((GLuint)collider->getCenter().y == (GLuint)this->getCenter().y) {
			//check if Centipede is in moving direction-> fixes error that heads get stuck to each other
			if (direction == LEFT && collider->getCenter().x < this->getCenter().x ||
				direction == RIGHT && collider->getCenter().x > this->getCenter().x) {
				//change direction
				updateDirection();
			}
		}
	}
	if (collider->ID == 1) {
		//die, spawn mushroom
		if(isAlive) //prevents double mushroom spawning
			centipedeManager->spawnMushroom(this->getCenter());
		isAlive = false;
	}
}

void CentipedeSegment::updateTexCoord()
{
	if (type == HEAD) {
		TexCoords.x1 = 0;
		TexCoords.y1 = 0;
		TexCoords.x2 = 7;
		TexCoords.y2 = 8;
	}
	else {
		TexCoords.x1 = 0;
		TexCoords.y1 = 16;
		TexCoords.x2 = 7;
		TexCoords.y2 = 24;
	}

	if (direction == RIGHT) {
		//mirror on center y axis
		GLfloat help;
		help = TexCoords.x1;
		TexCoords.x1 = TexCoords.x2;
		TexCoords.x2 = help;
	}
}

CentipedeSegment::Direction CentipedeSegment::getOppositeDirection(Direction direction)
{
	Direction result;
	switch (direction)
	{
	case LEFT:
		result = RIGHT;
		break;
	case RIGHT:
		result = LEFT;
		break;
	case UP:
		result = DOWN;
		break;
	case DOWN:
		result = UP;
		break;
	default:
		break;
	}
	return result;
}


CentipedeSegment* CentipedeSegment::getPrevious() {
	return previous;
};

void CentipedeSegment::setFollowing(CentipedeSegment *following)
{
	this->following = following;
}

CentipedeSegment* CentipedeSegment::getFollowing() {
	return following;
};