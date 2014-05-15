#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Engine.h"
#include "Core.h"
#include "Shape.h"
#include "WallMode.h"
#include "GameObject.h"
#include "DrawThing.h"


class SpaceShip : GameObject
{
public:
	WallMode wMode;
	Vector2D acceleration;
	float rotationSpeed;
	SpaceShip(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints);// : GameObject(inPosition, inVelocity, numPoints, inShapePoints);
	void setWallMode(WallMode newMode);
	void draw (Core::Graphics& g);
	void update (float dt);
	bool isOutOfBounds(Vector2D& pos);
};

#endif