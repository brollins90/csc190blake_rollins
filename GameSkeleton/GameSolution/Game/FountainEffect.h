#ifndef FOUNTAINEFFECT_H
#define FOUNTAINEFFECT_H

#include "Core.h"
#include "ParticleEffect.h"
#include "Randomer.h"

class FountainEffect : public ParticleEffect
{
public:
	FountainEffect(Vector2D inPosition);
	~FountainEffect(void);
	void draw(Core::Graphics& g);
	bool update(float dt);
};

#endif