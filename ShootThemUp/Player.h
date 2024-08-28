#pragma once
#include "Ship.h"
#include "Vec2.h"
#include "Controller.h"

class Player : public Ship
{
	public:
		Player();
		~Player();
		void init();
		void unInit();
		void update();
		void draw();
	protected:
		Controller m_controller;


};

