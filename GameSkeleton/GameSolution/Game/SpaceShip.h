#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Vector2D.h"
#include "Core.h"

class SpaceShip
{
public:
	Engine::Vector2D position;
	Engine::Vector2D velocity;
	void draw(Core::Graphics&);
	void update(float);
	SpaceShip(void);
	~SpaceShip(void);
};

#endif