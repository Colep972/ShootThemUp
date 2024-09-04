#include "Projectile.h"
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
		m_shape.setSize(sf::Vector2f(m_dim.V_x, m_dim.V_y));
		m_shape.setPosition(sf::Vector2f(m_pos.V_x, m_pos.V_y));
		m_shape.setFillColor(sf::Color::Yellow);
		Game::getWindow()->draw(&m_shape);
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
