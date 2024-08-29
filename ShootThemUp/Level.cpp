#include "Level.h"
#include "Player.h"
#include "Ennemy.h"

Level::Level()
{

}

Level::~Level()
{

}

void Level::initLevel(Vec2 dimWindow)
{
	Player* player = new Player();
	Vec2 posPlayer;
	Vec2 dimPlayer;
	Vec2 posEnnemy;
	Vec2 dimEnnemy;
	dimPlayer.initVec2(250, 50);
	dimEnnemy.initVec2(50, 15);
	posPlayer.initVec2((dimWindow.V_x / 2) - dimPlayer.V_x / 2, dimWindow.V_y - dimPlayer.V_y);
	player->init(posPlayer, dimPlayer, 100.f, 10.f, 0, dimWindow.V_x - dimPlayer.V_x);
	m_tabGameObject.push_back(player);
	for (int i = 0; i < 5; i++)
	{
		Ennemy* ennemy = new Ennemy();
		posEnnemy.initVec2(i * 25.f, i * 55.f);
		ennemy->initEnnemy(posEnnemy,dimEnnemy,250.f,50.f,0,dimWindow.V_x);
		m_tabGameObject.push_back(ennemy);
	}
}

void Level::update()
{
	for (it = m_tabGameObject.begin(); it != m_tabGameObject.end(); it++)
	{
		(*it)->update();
	}
}

void Level::draw()
{
	for (it = m_tabGameObject.begin(); it != m_tabGameObject.end(); it++)
	{
		(*it)->draw();
	}
}
