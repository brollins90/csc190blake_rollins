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

void GameObject::draw( Core::Graphics& g )
{
	Matrix3D temp;
	temp = temp * temp.Translation(position.x, position.y) * temp.Rotation(angle) * temp.Scale(scale);

	shape->draw(g, temp);
//	shape->draw(g, position);
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