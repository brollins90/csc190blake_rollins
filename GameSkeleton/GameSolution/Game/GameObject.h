#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Engine.h"
#include "Core.h"
#include "Shape.h"

using Engine::Vector2D;

class GameObject
{
protected:
	Vector2D position;
	Vector2D velocity;
	Shape* shape;
	float angle;
	float scale;
public:
	GameObject(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapepoints);
	~GameObject(void);
	void draw( Core::Graphics& g );
	void update( float dt);
};

#endif