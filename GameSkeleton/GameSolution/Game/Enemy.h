#ifndef ENEMY_H
#define ENEMY_H

#include "Engine.h"
#include "Core.h"
#include "Shape.h"
#include "WallMode.h"
#include "GameObject.h"
#include "DrawThing.h"
#include "LerpingObject.h"

class Enemy : LerpingObject
{	
	Enemy(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints, int numPathPoints, Vector2D* inPathPoints, bool inHasChild, LerpingObject* inSubObject);
	~Enemy(void);

	void draw (Core::Graphics& g, Matrix3D m);
	bool update (float dt);
};

#endif