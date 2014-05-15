#include "SpaceShip.h"

extern Shape* walls;
extern DrawThing* myDrawThing;

SpaceShip::SpaceShip(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints, GameObject* inTurret) : GameObject(inPosition, inVelocity, numPoints, inShapePoints)
{
	wMode = WRAP;
	acceleration = Vector2D(100, 100);
	rotationSpeed = 0.05F;
	turret1 = inTurret;
}

void SpaceShip::setWallMode(WallMode newMode)
{
	wMode = newMode;
}
void SpaceShip::draw (Core::Graphics& g)
{
	GameObject::draw(g);
	turret1->draw(g);

	Matrix3D temp;
	temp = temp * temp.Translation(position.x, position.y) * temp.Rotation(angle) * temp.Scale(scale);

	myDrawThing->setShipMatrix(temp);

}
void SpaceShip::update (float dt)
{
	Vector2D prevPos(position.x,position.y);
	Core::Input::GetMousePos(mousePosX, mousePosY);

	GameObject::update(dt);
	turret1->update(dt);

	if (Core::Input::IsPressed(Core::Input::KEY_RIGHT))
	{
		GameObject::rotate( rotationSpeed);
		turret1->rotate( rotationSpeed);
	}
	if (Core::Input::IsPressed(Core::Input::KEY_LEFT))
	{
		GameObject::rotate( -rotationSpeed);
	}
	if (Core::Input::IsPressed(Core::Input::KEY_UP))
	{
		velocity = velocity - (dt * acceleration * Vector2D(-sin(angle),cos(angle)));
	}
	if (Core::Input::IsPressed(Core::Input::KEY_DOWN))
	{
		velocity = velocity - (dt * acceleration * Vector2D(sin(angle),-cos(angle)));
	}
	position = position + velocity * dt;
	if (Core::Input::IsPressed(Core::Input::BUTTON_LEFT))
	{
	}

	turret1->setPosition(position);
		
	if (wMode == WALLS)
	{
		for (int i =0 ; i < walls->getNumPoints(); i++)
		{
			Vector2D& wallPointLeft = walls->get(i);
			Vector2D& wallPointRight = walls->get((i + 1) % walls->getNumPoints());
			Vector2D wallPointLeftToShip = position - wallPointLeft;
			Vector2D wallVector = wallPointRight - wallPointLeft;
			Vector2D wallnormal = wallVector.PerpCCW().Normalize();
			float f1 = Vector2D::DotProduct(wallnormal,wallPointLeftToShip);

			if (f1 < 0 && !isOutOfBounds(prevPos)) 
			{
				Vector2D bounceVector = wallnormal * Vector2D::DotProduct(velocity, wallnormal);
				velocity = velocity + (bounceVector * -2);
				position = prevPos;
			}
		}

	}
	if (wMode == BOUNCE || wMode == WALLS)
	{
		if (position.x < 0)
		{
			velocity.x *= -1;
		}
		if (position.x > 1024)
		{
			velocity.x *= -1;
		}
		if (position.y < 0)
		{
			velocity.y *= -1;
		}
		if (position.y > 768)
		{
			velocity.y *= -1;
		}
	}
	if (wMode == WRAP)
	{
		if (position.x < 0)
		{
			position.x = 1024;
		}
		if (position.x > 1024) 
		{
			position.x = 0;
		}
		if (position.y < 0)
		{
			position.y = 768;
		}
		if (position.y > 768) 
		{
			position.y = 0;
		}
	}
	myDrawThing->setFloat(1,position.x);
	myDrawThing->setFloat(2,position.y);
	myDrawThing->setFloat(3,velocity.x);
	myDrawThing->setFloat(4,velocity.y);

	myDrawThing->setMousePos(mousePosX, mousePosY);
}

bool SpaceShip::isOutOfBounds(Vector2D& pos)
{	
	for (int i =0 ; i < walls->getNumPoints(); i++)
	{
		Vector2D& wallPointLeft = walls->get(i);
		Vector2D& wallPointRight = walls->get((i + 1) % walls->getNumPoints());
		Vector2D wallPointLeftToShip = pos - wallPointLeft;
		Vector2D wallVector = wallPointRight - wallPointLeft;
		Vector2D wallnormal = wallVector.PerpCCW().Normalize();
		float f1 = Vector2D::DotProduct(wallnormal,wallPointLeftToShip);

		if (f1 < 0) 
		{
			return true;
		}
	}
	return false;
}


void SpaceShip::addTurret(GameObject* t)
{
	turret1 = t;
}
