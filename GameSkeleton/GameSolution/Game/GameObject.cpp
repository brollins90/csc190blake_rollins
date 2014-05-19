#include "GameObject.h"

GameObject::GameObject(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapepoints)
{
	position = inPosition;
	velocity = inVelocity;
	shape = new Shape(numPoints, inShapepoints);
	angle = 0;
	scale = 1;
}

GameObject::~GameObject(void)
{
	delete &position;
	delete &velocity;
	delete shape;
}

void GameObject::draw( Core::Graphics& g)
{
	shape->draw(g, position);
}

void GameObject::draw( Core::Graphics& g, Matrix3D& m )
{
	m = m * m.Scale(scale);
	shape->draw(g, m);
}

void GameObject::update( float dt )
{
	dt;
};

void GameObject::rotate(float angleInc)
{
	angle += angleInc;
}

void GameObject::setPosition(const Vector2D& pos)
{
	position = pos;
}