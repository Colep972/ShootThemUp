#pragma once
class Vec2
{
	public:
		Vec2();
		virtual ~Vec2();
		void initVec2(float x, float y);
		bool isEqual(Vec2 v);
		Vec2 add(Vec2 v);
		friend bool operator==(Vec2 v1, Vec2 v2);
		Vec2 operator+(Vec2 &v);
		float V_x;
		float V_y;
};

