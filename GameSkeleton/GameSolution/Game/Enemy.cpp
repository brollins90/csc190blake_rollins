#include "Enemy.h"
#include "GameManager.h"
#include "GameObjectManager.h"
#include "EffectManager.h"
#include "ExplosionEffect.h"

extern GameManager* myGameManager;
extern GameObjectManager* projectileManager;
extern EffectManager* myEffectManager;

extern DrawThing* myDrawThing;

Enemy::Enemy(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints, Core::RGB inColor, Vector2D inEndPoint) : Projectile(inPosition, inVelocity, numPoints, inShapePoints, inColor, inEndPoint)
{

}

Enemy::~Enemy(void) 
{
}

void Enemy::setEndPoint(Vector2D newPoint)
{
	endPoint = newPoint;
}

bool Enemy::update(float dt)
{
	GameObject::update(dt);
	if (!myGameManager->isOutOfBounds(position))
	{
		for (int i = 0; i < projectileManager->numActiveObjects; i++)
		{
			Vector2D otherPos = projectileManager->get(i)->position;
			float l2 = (position - otherPos).LengthSquared();
			if (l2 < 20) {
				myEffectManager->addEffect(new ExplosionEffect(position, 20000, RGB(255,128,0), 5));
				myGameManager->enemiesDestroyed++;
				return false;
			}
		}
		
		if (curPercentage > 1) {
			position = endPoint;
			return true;
		}
		Vector2D pathVector = endPoint - startPoint;
		float pathLength = pathVector.Length();
		float oneTimeUnit = (velocity.x / pathLength);
		curPercentage += oneTimeUnit;

		position = Vector2D::LERP(startPoint, endPoint, curPercentage);
		return true;
	} 
	return false;
	
}