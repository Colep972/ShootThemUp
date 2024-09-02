#include "Timer.h"
#include <Windows.h>

Timer::Timer()
{
	m_currentTime = 0.0f;
	m_elapsedTime = 0.0f;
	m_totalTime = 0.0f;
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
	m_elapsedTime = elapsedTime / 1000.0f;
	m_totalTime += m_elapsedTime;
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
