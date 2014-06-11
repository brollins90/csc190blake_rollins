#include "EffectManager.h"

EffectManager::EffectManager()
{
	numActiveEffects = 0;
}

EffectManager::~EffectManager()
{
	std::vector<ParticleEffect*>::iterator it;
	for (it = effectList.begin(); it != effectList.end();)
	{
		delete (*it);
		it = effectList.erase(it);
	}
}

void EffectManager::addEffect(ParticleEffect* newEffect) 
{
	effectList.push_back(newEffect);
	numActiveEffects++;
}

void EffectManager::draw(Core::Graphics& g)
{
	//ASSERT((effectList != NULL), "effectList is null")
	for (ParticleEffect* e : effectList)
	{
		e->draw(g);
	}
}

bool EffectManager::update(float dt)
{
	//ASSERT((effectList != NULL), "effectList is null")
	std::vector<ParticleEffect*>::iterator it;
	for (it = effectList.begin(); it != effectList.end();)
	{
		if (!(*it)->update(dt)) 
		{
			delete (*it);
			it = effectList.erase(it);
			numActiveEffects--;		
		}
		else 
		{
			it++;
		}
	}
	return true;
}