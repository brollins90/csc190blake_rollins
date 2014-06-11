#ifndef EFFECT_MANAGER_H
#define EFFECT_MANAGER_H

#include "Core.h"
#include "DebugMemory.h"
#include "Particle.h"
#include "ParticleEffect.h"

const int MAX_EFFECTS = 10;

class EffectManager
{
protected:
	int numActiveEffects;
	vector<ParticleEffect*> effectList;
public:
	EffectManager(void);
	~EffectManager(void);		

	void draw(Core::Graphics& g);
	virtual	bool update(float dt);
	
	void addEffect(ParticleEffect* newEffect);
};

#endif