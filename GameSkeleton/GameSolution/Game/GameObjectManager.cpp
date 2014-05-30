#include "GameObjectManager.h"

GameObjectManager::GameObjectManager()
{
	numActiveObjects = 0;
	GameObject* goArray[MAX_OBJECTS] = {};
	static_cast<void>(goArray);
}

GameObjectManager::~GameObjectManager()
{

}

void GameObjectManager::addObject(GameObject* newObj)
{
	if (numActiveObjects < MAX_OBJECTS)
	{
		goArray[numActiveObjects++] = newObj;
	}
}

void GameObjectManager::draw(Core::Graphics& g)
{
	for (int i = 0; i < numActiveObjects; i++)
	{
		//Matrix3D t;
//		t = Matrix3D().Translation(goArray[i]->position);
		goArray[i]->draw(g);
	}
}

bool GameObjectManager::update(float dt)
{
	for (int i = numActiveObjects - 1; i >= 0; i--)
	{
		if (goArray[i] != NULL ) 
		{
			if (!goArray[i]->update(dt) )
			{
				//delete effectArray[i];
				for (int j=i; j<numActiveObjects-1; j++)
				{
					goArray[j] = goArray[j+1];
				}
				numActiveObjects--;
			}
		}
		
	}
	return true;
}