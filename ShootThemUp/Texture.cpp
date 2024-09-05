#include "Texture.h"

Texture::Texture()
{

}

Texture::~Texture()
{

}

bool Texture::init(std::string path)
{
    if (m_texture.loadFromFile(path) == false)
    {
        return false;
    }
}

sf::Texture* Texture::getTexture()
{
    return &m_texture;
}
