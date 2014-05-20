#include "Shape.h"


Shape::Shape(int numberOfPoints, Vector2D* inputPoints)
{
	NUM_POINTS = numberOfPoints;
	shapePoints = new Vector2D[NUM_POINTS];
		
	for (int i = 0; i < NUM_POINTS; i++)
	{
		shapePoints[i] = inputPoints[i];
	}
}

Shape::~Shape(void)
{
	delete shapePoints;
}

void Shape::draw( Core::Graphics& g, Vector2D& pos)
{
	for (int i = 0; i < NUM_POINTS; i++) 
	{
		const Vector2D& p1 = pos + shapePoints[i];
		const Vector2D& p2 = pos + shapePoints[(i + 1) % NUM_POINTS];
		g.DrawLine(p1.x, p1.y, p2.x, p2.y);
	}
}

void Shape::draw( Core::Graphics& g, Matrix3D& m)
{
	for (int i = 0; i < NUM_POINTS; i++) 
	{
		const Vector2D& p1 = m * shapePoints[i];
		const Vector2D& p2 = m * shapePoints[(i + 1) % NUM_POINTS];
		g.DrawLine(p1.x, p1.y, p2.x, p2.y);
	}
}

void Shape::addMatrixTranslation(Matrix3D& t)
{
	translation = Matrix3D(t);
}

int Shape::getNumPoints()
{
	return NUM_POINTS;
}

Vector2D& Shape::get(int index)
{
	return shapePoints[index];
}