#include "GameObject.h"
#include <iostream>

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

void GameObject::update(GameObject* otherGameObject)
{
	collide(otherGameObject);
}

void GameObject::draw()
{

}

void GameObject::collide(GameObject* otherGameObject)
{
	if (m_dim.getSquaredDistance(otherGameObject->getDim()) <= 0)
	{
		m_speed = 10.f;
	}
}

Vec2 GameObject::getDim()
{
	return m_dim;
}

