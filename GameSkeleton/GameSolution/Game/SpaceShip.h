#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Engine.h"
#include "Core.h"
#include "DebugMemory.h"
#include "Shape.h"
#include "WallMode.h"
#include "GameObject.h"
#include "DrawThing.h"
#include "ParticleEffect.h"
#include "FountainEffect.h"
#include "GameObjectManager.h"
#include "LerpingObject.h"
#include "Projectile.h"
#include "GameManager.h"
#include "EnemyManager.h"

class SpaceShip : public GameObject
{
public:
	SpaceShip(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints, Core::RGB inColor, GameObject* inTurret);
	~SpaceShip(void);

	Vector2D acceleration;
	float rotationSpeed;	
	GameObject* turret1;
	FountainEffect* effect2;
	int mousePosX;
	int mousePosY;
	int reloadDelay;
	int flameTimer;

	void draw (Core::Graphics& g);
	virtual bool update (float dt);
};

#endif