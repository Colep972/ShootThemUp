#include "Sprite.h"

Sprite::Sprite()
{
    m_sprite = nullptr;
}

Sprite::~Sprite()
{

}

void Sprite::init(Vec2 pos, Vec2 dim, std::string path)
{
    m_sprite = new sf::Sprite;
    m_pos = pos;
    m_dim = dim;
    loadSprite(path);
}

bool Sprite::loadSprite(std::string path)
{
    sf::Texture texture;
    if (texture.loadFromFile(path) == false)
        return false;
    m_sprite->setTexture(texture);
    m_sprite->setPosition(m_pos.V_x, m_pos.V_y);
    return true;
}

sf::Sprite Sprite::getSprite()
{
    return *(m_sprite);
}
