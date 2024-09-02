#include <SFML/System/Vector2.hpp>
#include "Game.h"
#include "Ship.h"

Ship::Ship()
{
	m_random = static_cast<float>(rand() % 800);
	m_posRandom = rand() % 3 - 1;
}

Ship::~Ship()
{

}

void Ship::init(Vec2 pos, Vec2 dim, float speed, float acceleration)
{
	m_pos = pos;
	m_dim = dim;
	m_speed = speed;
	m_acceleration = acceleration;
}

void Ship::unInit()
{

}

void Ship::update(GameObject* otherGameObject)
{
	move();
	//collide(otherGameObject);
}

void Ship::draw()
{
		sf::Vector2f dim;
		dim.x = m_dim.V_x;
		dim.y = m_dim.V_y;
		m_shape.setSize(dim);
		m_shape.setPosition(m_pos.V_x, m_pos.V_y);
		m_shape.setFillColor(sf::Color::Blue);
		Game::getWindow()->draw(m_shape);
}

sf::RectangleShape Ship::getShape()
{
	return m_shape;
}

void Ship::move()
{
	m_pos.V_x += m_speed * Game::GetGame()->getElapsedTime();
	if (m_pos.V_x <= m_minDim)
	{
		m_pos.V_x = m_maxDim;
	}
	if (m_pos.V_x >= m_maxDim)
	{
		m_pos.V_x = 0;
	}
}