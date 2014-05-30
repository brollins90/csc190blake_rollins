#ifndef PARTICLE_H
#define PARTICLE_H

#include "Engine.h"
#include "Core.h"

using Engine::Vector2D;
using Core::RGB;

class Particle
{
public:
	Particle(void);
	Particle(Vector2D inPosition, Vector2D inVelocity, RGB inColor);
	~Particle(void);

	RGB color;
	Vector2D position;
	Vector2D positionOrg;
	Vector2D veloctiy;
	float lifetime;
};
#endif