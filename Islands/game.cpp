/*
 *	Program:	Islands
 *	License:	GNU GPL 2.0
 *	Author:		dsonyy
 *	GitHub:		https://github.com/dsonyy/Islands
 */


#include <string>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "game.h"
#include "buffer.h"

#include "state-test.h"


Game::Game(std::vector<StateI *> avalible_states)
	: screen_buffer_(Window::Width, Window::Height)
{
	CreateWindow(Window::Width, Window::Height, Window::Title);

	states_.push_back(avalible_states.front());

	running_ = true;
}

Game::~Game()
{

}

void Game::CreateWindow(unsigned int width, unsigned int height, 
	const std::string & title)
{
	window_.create(sf::VideoMode(Window::Width, Window::Height), 
		Window::Title, Window::Style);
}

void Game::Loop()
{
	sf::Clock clock;
	sf::Time next_tick;
	sf::Event event;

	while (running_)
	{
		while (window_.pollEvent(event))
		{

		}

		if (clock.getElapsedTime() >= next_tick)
		{
			Update();
			Render();

			next_tick += sf::milliseconds(1000 / Window::FrameRate);
		}


	}
}

void Game::HandleInput(const sf::Event & event)
{
	switch (event.type)
	{
	case sf::Event::Closed:
		break;
	
	case sf::Event::KeyPressed:
		break;

	case sf::Event::KeyReleased:
		break;
	
	}
}

void Game::Update()
{
	for each (StateI * state in states_)
	{
		state->Update(*this);
	}
}

void Game::Draw(const sf::Drawable & drawable)
{
	window_.draw(drawable);
}

void Game::Render()
{
	

	for each (StateI * state in states_)
	{
		state->Draw(*this);
	}

	window_.clear();

	window_.draw(screen_buffer_.GetSprite());

	window_.display();
}
