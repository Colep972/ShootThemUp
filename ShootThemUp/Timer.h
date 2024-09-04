#pragma once
#include <Windows.h>
class Timer
{
	public:
		Timer();
		virtual ~Timer();
		void initTimer();
		bool updateTime();
		float getElapsedTime();
		float getTotalTime();
	protected:
		DWORD m_systemElapsedTime;
		float m_elapsedTime;
		float m_currentTime;
		float m_totalTime;
};

