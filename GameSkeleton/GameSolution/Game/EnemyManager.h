#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

#include "GameObjectManager.h"
#include "Enemy.h"

class EnemyManager : public GameObjectManager
{
	Vector2D shipLoc;
public:
	EnemyManager();
	void setShipLoc(Vector2D newShipLoc);
	void addEnemy();
	//void draw(Core::Graphics& g);
	//void addObject(Enemy* newObj);
	bool update(float dt);
};

#endif 