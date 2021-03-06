#ifndef EXPLOSION_EFFECT_H
#define EXPLOSION_EFFECT_H

#include "Core.h"
#include "DebugMemory.h"
#include "ParticleEffect.h"

class ExplosionEffect : public ParticleEffect
{
public:
	ExplosionEffect(Vector2D inOrigin, int inNumParticles, RGB inBaseColor, float inLifetime);

	void draw(Core::Graphics& g);
	virtual	bool update(float dt);
};

#endif