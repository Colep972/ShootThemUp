#pragma once
#include "Ship.h"
#include "Vec2.h"
#include "Controller.h"

class Player : public Ship
{
	public:
		Player();
		virtual ~Player();
		void init(Vec2 pos, Vec2 dim, float speed, float acceleration, float minDim,float maxDim);
		void unInit();
		void update();
		void draw();
		void moveX(int dir);
		void moveY(int dir);
		sf::RectangleShape getShape();
	protected:
	
};

