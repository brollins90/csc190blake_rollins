#include "EnemyManager.h"



EnemyManager::EnemyManager()
{
	shipLoc = Vector2D(500,500);
}

Vector2D enemyPoints[] =
{
	Vector2D(-5.0F, -5.0F),	Vector2D(+0.0F, -7.5F),	Vector2D(+5.0F, -5.0F),
	Vector2D(+5.0F, +5.0F),	Vector2D(-5.0F, +5.0F) };
int numEnemyPoints = sizeof(enemyPoints) / sizeof(enemyPoints[0]);


void EnemyManager::setShipLoc(Vector2D newShipLoc)
{
	shipLoc = newShipLoc;
}

void EnemyManager::addEnemy()
{
	GameObjectManager::addObject(new Enemy(
			Vector2D(300,300), // Position
			Vector2D(1,1), // velocity
			numEnemyPoints, // num shape points
			enemyPoints, // shape points 
			RGB(255,25,25), // color
			Vector2D(500,500) // endpoint	
			));
}

bool EnemyManager::update(float dt)
{
	for (int i = numActiveObjects - 1; i >= 0; i--)
	{
		if (goArray[i] != NULL ) 
		{
			Enemy* t = (Enemy*)goArray[i];
			t->setEndPoint(shipLoc);
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