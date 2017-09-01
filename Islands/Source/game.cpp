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
#include "input-record.h"

#include "state-test.h"


Game::Game(std::vector<StateI *> avalible_states, 
	WindowManager * window)
	: window_(window)
{
	window_->CreateWindow();

	states_.push_back(avalible_states.front());
	states_.front()->Init();

	std::fill(keys_, keys_ + sf::Keyboard::KeyCount, false);
	running_ = true;
}

Game::~Game()
{

}

void Game::Loop()
{
	sf::Clock clock;
	sf::Time next_tick;
	sf::Event event;

	while (running_)
	{
		while (window_->pollEvent(event))
		{
			HandleInput(event);
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
	InputRecord input_record;

	switch (event.type)
	{
	case sf::Event::Closed:
		running_ = false;
		break;

	case sf::Event::MouseMoved:
		input_record.PackMousePos(sf::Mouse::getPosition());
		break;

	case sf::Event::KeyPressed:
		input_record.PackKeyboard(event.key.code, InputStatus::PRESSED);
		break;

	case sf::Event::KeyReleased:
		input_record.PackKeyboard(event.key.code, InputStatus::RELEASED);
		break;
	
	}

	states_.back()->HandleInput(input_record);
}

void Game::Update()
{
	states_.back()->Update();
}

void Game::Render()
{
	window_->clear();

	for each (auto state in states_)
	{
		state->Draw(*window_);
	}

	window_->display();
}

void Game::PopState()
{
	states_.pop_back();

}

void Game::PushState(StateI * state)
{
	states_.push_back(state);
}
