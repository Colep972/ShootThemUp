#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::initGame()
{
    Vec2 posWindow;
    Vec2 playerPos;
    Vec2 dimWindow;
    Vec2 playerDim;
    dimWindow.initVec2(800, 600);
    playerDim.initVec2(250, 50);
    posWindow.initVec2((1920 / 2),(1080/3));
    playerPos.initVec2((dimWindow.V_x / 2)-playerDim.V_x/2, dimWindow.V_y-playerDim.V_y);
    m_window.initWindow("ShootThemUp", posWindow, dimWindow);
    Level::getLevel()->initLevel(dimWindow);
}

bool Game::update()
{
    if (m_timer.updateTime() == false)
        return false;
    m_controller.updateController();
    Level::getLevel()->update();
    return true;
}

void Game::draw()
{
    m_window.clear();
    Level::getLevel()->draw();
    m_window.display();
}

void Game::run()
{
    initGame();
    while (m_window.isOpen())
    {
        if (Level::getLevel()->isPlayerDead() == true)
            exit(0);
        if (m_window.updateEvent())
           break;
        if (update() == false)
           continue;
        draw();
    }
    unInitGame();
}

void Game::unInitGame()
{
    m_window.unInit();
}

Game* Game::GetGame()
{
    static Game g;
    return &g;
}

bool Game::isKey(int key)
{
    Game *g = Game::GetGame();
    return g->m_controller.isKey(key);
}

bool Game::isKeyDown(int key)
{
    Game* g = Game::GetGame();
    return g->m_controller.isKeyDown(key);
}

bool Game::isKeyNone(int key)
{
    Game* g = Game::GetGame();
    return g->m_controller.isKeyNone(key);
}

sf::RenderWindow* Game::getRenderWindow()
{
    Game* g = Game::GetGame();
    return g->m_window.getRenderWindow();
}

Window* Game::getWindow()
{
    Game* g = Game::GetGame();
    return g->m_window.getWindow();
}

float Game::getElapsedTime()
{
    Game* g = Game::GetGame();
    return g->m_timer.getElapsedTime();
}

float Game::getTotalTime()
{
    Game* g = Game::GetGame();
    return g->m_timer.getTotalTime();
}

Player* Game::getPlayer()
{
    Game* g = Game::GetGame();
    return g->m_player.getPlayer();
}


