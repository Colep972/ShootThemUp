#include <SFML/System/Vector2.hpp> 
#include "Player.h"
#include "Game.h"
#include "Projectile.h"


Player::Player()
{
	m_groupTag = BULLET::PLAYER;
	m_latestTime = 0.f;
	m_dir = 1;
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
	m_radius = (m_dim.V_x / 2) + (m_dim.V_y / 2);

}

void Player::unInit()
{

}

void Player::update()
{
	if (Game::isKey('Q'))
	{
		moveX(-1);
	}
	else if (Game::isKey('D'))
	{
		moveX(1);
	}
	if (Game::isKey(VK_LBUTTON))
	{
		if (Game::GetGame()->getTotalTime() - m_latestTime > .5f && m_isVisible)
		{
			shoot();
			m_latestTime = Game::GetGame()->getTotalTime();
		}
	}
}

void Player::draw()
{
	if (m_isVisible)
	{
		sf::Vector2f dim;
		dim.x = m_dim.V_x;
		dim.y = m_dim.V_y;
		m_shape.setSize(dim);
		m_shape.setPosition(m_pos.V_x, m_pos.V_y);
		m_shape.setFillColor(sf::Color::Red);
		Game::getWindow()->draw(&m_shape);
	}
}

void Player::moveX(int dir)
{
	m_speed += m_acceleration * Game::GetGame()->getElapsedTime();
	m_pos.V_x += m_speed * Game::GetGame()->getElapsedTime() * dir;
	/*if (m_speed > 800.f)
	{
		m_speed = 800.f;
	}*/
	if (m_pos.V_x <= m_minDim)
	{
		m_pos.V_x = 0;
	}
	if (m_pos.V_x >= m_maxDim)
	{
		m_pos.V_x = m_maxDim;
	}
}

void Player::moveY(int dir)
{
		m_pos.V_y += m_speed * Game::GetGame()->getElapsedTime()*dir;
}

sf::RectangleShape Player::getShape()
{
	return m_shape;
}

void Player::shoot()
{
	Vec2 pos;
	pos.initVec2(m_pos.V_x + (m_dim.V_x / 2), m_pos.V_y);
	Vec2 dim;
	dim.initVec2(5.f, 25.f);
	Projectile* projectile = Level::getLevel()->spawnEntity<Projectile>(pos, dim, 500.f, 50.f, 0.f, Game::GetGame()->getWindow()->getDim().V_x);
	projectile->setGroupeTag(m_groupTag);
}

