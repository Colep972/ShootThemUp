#pragma once
#include "Window.h"
#include "GameObject.h"
#include "Projectile.h"

class Ship : public GameObject
{
	public:
		Ship();
		~Ship();
		void init(Vec2 pos, Vec2 dim, float speed, float acceleration,float minDim,float maxDim);
		void unInit();
		void update();
		void draw();
		void move();
		sf::RectangleShape getShape();
	protected:
<<<<<<< HEAD
=======
		sf::RectangleShape m_shape;
>>>>>>> parent of 752d0cd (Jour J)
		int m_posRandom;
		float m_latestTime;
		
};

