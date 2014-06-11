#include "EnemyManager.h"


Vector2D enemy1Points[] =
{
	Vector2D(-5.0F, -5.0F),	Vector2D(+0.0F, -7.5F),	Vector2D(+5.0F, -5.0F),
	Vector2D(+5.0F, +5.0F),	Vector2D(-5.0F, +5.0F) };
int numEnemy1Points = sizeof(enemy1Points) / sizeof(enemy1Points[0]);


EnemyManager::EnemyManager()
{
	shipLoc = Vector2D(500,500);
}

void EnemyManager::setShipLoc(Vector2D newShipLoc)
{
	shipLoc = newShipLoc;
}

void EnemyManager::addEnemy()
{
	GameObjectManager::addObject(new Enemy(
		Vector2D(myRandomer->randomInRange(0,(float)SCREEN_WIDTH),myRandomer->randomInRange(0,(float)SCREEN_HEIGHT)), // Position
			Vector2D(50,50), // velocity
			numEnemy1Points, // num shape points
			enemy1Points, // shape points 
			RGB(255,128,0), // color
			Vector2D(500,500) // endpoint	
			));
}

bool EnemyManager::update(float dt)
{
	std::vector<GameObject*>::iterator it;
	for (it = goList.begin(); it != goList.end();)
	{
		GameObject* go = (*it);
		Enemy* t = (Enemy*)go;
		t->setEndPoint(shipLoc);
		if (!t->update(dt)) 
		{
			delete (*it);
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