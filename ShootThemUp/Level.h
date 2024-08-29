#pragma once
#include "list"
#include <algorithm>
#include "Vec2.h"
#include "GameObject.h"
class Level
{
	public:
		Level();
		~Level();
		void initLevel(Vec2 dimWindow);
		void update();
		void draw();
	protected:
		std::list<GameObject*> m_tabGameObject;
		std::list<GameObject*>::iterator it;

};

