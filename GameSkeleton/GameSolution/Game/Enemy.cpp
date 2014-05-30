
#include "Enemy.h"

extern DrawThing* myDrawThing;

Enemy::Enemy(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints, Core::RGB inColor, int inNumPathPoints, Vector2D* inPathPoints, bool inHasChild, LerpingObject* inSubObject) : LerpingObject(inPosition, inVelocity, numPoints, inShapePoints, inColor, inNumPathPoints, inPathPoints, inHasChild, inSubObject)
{

}

Enemy::~Enemy(void) 
{

}

void Enemy::draw (Core::Graphics& g, Matrix3D m)
{
	LerpingObject::draw(g, m);
}

bool Enemy::update(float dt)
{
	return LerpingObject::update(dt);
}