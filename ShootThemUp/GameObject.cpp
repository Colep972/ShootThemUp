#include "GameObject.h"

GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

void GameObject::init(Vec2 pos, Vec2 dim, float speed, float acceleration)
{
	m_pos = pos;
	m_dim = dim;
	m_speed = speed;
	m_acceleration = acceleration;
}

void GameObject::unInit()
{

}

void GameObject::update()
{

}

void GameObject::draw()
{

}

