#pragma once
#include <Windows.h>

enum Keystate
{
	NONE,
	PUSHED,
	DOWN,
	UP
};

class Controller
{
	public:
		Controller();
		~Controller();
		void updateController();
		bool isKey(int key);
		bool isKeyDown(int key);
		bool isKeyNone(int key);
	protected:
		BYTE m_keyStateTab[256];
};

