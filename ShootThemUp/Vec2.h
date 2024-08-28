#pragma once
class Vec2
{
	public:
		Vec2();
		~Vec2();
		void initVec2(int x, int y);
		int getX();
		int getY();
protected:
	int m_posx;
	int m_posy;
};

