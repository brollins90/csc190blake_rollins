#include "Asteroid.h"

Asteroid::Asteroid(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints, int numPathPoints, Vector2D* inPathPoints) : GameObject(inPosition, inVelocity, numPoints, inShapePoints)
{
	pointInPath = 0;
	pathShape = new Shape(numPathPoints, inPathPoints);
//	NUM_PATH_POINTS = numPathPoints;
//	pathPoints = new Vector2D[NUM_PATH_POINTS];
	//	
	//for (int i = 0; i < NUM_PATH_POINTS; i++)
	//{
	//	pathPoints[i] = inPathPoints[i];
	//}
}


void Asteroid::draw (Core::Graphics& g)
{
	GameObject::draw(g);
}
void Asteroid::update (float dt)
{
	dt;
//		GameObject::update(dt);
		
	position = pathShape->get((pointInPath++) % pathShape->getNumPoints());
	//floatsToDebug[0] = position.x;
	//floatsToDebug[1] = position.y;
}