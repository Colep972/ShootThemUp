#include <SFML/System/Vector2.hpp> 
#include "Player.h"
#include "Game.h"


Player::Player()
{

}

Player::~Player()
{

}

void Player::init(Vec2 pos, Vec2 dim, float speed, float acceleration, float minDim, float maxDim)
{
	m_dim = dim;
	m_pos = pos;
	m_speed = speed;
	m_acceleration = acceleration;
	m_maxDim = maxDim;
	m_minDim = minDim;
}

void Player::unInit()
{

}

void Player::update()
{
	/*if (Game::isKey('z') || Game::isKey('Z'))
	{
		moveY(true);
	}
	else if (Game::isKey('s') || Game::isKey('S'))
	{
		moveY(false);
	}*/
	if (Game::isKey('Q'))
	{
		moveX(-1);
	}
	else if (Game::isKey('D'))
	{
		moveX(1);
	}
	if (Game::isKeyNone('Q'))
	{
		m_speed = 100.f;
	}
	else if (Game::isKeyNone('Z'))
	{
		m_speed = 100.f;
	}
}

void Player::draw()
{
	sf::Vector2f dim;
	dim.x = m_dim.V_x;
	dim.y = m_dim.V_y;
	m_shape.setSize(dim);
	m_shape.setPosition(m_pos.V_x,m_pos.V_y);
	m_shape.setFillColor(sf::Color::Red);
	Game::getWindow()->draw(m_shape);
}

void Player::moveX(int dir)
{
	m_speed += m_acceleration * Game::GetGame()->getElapsedTime();
	if (m_speed > 500.f)
	{
		m_speed = 500.f;
	}
	if (m_pos.V_x <= m_minDim)
	{
		m_pos.V_x = 0;
	}
	if (m_pos.V_x >= m_maxDim)
	{
		m_pos.V_x = m_maxDim;
	}
	m_pos.V_x += m_speed * Game::GetGame()->getElapsedTime() * dir;
}

void Player::moveY(int dir)
{
		m_pos.V_y += m_speed * Game::GetGame()->getElapsedTime()*dir;
}

sf::RectangleShape Player::getShape()
{
	return m_shape;
}

