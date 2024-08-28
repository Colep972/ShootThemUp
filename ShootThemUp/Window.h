#pragma once
#include "Vec2.h"
#include "string.h"
#include <iostream>
class Window
{
	public:
		Window();
		~Window();
		bool initWindow(std::string title);
	protected:
		std::string m_title;
};

