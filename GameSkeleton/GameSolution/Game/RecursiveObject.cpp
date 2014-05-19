#include "RecursiveObject.h"

extern DrawThing* myDrawThing;

RecursiveObject::RecursiveObject(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints, RecursiveObject* inSubObject, bool inHasChild) : GameObject(inPosition, inVelocity, numPoints, inShapePoints)
{
	hasChild = inHasChild;
	if (hasChild)
	{
		subObject = inSubObject;
		scaleChild(.5F);
	}
}

void RecursiveObject::scaleChild(float scaleValue)
{
	if (hasChild)
	{
		subObject->scale = scale * scaleValue;
		subObject->scaleChild(scaleValue);
	}
}

void RecursiveObject::draw(Core::Graphics& g, Matrix3D m)
{
	GameObject::draw(g, m);

	if (hasChild) 
	{
		m = m * m.Rotation(subObject->angle) * m.Translation(100, 100);
		subObject->draw(g, m);
	}
}

void RecursiveObject::update (float dt)
{
	if (hasChild) 
	{
		subObject->update(dt);
		subObject->position = Vector2D(position.x, position.y);
		subObject->angle = subObject->angle - (.1F);
	}
	GameObject::update(dt);
}