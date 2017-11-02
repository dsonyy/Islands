/*
 *	Program:	Islands
 *	License:	GNU GPL 2.0
 *	Author:		dsonyy
 *	GitHub:		https://github.com/dsonyy/Islands
 */


#pragma once

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "globals.h"

using namespace Global::Window;

class WindowManager
	: public sf::RenderWindow
{
public:
	WindowManager() {};
	~WindowManager() {};

	void CreateWindow(size_t width = Width, size_t height = Height,
		const std::string & title = Title, size_t style = Style);

private:

};
