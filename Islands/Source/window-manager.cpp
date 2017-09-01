/*
 *	Program:	Islands
 *	License:	GNU GPL 2.0
 *	Author:		dsonyy
 *	GitHub:		https://github.com/dsonyy/Islands
 */



#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "window-manager.h"

void WindowManager::CreateWindow(size_t width, size_t height,
	const std::string & title, size_t style)
{
	create(sf::VideoMode(width, height), title, style);
}