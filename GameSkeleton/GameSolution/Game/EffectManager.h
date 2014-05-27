#ifndef EFFECTMANAGER_H
#define EFFECTMANAGER_H

#include "Core.h"
#include "Particle.h"
#include "ParticleEffect.h"

const int MAX_EFFECTS = 10;

class EffectManager
{
public:
	EffectManager(void);
	~EffectManager(void);	

	ParticleEffect* effectArray[MAX_EFFECTS];
	int numActiveEffects;
	void addEffect(ParticleEffect* newEffect);

	void draw(Core::Graphics& g);
	bool update(float dt);
};

#endif