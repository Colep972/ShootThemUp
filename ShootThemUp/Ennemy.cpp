#include "Ennemy.h"
#include "Sprite.h"
#include "Projectile.h"
#include "Game.h"
#include "Level.h"
#include "Window.h"

Ennemy::Ennemy()
{
	m_groupTag = BULLET::ENNEMY;
	m_posRandom = rand() % 3 - 1;
	m_isVisible = true;
	m_latestTime = 0.f;
	m_shootDelay = 0.f;
	m_shootDeltaTime = 0.f;
	m_dir = 1;
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
	m_radius = (m_dim.V_x / 2)+ (m_dim.V_y / 2);
}

void Ennemy::unInit()
{

}

bool Ennemy::updateShoot()
{
	m_shootDelay = static_cast<float>(rand() % 10 + 1);
	m_shootDeltaTime += Game::GetGame()->getElapsedTime();
	if (m_isVisible == false)
		return false;
	if (m_shootDeltaTime < m_shootDelay)
		return false;
	shoot();
	m_shootDeltaTime = 0.f;
	return true;
}

void Ennemy::update()
{
	
	move();
	updateShoot();
}

void Ennemy::draw()
{
	if (m_isVisible)
	{
		Game::GetGame()->getRenderWindow()->draw(m_sprite);
		m_sprite.setPosition(m_pos.V_x, m_pos.V_y);
	}
}


void Ennemy::move()
{
	m_pos.V_x += m_speed * Game::GetGame()->getElapsedTime() * m_posRandom * m_dir;
	if (m_pos.V_x <= m_minDim)
	{
		m_pos.V_x = m_maxDim;
	}
	else if (m_pos.V_x >= m_maxDim)
	{
		m_pos.V_x = 0;
	}
}

void Ennemy::shoot()
{
	Vec2 pos;
	pos.initVec2(m_pos.V_x, m_pos.V_y);
	Vec2 dim;
	dim.initVec2(5.f, 25.f);
	Projectile* projectile = Level::getLevel()->spawnEntity<Projectile>(pos, dim, 500.f, 50.f, 0.f, Game::GetGame()->getWindow()->getDim().V_x);
	projectile->setGroupeTag(m_groupTag);
}
