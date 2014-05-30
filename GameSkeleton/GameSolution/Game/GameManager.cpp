#include "GameManager.h"

#include "Engine.h"
#include "Core.h"
#include <sstream>
#include "DrawThing.h"
#include "Shape.h"
#include "GameObject.h"
#include "WallMode.h"
#include "SpaceShip.h"
#include "LerpingObject.h"
#include "ParticleEffect.h"
#include "ExplosionEffect.h"
#include "FountainEffect.h"
#include "Randomer.h"
#include "EffectManager.h"
#include "GameObjectManager.h"

using Core::Input;

const extern int SCREEN_WIDTH;
const extern int SCREEN_HEIGHT;

extern WallMode gameMode = WALLS;

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

int numScreenEdgePoints = 4;
Vector2D screenEdgePoints[] =
{
	Vector2D(0.0F,0.0F),
	Vector2D((float)SCREEN_WIDTH,0.0F),
	Vector2D((float)SCREEN_WIDTH,(float)SCREEN_HEIGHT),
	Vector2D(0.0F, (float)SCREEN_HEIGHT)
};

int numSquarePoints = 5;
Vector2D square[] =
{
	Vector2D(-50.0F, -50.0F),
	Vector2D(+00.0F, -75.0F),
	Vector2D(+50.0F, -50.0F),
	Vector2D(+50.0F, +50.0F),
	Vector2D(-50.0F, +50.0F)
};

int numShipPoints = 15;
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

int numTurretPoints = 16;
Vector2D turretPoints[] =
{
	Vector2D(-08.0F, +10.0F),
	Vector2D(-08.0F, -08.0F),
	Vector2D(-07.0F, -08.0F),
	Vector2D(-07.0F, -14.0F),
	Vector2D(-05.0F, -14.0F),
	Vector2D(-05.0F, -08.0F),
	Vector2D(-03.0F, -08.0F),
	Vector2D(-03.0F, -06.0F),
	Vector2D(+03.0F, -06.0F),
	Vector2D(+03.0F, -08.0F),
	Vector2D(+05.0F, -08.0F),
	Vector2D(+05.0F, -14.0F),
	Vector2D(+07.0F, -14.0F),
	Vector2D(+07.0F, -08.0F),
	Vector2D(+08.0F, -08.0F),
	Vector2D(+08.0F, +10.0F)
};

int numAsteroidPoints = 11;
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

int numAsteroidPathPoints2 = 4;
Vector2D asteroidPathPoints2[] =
{
	Vector2D(+824.0f, +100.0f),
	Vector2D(+700.0f, +500.0f),
	Vector2D(+600.0f, +200.0f),
	Vector2D(+050.0f, +100.0f)
};



extern Shape* walls = new Shape(numWallPoints, wallPoints);
extern Shape* screenEdge = new Shape(numScreenEdgePoints, screenEdgePoints);
extern DrawThing* myDrawThing = new DrawThing;
extern Randomer* myRandomer = new Randomer;
extern EffectManager* myEffectManager = new EffectManager;
extern GameObjectManager* goManager = new GameObjectManager;

GameObject wallsObj(Vector2D(0,0),Vector2D(0,0),5, wallPoints);
GameObject laser1(Vector2D(0,0),Vector2D(0,0),numTurretPoints, turretPoints);


GameManager::GameManager(void)
{

	laser1.scale = .25F;
	myEffectManager->addEffect(new ExplosionEffect(Vector2D(300,300), 1000, RGB(255,128,0), 5));
	myEffectManager->addEffect(new ExplosionEffect(Vector2D(500,300), 1000, RGB(255,128,0), 2));
	myEffectManager->addEffect(new ExplosionEffect(Vector2D(400,400), 1000, RGB(255,128,0), 10));


	goManager->addObject(new SpaceShip(Vector2D((float)(SCREEN_WIDTH / 2), (float)(SCREEN_HEIGHT / 2)),Vector2D(0,0),numShipPoints, shipPoints,new GameObject(Vector2D(0,0),Vector2D(0,0),numTurretPoints, turretPoints),&laser1));
	goManager->addObject(new LerpingObject(Vector2D(50,50), Vector2D(4,0), numAsteroidPoints, asteroidPoints, 4, asteroidPathPoints, false, NULL));

	LerpingObject* r1 = new LerpingObject(Vector2D(200,200), Vector2D(5,5), numAsteroidPoints, asteroidPoints, 0, NULL, false, NULL);
	LerpingObject* r2 = new LerpingObject(Vector2D(300,300), Vector2D(5,5), numAsteroidPoints, asteroidPoints, 0, NULL, true, r1);
	LerpingObject* r3 = new LerpingObject(Vector2D(400,400), Vector2D(5,5), numAsteroidPoints, asteroidPoints, numAsteroidPathPoints2, asteroidPathPoints2, true, r2);
	goManager->addObject(r3);
}

GameManager::~GameManager(void)
{
}

void GameManager::draw( Core::Graphics& g)
{
	if (gameMode == WALLS)
	{
		g.SetColor(RGB(255,255,255)); // WHITE
		Matrix3D t;
		wallsObj.draw(g, t);
	}

	g.SetColor(RGB(128,128,128));
	goManager->draw(g);
	myEffectManager->draw(g);
	
	// Draw the debug stuff
	myDrawThing->draw(g);	
}

bool GameManager::update(float dt)
{
	wallsObj.update(dt);

	goManager->update(dt);
	myEffectManager->update(dt);
	
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
