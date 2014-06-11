#include "GameManager.h"
//#define DEBUG_ON 1

const extern int SCREEN_WIDTH;
const extern int SCREEN_HEIGHT;

enum GameState
{
	SPLASH, PLAYING, OVER
};

Vector2D wallPoints[] =
{	Vector2D(512.0F,0.0F),		Vector2D(950.0F,200.0F),	Vector2D(1024.0F,384.0F),
	Vector2D(512.0F, 768.0F),	Vector2D(0.0F, 384.0F),		Vector2D(512.0F,0.0F) };
int numWallPoints = sizeof(wallPoints) / sizeof(wallPoints[0]);

Vector2D screenEdgePoints[] =
{
	Vector2D(0.0F,0.0F),		Vector2D((float)SCREEN_WIDTH,0.0F),
	Vector2D((float)SCREEN_WIDTH,(float)SCREEN_HEIGHT),		Vector2D(0.0F, (float)SCREEN_HEIGHT)
};
int numScreenEdgePoints = sizeof(screenEdgePoints) / sizeof(screenEdgePoints[0]);

Vector2D squarePoints[] =
{
	Vector2D(-50.0F, -50.0F),	Vector2D(+00.0F, -75.0F),	Vector2D(+50.0F, -50.0F),
	Vector2D(+50.0F, +50.0F),	Vector2D(-50.0F, +50.0F) };
int numSquarePoints = sizeof(squarePoints) / sizeof(squarePoints[0]);

Vector2D shipPoints[] =
{
	Vector2D(+00.00f, -28.50f),	Vector2D(+06.00f, +05.25f),	Vector2D(+08.25f, +05.25f),
	Vector2D(+08.25f, +22.50f),	Vector2D(+08.25f, +21.00f),	Vector2D(+23.25f, +21.00f),
	Vector2D(+08.25f, +12.00f),	Vector2D(+08.25f, +22.50f),	Vector2D(-08.25f, +22.50f),
	Vector2D(-08.25f, +12.00f),	Vector2D(-23.25f, +21.00f),	Vector2D(-08.25f, +21.00f),
	Vector2D(-08.25f, +22.50f),	Vector2D(-08.25f, +05.25f),	Vector2D(-06.00f, +05.25f)
};
int numShipPoints = sizeof(shipPoints) / sizeof(shipPoints[0]);

Vector2D turretPoints[] =
{
	Vector2D(-08.0F, +10.0F),	Vector2D(-08.0F, -08.0F),	Vector2D(-07.0F, -08.0F),
	Vector2D(-07.0F, -14.0F),	Vector2D(-05.0F, -14.0F),	Vector2D(-05.0F, -08.0F),
	Vector2D(-03.0F, -08.0F),	Vector2D(-03.0F, -06.0F),	Vector2D(+03.0F, -06.0F),
	Vector2D(+03.0F, -08.0F),	Vector2D(+05.0F, -08.0F),	Vector2D(+05.0F, -14.0F),
	Vector2D(+07.0F, -14.0F),	Vector2D(+07.0F, -08.0F),	Vector2D(+08.0F, -08.0F),
	Vector2D(+08.0F, +10.0F)
};
int numTurretPoints = sizeof(turretPoints) / sizeof(turretPoints[0]);

Vector2D asteroidPoints[] =
{
	Vector2D(-33.0f, +00.0f),	Vector2D(-13.0f, -05.0f),	Vector2D(-10.0f, -16.0f),
	Vector2D(+03.0f, -28.0f),	Vector2D(+30.0f, -14.0f),	Vector2D(+29.0f, +02.0f),
	Vector2D(+34.0f, +15.0f),	Vector2D(+16.0f, +25.0f),	Vector2D(+03.0f, +28.0f),
	Vector2D(-08.0f, +28.0f),	Vector2D(-27.0f, +17.0f)
};
int numAsteroidPoints = sizeof(asteroidPoints) / sizeof(asteroidPoints[0]);

Vector2D asteroidPathPoints[] =
{
	Vector2D(+224.0f, +100.0f),	Vector2D(+700.0f, +200.0f),	Vector2D(+600.0f, +300.0f),
	Vector2D(+050.0f, +100.0f)
};
int numAsteroidPathPoints = sizeof(asteroidPathPoints) / sizeof(asteroidPathPoints[0]);

Vector2D asteroidPathPoints2[] =
{
	Vector2D(+824.0f, +100.0f),	Vector2D(+700.0f, +500.0f),	Vector2D(+600.0f, +200.0f),
	Vector2D(+050.0f, +100.0f)
};
int numAsteroidPathPoints2 = sizeof(asteroidPathPoints2) / sizeof(asteroidPathPoints2[0]);


extern WallMode gameMode = BOUNCE;
extern Logger* myLogger = NULL;
extern Profiler* myProfiler = NULL;
extern Shape* walls = NULL;
extern Shape* screenEdge = NULL;
extern DrawThing* myDrawThing = NULL;
extern Randomer* myRandomer = NULL;
extern EffectManager* myEffectManager = NULL;
extern GameObjectManager* goManager = NULL;
extern SpaceShip* theShip = NULL;
extern GameObjectManager* projectileManager = NULL;
extern EnemyManager* enemyManager = NULL;
extern Clock* myClock = NULL;
extern Clock* profilerClock = NULL;


GameObject* wallsObj = NULL;
GameObject* lifeObj = NULL;
GameState currentGameState = SPLASH;
float enemySpawnTimerReset = 5.0F;
float enemySpawnTimer = enemySpawnTimerReset;
float previousEnemySpawn = 0;

GameManager::GameManager(void)
{
	wallsObj = new GameObject(Vector2D(0,0),Vector2D(0,0),5, wallPoints, RGB(255,128,0));
	lifeObj = new GameObject(Vector2D((float)(SCREEN_WIDTH / 2) - 50, (float)(20)),Vector2D(0,0),numShipPoints, shipPoints, RGB(255,255,0));
	lifeObj->scale = .3f;
	enemiesDestroyed = 0;
	livesRemaining = 5;
	shotsFired = 0;
	score = 0;
	enemySpawnTimerReset = 5.0F;
	enemySpawnTimer = enemySpawnTimerReset;
	previousEnemySpawn = 0;
}

GameManager::~GameManager(void)
{
}

void GameManager::removeLife()
{
	livesRemaining--;
	myEffectManager->addEffect(new ExplosionEffect(theShip->position, 100, RGB(255,128,0), 3));
	theShip->position = Vector2D((float)(SCREEN_WIDTH / 2), (float)(SCREEN_HEIGHT / 2));
	theShip->velocity = Vector2D(0,0);
	theShip->angle = 0;
}

bool GameManager::initialize()
{
	myLogger = new Logger;
	LOG(Engine::Logging::Info, "myLogger created.");
	const char* loggerFileName = "logger.html";
	myLogger->initialize(loggerFileName);
	LOG(Engine::Logging::Info, "myLogger initialized.");
		
	myProfiler = new Profiler;
	LOG(Engine::Logging::Info, "myProfiler created.");
	const char* profileFileName = "profiler.csv";
	myProfiler->initialize(profileFileName);
	LOG(Engine::Logging::Info, "myProfiler initialized.");

	bool forceFail = false;
	ASSERT(!forceFail, "Forced to fail to test the asserter")

	walls = new Shape(numWallPoints, wallPoints);
	LOG(Engine::Logging::Info, "walls created.");
	screenEdge = new Shape(numScreenEdgePoints, screenEdgePoints);
	LOG(Engine::Logging::Info, "screenEdge created.");
	myDrawThing = new DrawThing;
	LOG(Engine::Logging::Info, "myDrawThing created.");
	myRandomer = new Randomer;
	LOG(Engine::Logging::Info, "myRandomer created.");
	myEffectManager = new EffectManager;
	LOG(Engine::Logging::Info, "myEffectManager created.");
	myEffectManager->addEffect(new StarBackgroundEffect(Vector2D(0,0), 100, RGB(192,192,192), 1));
	LOG(Engine::Logging::Info, "Added background effect to the myEffectManager.");
	
	goManager = new GameObjectManager;
	LOG(Engine::Logging::Info, "goManager created.");
	theShip = new SpaceShip(Vector2D((float)(SCREEN_WIDTH / 2), (float)(SCREEN_HEIGHT / 2)),Vector2D(0,0),numShipPoints, shipPoints, RGB(255,255,255), new GameObject(Vector2D(0,0),Vector2D(0,0),numTurretPoints, turretPoints, RGB(255,255,255)));
	LOG(Engine::Logging::Info, "theShip created.");
	ASSERT((theShip != NULL), "theShip is null")

	projectileManager = new GameObjectManager;
	LOG(Engine::Logging::Info, "projectileManager created.");
	enemyManager = new EnemyManager;
	LOG(Engine::Logging::Info, "enemyManager created.");
	myClock = new Clock;
	LOG(Engine::Logging::Info, "myClock created.");
	myClock->initialize();
	LOG(Engine::Logging::Info, "myClock initialized.");
	myClock->newFrame();

	profilerClock = new Clock;
	LOG(Engine::Logging::Info, "profilerClock created.");
	profilerClock->initialize();
	LOG(Engine::Logging::Info, "profilerClock initialized.");
	profilerClock->newFrame();

	// Everything is set up.
	return true;
}


bool GameManager::shutdown()
{
	currentGameState = OVER;
	myClock->shutdown();
	profilerClock->shutdown();
	myProfiler->shutdown();
	myLogger->shutdown();

	
	delete walls;
	delete wallsObj;
	delete lifeObj;
	delete theShip;
	delete projectileManager;
	delete screenEdge;
	delete myDrawThing;
	delete profilerClock;
	delete myClock;
	delete myRandomer;
	delete myEffectManager;
	delete goManager;
	delete enemyManager;
	delete myLogger;
	delete myProfiler;
	return true;
}

void GameManager::draw( Core::Graphics& g)
{
	if (currentGameState == SPLASH) 
	{					
		g.SetColor(RGB(255,255,0)); // YELLOW
		g.DrawString(10, 5, "Read to play?");
		g.DrawString(10, 20, "Press the letter 'g' to play.");
	}

	else if (currentGameState == PLAYING)
	{
		// Draw the Walls
		if (gameMode == WALLS)
		{
			Matrix3D t;
			wallsObj->draw(g, t);
		}

		// Draw the SpaceShip
		theShip->draw(g);
		myProfiler->addEntry("Draw SpaceShip", profilerClock->timeElapsedLastFrame());
		profilerClock->newFrame();

		// Draw the Game info
		g.SetColor(RGB(255,255,0)); // YELLOW
		std::stringstream ss;
		ss << "Shots fired: " << shotsFired;
		g.DrawString(10, 5, ss.str().c_str());
		ss.str(std::string());
		ss << "Enemies destroyed: " << enemiesDestroyed;
		g.DrawString(10, 20, ss.str().c_str());
		ss.str(std::string());
		ss << "Score: " << score;
		g.DrawString((SCREEN_WIDTH - 125), 5, ss.str().c_str());
		ss.str(std::string());
		ss << "Next spawn: " << enemySpawnTimer;
		g.DrawString((SCREEN_WIDTH - 125), 20, ss.str().c_str());

		for (int i = 0; i < livesRemaining; i++) 
		{
			lifeObj->position = lifeObj->position + Vector2D((float)(i * 15), 0.0f);
			lifeObj->draw(g);
			lifeObj->position = Vector2D((float)(SCREEN_WIDTH / 2) - 50, (float)(20));
		}
		lifeObj->position = Vector2D((float)(SCREEN_WIDTH / 2) - 50, (float)(20));
		myProfiler->addEntry("Draw Game Info", profilerClock->timeElapsedLastFrame());
		profilerClock->newFrame();

		// Draw the Game Objects
		goManager->draw(g);
		myProfiler->addEntry("Draw Main Objects", profilerClock->timeElapsedLastFrame());
		profilerClock->newFrame();

		// Draw the Projectiles
		projectileManager->draw(g);
		myProfiler->addEntry("Draw Projectiles", profilerClock->timeElapsedLastFrame());
		profilerClock->newFrame();

		// Draw the Enemies
		enemyManager->draw(g);
		myProfiler->addEntry("Draw Enemies", profilerClock->timeElapsedLastFrame());
		profilerClock->newFrame();

		// Draw the Particles
		myEffectManager->draw(g);
		myProfiler->addEntry("Draw Particle Effects", profilerClock->timeElapsedLastFrame());
		profilerClock->newFrame();

#ifdef DEBUG_ON
		// Draw the debug stuff
		myDrawThing->draw(g);	
		myProfiler->addEntry("Draw Debug Info", profilerClock->timeElapsedLastFrame());
		profilerClock->newFrame();
#endif
	}
	else if (currentGameState == OVER)
	{
		g.SetColor(RGB(255,255,0)); // YELLOW
		g.DrawString(10, 5, "The Game is over.");
		std::stringstream ss;
		ss << "Your score is " << score;
		g.DrawString(10, 20, ss.str().c_str());
		ss.str(std::string());
		ss << "You fired " << shotsFired << " shots.";
		g.DrawString(10, 35, ss.str().c_str());
		ss.str(std::string());
		ss << "You destroyed " << enemiesDestroyed << " enemies.";
		g.DrawString(10, 50, ss.str().c_str());
		//ss.str(std::string());
		//ss << "You played for " << totalTime << " xxx.";
		//g.DrawString(10, 65, ss.str().c_str());
		ss.str(std::string());
		ss << "Press Esc to quit.";
		g.DrawString(10, 80, ss.str().c_str());
	}

}

bool GameManager::update(float dt)
{
	if (currentGameState == SPLASH)
	{		
		if (Core::Input::IsPressed( 'G' ))
		{
			currentGameState = PLAYING;
		}
	}

	if (currentGameState == PLAYING)
	{
		if (livesRemaining <= 0) 
		{
			currentGameState = OVER;
		}

		// Set the Lap on the Clock
//		totalTime = myClock->timeElapsedSinceStart();
		float deltaTime = myClock->timeElapsedLastFrame();
		myClock->newFrame();
		// Display FPS timer
		myDrawThing->setSPF(deltaTime);
		myDrawThing->setFPS(1/deltaTime);

		// Add enemies
		myProfiler->newFrame();
		enemySpawnTimer -= deltaTime;
		if (enemySpawnTimer < 0) {
		
			enemyManager->addEnemy();
			enemySpawnTimer = enemySpawnTimerReset;
			enemySpawnTimerReset -= .22f;
		}
		myProfiler->addEntry("Add Enemies", profilerClock->timeElapsedLastFrame());
		profilerClock->newFrame();

		// Update the Spaceship
		theShip->update(dt);
		myProfiler->addEntry("Update Spaceship", profilerClock->timeElapsedLastFrame());
		profilerClock->newFrame();

		// Update the Game Objects
		goManager->update(dt);
		myProfiler->addEntry("Update Main Objects", profilerClock->timeElapsedLastFrame());
		profilerClock->newFrame();

		// Update the Projectiles
		projectileManager->update(dt);
		myProfiler->addEntry("Update Projectiles", profilerClock->timeElapsedLastFrame());
		profilerClock->newFrame();

		// Update the Enemies
		enemyManager->update(dt);
		myProfiler->addEntry("Update Enemies", profilerClock->timeElapsedLastFrame());
		profilerClock->newFrame();

		// Update the Particles
		myEffectManager->update(dt);
		myProfiler->addEntry("Update Particle Effects", profilerClock->timeElapsedLastFrame());
		profilerClock->newFrame();

		// Update the Walls
		wallsObj->update(dt);
		myProfiler->addEntry("Update Walls", profilerClock->timeElapsedLastFrame());
		profilerClock->newFrame();

		if ( Input::IsPressed( '1' ) )
		{
			gameMode = WRAP;
			myDrawThing->setString(0, "WRAP");
		}
		if ( Input::IsPressed( '2' ) )
		{
			gameMode = BOUNCE;
			myDrawThing->setString(0, "BOUNCE");
		}
		if ( Input::IsPressed( '3' ) )
		{
			gameMode = WALLS;
			myDrawThing->setString(0, "WALLS");
		}

		myDrawThing->setEnemiesDestroyed(enemiesDestroyed);
	}

	else if (currentGameState == OVER)
	{

	}
	
	return true;
}

bool GameManager::isOutOfBounds(Vector2D& pos)
{	
	Shape* boundsShape;
	if (gameMode == WALLS)
	{
		boundsShape = walls;

	} else {
		boundsShape = screenEdge;
	}
	
	for (int i =0 ; i < boundsShape->getNumPoints(); i++)
	{
		Vector2D& wallPointLeft = boundsShape->get(i);
		Vector2D& wallPointRight = boundsShape->get((i + 1) % boundsShape->getNumPoints());
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
