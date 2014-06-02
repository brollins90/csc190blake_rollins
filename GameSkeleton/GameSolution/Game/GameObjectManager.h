#ifndef GAME_OBJECT_MANAGER_H
#define GAME_OBJECT_MANAGER_H

#include "Core.h"
#include "GameObject.h"

const int MAX_OBJECTS = 40;

class GameObjectManager
{
public:
	GameObjectManager(void);
	~GameObjectManager(void);	

	GameObject* goArray[MAX_OBJECTS];
	int numActiveObjects;

	void draw(Core::Graphics& g);
	bool update(float dt);
	
	void addObject(GameObject* newObj);
	GameObject* get(int index) ;
};

#endif