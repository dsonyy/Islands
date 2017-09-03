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

#include "states-manager.h"


Game::Game(StatesManager & states, WindowManager & window)
	: window_(window), states_(states)
{
	window_.CreateWindow();

	running_ = true;
}

Game::~Game()
{
}

void Game::Loop()
{
	sf::Clock clock;
	sf::Time next_tick;
	
	while (running_)
	{
		HandleInput();

		if (clock.getElapsedTime() >= next_tick)
		{
			Update();
			Render();

			next_tick += sf::milliseconds(1000 / Window::FrameRate);
		}

	}
}

void Game::HandleInput()
{
	InputRecord input_record;
	sf::Event event;

	while (window_.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			running_ = false;
			break;

		case sf::Event::MouseMoved:
			input_record.PackMousePos(sf::Mouse::getPosition(window_));
			break;
			
		case sf::Event::KeyPressed:
			input_record.PackKeyboard(event.key.code, InputStatus::PRESSED);
			break;

		case sf::Event::KeyReleased:
			input_record.PackKeyboard(event.key.code, InputStatus::RELEASED);
			break;

		}
	}

	states_.GetActiveState().HandleInput(input_record);
}

void Game::Update()
{
	states_.GetActiveState().Update();
}

void Game::Render()
{
	window_.clear();

	states_.GetActiveState().Draw(window_);

	window_.display();
}
