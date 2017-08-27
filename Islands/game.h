/*
 *	Program:	Islands
 *	License:	GNU GPL 2.0
 *	Author:		dsonyy
 *	GitHub:		https://github.com/dsonyy/Islands
 */

#pragma once

#include <string>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "buffer.h"

class Window;

class Game
{
public:
	Game();
	~Game();

	void Create(unsigned int width, unsigned int height, const std::string & title);
	
	void Draw(const sf::Drawable & drawable);
	void Render();

private:
	sf::RenderWindow window_;
};


class Window
{
public:
	static const unsigned int Width = 800;
	static const unsigned int Height = 600;
	static const int Style = sf::Style::Close | sf::Style::Titlebar;
	static const std::string Title;
};
const std::string Window::Title = "Islands";
