#pragma once
#include <SFML/Graphics.hpp>
#include "Vec2.h"
#include "string.h"
#include <iostream>
class Window
{
	public:
		Window();
		virtual ~Window();
		void initWindow(std::string title, Vec2 pos, Vec2 dim);
		void unInit();
		void clear();
		void display();
		bool updateEvent();
		bool isOpen();
		void draw(sf::Shape* shape);
		sf::RenderWindow* getRenderWindow();
		Window* getWindow();
		Vec2 getPos();
		Vec2 getDim();
	protected:
		std::string m_title;
		sf::RenderWindow* m_window;
		Vec2 m_windowPosition;
		Vec2 m_windowDim;
};
