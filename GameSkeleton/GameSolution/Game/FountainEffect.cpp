#include "FountainEffect.h"

extern Randomer* myRandomer;

Vector2D shapePoints[] =
{
	Vector2D(-5,-5),
	Vector2D(+5,-5),
	Vector2D(+5,+5),
	Vector2D(-5,+5)
};

FountainEffect::FountainEffect(Vector2D inPosition) : ParticleEffect(inPosition)
{
	numParticles = 100;
	particles = new Particle[numParticles];
	for (int i = 0; i < numParticles; i++)
	{
		particles[i].position = position;
		particles[i].veloctiy = myRandomer->randomUnitVector() * myRandomer->randomInRange(5,50);
		particles[i].color = RGB(255,255,255);
		particles[i].lifetime = 100;
	}
}

FountainEffect::~FountainEffect()
{
	delete(particles);
}

void FountainEffect::draw(Core::Graphics& g)
{
	g;
	for (int i = 0; i < numParticles; i++)
	{
		for (int j = 0; j < 4; j++) 
		{
			g.SetColor(particles[i].color);
			const Vector2D& p1 = particles[i].position + shapePoints[j];
			const Vector2D& p2 = particles[i].position + shapePoints[(j + 1) % 4];
			g.DrawLine(p1.x, p1.y, p2.x, p2.y);
		} 
	}
}

bool FountainEffect::update(float dt)
{
	for (int i = 0; i < numParticles; i++)
	{
		particles[i].position = particles[i].position + (particles[i].veloctiy * dt);
		//??
		//particles[i].lifetime -= dt;
	}
	// decrease life
	return true;
}
