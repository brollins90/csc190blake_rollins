#include "GameObjectManager.h"

using std::vector;

GameObjectManager::GameObjectManager()
{
	numActiveObjects = 0;
}

GameObjectManager::~GameObjectManager()
{
}

GameObject* GameObjectManager::get(int index) 
{
	return goList.at(index);
}

void GameObjectManager::addObject(GameObject* newObj)
{
	goList.push_back(newObj);
	numActiveObjects++;
}

void GameObjectManager::draw(Core::Graphics& g)
{
	for (GameObject* go : goList)
	{
		go->draw(g);
	}
}

bool GameObjectManager::update(float dt)
{
	std::vector<GameObject*>::iterator it;
	for (it = goList.begin(); it != goList.end();)
	{
		if (!(*it)->update(dt)) 
		{
			it = goList.erase(it);
			numActiveObjects--;		
		}
		else 
		{
			it++;
		}
	}
	return true;
}