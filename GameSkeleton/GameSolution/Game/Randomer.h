#ifndef RANDOMER_H
#define RANDOMER_H

#include "Engine.h"
using Engine::Vector2D;


class Randomer
{
public:
	Randomer(void);
	~Randomer(void);
	float randomFloat();
	float randomInRange(float min, float max);
	Vector2D randomUnitVector();
};

#endif