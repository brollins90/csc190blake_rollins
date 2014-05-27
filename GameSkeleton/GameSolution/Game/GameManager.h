#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Core.h"

class GameManager
{
public:
	GameManager(void);
	~GameManager( void );

	void draw( Core::Graphics& g );
	bool update(float dt);
};

#endif