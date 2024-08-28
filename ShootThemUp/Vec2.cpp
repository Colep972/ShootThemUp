#include "Vec2.h"

Vec2::Vec2()
{
	float V_x = 0.0;
	float V_y = 0.0;
}

Vec2::~Vec2()
{

}

void Vec2::initVec2(float x, float y)
{
	V_x = x;
	V_y = y;
}