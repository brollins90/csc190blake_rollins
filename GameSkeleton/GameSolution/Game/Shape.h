#ifndef SHAPE_H
#define SHAPE_H

#include "Engine.h"
#include "Core.h"

using Engine::Vector2D;

class Shape
{
private:
	int NUM_POINTS;
	Vector2D* shapePoints;
public:
	Shape(int numberOfPoints, Vector2D* inputPoints);
	~Shape(void);
	void draw( Core::Graphics& g, Vector2D& pos);
	int getNumPoints();
	Vector2D& get(int index);
};

#endif