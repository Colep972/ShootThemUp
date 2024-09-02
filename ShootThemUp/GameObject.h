#pragma once
#include "Vec2.h"
class GameObject
{
	public:
		GameObject();
		virtual ~GameObject();
		virtual void init(Vec2 pos,Vec2 dim, float speed, float acceleration);
		virtual void unInit();
		virtual void update(GameObject* otherGameObject);
		virtual void draw();
		virtual void collide(GameObject* otherGameObject);
		virtual Vec2 getDim();
	protected:
		Vec2 m_pos;
		Vec2 m_dim;
		float m_speed;
		float m_acceleration;
		float m_maxDim;
		float m_minDim;
};

