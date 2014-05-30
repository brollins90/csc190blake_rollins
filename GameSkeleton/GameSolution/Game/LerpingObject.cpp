#include "LerpingObject.h"

extern DrawThing* myDrawThing;

LerpingObject::LerpingObject(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints, int inNumPathPoints, Vector2D* inPathPoints, bool inHasChild, LerpingObject* inSubObject) : GameObject(inPosition, inVelocity, numPoints, inShapePoints)
{
	pointInPath = 0;
	curPercentage = 0.0f;
	numPathPoints = inNumPathPoints;
	pathShape = new Shape(numPathPoints, inPathPoints);

	hasChild = inHasChild;
	if (hasChild)
	{
		subObject = inSubObject;
		scaleChild(.75F);
		
	}
}

LerpingObject::~LerpingObject()
{
	delete pathShape;
	delete subObject;
}

void LerpingObject::draw (Core::Graphics& g)
{
//	Matrix3D m;
	//m= m * Matrix3D().Translation(position);
	LerpingObject::draw(g, Matrix3D().Translation(position));
	/*
	if (hasChild) 
	{
		m = m * m.Rotation(subObject->angle) * m.Translation(100, 100);
		subObject->draw(g, m);
	}*/

}

void LerpingObject::draw (Core::Graphics& g, Matrix3D m)
{
//	m = m * Matrix3D().Translation(position);
	GameObject::draw(g, m);
	
	if (hasChild) 
	{
		m = m * m.Rotation(subObject->angle) * m.Translation(100, 100);
		subObject->draw(g, m);
	}
	
	myDrawThing->setFloat(22, position.x);
	myDrawThing->setFloat(23, position.y);

}

bool LerpingObject::update (float dt)
{
	GameObject::update(dt);
	
	if (numPathPoints != 0) {
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
	if (hasChild) 
	{
		subObject->update(dt);
		subObject->position = Vector2D(position.x, position.y);
		subObject->angle = subObject->angle - (.1F);
	}
	return true;
}

void LerpingObject::scaleChild(float scaleValue)
{
	if (hasChild)
	{
		subObject->scale = scale * scaleValue;
		subObject->scaleChild(scaleValue);
	}
}