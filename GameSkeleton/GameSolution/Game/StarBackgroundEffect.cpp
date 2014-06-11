#include "StarBackgroundEffect.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

Vector2D starShapePoints[] =
{
	Vector2D(-2,+0),
	Vector2D(+0,+2),
	Vector2D(+2,+0),
	Vector2D(+0,-2)
};
int numStarShapePoints = sizeof(starShapePoints) / sizeof(starShapePoints[0]);

StarBackgroundEffect::StarBackgroundEffect(Vector2D inOrigin, int inNumParticles, RGB inBaseColor, float inLifetime) : ParticleEffect(inOrigin, inNumParticles, inBaseColor, inLifetime)
{
	for (int i = 0; i < numParticles; i++)
	{
		particles[i].position = Vector2D(myRandomer->randomInRange(1,(float)SCREEN_WIDTH),myRandomer->randomInRange(1,(float)SCREEN_HEIGHT));
		particles[i].veloctiy = Vector2D(-2, -1);
		particles[i].color = baseColor;		
		particles[i].lifetime = lifetime; 
	}
}

void StarBackgroundEffect::draw(Core::Graphics& g)
{
	ParticleEffect::draw(g);
	for (int i = 0; i < numParticles; i++)
	{
		for (int j = 0; j < numStarShapePoints; j++) 
		{
			if (particles[i].lifetime > 0) 
			{
				g.SetColor(particles[i].color);
				const Vector2D& p1 = particles[i].position + starShapePoints[j];
				const Vector2D& p2 = particles[i].position + starShapePoints[(j + 1) % 4];
				g.DrawLine(p1.x, p1.y, p2.x, p2.y);
			}
		} 
	}
}

bool StarBackgroundEffect::update(float dt)
{
	ParticleEffect::update(dt);
	bool stillAlive = true;
	for (int i = 0; i < numParticles; i++)
	{
		particles[i].position = particles[i].position + (particles[i].veloctiy * dt);
		
		if (particles[i].position.x < 0) 
		{
			particles[i].position.x = (float)SCREEN_WIDTH;
		}
		
		if (particles[i].position.y < 0) 
		{
			particles[i].position.y = (float)SCREEN_HEIGHT;
		}
	}
	return stillAlive;
}