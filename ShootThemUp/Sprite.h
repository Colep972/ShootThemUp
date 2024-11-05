#pragma once
#include "Vec2.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class Texture;
class Sprite
{
	public:
		Sprite();
		virtual ~Sprite();
		sf::Sprite init(Vec2 pos, Vec2 dim, std::string path);
		sf::Sprite getSprite();
		
	protected:
		Vec2 m_dim;
		Vec2 m_pos;
		sf::Sprite m_sprite;
		sf::Texture m_texture;

};

