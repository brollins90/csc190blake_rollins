#include "SpaceShip.h"

#include "ParticleEffect.h"
#include "FountainEffect.h"
#include "GameObjectManager.h"
#include "LerpingObject.h"
#include "Projectile.h"
#include "GameManager.h"

extern Shape* walls;
extern DrawThing* myDrawThing;
extern WallMode gameMode;
extern GameObjectManager* goManager;
extern GameManager* myGameManager;

int reloadDelay;
FountainEffect* effect2;
int flameTimer;

SpaceShip::SpaceShip(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints, Core::RGB inColor, GameObject* inTurret) : GameObject(inPosition, inVelocity, numPoints, inShapePoints, inColor)
{
	acceleration = Vector2D(100, 100);
	rotationSpeed = 0.02F;
	turret1 = inTurret;
	reloadDelay = 0;
	effect2 = new FountainEffect(inPosition, 300, RGB(255,128,0), 4);
	flameTimer = 0;
}

SpaceShip::~SpaceShip()
{
	
}

void SpaceShip::draw (Core::Graphics& g)
{
	
	// Draw the SpaceShip
	g.SetColor(objColor);
	Matrix3D spaceShipTranslation;
	spaceShipTranslation = spaceShipTranslation * spaceShipTranslation.Translation(position.x, position.y) * spaceShipTranslation.Rotation(angle) * spaceShipTranslation.Scale(scale);

	GameObject::draw(g, spaceShipTranslation);
	myDrawThing->setShipMatrix(spaceShipTranslation);


	// Figure out the Turret
	Core::Input::GetMousePos(mousePosX, mousePosY);
	Vector2D mousePos((float)mousePosX, (float)mousePosY);
	Vector2D mouseFromShip = position - mousePos;
	Vector2D mouseFromShipNormal = mouseFromShip.Normalize();

	// Draw the Turret
	Matrix3D turretRotate = Matrix3D(mouseFromShipNormal.PerpCW(), mouseFromShipNormal);
	Matrix3D turretTranslation;
	turretTranslation = turretTranslation.Translation(position.x, position.y) * turretRotate * turretTranslation.Scale(scale);
	
	g.SetColor(RGB(255,255,255)); // WHITE
	turret1->draw(g, turretTranslation);

	//// Draw the laser
	//if (laserPercentage > 0) 
	//{
	//	Matrix3D laserTranslation;
	//	laserTranslation = laserTranslation * laserTranslation.Translation(laser1->position.x, laser1->position.y) * turretRotate;
	//	
	//	g.SetColor(RGB(255,0,0)); // RED
	//	laser1->draw(g, laserTranslation);
	//}

	effect2->draw(g);

}

bool SpaceShip::update (float dt)
{
	flameTimer--;
		reloadDelay--;
	effect2->update(dt);
	Vector2D prevPos(position.x,position.y);
	Core::Input::GetMousePos(mousePosX, mousePosY);

	GameObject::update(dt);
	turret1->update(dt);

	// Right
	if (Core::Input::IsPressed(Core::Input::KEY_RIGHT) || Core::Input::IsPressed('D'))
	{
		GameObject::rotate( rotationSpeed);
	}

	// Left
	if (Core::Input::IsPressed(Core::Input::KEY_LEFT) || Core::Input::IsPressed('A'))
	{
		GameObject::rotate( -rotationSpeed);
	}

	// Up
	if (Core::Input::IsPressed(Core::Input::KEY_UP) || Core::Input::IsPressed('W'))
	{ 
		velocity = velocity - (dt * acceleration * Vector2D(-sin(angle),cos(angle)));
		flameTimer = 3;
	}

	// Down
	if (Core::Input::IsPressed(Core::Input::KEY_DOWN) || Core::Input::IsPressed('S'))
	{
		velocity = velocity - (dt * acceleration * Vector2D(sin(angle),-cos(angle)));
	}
	
	position = position + velocity * dt;
	effect2->setFountainAngle(angle);
	effect2->origin = position;
	effect2->resetAfterLife = (flameTimer > 0);
	
	
	// Left Click
	if (Core::Input::IsPressed(Core::Input::BUTTON_LEFT) || Core::Input::IsPressed(' '))
	{ 
		if (reloadDelay <= 0) {
			reloadDelay = 10;
			Vector2D laserShapePoints[] = {
				Vector2D(0,0),
				Vector2D(2,2)
			};
			goManager->addObject(
				new Projectile(Vector2D(position.x, position.y), // start
				Vector2D(5,5), // velocity
				2,
				laserShapePoints,
				RGB(255,0,0),
				Vector2D((float)mousePosX, (float)mousePosY))); // end point)); // color
		}
	}

	turret1->setPosition(position);
/*
	if (laserPercentage > 0) 
	{
		Vector2D laserPath = laserEnd - laserStart;
		float laserPathLength = laserPath.Length();
		float laserTimeUnit = (laserSpeed / laserPathLength);
		laserPercentage += laserTimeUnit;
		laser1->position = Vector2D::LERP(laserStart, laserEnd, laserPercentage);
		
		if (isOutOfBounds(laser1->position) )
		{
			laserPercentage = 0;
		}	
	}*/


	if (gameMode == WALLS)
	{
		for (int i =0 ; i < walls->getNumPoints(); i++)
		{
			Vector2D& wallPointLeft = walls->get(i);
			Vector2D& wallPointRight = walls->get((i + 1) % walls->getNumPoints());
			Vector2D wallPointLeftToShip = position - wallPointLeft;
			Vector2D wallVector = wallPointRight - wallPointLeft;
			Vector2D wallnormal = wallVector.PerpCCW().Normalize();
			float f1 = Vector2D::DotProduct(wallnormal,wallPointLeftToShip);

			if (f1 < 0 && !myGameManager->isOutOfBounds(prevPos)) 
			{
				Vector2D bounceVector = wallnormal * Vector2D::DotProduct(velocity, wallnormal);
				velocity = velocity + (bounceVector * -2);
				position = prevPos;
			}
		}
	}

	if (gameMode == BOUNCE || gameMode == WALLS)
	{
		if (position.x < 0) { velocity.x *= -1; }
		if (position.x > 1024) { velocity.x *= -1; }
		if (position.y < 0) { velocity.y *= -1; }
		if (position.y > 768) { velocity.y *= -1; }
	}
	if (gameMode == WRAP)
	{
		if (position.x < 0) { position.x = 1024; }
		if (position.x > 1024) { position.x = 0; }
		if (position.y < 0) { position.y = 768; }
		if (position.y > 768) { position.y = 0; }
	}

	myDrawThing->setFloat(1,position.x);
	myDrawThing->setFloat(2,position.y);
	myDrawThing->setFloat(3,velocity.x);
	myDrawThing->setFloat(4,velocity.y);

	myDrawThing->setMousePos(mousePosX, mousePosY);
	return true;
}

//bool SpaceShip::isOutOfBounds(Vector2D& pos)
//{	
//	for (int i =0 ; i < walls->getNumPoints(); i++)
//	{
//		Vector2D& wallPointLeft = walls->get(i);
//		Vector2D& wallPointRight = walls->get((i + 1) % walls->getNumPoints());
//		Vector2D wallPointLeftToShip = pos - wallPointLeft;
//		Vector2D wallVector = wallPointRight - wallPointLeft;
//		Vector2D wallnormal = wallVector.PerpCCW().Normalize();
//		float f1 = Vector2D::DotProduct(wallnormal,wallPointLeftToShip);
//
//		if (f1 < 0) 
//		{
//			return true;
//		}
//	}
//	return false;
//}
//
//
//void SpaceShip::addTurret(GameObject* t)
//{
//	turret1 = t;
//}
