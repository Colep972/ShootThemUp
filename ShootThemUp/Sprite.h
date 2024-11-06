#pragma once
#include <SFML/Graphics.hpp>
#include "Vec2.h"
#include <iostream>
<<<<<<< HEAD


class Texture;
=======
#include <SFML/Graphics.hpp>
>>>>>>> parent of 752d0cd (Jour J)
class Sprite
{
	public:
		Sprite();
		virtual ~Sprite();
<<<<<<< HEAD
		sf::Sprite init(Vec2 pos, Vec2 dim, std::string path);
		sf::Sprite getSprite();
		
	protected:
		Vec2 m_dim;
		Vec2 m_pos;
		sf::Sprite m_sprite;
		sf::Texture m_texture;
=======
		void init(Vec2 pos, Vec2 dim, std::string path);
		bool loadSprite(std::string path);
		sf::Sprite getSprite();
	protected:
		Vec2 m_dim;
		Vec2 m_pos;
		sf::Sprite* m_sprite;
>>>>>>> parent of 752d0cd (Jour J)

};

