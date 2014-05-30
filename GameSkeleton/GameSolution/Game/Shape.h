#ifndef SHAPE_H
#define SHAPE_H

#include "Engine.h"
#include "Core.h"

using Engine::Vector2D;
using Engine::Matrix3D;

class Shape
{
private:
	int NUM_POINTS;
	Vector2D* shapePoints;
	Matrix3D translation;
public:
	Shape(int numberOfPoints, Vector2D* inputPoints);
	~Shape(void);

	void draw( Core::Graphics& g, Vector2D& pos);
	void draw( Core::Graphics& g, Matrix3D& m);

	void addMatrixTranslation(Matrix3D&);
	int getNumPoints();
	Vector2D& get(int index);
};


#endif