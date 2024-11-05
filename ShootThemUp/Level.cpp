#include "Sprite.h"
#include "Level.h"
#include "Game.h"
#include <algorithm>
#include "Player.h"
#include "Ennemy.h"
#include "Texture.h"

Level::Level()
{
	m_latestTime = 0.f;
	m_player = nullptr;
	m_texture = nullptr;
}

Level::~Level()
{

}

void Level::initLevel(Vec2 dimWindow)
{
	
	/*m_texture->init();
	m_texture->init("../../data/player_shoot.png");
	m_texture->init("../../data/ennemy_shoot.png");*/
	Vec2 posPlayer;
	Vec2 dimPlayer;
	dimPlayer.initVec2(100, 25);
	posPlayer.initVec2((dimWindow.V_x / 2) - dimPlayer.V_x / 2, dimWindow.V_y - dimPlayer.V_y);
	m_player = Level::spawnEntity<Player>(posPlayer, dimPlayer, 200.f, 50.f, 0.f, dimWindow.V_x - dimPlayer.V_x);
	Sprite* sprite = new Sprite;
	m_player->setSprite(sprite->init(posPlayer, dimPlayer, "../../data/player.png"));
}

void Level::update()
{
	//srand(timeGetTime());
	if ((Game::GetGame()->getTotalTime() - m_latestTime) > 2.f)
	{
		Vec2 posEnnemy;
		Vec2 dimEnnemy;
		dimEnnemy.initVec2(50, 15);
		posEnnemy.initVec2(static_cast<float>(rand() % 800), (static_cast<float>(rand() % 500))/3);
		Level::spawnEntity<Ennemy>(posEnnemy, dimEnnemy, 50.f, 10.f, 0.f, Game::GetGame()->getWindow()->getDim().V_x);
		Sprite* sprite = new Sprite;
		m_tabGameObject.back()->setSprite(sprite->init(posEnnemy, dimEnnemy, "../../data/ennemy.png"));
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
		if((*it_i)->getVisibility() == false)
			continue;

		for (auto it_j = m_tabGameObject.begin(); it_j != m_tabGameObject.end(); it_j++)
		{
			if ((*it_j)->getVisibility() == false)
				continue;
			if ((*it_i)->getGroupTag() == (*it_j)->getGroupTag())
				continue;
			

			/*if ((*it_i)->isColliding((*it_j)))
			{
				(*it_i)->setVisibility(false);
				(*it_j)->setVisibility(false);
				break;
			}*/
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

bool Level::isPlayerDead()
{
	if (m_player->getVisibility())
	{
		return false;
	}
	return true;
}
