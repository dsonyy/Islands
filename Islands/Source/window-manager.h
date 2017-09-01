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

namespace Window
{
	const unsigned int FrameRate = 60;
	const unsigned int Width = 800;
	const unsigned int Height = 600;
	const int Style = sf::Style::Close | sf::Style::Titlebar;
	const std::string Title = "Islands";
}

class WindowManager
	: public sf::RenderWindow
{
public:
	WindowManager() {};
	~WindowManager() {};

	void CreateWindow(size_t width = 800, size_t height = 600,
		const std::string & title = "Islands", 
		size_t style = sf::Style::Close | sf::Style::Titlebar);

private:

};
