#pragma once
#include "Vec2.h"
class GameObject
{
	public:
		GameObject();
		virtual ~GameObject();
		virtual void init(Vec2 pos,Vec2 dim, int speed, int acceleration);
		virtual void unInit();
		virtual void update();
		virtual void draw();
	protected:
		Vec2 m_pos;
		Vec2 m_dim;
		float m_speed;
		float m_acceleration

};

