#include "FountainEffect.h"

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

FountainEffect::FountainEffect(Vector2D* inOrigin, int inNumParticles, RGB inBaseColor, int inLifetime) : ParticleEffect(inOrigin, inNumParticles, inBaseColor, inLifetime)
{
	inBaseColor;
	inLifetime;
	origin = new Vector2D(inOrigin->x,inOrigin->y);
	//orgPosition = Vector2D(inOrigin->x,inOrigin->y);
	numParticles = inNumParticles;
	particles = new Particle[numParticles];
	for (int i = 0; i < numParticles; i++)
	{
		particles[i].position = Vector2D(origin->x,origin->y);


		float angle = myRandomer->randomInRange(-.45F,.45F);

		particles[i].veloctiy = /*(myRandomer->randomUnitVector() **/ myRandomer->randomInRange(3,20)/*)*/ * Vector2D(-sin(angle),cos(angle));
		particles[i].color = RGB(242,131,12); //RGB(myRandomer->randomInRange(0,255),myRandomer->randomInRange(0,255),myRandomer->randomInRange(0,255));
		particles[i].lifetime = myRandomer->randomInRange(1,30); 


	}
}

FountainEffect::~FountainEffect()
{
	delete(origin);
}

void FountainEffect::draw(Core::Graphics& g)
{
	ParticleEffect::draw(g);
	for (int i = 0; i < numParticles; i++)
	{
		for (int j = 0; j < 4; j++) 
		{
			//if (particles[i].lifetime > 0) 
			//{
			g.SetColor(particles[i].color);
			const Vector2D& p1 = particles[i].position + particleShapePoints2[j];
			const Vector2D& p2 = particles[i].position + particleShapePoints2[(j + 1) % 4];
			g.DrawLine(p1.x, p1.y, p2.x, p2.y);
			//}
		} 
	}
}

bool FountainEffect::update(float dt)
{
	ParticleEffect::update(dt);
	for (int i = 0; i < numParticles; i++)
	{
		particles[i].position = particles[i].position + (particles[i].veloctiy * dt);
		//??
		particles[i].lifetime -= dt * 10;

		if (particles[i].lifetime <= 0) 
		{
			particles[i].position.x = origin->x;
			particles[i].position.y = origin->y;
			particles[i].lifetime = myRandomer->randomInRange(1,100);
		}
	}
	// decrease life
	return true;
}
