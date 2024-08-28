#pragma once
class Timer
{
	public:
		Timer();
		virtual ~Timer();
		void initTimer();
		bool updateTime();
		float getElapsedTime();
		float getTotaltime();
	protected:
		float m_elapsedTime;
		float m_currentTime;
		float m_totalTime;
};

