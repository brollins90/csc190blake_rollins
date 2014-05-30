
#include "Projectile.h"
#include "GameManager.h"

extern DrawThing* myDrawThing;
extern GameManager* myGameManager;

Projectile::Projectile(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints, Core::RGB inColor, Vector2D inEndPoint) : GameObject(inPosition, inVelocity, numPoints, inShapePoints, inColor)
{
	startPoint = inPosition;
	endPoint = inEndPoint;
	curPercentage = 0.0F;
}

Projectile::~Projectile(void) 
{

}

void Projectile::draw (Core::Graphics& g)
{
	g.SetColor(objColor);
	Projectile::draw(g, Matrix3D().Translation(position));
}

void Projectile::draw (Core::Graphics& g, Matrix3D m)
{
	g.SetColor(objColor);
	GameObject::draw(g, m);
}

bool Projectile::update(float dt)
{
	GameObject::update(dt);
	if (!myGameManager->isOutOfBounds(position))
	{

		Vector2D pathVector = endPoint - startPoint;
		float pathLength = pathVector.Length();
		float oneTimeUnit = (velocity.x / pathLength);
		curPercentage += oneTimeUnit;

		position = Vector2D::LERP(startPoint, endPoint, curPercentage);
		return true;
	} 
	return false;
	
}