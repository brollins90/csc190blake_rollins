#include "Core.h"
#include "GameManager.h"
#include <cstdlib>
#include <ctime>

extern const int SCREEN_WIDTH = 1024;
extern const int SCREEN_HEIGHT = 768;
GameManager gm;


bool update(float dt)
{
	gm.update(dt);

	if (Core::Input::IsPressed( Core::Input::KEY_ESCAPE ))
	{
		return true;
	}
	return false;
}

void draw( Core::Graphics& g )
{
	gm.draw(g);
}

void main()
{
	srand((unsigned int)time(NULL));
	Core::Init( "Blake Rollins", SCREEN_WIDTH, SCREEN_HEIGHT);
	Core::RegisterUpdateFn( update );
	Core::RegisterDrawFn( draw );
	Core::GameLoop();
}




