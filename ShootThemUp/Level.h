#pragma once
#include "list"
#include "Vec2.h"

class GameObject;
class Level
{
	public:
		Level();
		~Level();
		void initLevel(Vec2 dimWindow);
		void update();
		void updateCollision();
		void draw();
		static Level* getLevel();
		static std::list<GameObject*>& getList();
		template<class T>
		static T* spawnEntity(Vec2 pos, Vec2 dim, float speed, float acceleration, float minDim, float maxDim);
	protected:
		std::list<GameObject*> m_tabGameObject;
		float m_latestTime;

};

template<class T> T* Level::spawnEntity(Vec2 pos, Vec2 dim, float speed, float acceleration, float minDim, float maxDim)
{
	T* entity = new T;
	entity->init(pos,dim,speed,acceleration,minDim,maxDim);
	Level::getList().push_back(entity);
	return entity;
}

