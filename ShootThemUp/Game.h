#pragma once
#include "Window.h"
#include "Timer.h"
#include "Level.h"
#include "Player.h"

class Game
{
	public:
		Game();
		~Game();
		void initGame();
		bool update();
		void draw();
		void run();
		void unInitGame();
		static Game* GetGame();
		static bool isKey(int key);
		static bool isKeyDown(int key);
		static float getElapsedTime();
		static float getTotalTime();
		static Player* getPlayer();
		static bool isKeyNone(int key);
		static sf::RenderWindow* getRenderWindow();
		static Window* getWindow();
	protected:
		Window m_window;
		Timer m_timer;
		Controller m_controller;
		Player m_player;
};

