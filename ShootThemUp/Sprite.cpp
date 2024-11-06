#include "Sprite.h"

Sprite::Sprite()
{

}

Sprite::~Sprite()
{

}

<<<<<<< HEAD
sf::Sprite Sprite::init(Vec2 pos, Vec2 dim, std::string path)
{
    m_texture.loadFromFile(path);
    m_pos = pos;
    m_dim = dim;
    m_sprite.setTexture(m_texture);
    m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
    m_sprite.setPosition(m_pos.V_x, m_pos.V_y);
    m_sprite.scale(0.2f, 0.2f);
    return m_sprite;
=======
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
>>>>>>> parent of 752d0cd (Jour J)
}

sf::Sprite Sprite::getSprite()
{
<<<<<<< HEAD
    return m_sprite;
=======
    return *(m_sprite);
>>>>>>> parent of 752d0cd (Jour J)
}
