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
	SpaceShip(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints, GameObject* inTurret, GameObject* inLaser);// : GameObject(inPosition, inVelocity, numPoints, inShapePoints);
	~SpaceShip(void);

	void draw (Core::Graphics& g);
	void update (float dt);

	void addTurret(GameObject* t);
	bool isOutOfBounds(Vector2D& pos);
	
	Vector2D acceleration;
	int mousePosX, mousePosY;
	GameObject* turret1;
	GameObject* laser1;
	float rotationSpeed;	
	Vector2D laserStart;
	Vector2D laserEnd;
	float laserPercentage;
	bool laserFired;
};

#endif