#include "Engine.h"
#include "Core.h"
#include <sstream>
#include "DrawThing.h"
#include "Shape.h"
#include "GameObject.h"
#include "WallMode.h"
#include "SpaceShip.h"
#include "Asteroid.h"

//#include "SpaceShip2.h"
using Engine::Vector2D;
using Core::Input;

const static int SCREEN_WIDTH = 1024;
const static int SCREEN_HEIGHT = 768;

float floatsToDebug[10] = {0.0f};

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

Vector2D asteroidPoints[] =
{
	Vector2D(+00.0f, -05.0f),
	Vector2D(+05.0f, +00.0f),
	Vector2D(+00.0f, +05.0f),
	Vector2D(-05.0f, +00.0f)
};

Vector2D asteroidPathPoints[] =
{
	Vector2D(+224.0f, +100.0f),
	Vector2D(+700.0f, +200.0f),
	Vector2D(+600.0f, +300.0f),
	Vector2D(+050.0f, +100.0f)
};



WallMode gameMode = WRAP;


void DrawValue(Core::Graphics& g, int x, int y, float num)
{
	std::stringstream ss;
	ss << num;
	g.DrawString(x, y, ss.str().c_str());
}

GameObject wallsObj(Vector2D(0,0),Vector2D(0,0),5, wallPoints);

extern Shape* walls = new Shape(5, wallPoints);
extern DrawThing* myDrawThing = new DrawThing;

SpaceShip myShip(Vector2D((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2)),Vector2D(0,0),8, shipPoints);

Asteroid myAsteroid(Vector2D(50,50), Vector2D(1,0), 4, asteroidPoints, 4, asteroidPathPoints);

bool update(float dt)
{
	wallsObj.update(dt);
	myShip.update(dt);
	myAsteroid.update(dt);

	if (Input::IsPressed( Input::KEY_ESCAPE ))
	{
		return true;
	}
	if ( Input::IsPressed( '1' ) )
	{
		myShip.setWallMode(WRAP);
	}
	if ( Input::IsPressed( '2' ) )
	{
		myShip.setWallMode(BOUNCE);
	}
	if ( Input::IsPressed( '3' ) )
	{
		myShip.setWallMode(WALLS);
	}
	return false;
}

void draw( Core::Graphics& g )
{
//	graphics.SetColor( RGB(255,255,255) );
//	graphics.DrawString( SCREEN_WIDTH/2 - 50, SCREEN_HEIGHT/2 - 20, "Hello World");
//	graphics.DrawLine( 10, 10, 400, 300);

	wallsObj.draw(g);
	myShip.draw(g);
	myAsteroid.draw(g);
	myDrawThing->draw(g);
	/*
	DrawValue(g, 10, 5, floatsToDebug[0]);
	DrawValue(g, 10, 15, floatsToDebug[1]);
	DrawValue(g, 10, 25, floatsToDebug[2]);
	DrawValue(g, 10, 35, floatsToDebug[3]);
	DrawValue(g, 10, 45, floatsToDebug[4]);
	DrawValue(g, 10, 55, floatsToDebug[5]);
	DrawValue(g, 10, 65, floatsToDebug[6]);
	DrawValue(g, 10, 75, floatsToDebug[7]);
	DrawValue(g, 10, 85, floatsToDebug[8]);
	DrawValue(g, 10, 95, floatsToDebug[9]);*/
}

void main()
{
	
	//myShip.position = Engine::Vector2D((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2));
	Core::Init( "Game Demo", SCREEN_WIDTH, SCREEN_HEIGHT);
	Core::RegisterUpdateFn( update );
	Core::RegisterDrawFn( draw );
	Core::GameLoop();
}

