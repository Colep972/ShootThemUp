#include "Sprite.h"
#include "Windows.h"
#include "Texture.h"

Sprite::Sprite()
{

}

Sprite::~Sprite()
{

}

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
}

sf::Sprite Sprite::getSprite()
{
    return m_sprite;
}
