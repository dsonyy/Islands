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

class StateTest
	: public StateI
{
public:
	StateTest() : paused_(true), buffer_(100, 100, sf::Vector2f(300,300)){}
	~StateTest() {}

	virtual void Init();
	virtual void Cleanup();

	virtual void HandleInput(const InputRecord & input_record);
	virtual void Update();
	virtual void Draw(WindowManager & window);

	virtual void Pause();
	virtual void Resume();


private:
	bool paused_;
	Buffer buffer_;
};