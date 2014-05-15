#include "Engine.h"
#include "Core.h"
#include <sstream>
#include "DrawThing.h"
#include "Shape.h"
#include "GameObject.h"
#include "WallMode.h"
#include "SpaceShip.h"
#include "Asteroid.h"

using Engine::Vector2D;
using Core::Input;

const static int SCREEN_WIDTH = 1024;
const static int SCREEN_HEIGHT = 768;

int numWallPoints = 6;
Vector2D wallPoints[] =
{
	Vector2D(512.0F,0.0F), //(SCREEN_WIDTH / 2), 0),
	Vector2D(950.0F,200.0F),
	Vector2D(1024.0F,384.0F), //(SCREEN_HEIGHT / 2)),
	Vector2D(512.0F, 768.0F), //(SCREEN_WIDTH / 2), (float)SCREEN_HEIGHT),
	Vector2D(0.0F, 384.0F), //0, (SCREEN_HEIGHT / 2))
	Vector2D(512.0F,0.0F), //(SCREEN_WIDTH / 2), 0)
};

Vector2D turretPoints[] =
{
	Vector2D(+00.00F, -15.00F),
	Vector2D(+05.00F, +00.00F),
	Vector2D(-05.00F, +00.00)
};

Vector2D shipPoints[] =
{
	Vector2D(+00.00f, -28.50f),
	Vector2D(+06.00f, +05.25f),
	Vector2D(+08.25f, +05.25f),
	Vector2D(+08.25f, +22.50f),
	Vector2D(+08.25f, +21.00f),
	Vector2D(+23.25f, +21.00f),
	Vector2D(+08.25f, +12.00f),
	Vector2D(+08.25f, +22.50f),
	Vector2D(-08.25f, +22.50f),
	Vector2D(-08.25f, +12.00f),
	Vector2D(-23.25f, +21.00f),
	Vector2D(-08.25f, +21.00f),
	Vector2D(-08.25f, +22.50f),
	Vector2D(-08.25f, +05.25f),
	Vector2D(-06.00f, +05.25f)
};

Vector2D asteroidPoints[] =
{
	Vector2D(-33.0f, +00.0f),
	Vector2D(-13.0f, -05.0f),
	Vector2D(-10.0f, -16.0f),
	Vector2D(+03.0f, -28.0f),
	Vector2D(+30.0f, -14.0f),
	Vector2D(+29.0f, +02.0f),
	Vector2D(+34.0f, +15.0f),
	Vector2D(+16.0f, +25.0f),
	Vector2D(+03.0f, +28.0f),
	Vector2D(-08.0f, +28.0f),
	Vector2D(-27.0f, +17.0f)
};

Vector2D asteroidPathPoints[] =
{
	Vector2D(+224.0f, +100.0f),
	Vector2D(+700.0f, +200.0f),
	Vector2D(+600.0f, +300.0f),
	Vector2D(+050.0f, +100.0f)
};



WallMode gameMode = WRAP;
GameObject wallsObj(Vector2D(0,0),Vector2D(0,0),5, wallPoints);
extern Shape* walls = new Shape(5, wallPoints);
extern DrawThing* myDrawThing = new DrawThing;
GameObject turret1(Vector2D(0,0),Vector2D(0,0),3, turretPoints);
SpaceShip myShip(Vector2D((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2)),Vector2D(0,0),15, shipPoints,&turret1);
Asteroid myAsteroid(Vector2D(50,50), Vector2D(4,0), 11, asteroidPoints, 4, asteroidPathPoints);

bool update(float dt)
{
	wallsObj.update(dt);
	myShip.update(dt);
	myAsteroid.update(dt);
	myShip.addTurret(&turret1);

	if (Input::IsPressed( Input::KEY_ESCAPE ))
	{
		return true;
	}
	if ( Input::IsPressed( '1' ) )
	{
		myShip.setWallMode(WRAP);
		myDrawThing->setString(0, "WRAP");
	}
	if ( Input::IsPressed( '2' ) )
	{
		myShip.setWallMode(BOUNCE);
		myDrawThing->setString(0, "BOUNCE");
	}
	if ( Input::IsPressed( '3' ) )
	{
		myShip.setWallMode(WALLS);
		myDrawThing->setString(0, "WALLS");
	}
	return false;
}

void draw( Core::Graphics& g )
{
	wallsObj.draw(g);
	myShip.draw(g);
	myAsteroid.draw(g);
	myDrawThing->draw(g);
}

void main()
{
	Core::Init( "Blake Rollins", SCREEN_WIDTH, SCREEN_HEIGHT);
	Core::RegisterUpdateFn( update );
	Core::RegisterDrawFn( draw );
	Core::GameLoop();
}

