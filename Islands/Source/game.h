/*
 *	Program:	Islands
 *	License:	GNU GPL 2.0
 *	Author:		dsonyy
 *	GitHub:		https://github.com/dsonyy/Islands
 */


#pragma once

#include <string>
#include <vector>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "window-manager.h"
#include "state-i.h"
#include "states-manager.h"
#include "buffer.h"

class Game
{
public:
	Game(StatesManager & states, WindowManager & window);
	~Game();

	void Loop();
	void HandleInput();
	void Update();
	void Render();

private:
	WindowManager & window_;
	bool running_;
	StatesManager & states_;
};
