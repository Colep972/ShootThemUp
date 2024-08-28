#include "Vec2.h"

Vec2::Vec2():m_posx(0),m_posy(0)
{

}

Vec2::~Vec2()
{
}

void Vec2::initVec2(int x, int y)
{
	m_posx = x;
	m_posy = y;
}

int Vec2::getX()
{
	return m_posx;
}

int Vec2::getY()
{
	return m_posy;
}
