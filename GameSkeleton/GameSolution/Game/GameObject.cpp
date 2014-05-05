#include "GameObject.h"

GameObject::GameObject(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapepoints)
{
	position = inPosition;
	velocity = inVelocity;
	shape = new Shape(numPoints, inShapepoints);
}

GameObject::~GameObject(void)
{
	delete &position;
	delete &velocity;
	delete shape;
}

void GameObject::draw( Core::Graphics& g )
{
	shape->draw(g, position);
}

void GameObject::update( float dt )
{
	dt;
};
