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
	int mousePosX, mousePosY;
	GameObject* turret1, *laser1;
	float rotationSpeed;
	SpaceShip(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints, GameObject* inTurret, GameObject* inLaser);// : GameObject(inPosition, inVelocity, numPoints, inShapePoints);
	void setWallMode(WallMode newMode);
	void draw (Core::Graphics& g);
	void update (float dt);
	bool isOutOfBounds(Vector2D& pos);
	void addTurret(GameObject* t);
	
	Vector2D laserStart;
	Vector2D laserEnd;
	float laserPercentage;
	bool laserFired;
};

#endif