#pragma once
#include "Window.h"
#include "GameObject.h"
class Ship : public GameObject
{
	public:
		Ship();
		~Ship();
		void init(Vec2 pos, Vec2 dim, float speed, float acceleration);
		void unInit();
		void update(GameObject* otherGameObject);
		void draw();
		void move();
		sf::RectangleShape getShape();
	protected:
		sf::RectangleShape m_shape;
		float m_random;
		int m_posRandom;
		
};

