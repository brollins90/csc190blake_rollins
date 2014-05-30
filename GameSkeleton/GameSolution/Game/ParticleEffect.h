#ifndef PARTICLE_EFFECT_H
#define PARTICLE_EFFECT_H

#include "Core.h"
#include "Particle.h"
#include "Randomer.h"

extern Randomer* myRandomer;

class ParticleEffect
{
public:
	ParticleEffect(Vector2D inOrigin, int inNumParticles, RGB inBaseColor, int inLifetime);
	~ParticleEffect(void);
	
	Vector2D origin;
	Particle* particles;
	int lifetime;
	int numParticles;

	virtual void draw(Core::Graphics& g);
	virtual bool update(float dt);

	void setOrigin(Vector2D newOrigin);
};

#endif