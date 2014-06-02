#include "EffectManager.h"

EffectManager::EffectManager()
{
	numActiveEffects = 0;
	ParticleEffect* effectArray[MAX_EFFECTS] = {};
	static_cast<void>(effectArray);
}

EffectManager::~EffectManager()
{
}


void EffectManager::draw(Core::Graphics& g)
{
	for (int i = 0; i < numActiveEffects; i++)
	{
		effectArray[i]->draw(g);
	}
}

bool EffectManager::update(float dt)
{
	for (int i = numActiveEffects - 1; i >= 0; i--)
	{
		if (effectArray[i] != NULL ) 
		{
			if (!effectArray[i]->update(dt) )
			{
				//delete effectArray[i];
				for (int j=i; j<numActiveEffects-1; j++)
				{
					effectArray[j] = effectArray[j+1];
				}
				numActiveEffects--;
			}
		}		
	}
	return true;
}


void EffectManager::addEffect(ParticleEffect* newEffect) 
{
	if (numActiveEffects < MAX_EFFECTS) 
	{
		effectArray[numActiveEffects++] = newEffect;
	}
}