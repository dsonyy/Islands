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
		const std::string Regular1		= "resources/";
		const std::string Bold1			= "resources/";
		const std::string Italic1		= "resources/";
		const std::string BoldItalic1	= "resources/";

		const std::string Regular2		= "resources/";
		const std::string Bold2			= "resources/";
		const std::string Italic2		= "resources/";
		const std::string BoldItalic2	= "resources/";
	}

	namespace Textures
	{

	}

}

