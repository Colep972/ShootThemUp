#pragma once
#include "GameObject.h"
#include "Game.h"
class Projectile : public GameObject
{
public:
	Projectile();
	virtual ~Projectile();
	void init(Vec2 pos, Vec2 dim, float speed, float acceleration,float minDim, float maxDim);
	void draw();
	void update();
	void setPosition(Vec2 pos);
	void setGroupeTag(int tag);
private:
	float m_speed;
	float m_acceleration;
	sf::Sprite* m_spriteSFML;
};

