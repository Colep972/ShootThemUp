#pragma once
#include <SFML/Graphics.hpp>
class Texture
{
	public:
		Texture();
		virtual ~Texture();
		bool init(std::string path);
		sf::Texture* getTexture();

	protected:
		sf::Texture m_texture;


};
