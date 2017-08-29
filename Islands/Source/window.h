#pragma once

#include <SFML\Window.hpp>
#include <string>


namespace Window
{
	const unsigned int FrameRate = 60;
	const unsigned int Width = 800;
	const unsigned int Height = 600;
	const int Style = sf::Style::Close | sf::Style::Titlebar;
	const std::string Title = "Islands";
}