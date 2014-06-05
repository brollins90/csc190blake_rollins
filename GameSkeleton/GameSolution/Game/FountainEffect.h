#ifndef FOUNTAIN_EFFECT_H
#define FOUNTAIN_EFFECT_H

#include "Core.h"
#include "ParticleEffect.h"
#include "Matrix3D.h"

using Engine::Matrix3D;

class FountainEffect : public ParticleEffect
{
public:
	FountainEffect(Vector2D inOrigin, int inNumParticles, RGB inBaseColor, float inLifeTime);
	~FountainEffect(void);
	
	bool resetAfterLife;
	float fountainAngle;

	void draw(Core::Graphics& g);
	virtual	bool update(float dt);

	void setFountainAngle(float inAngle);
};

#endif