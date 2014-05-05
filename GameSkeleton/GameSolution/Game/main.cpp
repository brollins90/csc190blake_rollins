#include "Engine.h"
#include "Core.h"
#include <sstream>
#include "Shape.h"

//#include "SpaceShip2.h"
using Engine::Vector2D;
using Core::Input;

const static int SCREEN_WIDTH = 1024;
const static int SCREEN_HEIGHT = 768;

float floatsToDebug[10] = {0.0f};

int numWallPoints = 5;
Vector2D wallPoints[] =
{
	Vector2D((SCREEN_WIDTH / 2), 0),
	Vector2D((float)SCREEN_WIDTH,(SCREEN_HEIGHT / 2)),
	Vector2D((SCREEN_WIDTH / 2), (float)SCREEN_HEIGHT),
	Vector2D(0, (SCREEN_HEIGHT / 2)),
	Vector2D((SCREEN_WIDTH / 2), 0)
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
	Vector2D(+50.0f, +20.0f),
	Vector2D(+205.0f, +50.0f),
	Vector2D(+75.0f, +05.0f),
	Vector2D(+300.0f, +100.0f)
};

enum MODE 
{
	WRAP = 1,
	BOUNCE = 2,
	WALLS = 3
};

MODE gameMode = WRAP;


void DrawValue(Core::Graphics& g, int x, int y, float num)
{
	std::stringstream ss;
	ss << num;
	g.DrawString(x, y, ss.str().c_str());
}
//
//class Shape
//{
//public:
//	int NUM_POINTS;
//	Vector2D* shapePoints;
//	Shape(int numPoints, Vector2D* inShapePoints)
//	{
//		NUM_POINTS = numPoints;
//		shapePoints = new Vector2D[NUM_POINTS];
//		
//		for (int i = 0; i < NUM_POINTS; i++)
//		{
//			shapePoints[i] = inShapePoints[i];
//		}
//	}
//	~Shape()
//	{
//		delete shapePoints;
//	}
//	void draw( Core::Graphics& g, Vector2D& pos )
//	{
//		for (int i = 0; i< NUM_POINTS; i++) 
//		{
//			const Vector2D& p1 = pos + shapePoints[i];
//			const Vector2D& p2 = pos + shapePoints[(i + 1) % NUM_POINTS];
//			g.DrawLine(p1.x, p1.y, p2.x, p2.y);
//		}
//	}
//};


class GameObject
{
protected:
	Vector2D position;
	Vector2D velocity;
	Shape* shape;
public:
	GameObject(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints)
	{
		position = inPosition;
		velocity = inVelocity;
		shape = new Shape(numPoints, inShapePoints);
	}
	~GameObject()
	{
		delete &position;
		delete &velocity;
		delete shape;
	}
	void draw( Core::Graphics& g )
	{
		shape->draw(g, position);
	}

	void update(float dt)
	{
		dt;
	}

};


class SpaceShip : GameObject
{
public:
	SpaceShip(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints) : GameObject(inPosition, inVelocity, numPoints, inShapePoints)
	{
	}
	void draw (Core::Graphics& g)
	{
		GameObject::draw(g);
	}
	void update (float dt)
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
		
		if (gameMode == WRAP)
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
		if (gameMode == BOUNCE)
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
		if (gameMode == WALLS)
		{
			for (int i =0 ; i < numWallPoints; i++)
			{
				Vector2D& wallA = wallPoints[i];
				Vector2D& wallB = wallPoints[(i + 1) % numWallPoints];
				Vector2D shipVect = position - wallA;
				Vector2D wallVect = wallB - wallA;
				Vector2D wallVectPerp = wallVect.PerpCCW().Normalize();
				float f1 = wallVectPerp.DotProduct(shipVect);
				//floats[0] = f1;

				if (f1 < 0) 
				{
					Vector2D red = wallVectPerp * Vector2D::DotProduct(velocity, wallVectPerp);
//					floats[1] = red.x;
	//				floats[2] = red.y;

					velocity = velocity + (red * -2);
				}
			}

		}
	}
};


class Asteroid : GameObject
{
private:
	int NUM_PATH_POINTS;
	int pointInPath;
	Vector2D* pathPoints;
public:
	Asteroid(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints, int numPathPoints, Vector2D* inPathPoints) : GameObject(inPosition, inVelocity, numPoints, inShapePoints)
	{
		pointInPath = 0;
		NUM_PATH_POINTS = numPathPoints;
		pathPoints = new Vector2D[NUM_PATH_POINTS];
		
		for (int i = 0; i < NUM_PATH_POINTS; i++)
		{
			pathPoints[i] = inPathPoints[i];
		}

	}
	void draw (Core::Graphics& g)
	{
		GameObject::draw(g);
	}
	void update (float dt)
	{
		dt;
//		GameObject::update(dt);
		
		position = pathPoints[(pointInPath++) % NUM_PATH_POINTS];
		floatsToDebug[0] = position.x;
		floatsToDebug[1] = position.y;
	}
};







GameObject walls(Vector2D(0,0),Vector2D(0,0),5, wallPoints);

SpaceShip myShip(Vector2D((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2)),Vector2D(0,0),8, shipPoints);

Asteroid myAsteroid(Vector2D(50,50), Vector2D(0,0), 4, asteroidPoints, 4, asteroidPathPoints);

bool update(float dt)
{
	walls.update(dt);
	myShip.update(dt);
	myAsteroid.update(dt);

	if (Input::IsPressed( Input::KEY_ESCAPE ))
	{
		return true;
	}
	if ( Input::IsPressed( '1' ) )
	{
		gameMode = WRAP;
	}
	if ( Input::IsPressed( '2' ) )
	{
		gameMode = BOUNCE;
	}
	if ( Input::IsPressed( '3' ) )
	{
		gameMode = WALLS;
	}
	return false;
}

void draw( Core::Graphics& g )
{
//	graphics.SetColor( RGB(255,255,255) );
//	graphics.DrawString( SCREEN_WIDTH/2 - 50, SCREEN_HEIGHT/2 - 20, "Hello World");
//	graphics.DrawLine( 10, 10, 400, 300);

	walls.draw(g);
	myShip.draw(g);
	myAsteroid.draw(g);
	
	DrawValue(g, 10, 5, floatsToDebug[0]);
	DrawValue(g, 10, 15, floatsToDebug[1]);
	DrawValue(g, 10, 25, floatsToDebug[2]);
	DrawValue(g, 10, 35, floatsToDebug[3]);
	DrawValue(g, 10, 45, floatsToDebug[4]);
	DrawValue(g, 10, 55, floatsToDebug[5]);
	DrawValue(g, 10, 65, floatsToDebug[6]);
	DrawValue(g, 10, 75, floatsToDebug[7]);
	DrawValue(g, 10, 85, floatsToDebug[8]);
	DrawValue(g, 10, 95, floatsToDebug[9]);
}

void main()
{
	
	//myShip.position = Engine::Vector2D((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2));
	Core::Init( "Game Demo", SCREEN_WIDTH, SCREEN_HEIGHT);
	Core::RegisterUpdateFn( update );
	Core::RegisterDrawFn( draw );
	Core::GameLoop();
}

