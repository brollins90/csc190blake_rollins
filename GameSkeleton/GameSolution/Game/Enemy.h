#ifndef ENEMY_H
#define ENEMY_H

#include "Engine.h"
#include "Core.h"
#include "Shape.h"
#include "WallMode.h"
#include "GameObject.h"
#include "DrawThing.h"
#include "Projectile.h"

class Enemy : public Projectile
{	
public:
	Enemy(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints, Core::RGB inColor, Vector2D inEndPoint);
	~Enemy(void);
/*
	void draw (Core::Graphics& g, Matrix3D m);*/
	bool update (float dt);
	void setEndPoint(Vector2D newPoint);

	int pointValue;
};

#endif