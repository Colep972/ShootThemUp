#include "Sprite.h"
#include "Windows.h"
#include "Texture.h"

Sprite::Sprite()
{
    m_sprite = nullptr;
}

Sprite::~Sprite()
{

}

sf::Sprite* Sprite::init(Vec2 pos, Vec2 dim,Texture* texture)
{
    m_texture = texture;
    m_sprite = new sf::Sprite;
    m_pos = pos;
    m_dim = dim;
    m_sprite->setTexture(*texture->getTexture());
    m_sprite->setOrigin(texture->getTexture()->getSize().x / 2, texture->getTexture()->getSize().y / 2);
    m_sprite->setPosition(m_pos.V_x, m_pos.V_y);
    m_sprite->scale(0.2f, 0.2f);
    return m_sprite;
}
