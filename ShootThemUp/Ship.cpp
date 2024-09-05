#include <SFML/System/Vector2.hpp>
#include "Game.h"
#include "Ship.h"

Ship::Ship()
{
	m_posRandom = rand() % 3 - 1;
	m_isVisible = true;
}

Ship::~Ship()
{

}

void Ship::init(Vec2 pos, Vec2 dim, float speed, float acceleration, float minDim, float maxDim)
{
	m_pos = pos;
	m_dim = dim;
	m_speed = speed;
	m_acceleration = acceleration;
	m_radius = m_dim.V_x / 2;
}

void Ship::unInit()
{

}

void Ship::update()
{
	move();
}

void Ship::draw()
{
	
}

void Ship::move()
{
	m_pos.V_x += m_speed * Game::GetGame()->getElapsedTime()*m_posRandom;
	if (m_pos.V_x <= m_minDim)
	{
		m_pos.V_x = m_maxDim;
	}
	else if (m_pos.V_x >= m_maxDim)
	{
		m_pos.V_x = 0;
	}
}