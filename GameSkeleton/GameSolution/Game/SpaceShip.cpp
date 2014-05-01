#include "SpaceShip.h"
#include <sstream>

using Engine::Vector2D;

Vector2D shipPoints[] =
{
	Vector2D(+00.0f, -30.0f),
	Vector2D(+10.0f, -22.0f),
	Vector2D(+10.0f, +00.0f),
	Vector2D(+10.0f, +10.0f),
	Vector2D(-10.0f, +10.0f),
	Vector2D(-10.0f, +00.0f),
	Vector2D(-10.0f, -22.0f),
	Vector2D(+00.0f, -30.0f)
};

float floats[10] = {0.0f};

Vector2D wallA(200, 0);
Vector2D wallB(400, 400);


SpaceShip::SpaceShip() { }
SpaceShip::~SpaceShip() { }

void DrawValue(Core::Graphics& g, int x, int y, float num)
{
	std::stringstream ss;
	ss << num;
	g.DrawString(x, y, ss.str().c_str());
}

void SpaceShip::draw(Core::Graphics& g)
{
	const unsigned int NUM_POINTS = sizeof(shipPoints) / sizeof(*shipPoints);
	for (unsigned int i = 0; i< NUM_POINTS; i++) 
	{
		const Vector2D& p1 = position + shipPoints[i];
		const Vector2D& p2 = position + shipPoints[(i + 1) % NUM_POINTS];
		g.DrawLine(p1.x, p1.y, p2.x, p2.y);
	}
	g.DrawLine(wallA.x, wallA.y, wallB.x, wallB.y);
	
	DrawValue(g, 10, 5, position.x);
	DrawValue(g, 10, 15, position.y);
	DrawValue(g, 10, 25, velocity.x);
	DrawValue(g, 10, 35, velocity.y);
	DrawValue(g, 10, 45, floats[0]);
	DrawValue(g, 10, 55, floats[1]);
	DrawValue(g, 10, 65, floats[2]);

}

void SpaceShip::update(float dt)
{
	int mode = 3;

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

	if (mode == 1)
	{
		if (position.x < 0)
		{
			position.x = 400;
		}
		if (position.x > 400) 
		{
			position.x = 0;
		}
		if (position.y < 0)
		{
			position.y = 400;
		}
		if (position.y > 400) 
		{
			position.y = 0;
		}
	}
	if (mode == 2)
	{
		if (position.x < 0)
		{
			velocity.x *= -1;
		}
		if (position.x > 400)
		{
			velocity.x *= -1;
		}
		if (position.y < 0)
		{
			velocity.y *= -1;
		}
		if (position.y > 400)
		{
			velocity.y *= -1;
		}
	}
	if (mode == 3)
	{
		Vector2D shipVect = position - wallA;
		Vector2D wallVect = wallB - wallA;
		Vector2D wallVectPerp = wallVect.PerpCCW().Normalize();
		float f1 = wallVectPerp.DotProduct(shipVect);
		floats[0] = f1;

		if (f1 < 0) 
		{
			Vector2D red = wallVectPerp * Vector2D::DotProduct(velocity, wallVectPerp);
			floats[1] = red.x;
			floats[2] = red.y;

			velocity = velocity + (red * -2);
		}

	}
}
