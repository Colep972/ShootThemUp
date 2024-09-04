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

void Window::draw(sf::Shape* shape)
{
	m_window->draw(*shape);
}

sf::RenderWindow* Window::getRenderWindow()
{
	return m_window;
}

Window* Window::getWindow()
{
	return this;
}

Vec2 Window::getPos()
{
	return m_windowPosition;
}

Vec2 Window::getDim()
{
	return m_windowDim;
}

void Window::clear()
{
	m_window->clear();
}

void Window::display()
{
	m_window->display();
}

bool Window::updateEvent()
{
	sf::Event event;
	while (m_window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window->close();
			return true;
			break;
		case sf::Event::KeyPressed:
			if (event.key.scancode == sf::Keyboard::Scan::Escape)
			{
				m_window->close();
				return true;
			}
			break;
		}
	}
	return false;
}


