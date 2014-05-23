#include "ParticleEffect.h"

ParticleEffect::ParticleEffect(Vector2D inOrigin, int inNumParticles, RGB inBaseColor, int inLifetime)
{
	inOrigin;
	inNumParticles;
	inBaseColor;
	inLifetime;
}

ParticleEffect::~ParticleEffect()
{	
	delete(particles);
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