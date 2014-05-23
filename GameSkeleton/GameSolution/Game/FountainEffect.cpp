#include "FountainEffect.h"
#include "DrawThing.h"


extern DrawThing* myDrawThing;

Vector2D particleShapePoints2[] =
{
	Vector2D(-2,-2),
	Vector2D(+2,-2),
	Vector2D(+2,+2),
	Vector2D(-2,+2)
	/*
	Vector2D(-5,-5),
	Vector2D(+5,-5),
	Vector2D(+5,+5),
	Vector2D(-5,+5)*/
};


FountainEffect::FountainEffect(Vector2D inOrigin, int inNumParticles, RGB inBaseColor, int inLifetime) : ParticleEffect(inOrigin, inNumParticles, inBaseColor, inLifetime)
{
	inBaseColor;
	inLifetime;
	origin = inOrigin;
	//orgPosition = Vector2D(inOrigin->x,inOrigin->y);
	resetPosition = false;
	shipAngle = 0;

	numParticles = inNumParticles;
	particles = new Particle[numParticles];
	for (int i = 0; i < numParticles; i++)
	{
		particles[i].position = Vector2D(origin.x,origin.y);


		float angle = myRandomer->randomInRange(-.45F,.45F);

		particles[i].veloctiy = /*(myRandomer->randomUnitVector() **/ myRandomer->randomInRange(3,20)/*)*/ * Vector2D(-sin(angle),cos(angle));
		particles[i].color = RGB(242,131,12); //RGB(myRandomer->randomInRange(0,255),myRandomer->randomInRange(0,255),myRandomer->randomInRange(0,255));
		particles[i].lifetime = myRandomer->randomInRange(1,4); 


	}
}

FountainEffect::~FountainEffect()
{
//	delete(origin);
}

void FountainEffect::draw(Core::Graphics& g)
{
		//subObject->draw(g, m);

	ParticleEffect::draw(g);
	for (int i = 0; i < numParticles; i++)
	{
		for (int j = 0; j < 4; j++) 
		{
			if (particles[i].lifetime > 0) 
			{
		Matrix3D m;
		m = m * m.Translation(particles[i].position);
		m = m * m.Rotation(shipAngle) * m.Translation(0, 28.5);
		//m = m * m.Translation(origin);
			g.SetColor(particles[i].color);
			const Vector2D& p1 = m * /*particles[i].position  +*/ particleShapePoints2[j];
			const Vector2D& p2 = m * /*particles[i].position  +*/ particleShapePoints2[(j + 1) % 4];
			g.DrawLine(p1.x, p1.y, p2.x, p2.y);
			}
		} 
	}
}

bool FountainEffect::update(float dt)
{
	ParticleEffect::update(dt);

	float angle = shipAngle + myRandomer->randomInRange(-.75F,.75F);
	
	myDrawThing->setFloat(23,angle);

	//Matrix3D m;
//	m = m * m.Rotation(angle);

	for (int i = 0; i < numParticles; i++)
	{
		particles[i].position = particles[i].position /*origin*/ + (particles[i].veloctiy * dt);
		//??
		particles[i].lifetime -= dt * 10;

		if (particles[i].lifetime <= 0 && resetPosition) 
		{
			particles[i].position.x = origin.x;
			particles[i].position.y = origin.y;
			particles[i].veloctiy = /*m * (myRandomer->randomUnitVector() **/ (myRandomer->randomInRange(3,20)/*)*/ * Vector2D(-sin(angle),cos(angle)));
			particles[i].lifetime = myRandomer->randomInRange(1,4);
		}
	}
	// decrease life
	return true;
}

void FountainEffect::setShipAngle(float inAngle)
{
	shipAngle = inAngle;
}
