#ifndef EXPLOSION_EFFECT_H
#define EXPLOSION_EFFECT_H

#include "Core.h"
#include "ParticleEffect.h"

class ExplosionEffect : public ParticleEffect
{
public:
	ExplosionEffect(Vector2D inOrigin, int inNumParticles, RGB inBaseColor, float inLifetime);
	~ExplosionEffect(void);

	void draw(Core::Graphics& g);
	virtual	bool update(float dt);
};

#endif