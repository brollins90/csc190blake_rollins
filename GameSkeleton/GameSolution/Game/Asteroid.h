#ifndef ASTEROID_H
#define ASTEROID_H

#include "Engine.h"
#include "Core.h"
#include "Shape.h"
#include "WallMode.h"
#include "GameObject.h"
#include "DrawThing.h"


class Asteroid : GameObject
{
private:
	//int NUM_PATH_POINTS;
	int pointInPath;
	float curPercentage;
	//Vector2D* pathPoints;
	Shape* pathShape;
public:
	Asteroid(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints, int numPathPoints, Vector2D* inPathPoints);
	void draw (Core::Graphics& g);
	void update (float dt);
};

#endif