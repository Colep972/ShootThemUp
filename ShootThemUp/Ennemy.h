#pragma once
#include "Vec2.h"
#include "Ship.h"
class Ennemy : public Ship
{
	public:
		Ennemy();
		virtual ~Ennemy();
		void init(Vec2 pos, Vec2 dim, float speed, float acceleration, float minDim, float maxDim);
		void unInit();
		bool updateShoot();
		void update();
		void draw();
		void move();
		void shoot();
		sf::RectangleShape getShape();
	protected:
		float m_shootDelay;
		float m_shootDeltaTime;
		

};

