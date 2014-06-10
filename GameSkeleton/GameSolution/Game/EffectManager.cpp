#include "EffectManager.h"

EffectManager::EffectManager()
{
	numActiveEffects = 0;
	ParticleEffect* effectArray = new ParticleEffect[MAX_EFFECTS];
	static_cast<void>(effectArray);
}

EffectManager::~EffectManager()
{
	delete [] &effectArray;
}


void EffectManager::draw(Core::Graphics& g)
{
	ASSERT((effectArray != NULL), "effectArray is null")
	for (int i = 0; i < numActiveEffects; i++)
	{
		effectArray[i]->draw(g);
	}
}

bool EffectManager::update(float dt)
{
	ASSERT((effectArray != NULL), "effectArray is null")
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