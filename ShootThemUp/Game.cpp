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
    posWindow.initVec2(dimWindow.V_x / 2, dimWindow.V_y / 2);
    playerPos.initVec2((dimWindow.V_x / 2)-playerDim.V_x/2, dimWindow.V_y-playerDim.V_y);
    m_window.initWindow("ShootThemUp", posWindow, dimWindow);
    Level::getLevel()->initLevel(dimWindow);
}

void Game::update()
{
    Level::getLevel()->update();
    m_timer.updateTime();
    m_controller.updateController();
}

void Game::draw()
{
    m_window.getWindow()->clear();
    Level::getLevel()->draw();
    m_window.getWindow()->display();
}

void Game::run()
{
    initGame();
    while (m_window.isOpen())
    {
        bool quit = false;
        sf::Event event;
        while (m_window.getWindow()->pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    m_window.getWindow()->close();
                    quit = true;
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.scancode == sf::Keyboard::Scan::Escape)
                    {
                        m_window.getWindow()->close();
                        quit = true;
                    }
                    break;
            }
        }
        if (quit)
        {
            break;
        }
        update();
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

sf::RenderWindow* Game::getWindow()
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


