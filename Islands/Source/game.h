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

class Game
{
public:
	Game(std::vector<StateI *> avalible_states);
	~Game();

	void CreateWindow(unsigned int width, unsigned int height, const std::string & title);
	
	void Loop();
	void HandleInput(const sf::Event & event);
	void Update();
	void Draw(const sf::Drawable & drawable);
	void Render();


private:
	sf::RenderWindow window_;
	Buffer screen_buffer_;
	bool running_;
	std::vector<StateI *> states_;
};

namespace Window
{
	const unsigned int FrameRate = 60;
	const unsigned int Width = 800;
	const unsigned int Height = 600;
	const int Style = sf::Style::Close | sf::Style::Titlebar;
	const std::string Title = "Islands";
}