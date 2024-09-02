#pragma once
class Vec2
{
	public:
		Vec2();
		virtual ~Vec2();
		void initVec2(float x, float y);
		bool isEqual(Vec2 v);
		float getDistance(Vec2 otherVec2);
		float getSquaredDistance(Vec2 otherVec2);
		friend bool operator==(Vec2 v1, Vec2 v2);
		float V_x;
		float V_y;
};

