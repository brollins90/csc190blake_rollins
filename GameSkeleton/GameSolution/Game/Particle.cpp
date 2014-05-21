#include "Particle.h"

Particle::Particle()
{
	position = Vector2D();
	veloctiy = Vector2D();
	color = RGB(255,255,255);
}

Particle::Particle(Vector2D inPosition, Vector2D inVelocity, RGB inColor)
{
	position = inPosition;
	veloctiy = inVelocity;
	color = inColor;
}

Particle::~Particle()
{

}