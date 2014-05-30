#ifndef LERPING_OBJECT_H
#define LERPING_OBJECT_H

#include "Engine.h"
#include "Core.h"
#include "Shape.h"
#include "WallMode.h"
#include "GameObject.h"
#include "DrawThing.h"

class LerpingObject : public GameObject
{
private:
	float curPercentage;
	int pointInPath;
	int numPathPoints;
	Shape* pathShape;
	LerpingObject* subObject;
	bool hasChild;
public:
	LerpingObject(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints, Core::RGB inColor, int numPathPoints, Vector2D* inPathPoints, bool inHasChild, LerpingObject* inSubObject);
	~LerpingObject(void);
	
	void draw (Core::Graphics& g);
	void draw (Core::Graphics& g, Matrix3D m);
	virtual bool update (float dt);

	void scaleChild(float scaleValue);
};

#endif