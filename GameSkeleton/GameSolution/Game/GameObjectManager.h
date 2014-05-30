#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H

#include "Core.h"
#include "GameObject.h"

const int MAX_OBJECTS = 20;

class GameObjectManager
{
public:
	GameObjectManager(void);
	~GameObjectManager(void);	

	GameObject* goArray[MAX_OBJECTS];
	int numActiveObjects;
	void addObject(GameObject* newObj);

	void draw(Core::Graphics& g);
	bool update(float dt);
};

#endif