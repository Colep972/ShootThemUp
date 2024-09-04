#pragma once
#include <Windows.h>

class Controller
{
	public:
		enum Keystate
		{
			NONE,
			PUSHED,
			DOWN,
			UP
		};
		Controller();
		~Controller();
		void updateController();
		bool isKey(int key);
		bool isKeyDown(int key);
		bool isKeyNone(int key);
	protected:
		BYTE m_keyStateTab[256];
};

