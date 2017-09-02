/*
 *	Program:	Islands
 *	License:	GNU GPL 2.0
 *	Author:		dsonyy
 *	GitHub:		https://github.com/dsonyy/Islands
 */


#include <cmath>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "window-manager.h"
#include "game.h"
#include "state-i.h"
#include "state-test.h"

void StateTest::Init()
{
	paused_ = false;
	buffer_.Clear(sf::Color::Blue);
}

void StateTest::Cleanup()
{
	paused_ = true;
}

void StateTest::HandleInput(const InputRecord & input_record)
{
	if (input_record.MouseMoved())
	{
		sf::Vector2i mouse_pos = input_record.UnpackMousePos();
	}
}

void StateTest::Update()
{
	buffer_.rotate(1);
}

void StateTest::Draw(WindowManager & window)
{
	window.draw(buffer_);
}

void StateTest::Pause()
{
	paused_ = true;
}

void StateTest::Resume()
{
	paused_ = false;
}
