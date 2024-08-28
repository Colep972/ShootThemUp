#pragma once
#include "Window.h"
#include "Timer.h"
#include "Controller.h"

class Game
{
	public:
		Game();
		~Game();
		void initGame();
		void update();
		void draw();
		void run();
		void unInitGame();
	protected:
		Window m_window;
		sf::CircleShape shape;
		Timer timer;
		Controller c;

};

