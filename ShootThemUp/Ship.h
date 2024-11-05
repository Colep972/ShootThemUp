#pragma once
#include "GameObject.h"

class Ship : public GameObject
{
	public:
		Ship();
		~Ship();
		void init(Vec2 pos, Vec2 dim, float speed, float acceleration,float minDim,float maxDim);
		void unInit();
		void update();
		void draw();
		void move();
	protected:
		int m_posRandom;
		float m_latestTime;
		
};

