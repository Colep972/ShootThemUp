#pragma once
#include "Vec2.h"
#include "Sprite.h"


enum BULLET
{
	NONE,
	PLAYER,
	ENNEMY
};

class GameObject
{
	public:
		GameObject();
		virtual ~GameObject();
		virtual void init(Vec2 pos,Vec2 dim, float speed, float acceleration);
		virtual void unInit();
		virtual void update();
		virtual void draw();
		virtual Vec2 getDim();
		virtual Vec2 getPos();
		float getRadius();
		bool isColliding(GameObject* g);
		void setVisibility(bool visible);
		void setDirection(int direction);
		bool getVisibility();
		int getGroupTag();
		void setSprite(sf::Sprite sprite);

	protected:
		sf::Sprite m_sprite;
		Vec2 m_pos;
		Vec2 m_dim;
		float m_speed;
		float m_acceleration;
		float m_maxDim;
		float m_minDim;
		float m_radius;
		bool m_isVisible;
		int m_groupTag;
		int m_dir;

};

