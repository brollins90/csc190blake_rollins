#ifndef PARTICLEEFFECT_H
#define PARTICLEEFFECT_H

#include "Core.h"
#include "Particle.h"

class ParticleEffect
{
public:
	int numParticles;
	Particle* particles;
	Vector2D position;
	ParticleEffect(Vector2D origin);
	~ParticleEffect(void);
	virtual bool update(float dt);
	virtual void draw(Core::Graphics& g);
};

#endif