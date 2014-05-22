#include "Randomer.h"

const float TWO_PI = 2 * 3.14159F;

Randomer::Randomer()
{

}
Randomer::~Randomer()
{

}

float Randomer::randomFloat()
{
	return (float)rand() / RAND_MAX;
}

Vector2D Randomer::randomUnitVector()
{
	float angle = TWO_PI * randomFloat();
	Vector2D vector (cos(angle), sin(angle));
	return vector.Normalize();
}

float Randomer::randomInRange( float min, float max)
{
	//min = (min == 0) ? .0001F : min;
	//max = (max == 0) ? .0001F : max;
	//max = (min == max) ? max + .0001F : max;
	//return (rand() % ((int)max - (int)min)) + min;


	float r3 = min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(max-min)));
	return r3;
}