#include "Texture.h"

Texture::Texture()
{
    m_texture = nullptr;
}

Texture::~Texture()
{

}

sf::Texture* Texture::init(std::string path)
{
    if (m_texture->loadFromFile(path) == false)
    {
        return nullptr;
    }
    return m_texture;
}

sf::Texture* Texture::getTexture()
{
    return m_texture;
}
