#include "ParticleEffect.h"

ParticleEffect::ParticleEffect()
{}

ParticleEffect::ParticleEffect(Vector2D inOrigin, int inNumParticles, RGB inBaseColor, float inLifetime)
{
	origin = inOrigin;
	numParticles = inNumParticles;
	baseColor = inBaseColor;
	lifetime = inLifetime;
	particles = new Particle[numParticles];
}

ParticleEffect::~ParticleEffect()
{	
	delete [] &particles;
}

void ParticleEffect::draw(Core::Graphics& g)
{
	g;
}

bool ParticleEffect::update(float dt)
{
	dt;
	return true;
}
void ParticleEffect::setOrigin(Vector2D newOrigin)
{
	origin = newOrigin;
}