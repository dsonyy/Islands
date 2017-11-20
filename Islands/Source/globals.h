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
		const std::string Courier	= "resources/cour.ttf";
		const std::string CourierB	= "resources/courbd.ttf";
		const std::string CourierI	= "resources/couri.ttf";
		const std::string CourierBI	= "resources/courbi.ttf";
	}

	namespace Textures
	{

	}

}

