#include "Window.h"
#include <SFML/Window.hpp>

Window::Window()
{

}

Window::~Window()
{

}

bool Window::initWindow(std::string title)
{
	m_title = title;
	sf::Window window(sf::VideoMode(600,400), m_title);
}
