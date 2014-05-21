#include "ParticleEffect.h"

ParticleEffect::ParticleEffect(Vector2D origin)
{
	position = origin;
}

//ParticleEffect::ParticleEffect(Vector2D origin, int num, RGB color)
//{
//	position = origin;
//}

ParticleEffect::~ParticleEffect()
{

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