#include "Level.h"
#include "Player.h"
#include "Ennemy.h"
#include "Game.h"

Level::Level()
{
	m_latestTime = 0.f;
}

Level::~Level()
{

}

void Level::initLevel(Vec2 dimWindow)
{
	
	Player* player = new Player();
	Vec2 posPlayer;
	Vec2 dimPlayer;
	dimPlayer.initVec2(250, 25);
	posPlayer.initVec2((dimWindow.V_x / 2) - dimPlayer.V_x / 2, dimWindow.V_y - dimPlayer.V_y);
	player->init(posPlayer, dimPlayer, 100.f, 10.f, 0, dimWindow.V_x - dimPlayer.V_x);
	m_tabGameObject.push_back(player);
}

void Level::update()
{
	sf::RenderWindow* window = Game::getWindow();
	srand(timeGetTime());
	Vec2 posEnnemy;
	Vec2 dimEnnemy;
	dimEnnemy.initVec2(50, 15);
	if ((Game::GetGame()->getTotalTime() - m_latestTime) > 3.0f)
	{
		m_latestTime = Game::getTotalTime();
		Ennemy* ennemy = new Ennemy;
		posEnnemy.initVec2(static_cast<float>(rand() % 800), static_cast<float>(rand() % 500));
		ennemy->initEnnemy(posEnnemy, dimEnnemy, 250.f, 50.f, 0, window->getSize().x);
		m_tabGameObject.push_back(ennemy);
	}
	for (it = m_tabGameObject.begin(); it != m_tabGameObject.end(); it++)
	{
		(*it)->update((*it));
	}
}

void Level::draw()
{
	for (it = m_tabGameObject.begin(); it != m_tabGameObject.end(); it++)
	{
		(*it)->draw();
	}
}
