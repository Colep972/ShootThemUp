#pragma once
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
		float m_elapsedTime;
		float m_currentTime;
		float m_totalTime;
};

