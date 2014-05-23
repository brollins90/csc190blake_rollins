#ifndef FOUNTAINEFFECT_H
#define FOUNTAINEFFECT_H

#include "Core.h"
#include "ParticleEffect.h"

class FountainEffect : public ParticleEffect
{
public:
	Vector2D orgPosition;

	FountainEffect(Vector2D* inOrigin, int inNumParticles, RGB inBaseColor, int inLifeTime);
	~FountainEffect(void);
	void draw(Core::Graphics& g);
	bool update(float dt);
};

#endif