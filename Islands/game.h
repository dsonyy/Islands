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

#include "state-i.h"
#include "buffer.h"

class Window;

class Game
{
public:
	Game();
	~Game();

	void CreateWindow(unsigned int width, unsigned int height, const std::string & title);
	
	void Loop();
	void HandleInput(const sf::Event & event);
	void Update();
	void Draw(const sf::Drawable & drawable);
	void Render();



private:
	sf::RenderWindow window_;
	bool running_;
	std::vector<StateI *> states_;
};


class Window
{
public:
	static const unsigned int FrameRate = 30;
	static const unsigned int Width = 800;
	static const unsigned int Height = 600;
	static const int Style = sf::Style::Close | sf::Style::Titlebar;
};

