#include "Timer.h"

Timer::Timer()
{
	m_currentTime = 0.f;
	m_elapsedTime = 0.f;
	m_totalTime = 0.f;
	m_systemElapsedTime = 0.f;
}

Timer::~Timer()
{

}

void Timer::initTimer()
{

}

bool Timer::updateTime()
{
	DWORD time = timeGetTime();
	DWORD elapsedTime = time - m_currentTime;
	m_currentTime = time;
	m_systemElapsedTime += elapsedTime;
	if (m_systemElapsedTime < 16)
		return false;

	m_elapsedTime = m_systemElapsedTime / 1000.0f;
	m_totalTime += m_elapsedTime;
	m_systemElapsedTime = 0;
	return true;
}

float Timer::getElapsedTime()
{
	return m_elapsedTime;
}

float Timer::getTotalTime()
{
	return m_totalTime;
}
