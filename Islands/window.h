/*
 *	Program:	Islands
 *	License:	GNU GPL 2.0
 *	Author:		dsonyy
 *	GitHub:		https://github.com/dsonyy/Islands
 */

#pragma once

#include <string>
#include <vector>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "buffer.h"

using std::string;

class Window
{
public:
	Window(unsigned int width, unsigned int height, string title);
	~Window();

	void Create(unsigned int width, unsigned int height, string title);
	void Resize(unsigned int width, unsigned int height);
	void SetTitle(string title);

	void Draw(sf::Drawable & drawable);
	void Render();

private:
	sf::RenderWindow render_window_;
};
