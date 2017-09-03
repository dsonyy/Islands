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

#include "resources-manager.h"
#include "window-manager.h"
#include "state-i.h"
#include "buffer.h"

class StatesManager;

class Game
{
public:
	Game(StatesManager & states, 
		WindowManager & window,
		ResourcesManager & resources);
	~Game();

	void Loop();
	void HandleInput();
	void Update();
	void Render();

private:
	bool running_;
	WindowManager & window_;
	StatesManager & states_;
	ResourcesManager & resources_;
};
