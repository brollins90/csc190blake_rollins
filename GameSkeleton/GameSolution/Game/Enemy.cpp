#include "Enemy.h"
#include "GameManager.h"
#include "GameObjectManager.h"
#include "EffectManager.h"
#include "ExplosionEffect.h"

extern SpaceShip* theShip;
extern GameManager* myGameManager;
extern GameObjectManager* projectileManager;
extern EffectManager* myEffectManager;

extern DrawThing* myDrawThing;

int COLLISION_DISTANCE = 20;

Enemy::Enemy(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints, Core::RGB inColor, Vector2D inEndPoint) : Projectile(inPosition, inVelocity, numPoints, inShapePoints, inColor, inEndPoint)
{
	pointValue = 100;
}

void Enemy::setEndPoint(Vector2D newPoint)
{
	endPoint = newPoint;
}

bool Enemy::update(float dt)
{
//	GameObject::update(dt);
	ASSERT((myGameManager != NULL), "myGameManager is null")
	if (!myGameManager->isOutOfBounds(position))
	{
		ASSERT((projectileManager != NULL), "projectileManager is null")
		// Check if a laser (projectile) has killed the Enemy
		for (int i = 0; i < projectileManager->numActiveObjects; i++)
		{
			Vector2D ProjectilePos = projectileManager->get(i)->position;			
			float distance = (position - ProjectilePos).LengthSquared();
			if (distance < COLLISION_DISTANCE) {
				myEffectManager->addEffect(new ExplosionEffect(position, 100, RGB(255,128,0), 3));
				myGameManager->enemiesDestroyed++;
				myGameManager->score += pointValue;

				return false;
			}
		}

		// Check if the Enemy has collided with the Spaceship
		float distance = (position - theShip->position).LengthSquared();
		if (distance < COLLISION_DISTANCE) {
			myGameManager->removeLife();
			return false;
		}
		
		if (curPercentage > 1) {
			position = endPoint;
			return true;
		}
		Vector2D pathVector = endPoint - startPoint;
		float pathLength = pathVector.Length();
		float oneTimeUnit = (velocity.x / pathLength);
		curPercentage += oneTimeUnit * dt;

		position = Vector2D::LERP(startPoint, endPoint, curPercentage);
		return true;
	} 
	return false;
	
}