#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Core.h"
#include "Engine.h"

class GameManager
{
public:
	GameManager(void);
	~GameManager( void );

	void draw( Core::Graphics& g );
	bool update(float dt);

	bool isOutOfBounds(Engine::Vector2D& pos);
};

#endif