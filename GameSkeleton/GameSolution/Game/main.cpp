#include "Engine.h"
#include "Core.h"
#include "SpaceShip2.h"
using Engine::Vector2D;
using Core::Input;

const static int SCREEN_WIDTH = 1024;
const static int SCREEN_HEIGHT = 768;

int numWallPoints = 5;
Vector2D wallPoints[] =
{
	Vector2D((SCREEN_WIDTH / 2), 0),
	Vector2D((float)SCREEN_WIDTH,(SCREEN_HEIGHT / 2)),
	Vector2D((SCREEN_WIDTH / 2), (float)SCREEN_HEIGHT),
	Vector2D(0, (SCREEN_HEIGHT / 2)),
	Vector2D((SCREEN_WIDTH / 2), 0)
};


class Shape
{
public:
	int NUM_POINTS;
	Vector2D* shapePoints;
	Shape(int numPoints, Vector2D* inShapePoints)
	{
		NUM_POINTS = numPoints;
		shapePoints = new Vector2D[NUM_POINTS];
		
		for (int i = 0; i < NUM_POINTS; i++)
		{
			shapePoints[i] = inShapePoints[i];
		}
	}
	~Shape()
	{
		delete shapePoints;
	}
	void draw( Core::Graphics& g, Vector2D& pos )
	{
		for (int i = 0; i< NUM_POINTS; i++) 
		{
			const Vector2D& p1 = pos + shapePoints[i];
			const Vector2D& p2 = pos + shapePoints[(i + 1) % NUM_POINTS];
			g.DrawLine(p1.x, p1.y, p2.x, p2.y);
		}
	}
};


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
		if (mode == 2)
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
		if (mode == 3)
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







GameObject walls(Vector2D(0,0),Vector2D(0,0),5, wallPoints);


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

SpaceShip myShip(Vector2D((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2)),Vector2D(0,0),8, shipPoints);

bool update(float dt)
{
	walls.update(dt);
	myShip.update(dt);

	if (Input::IsPressed( Input::KEY_ESCAPE ))
	{
		return true;
	}
	if ( Input::IsPressed( '1' ) )
	{

	}
	return false;
}

void draw( Core::Graphics &graphics )
{
//	graphics.SetColor( RGB(255,255,255) );
//	graphics.DrawString( SCREEN_WIDTH/2 - 50, SCREEN_HEIGHT/2 - 20, "Hello World");
//	graphics.DrawLine( 10, 10, 400, 300);

	walls.draw(graphics);
	myShip.draw(graphics);
}

void main()
{
	
	//myShip.position = Engine::Vector2D((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2));
	Core::Init( "Game Demo", SCREEN_WIDTH, SCREEN_HEIGHT);
	Core::RegisterUpdateFn( update );
	Core::RegisterDrawFn( draw );
	Core::GameLoop();
}

