#include "GameObject.h"

GameObject::GameObject(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapepoints, Core::RGB inColor)
{
	position = inPosition;
	velocity = inVelocity;
	shape = new Shape(numPoints, inShapepoints);
	angle = 0;
	scale = 1;
	objColor = inColor;
}

GameObject::~GameObject(void)
{
	//delete &position;
	//delete &velocity;
	delete shape;
}

void GameObject::draw( Core::Graphics& g)
{
	g.SetColor(objColor);
	shape->draw(g, position);
}

void GameObject::draw( Core::Graphics& g, Matrix3D& m )
{
	g.SetColor(objColor);
	m = m * m.Scale(scale);
	shape->draw(g, m);
}

bool GameObject::update( float dt )
{
	dt;
	return true;
};

void GameObject::rotate(float angleInc)
{
	angle += angleInc;
}

void GameObject::setPosition(const Vector2D& pos)
{
	position = pos;
}

void GameObject::setColor(Core::RGB newColor)
{
	objColor = newColor;
}
