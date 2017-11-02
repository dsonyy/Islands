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

#include "globals.h"
#include "game.h"
#include "buffer.h"
#include "input-record.h"
#include "resources-manager.h"
#include "states-manager.h"


Game::Game(StatesManager & states, 
	WindowManager & window, 
	ResourcesManager & resources)
	: window_(window), 
	states_(states),
	resources_(resources)
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
	sf::Time next_tick = clock.getElapsedTime();
	
	while (running_)
	{
		HandleInput();

		if (clock.getElapsedTime() >= next_tick)
		{			Update();
			Render();

			next_tick += sf::milliseconds(1000 / Global::Window::FrameRate);
		}

	}
}

void Game::HandleInput()
{
	sf::Event event;

	while (window_.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			running_ = false;
			break;

		case sf::Event::MouseMoved:
			input_.UpdateMousePos(window_);
			break;
			
		case sf::Event::MouseButtonPressed:
			input_.PressMouseButton(event.mouseButton.button);
			break;

		case sf::Event::MouseButtonReleased:
			input_.ReleaseMouseButton(event.mouseButton.button);
			break;

		case sf::Event::KeyPressed:
			input_.PressKeyboardKey(event.key.code);
			break;

		case sf::Event::KeyReleased:
			input_.ReleaseKeyboardKey(event.key.code);
			break;

		}
	}

	states_.GetActiveState().HandleInput(input_);

	input_.Refresh();
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
