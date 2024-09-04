#include "GameObject.h"
#include <iostream>

GameObject::GameObject()
{
	m_isVisible = true;
	m_groupTag = BULLET::NONE;
	m_dir = 1;
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
	m_radius = (m_dim.V_x / 2) + (m_dim.V_y / 2);
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

Vec2 GameObject::getDim()
{
	return m_dim;
}

Vec2 GameObject::getPos()
{
	return m_pos;
}

float GameObject::getRadius()
{
	return m_radius;
}

bool GameObject::isColliding(GameObject* g)
{
	float dx = (g->getPos().V_x + g->getDim().V_x / 2) - (getPos().V_x + getDim().V_x / 2);
	float dy = (g->getPos().V_y + g->getDim().V_y / 2) - (getPos().V_y + getDim().V_y / 2);
	float distance = sqrt(dx * dx + dy * dy);
	return distance <= getRadius() + g->getRadius();
}

void GameObject::setVisibility(bool visible)
{
	m_isVisible = visible;
}

void GameObject::setDirection(int direction)
{
	m_dir = direction;
}

bool GameObject::getVisibility()
{
	return m_isVisible;
}

int GameObject::getGroupTag()
{
	return m_groupTag;
}


