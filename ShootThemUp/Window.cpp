#include "Window.h"
#include <Windows.h>



Window::Window()
{
	m_title = "";
	m_window = nullptr;
	m_windowDim.V_x = 0.0f;
	m_windowDim.V_y = 0.0f;
	m_windowPosition.V_x = 0.0f;
	m_windowPosition.V_y = 0.0f;
}

Window::~Window()
{
	if (m_window != nullptr)
	{
		OutputDebugStringA("L'objet window n'a pas été libéré\r\n");
	}
}

void Window::initWindow(std::string title, Vec2 pos, Vec2 dim)
{
	m_title = title;
	m_window = new sf::RenderWindow(sf::VideoMode(dim.V_x, dim.V_y), m_title);
	sf::Vector2i sfmlPos(pos.V_x, pos.V_y);
	m_window->setPosition(sfmlPos);
	m_windowDim = dim;
	m_windowPosition = pos;
}

void Window::unInit()
{
	delete m_window;
	m_window = nullptr;
}

bool Window::isOpen()
{
	if (m_window->isOpen())
	{
		return true;
	}
	return false;
}

sf::RenderWindow* Window::getWindow()
{
	return m_window;
}

Vec2 Window::getPos()
{
	return m_windowPosition;
}

Vec2 Window::getDim()
{
	return m_windowDim;
}


