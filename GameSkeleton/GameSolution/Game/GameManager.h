#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Engine.h"
#include "Core.h"
#include "DebugMemory.h"
#include <sstream>
#include "Logger.h"
#include "Profiler.h"
#include "DrawThing.h"
#include "Shape.h"
#include "GameObject.h"
#include "WallMode.h"
#include "SpaceShip.h"
#include "LerpingObject.h"
#include "ParticleEffect.h"
#include "ExplosionEffect.h"
#include "FountainEffect.h"
#include "Randomer.h"
#include "EffectManager.h"
#include "GameObjectManager.h"
#include "Clock.h"
#include "Enemy.h"
#include "EnemyManager.h"
#include "StarBackgroundEffect.h"

using Core::Input;
using Engine::Timing::Clock;
using Engine::Profiling::Profiler;
using Engine::Logging::Logger;
//using Engine::Randoming::Randomer;



class GameManager
{
public:
	GameManager(void);
	~GameManager( void );
	
	int enemiesDestroyed;
	int livesRemaining;
	int shotsFired;
	int score;
	float totalTime;

	bool initialize();
	bool shutdown();
	void draw( Core::Graphics& g );
	bool update(float dt);

	bool isOutOfBounds(Engine::Vector2D& pos);
	void removeLife(void);
};

#endif