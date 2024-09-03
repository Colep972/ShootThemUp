#include "Vec2.h"
#include "math.h"

Vec2::Vec2()
{
	V_x = 0.0;
	V_y = 0.0;
}

Vec2::~Vec2()
{

}

void Vec2::initVec2(float x, float y)
{
	V_x = x;
	V_y = y;
}

bool Vec2::isEqual(Vec2 v)
{
	if (V_x != v.V_x)
	{
		return false;
	}
	if (V_y != v.V_y)
	{
		return false;
	}
	return true;
}

bool operator==(Vec2 v1, Vec2 v2)
{
	return v1.isEqual(v2);
}

Vec2 Vec2::add(Vec2 v)
{
	Vec2 tmp;
	tmp.initVec2(v.V_x + V_x, v.V_y + V_y);
	return tmp;
}



