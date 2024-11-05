#include "Projectile.h"
#include <math.h>  
#define PI 3.1415

Projectile::Projectile()
{
	m_isVisible = true;
}

Projectile::~Projectile()
{

}

void Projectile::init(Vec2 pos, Vec2 dim, float speed, float acceleration,float minDim,float maxDim)
{
	m_dim = dim;
	m_speed = speed;
	m_radius = m_dim.V_x * 0.5f;
	m_pos = pos;
	m_radius = (m_dim.V_x / 2) + (m_dim.V_y / 2);
}

void Projectile::draw()
{
	if (m_isVisible) 
	{
		/*if (m_groupTag == PLAYER)
		{
			Game::getWindow()->getRenderWindow()->draw(*m_spriteSFMLPlayer);
			m_spriteSFMLPlayer->setPosition(m_pos.V_x, m_pos.V_y);
		}
		if (m_groupTag == ENNEMY)
		{ 
			Game::getWindow()->getRenderWindow()->draw(*m_spriteSFMLEnnemy);
			m_spriteSFMLEnnemy->setPosition(m_pos.V_x, m_pos.V_y);
		}*/
	}
}

void Projectile::update()
{
	switch (m_groupTag)
	{
		case PLAYER:
			m_pos.V_y -= m_speed * Game::getElapsedTime();
			break;
		case ENNEMY:
			m_pos.V_y += m_speed * Game::getElapsedTime();
			break;
		default:
			break;
	}
}

void Projectile::setPosition(Vec2 pos)
{
	m_pos.V_x = pos.V_x;
	m_pos.V_y = pos.V_y;
}

void Projectile::setGroupeTag(int tag)
{
	m_groupTag = tag;
}
