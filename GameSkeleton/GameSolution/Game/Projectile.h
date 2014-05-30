#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Engine.h"
#include "Core.h"
#include "Shape.h"
#include "WallMode.h"
#include "GameObject.h"
#include "DrawThing.h"

class Projectile : public GameObject
{	
public:
	Projectile(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints, Vector2D inEndPoint);
	~Projectile(void);
	
	void draw (Core::Graphics& g);
	void draw (Core::Graphics& g, Matrix3D m);
	bool update (float dt);

	Vector2D startPoint;
	Vector2D endPoint;
	float curPercentage;
};

#endif