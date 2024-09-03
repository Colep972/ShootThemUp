#include "Level.h"
#include "Player.h"
#include "Ennemy.h"
#include "Game.h"
#include <algorithm>

Level::Level()
{
	m_latestTime = 0.f;
}

Level::~Level()
{

}

void Level::initLevel(Vec2 dimWindow)
{
	Vec2 posPlayer;
	Vec2 dimPlayer;
	dimPlayer.initVec2(250, 25);
	posPlayer.initVec2((dimWindow.V_x / 2) - dimPlayer.V_x / 2, dimWindow.V_y - dimPlayer.V_y);
	Level::spawnEntity<Player>(posPlayer, dimPlayer, 100.f, 50.f, 0.f, dimWindow.V_x - dimPlayer.V_x);
}

void Level::update()
{
	srand(timeGetTime());
	if ((Game::GetGame()->getTotalTime() - m_latestTime) > 3.0f)
	{
		Vec2 posEnnemy;
		Vec2 dimEnnemy;
		dimEnnemy.initVec2(50, 15);
		posEnnemy.initVec2(static_cast<float>(rand() % 800), (static_cast<float>(rand() % 500))/3);
		Level::spawnEntity<Ennemy>(posEnnemy, dimEnnemy, 50.f, 10.f, 0.f, Game::GetGame()->getWindow()->getSize().x);
		m_latestTime = Game::getTotalTime();
	}
	updateCollision();
	for (auto it = m_tabGameObject.begin(); it != m_tabGameObject.end(); it++)
	{
		(*it)->update();
	}
}

void Level::updateCollision()
{
	for (auto it_i = m_tabGameObject.begin(); it_i != m_tabGameObject.end(); it_i++)
	{
		for (auto it_j = m_tabGameObject.begin(); it_j != m_tabGameObject.end(); it_j++)
		{
			if ((*it_i)->getGroupTag() != (*it_j)->getGroupTag() && GameObject::isColliding((*it_i), (*it_j)))
			{
				(*it_i)->setVisibility(false);
				(*it_j)->setVisibility(false);
			}
		}
	}
}

void Level::draw()
{
	for (auto it = m_tabGameObject.begin(); it != m_tabGameObject.end(); it++)
	{
		(*it)->draw();
	}
}

Level* Level::getLevel()
{
	static Level l;
	return &l;
}

std::list<GameObject*>& Level::getList()
{
	Level* l = Level::getLevel();
	return l->m_tabGameObject;
}
