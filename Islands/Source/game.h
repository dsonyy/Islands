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
#include "states-container.h"
#include "buffer.h"

class Game
{
public:
	Game(StatesContainer & states, WindowManager & window);
	~Game();

	void Loop();
	void HandleInput();
	void Update();
	void Render();

	void ChangeState(StateI & new_state);

private:
	WindowManager & window_;
	bool running_;
	StateI & state_;
};
