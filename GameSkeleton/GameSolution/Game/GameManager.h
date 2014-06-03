#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Core.h"
#include "Engine.h"
#include <sstream>
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
#include "Profiler.h"

class GameManager
{
public:
	GameManager(void);
	~GameManager( void );
	
	int enemiesDestroyed;

	bool initialize();
	bool shutdown();
	void draw( Core::Graphics& g );
	bool update(float dt);

	bool isOutOfBounds(Engine::Vector2D& pos);
};

#endif