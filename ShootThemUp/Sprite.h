#pragma once
#include "Vec2.h"
#include <iostream>
#include <SFML/Graphics.hpp>
class Sprite
{
	public:
		Sprite();
		virtual ~Sprite();
		void init(Vec2 pos, Vec2 dim, std::string path);
		bool loadSprite(std::string path);
		sf::Sprite getSprite();
	protected:
		Vec2 m_dim;
		Vec2 m_pos;
		sf::Sprite* m_sprite;

};

