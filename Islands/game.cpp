#include <string>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "game.h"
#include "buffer.h"


Game::Game()
{
	Create(Window::Width, Window::Height, Window::Title);
}

Game::~Game()
{

}

void Game::Create(unsigned int width, unsigned int height, 
	const std::string & title)
{
	window_.create(sf::VideoMode(Window::Width, Window::Height), 
		Window::Title, Window::Style);
}

void Game::Draw(const sf::Drawable & drawable)
{
	window_.draw(drawable);
}

void Game::Render()
{
	window_.clear();
	window_.display();
}
