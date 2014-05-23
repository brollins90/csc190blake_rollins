#include "SpaceShip.h"

#include "ParticleEffect.h"
#include "FountainEffect.h"

extern Shape* walls;
extern DrawThing* myDrawThing;

const int laserSpeed = 10;

Vector2D* orgPos;
FountainEffect* effect2;
bool isMoving;
int flameTimer;

SpaceShip::SpaceShip(Vector2D inPosition, Vector2D inVelocity, int numPoints, Vector2D* inShapePoints, GameObject* inTurret, GameObject* inLaser) : GameObject(inPosition, inVelocity, numPoints, inShapePoints)
{
	wMode = WALLS;
	acceleration = Vector2D(100, 100);
	rotationSpeed = 0.05F;
	turret1 = inTurret;
	laser1 = inLaser;
	laserStart = Vector2D();
	laserEnd = Vector2D();
	laserPercentage = 0;
	laserFired = false;
	orgPos = &inPosition;
	//Vector2D* fountainOrigin = &inPosition;
	effect2 = new FountainEffect(inPosition, 300, RGB(255,128,0), 10);
	
	isMoving = false;
	flameTimer = 0;
}

void SpaceShip::setWallMode(WallMode newMode)
{
	wMode = newMode;
}
void SpaceShip::draw (Core::Graphics& g)
{
	
	// Draw the SpaceShip
	g.SetColor(RGB(255,255,255)); // WHITE
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

	// Draw the laser
	if (laserPercentage > 0) 
	{
		Matrix3D laserTranslation;
		laserTranslation = laserTranslation * laserTranslation.Translation(laser1->position.x, laser1->position.y) * turretRotate;// laserTranslation.Rotation(laser1->angle) * laserTranslation.Scale(laser1->scale);
		
		g.SetColor(RGB(255,0,0)); // RED
		laser1->draw(g, laserTranslation);
	}

	effect2->draw(g);

}

void SpaceShip::update (float dt)
{
	flameTimer--;
	effect2->update(dt);
	Vector2D prevPos(position.x,position.y);
	Core::Input::GetMousePos(mousePosX, mousePosY);

	GameObject::update(dt);
	turret1->update(dt);

	// Right
	if (Core::Input::IsPressed(Core::Input::KEY_RIGHT) || Core::Input::IsPressed('D'))
	{ GameObject::rotate( rotationSpeed); }

	// Left
	if (Core::Input::IsPressed(Core::Input::KEY_LEFT) || Core::Input::IsPressed('A'))
	{ GameObject::rotate( -rotationSpeed); }

	// Up
	if (Core::Input::IsPressed(Core::Input::KEY_UP) || Core::Input::IsPressed('W'))
	{ 
		velocity = velocity - (dt * acceleration * Vector2D(-sin(angle),cos(angle)));
		flameTimer = 30;

	}

	// Down
	if (Core::Input::IsPressed(Core::Input::KEY_DOWN) || Core::Input::IsPressed('S'))
	{ velocity = velocity - (dt * acceleration * Vector2D(sin(angle),-cos(angle)));	}

//	effect2->resetPosition = false;

	position = position + velocity * dt;
	effect2->setShipAngle(angle);
	effect2->origin = position;
	effect2->resetPosition = (flameTimer > 0);

	
	myDrawThing->setFloat(22,angle);

	
	orgPos->x = position.x;
	orgPos->y = position.y;
	
	// Left Click
	if (Core::Input::IsPressed(Core::Input::BUTTON_LEFT) || Core::Input::IsPressed(' '))
	{ 
		if (laserPercentage == 0)
		{
			laserStart = Vector2D(position.x, position.y);
			laserEnd = Vector2D((float)mousePosX, (float)mousePosY);
			Vector2D laserPath = laserEnd - laserStart;
			float laserPathLength = laserPath.Length();
			float laserTimeUnit = (laserSpeed / laserPathLength);
			laserPercentage += laserTimeUnit;
		}	
	}

	turret1->setPosition(position);

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
	}


	if (wMode == WALLS)
	{
		for (int i =0 ; i < walls->getNumPoints(); i++)
		{
			Vector2D& wallPointLeft = walls->get(i);
			Vector2D& wallPointRight = walls->get((i + 1) % walls->getNumPoints());
			Vector2D wallPointLeftToShip = position - wallPointLeft;
			Vector2D wallVector = wallPointRight - wallPointLeft;
			Vector2D wallnormal = wallVector.PerpCCW().Normalize();
			float f1 = Vector2D::DotProduct(wallnormal,wallPointLeftToShip);

			if (f1 < 0 && !isOutOfBounds(prevPos)) 
			{
				Vector2D bounceVector = wallnormal * Vector2D::DotProduct(velocity, wallnormal);
				velocity = velocity + (bounceVector * -2);
				position = prevPos;
			}
		}
	}

	if (wMode == BOUNCE || wMode == WALLS)
	{
		if (position.x < 0) { velocity.x *= -1; }
		if (position.x > 1024) { velocity.x *= -1; }
		if (position.y < 0) { velocity.y *= -1; }
		if (position.y > 768) { velocity.y *= -1; }
	}
	if (wMode == WRAP)
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
}

bool SpaceShip::isOutOfBounds(Vector2D& pos)
{	
	for (int i =0 ; i < walls->getNumPoints(); i++)
	{
		Vector2D& wallPointLeft = walls->get(i);
		Vector2D& wallPointRight = walls->get((i + 1) % walls->getNumPoints());
		Vector2D wallPointLeftToShip = pos - wallPointLeft;
		Vector2D wallVector = wallPointRight - wallPointLeft;
		Vector2D wallnormal = wallVector.PerpCCW().Normalize();
		float f1 = Vector2D::DotProduct(wallnormal,wallPointLeftToShip);

		if (f1 < 0) 
		{
			return true;
		}
	}
	return false;
}


void SpaceShip::addTurret(GameObject* t)
{
	turret1 = t;
}
