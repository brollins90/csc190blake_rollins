#ifndef FOUNTAINEFFECT_H
#define FOUNTAINEFFECT_H

#include "Core.h"
#include "ParticleEffect.h"
#include "Matrix3D.h"
using Engine::Matrix3D;

class FountainEffect : public ParticleEffect
{
public:
	FountainEffect(Vector2D inOrigin, int inNumParticles, RGB inBaseColor, int inLifeTime);
	~FountainEffect(void);
	
	bool resetAfterLife;
	float fountainAngle;

	void draw(Core::Graphics& g);
	bool update(float dt);
	void setFountainAngle(float inAngle);
};

#endif