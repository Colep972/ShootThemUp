#include "Ennemy.h"

Ennemy::Ennemy()
{
	m_groupTag = 2;
	m_posRandom = rand() % 3 - 1;
	m_isVisible = true;
}

Ennemy::~Ennemy()
{

}

void Ennemy::init(Vec2 pos, Vec2 dim, float speed, float acceleration, float minDim, float maxDim)
{
	m_pos = pos;
	m_dim = dim;
	m_speed = speed;
	m_acceleration = acceleration;
	m_minDim = minDim;
	m_maxDim = maxDim;
}

void Ennemy::unInit()
{

}

void Ennemy::update()
{
	move();
}

void Ennemy::draw()
{
	if (m_isVisible)
	{
		sf::Vector2f dim;
		dim.x = m_dim.V_x;
		dim.y = m_dim.V_y;
		m_shape.setSize(dim);
		m_shape.setPosition(m_pos.V_x, m_pos.V_y);
		m_shape.setFillColor(sf::Color::Blue);
		Game::getWindow()->draw(m_shape);
	}
}

sf::RectangleShape Ennemy::getShape()
{
	return m_shape;
}

void Ennemy::move()
{
	m_pos.V_x += m_speed * Game::GetGame()->getElapsedTime() * m_posRandom;
	if (m_pos.V_x <= m_minDim)
	{
		m_pos.V_x = m_maxDim;
	}
	else if (m_pos.V_x >= m_maxDim)
	{
		m_pos.V_x = 0;
	}
}
