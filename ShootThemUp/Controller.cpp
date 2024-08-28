#include "Controller.h"
#include <string>

Controller::Controller()
{
	for (int i = 0; i < 256; i++)
	{
		m_keyStateTab[i] = Keystate::NONE;
	}
}

Controller::~Controller()
{

}

void Controller::updateController()
{
	std::string tmp;
	std::string tmp2;
	for (int i = 0; i < 256; i++)
	{
		bool key = GetAsyncKeyState(i) < 0;
		if (key)
		{
			switch (m_keyStateTab[i])
			{
				case Keystate::NONE:
					m_keyStateTab[i] = Keystate::DOWN;
					break;
				case Keystate::DOWN:
					m_keyStateTab[i] = Keystate::PUSHED;
					break;
				case Keystate::UP:
					m_keyStateTab[i] = Keystate::DOWN;
					break;
			}
		}
		else
		{
			switch (m_keyStateTab[i])
			{
				case Keystate::DOWN:
					m_keyStateTab[i] = Keystate::UP;
					break;
				case Keystate::UP:
					m_keyStateTab[i] = Keystate::NONE;
					break;
				case Keystate::PUSHED:
					m_keyStateTab[i] = Keystate::UP;
					break;
			}
		}
	}
}

bool Controller::isKey(int key)
{
	return m_keyStateTab[key] == Keystate::DOWN || m_keyStateTab[key] == Keystate::PUSHED;
}

bool Controller::isKeyDown(int key)
{
	return m_keyStateTab[key] == Keystate::DOWN;
}
