
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "window-manager.h"

void WindowManager::CreateWindow(size_t width, size_t height,
	const std::string & title, size_t style)
{
	create(sf::VideoMode(width, height), title, style);
}