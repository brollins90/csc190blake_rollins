#ifndef ASTEROID_H
#define ASTEROID_H

#include "Engine.h"
#include "Core.h"
#include "Shape.h"
#include "WallMode.h"
#include "GameObject.h"
#include "DrawThing.h"

class LerpingObject : public GameObject
{
private:
	int pointInPath;
	float curPercentage;
	int numPathPoints;
	Shape* pathShape;
	bool hasChild;
	LerpingObject* subObject;
public:
	LerpingObject(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints, Core::RGB inColor, int numPathPoints, Vector2D* inPathPoints, bool inHasChild, LerpingObject* inSubObject);
	~LerpingObject(void);
	
	void draw (Core::Graphics& g);
	void draw (Core::Graphics& g, Matrix3D m);
	void scaleChild(float scaleValue);
	virtual bool update (float dt);
};

#endif