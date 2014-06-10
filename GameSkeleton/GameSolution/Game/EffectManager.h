#ifndef EFFECT_MANAGER_H
#define EFFECT_MANAGER_H

#include "Core.h"
#include "DebugMemory.h"
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

	void draw(Core::Graphics& g);
	virtual	bool update(float dt);
	
	void addEffect(ParticleEffect* newEffect);
};

#endif