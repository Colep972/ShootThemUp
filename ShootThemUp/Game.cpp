#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::initGame()
{
    Vec2 pos;
    Vec2 dim;
    dim.initVec2(800, 600);
    pos.initVec2(dim.V_x / 2, dim.V_y / 2);
    m_window.initWindow("ShootThemUp", pos, dim);
    shape.setRadius(100.f);
    shape.setPosition((m_window.getDim().V_x / 2) - 100.f, (m_window.getDim().V_y / 2) - 100.f);
    shape.setFillColor(sf::Color::Red);
}

void Game::update()
{
    timer.updateTime();
    c.updateController();
}

void Game::draw()
{
    m_window.getWindow()->clear();
    m_window.getWindow()->draw(shape);
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
            if (event.type == sf::Event::Closed)
            {
                m_window.getWindow()->close();
                quit = true;
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
    unInit();
}

void Game::unInitGame()
{
    m_window.unInit();
}
