#include "Engine.h"
#include "Core.h"
#include "SpaceShip.h"

using Core::Input;

const static int SCREEN_WIDTH = 1024;
const static int SCREEN_HEIGHT = 768;

SpaceShip myShip;

bool update(float dt)
{
	dt;
	
	myShip.update(dt);

	if (Input::IsPressed( Input::KEY_ESCAPE ))
	{
		return true;
	}
	return false;
}

void draw( Core::Graphics &graphics )
{
	graphics.SetColor( RGB(255,255,255) );
	graphics.DrawString( SCREEN_WIDTH/2 - 50, SCREEN_HEIGHT/2 - 20, "Hello World");
	graphics.DrawLine( 10, 10, 400, 300);

	myShip.draw(graphics);
}

void main()
{
	myShip.position = Engine::Vector2D(75, 300);
	Core::Init( "Game Demo", SCREEN_WIDTH, SCREEN_HEIGHT);
	Core::RegisterUpdateFn( update );
	Core::RegisterDrawFn( draw );
	Core::GameLoop();
}

