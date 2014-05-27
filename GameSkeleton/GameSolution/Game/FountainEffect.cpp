#include "FountainEffect.h"
#include "DrawThing.h"


extern DrawThing* myDrawThing;

Vector2D particleShapePoints2[] =
{
	Vector2D(-2,-2),
	Vector2D(+2,-2),
	Vector2D(+2,+2),
	Vector2D(-2,+2)
};


FountainEffect::FountainEffect(Vector2D inOrigin, int inNumParticles, RGB inBaseColor, int inLifetime) : ParticleEffect(inOrigin, inNumParticles, inBaseColor, inLifetime)
{
	origin = inOrigin;
	numParticles = inNumParticles;
	fountainAngle = 0;

	particles = new Particle[numParticles];
	for (int i = 0; i < numParticles; i++)
	{
		particles[i].position = Vector2D(origin.x,origin.y);

		float angle = myRandomer->randomInRange(-.45F,.45F);

		particles[i].veloctiy = myRandomer->randomInRange(3,20) * Vector2D(-sin(angle),cos(angle));
		particles[i].color = inBaseColor;
		particles[i].lifetime = myRandomer->randomInRange(1,(float)lifetime); 
	}
}

FountainEffect::~FountainEffect()
{
}

void FountainEffect::draw(Core::Graphics& g)
{
	ParticleEffect::draw(g);
	for (int i = 0; i < numParticles; i++)
	{
		for (int j = 0; j < 4; j++) 
		{
			if (particles[i].lifetime > 0) 
			{
				Matrix3D m;
				m = m * m.Translation(particles[i].position);
				m = m * m.Rotation(fountainAngle) * m.Translation(0, 28.5);
				g.SetColor(particles[i].color);
				const Vector2D& p1 = m * particleShapePoints2[j];
				const Vector2D& p2 = m * particleShapePoints2[(j + 1) % 4];
				g.DrawLine(p1.x, p1.y, p2.x, p2.y);
			}
		} 
	}
}

bool FountainEffect::update(float dt)
{
	ParticleEffect::update(dt);

	float angle = fountainAngle + myRandomer->randomInRange(-.75F,.75F);
	
	for (int i = 0; i < numParticles; i++)
	{
		particles[i].position = particles[i].position + (particles[i].veloctiy * dt);
		particles[i].lifetime -= dt * 10;

		if (particles[i].lifetime <= 0 && resetAfterLife) 
		{
			particles[i].position = origin;
			particles[i].veloctiy = (myRandomer->randomInRange(3,20) * Vector2D(-sin(angle),cos(angle)));
			particles[i].lifetime = myRandomer->randomInRange(1,(float)lifetime); 
		}
	}
	return true;
}

void FountainEffect::setFountainAngle(float inAngle)
{
	fountainAngle = inAngle;
}
