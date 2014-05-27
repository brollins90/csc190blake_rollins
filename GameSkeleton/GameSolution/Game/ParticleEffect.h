#ifndef PARTICLEEFFECT_H
#define PARTICLEEFFECT_H

#include "Core.h"
#include "Particle.h"
#include "Randomer.h"

extern Randomer* myRandomer;

class ParticleEffect
{
public:
	Vector2D origin;
	int lifetime;
	int numParticles;
	Particle* particles;

	ParticleEffect(Vector2D inOrigin, int inNumParticles, RGB inBaseColor, int inLifetime);
	~ParticleEffect(void);
	
	virtual void draw(Core::Graphics& g);
	virtual bool update(float dt);
	void setOrigin(Vector2D newOrigin);
};

#endif