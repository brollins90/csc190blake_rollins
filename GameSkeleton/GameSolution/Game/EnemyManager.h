#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

#include "DebugMemory.h"
#include "GameObjectManager.h"
#include "Enemy.h"
#include "Randomer.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern Randomer* myRandomer;

class EnemyManager : public GameObjectManager
{
	Vector2D shipLoc;
public:
	EnemyManager();
	~EnemyManager();
	void setShipLoc(Vector2D newShipLoc);
	void addEnemy();
	bool update(float dt);
};

#endif 