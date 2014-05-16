#include "Asteroid.h"

extern DrawThing* myDrawThing;

Asteroid::Asteroid(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints, int numPathPoints, Vector2D* inPathPoints) : GameObject(inPosition, inVelocity, numPoints, inShapePoints)
{
	pointInPath = 0;
	curPercentage = 0.0f;
	pathShape = new Shape(numPathPoints, inPathPoints);
}


void Asteroid::draw (Core::Graphics& g)
{
	Matrix3D temp;
	temp = temp * temp.Translation(position.x, position.y) * temp.Rotation(angle) * temp.Scale(scale);
	
	GameObject::draw(g, temp);
}

void Asteroid::update (float dt)
{
	GameObject::update(dt);
	
	Vector2D& curPathLeft = pathShape->get(pointInPath);
	Vector2D& curPathRight = pathShape->get((pointInPath + 1) % pathShape->getNumPoints());
	Vector2D pathVector = curPathRight - curPathLeft;
	float pathLength = pathVector.Length();
	float oneTimeUnit = (velocity.x / pathLength);
	curPercentage += oneTimeUnit;

	position = Vector2D::LERP(curPathLeft, curPathRight, curPercentage);

	if (curPercentage > 1)
	{
		pointInPath = (pointInPath + 1) % pathShape->getNumPoints();
		curPercentage = 0;
	}
}