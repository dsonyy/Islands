/*
 *	Program:	Islands
 *	License:	GNU GPL 2.0
 *	Author:		dsonyy
 *	GitHub:		https://github.com/dsonyy/Islands
 */


#pragma once

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "state-i.h"
#include "buffer.h"
#include "input-record.h"
#include "window-manager.h"


class StateTest
	: public StateI
{
public:
	StateTest() : paused_(true), buffer_(100, 100, sf::Vector2f(500,500)){}
	~StateTest() {}

	virtual void Init();
	virtual void Cleanup();

	virtual void HandleInput(const InputRecord & input_record);
	virtual void Update();
	virtual void Draw(WindowManager & window);

	virtual void Pause();
	virtual void Resume();

	virtual StateI * WaitForChange(StatesManager & states_manager);
private:
	bool paused_;
	Buffer buffer_;
};