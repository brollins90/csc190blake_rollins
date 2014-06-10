#ifndef STAR_BACKGROUND_EFFECT
#define STAR_BACKGROUND_EFFECT

#include "Core.h"
#include "DebugMemory.h"
#include "ParticleEffect.h"

class StarBackgroundEffect : public ParticleEffect
{
public:
	StarBackgroundEffect(Vector2D inOrigin, int inNumParticles, RGB inBaseColor, float inLifetime);
	~StarBackgroundEffect(void);

	void draw(Core::Graphics& g);
	virtual bool update(float dt);
};

#endif