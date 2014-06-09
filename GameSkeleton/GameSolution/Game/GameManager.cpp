#include "GameManager.h"

const extern int SCREEN_WIDTH;
const extern int SCREEN_HEIGHT;

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
extern Logger* myLogger = new Logger;
extern Profiler* myProfiler = new Profiler;
extern Shape* walls = new Shape(numWallPoints, wallPoints);
extern Shape* screenEdge = new Shape(numScreenEdgePoints, screenEdgePoints);
extern DrawThing* myDrawThing = new DrawThing;
extern Randomer* myRandomer = new Randomer;
extern EffectManager* myEffectManager = new EffectManager;
extern GameObjectManager* goManager = new GameObjectManager;
extern GameObjectManager* projectileManager = new GameObjectManager;
extern EnemyManager* enemyManager = new EnemyManager;
extern Clock* myClock = new Clock;
extern Clock* profilerClock = new Clock;


GameObject wallsObj(Vector2D(0,0),Vector2D(0,0),5, wallPoints, RGB(255,128,0));

float enemySpawnTimer = 5.0F;
float previousEnemySpawn = 0;

GameManager::GameManager(void)
{
	enemiesDestroyed = 0;
}

GameManager::~GameManager(void)
{
}

bool GameManager::initialize()
{
	myClock->initialize();
	myClock->newFrame();
	profilerClock->initialize();
	profilerClock->newFrame();
	const char* loggerFileName = "logger.html";
	myLogger->initialize(loggerFileName);
	const char* profileFileName = "profiler.csv";
	myProfiler->initialize(profileFileName);

//	bool forceFail = true;
	ASSERT(true, "force to fail to test the asserter")

	goManager->addObject(new SpaceShip(Vector2D((float)(SCREEN_WIDTH / 2), (float)(SCREEN_HEIGHT / 2)),Vector2D(0,0),numShipPoints, shipPoints, RGB(255,255,255), new GameObject(Vector2D(0,0),Vector2D(0,0),numTurretPoints, turretPoints, RGB(255,255,255))));
	//goManager->addObject(new LerpingObject(Vector2D(50,50), Vector2D(1,0), numAsteroidPoints, asteroidPoints, RGB(255,128,0), 4, asteroidPathPoints, false, NULL));

	//LerpingObject* r1 = new LerpingObject(Vector2D(200,200), Vector2D(10,0), numAsteroidPoints, asteroidPoints, RGB(255,128,0), 0, NULL, false, NULL);
	//LerpingObject* r2 = new LerpingObject(Vector2D(300,300), Vector2D(2,0), numAsteroidPoints, asteroidPoints, RGB(255,128,0), 0, NULL, true, r1);
	//LerpingObject* r3 = new LerpingObject(Vector2D(400,400), Vector2D(7,0), numAsteroidPoints, asteroidPoints, RGB(255,128,0), numAsteroidPathPoints2, asteroidPathPoints2, true, r2);
	//goManager->addObject(r3);

	myEffectManager->addEffect(new StarBackgroundEffect(Vector2D(0,0), 100, RGB(192,192,192), 1));
	return true;
}

bool GameManager::shutdown()
{
	myClock->shutdown();
	profilerClock->shutdown();
	myProfiler->shutdown();
	myLogger->shutdown();
	return true;
}

void GameManager::draw( Core::Graphics& g)
{
	// Draw the Walls
	if (gameMode == WALLS)
	{
		Matrix3D t;
		wallsObj.draw(g, t);
	}

	// Draw the SpaceShip
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
		
	// Draw the debug stuff
	myDrawThing->draw(g);	
	myProfiler->addEntry("Draw Debug Info", profilerClock->timeElapsedLastFrame());
	profilerClock->newFrame();
}

bool GameManager::update(float dt)
{
	// Set the Lap on the Clock
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
		enemySpawnTimer = 5;
	}
	myProfiler->addEntry("Add Enemies", profilerClock->timeElapsedLastFrame());
	profilerClock->newFrame();

	// Update the Spaceship
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
	wallsObj.update(dt);
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
