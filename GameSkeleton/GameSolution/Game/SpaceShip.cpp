#include "SpaceShip.h"

extern Shape* walls;

SpaceShip::SpaceShip(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints) : GameObject(inPosition, inVelocity, numPoints, inShapePoints)
{
	wMode = WRAP;
}

void SpaceShip::setWallMode(WallMode newMode)
{
	wMode = newMode;
}
void SpaceShip::draw (Core::Graphics& g)
{
	GameObject::draw(g);
}
void SpaceShip::update (float dt)
{
	GameObject::update(dt);

	if (Core::Input::IsPressed(Core::Input::KEY_RIGHT))
	{
		velocity.x += dt * 100;
	}
	if (Core::Input::IsPressed(Core::Input::KEY_LEFT))
	{
		velocity.x -= dt * 100;
	}
	if (Core::Input::IsPressed(Core::Input::KEY_UP))
	{
		velocity.y -= dt * 100;
	}
	if (Core::Input::IsPressed(Core::Input::KEY_DOWN))
	{
		velocity.y += dt * 100;
	}
	position = position + velocity * dt;
		
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
	if (wMode == BOUNCE)
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
			//floats[0] = f1;

			if (f1 < 0) 
			{
				Vector2D bounceVector = wallnormal * Vector2D::DotProduct(velocity, wallnormal);
//					floats[1] = red.x;
//				floats[2] = red.y;

				velocity = velocity + (bounceVector * -2);
			}
		}

	}
}