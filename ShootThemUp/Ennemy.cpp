#include "Ennemy.h"

Ennemy::Ennemy()
{

}

Ennemy::~Ennemy()
{

}

void Ennemy::initEnnemy(Vec2 pos, Vec2 dim, float speed, float acceleration, float minDim, float maxDim)
{
	m_pos = pos;
	m_dim = dim;
	m_speed = speed;
	m_acceleration = acceleration;
	m_minDim = minDim;
	m_maxDim = maxDim;
}
