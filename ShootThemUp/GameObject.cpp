#include "GameObject.h"
#include <iostream>

GameObject::GameObject()
{
	m_isVisible = true;
	m_groupTag = 0;
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
	m_radius = m_dim.V_x / 2;
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

bool GameObject::isColliding(GameObject* g1, GameObject* g2)
{
	Vec2 tmpCenter1;
	float dx = (g2->getPos().V_x + g2->getDim().V_x / 2) - (g1->getPos().V_x + g1->getDim().V_x / 2);
	float dy = (g2->getPos().V_y + g2->getDim().V_y / 2) - (g1->getPos().V_y + g1->getDim().V_y / 2);
	float distance = sqrt(dx * dx + dy * dy);
	return distance <= g1->getRadius() + g2->getRadius();
}

void GameObject::setVisibility(bool visible)
{
	m_isVisible = visible;
}

bool GameObject::getVisibility()
{
	return m_isVisible;
}

int GameObject::getGroupTag()
{
	return m_groupTag;
}


