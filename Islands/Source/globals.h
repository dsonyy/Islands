#pragma once
#include <string>

#include <SFML\Graphics.hpp>


namespace Global
{
	namespace Window
	{
		const unsigned int FrameRate = 60;
		const unsigned int Width = 800;
		const unsigned int Height = 450;
		const int Style = sf::Style::Close | sf::Style::Titlebar;
		const std::string Title = "Islands";
	}

	namespace Font
	{
		const std::string Courier	= "resources/fonts/cour.ttf";
		const std::string CourierB	= "resources/fonts/courbd.ttf";
		const std::string CourierI	= "resources/fonts/couri.ttf";
		const std::string CourierBI	= "resources/fonts/courbi.ttf";
	}

	namespace Textures
	{

	}

}

