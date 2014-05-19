#ifndef RECURSIVE_H
#define RECURSIVE_H

#include "Engine.h"
#include "Core.h"
#include "Shape.h"
#include "WallMode.h"
#include "GameObject.h"
#include "DrawThing.h"

class RecursiveObject : public GameObject
{

public:
	RecursiveObject* subObject;
	bool hasChild;
	RecursiveObject(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints, RecursiveObject* inSubObject, bool inHasChild);
	void draw (Core::Graphics& g, Matrix3D m);
	void update (float dt);
	void scaleChild(float scaleValue);
};

#endif