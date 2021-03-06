#include "ExplosionEffect.h"

Vector2D particleShapePoints[] =
{
	Vector2D(-5,-5),
	Vector2D(+5,-5),
	Vector2D(+5,+5),
	Vector2D(-5,+5)
};
int numParticleShapePoints = sizeof(particleShapePoints) / sizeof(particleShapePoints[0]);

ExplosionEffect::ExplosionEffect(Vector2D inOrigin, int inNumParticles, RGB inBaseColor, float inLifetime) : ParticleEffect(inOrigin, inNumParticles, inBaseColor, inLifetime)
{
//	inBaseColor;
//	origin = inOrigin;
//	numParticles = inNumParticles;
	//particles = new Particle[numParticles];
	float halfLifetime = inLifetime * .5F;
	for (int i = 0; i < numParticles; i++)
	{
		particles[i].position = Vector2D(origin.x,origin.y);
		particles[i].veloctiy = myRandomer->randomUnitVector() * myRandomer->randomInRange(10,100);
		particles[i].color = RGB(myRandomer->randomInRange(0,255),myRandomer->randomInRange(0,255),myRandomer->randomInRange(0,255));
		
		particles[i].lifetime = myRandomer->randomInRange(halfLifetime,inLifetime + halfLifetime); 
	}
}

void ExplosionEffect::draw(Core::Graphics& g)
{
	ParticleEffect::draw(g);
	for (int i = 0; i < numParticles; i++)
	{
		for (int j = 0; j < numParticleShapePoints; j++) 
		{
			if (particles[i].lifetime > 0) 
			{
				g.SetColor(particles[i].color);
				const Vector2D& p1 = particles[i].position + particleShapePoints[j];
				const Vector2D& p2 = particles[i].position + particleShapePoints[(j + 1) % 4];
				g.DrawLine(p1.x, p1.y, p2.x, p2.y);
			}
		} 
	}
}

bool ExplosionEffect::update(float dt)
{
	ParticleEffect::update(dt);
	bool stillAlive = false;
	for (int i = 0; i < numParticles; i++)
	{
		particles[i].position = particles[i].position + (particles[i].veloctiy * dt);
		
		particles[i].lifetime -= dt * 3;

		if (particles[i].lifetime > 0) {
			stillAlive = true;
		}
	}
	return stillAlive;
}
