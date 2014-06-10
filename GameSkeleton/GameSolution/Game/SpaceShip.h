#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Engine.h"
#include "Core.h"
#include "DebugMemory.h"
#include "Shape.h"
#include "WallMode.h"
#include "GameObject.h"
#include "DrawThing.h"

class SpaceShip : public GameObject
{
public:
	SpaceShip(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints, Core::RGB inColor, GameObject* inTurret);
	~SpaceShip(void);

	Vector2D acceleration;
	float rotationSpeed;	
	int mousePosX;
	int mousePosY;
	GameObject* turret1;

	void draw (Core::Graphics& g);
	virtual bool update (float dt);
};

#endif