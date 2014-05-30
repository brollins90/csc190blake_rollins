#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Engine.h"
#include "Core.h"
#include "Shape.h"

using Engine::Vector2D;

class GameObject
{
public:
	GameObject( Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapepoints );
	~GameObject( void );

	Vector2D position;
	Vector2D velocity;
	Shape* shape;
	float angle;
	float scale;

virtual void draw( Core::Graphics& g );
virtual	void draw( Core::Graphics& g, Matrix3D& temp );
	void rotate( float angleInc );
	void setPosition( const Vector2D& pos );
virtual	bool update( float dt );
};

#endif