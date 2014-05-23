#ifndef EXPLOSIONEFFECT_H
#define EXPLOSIONEFFECT_H

#include "Core.h"
#include "ParticleEffect.h"

class ExplosionEffect : public ParticleEffect
{
public:
	ExplosionEffect(Vector2D* inOrigin, int inNumParticles, RGB inBaseColor, int inLifetime);
	~ExplosionEffect(void);
	void draw(Core::Graphics& g);
	bool update(float dt);
};

#endif