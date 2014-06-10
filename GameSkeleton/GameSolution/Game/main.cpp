//#define LOG_ON 1
//#define PROFILER_ON 1
//#define ASSERTER_ON 1

#include "Core.h"
#include "GameManager.h"
#include <cstdlib>
#include <ctime>

extern const int SCREEN_WIDTH = 1024;
extern const int SCREEN_HEIGHT = 768;
extern GameManager* myGameManager = new GameManager;


bool update(float dt)
{
	myGameManager->update(dt);

	if (Core::Input::IsPressed( Core::Input::KEY_ESCAPE ))
	{
		return myGameManager->shutdown();
	}
	return false;
}

void draw( Core::Graphics& g )
{
	myGameManager->draw(g);
}

void main()
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	myGameManager->initialize();
	srand((unsigned int)time(NULL));
	Core::Init( "Blake Rollins", SCREEN_WIDTH, SCREEN_HEIGHT);
	Core::RegisterUpdateFn( update );
	Core::RegisterDrawFn( draw );
	Core::GameLoop();
}




