#ifndef GAME_OBJECT_MANAGER_H
#define GAME_OBJECT_MANAGER_H

#include "Core.h"
#include "DebugMemory.h"
#include "GameObject.h"

const int MAX_OBJECTS = 40;

class GameObjectManager
{
protected:
	vector<GameObject*> goList;
public:
	int numActiveObjects;

	GameObjectManager(void);
	~GameObjectManager(void);	

	void draw(Core::Graphics& g);
	bool update(float dt);
	
	void addObject(GameObject* newObj);
	GameObject* get(int index) ;
};

#endif