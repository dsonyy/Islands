/*
 *	Program:	Islands
 *	License:	GNU GPL 2.0
 *	Author:		dsonyy
 *	GitHub:		https://github.com/dsonyy/Islands
 */


#include <vector>
#include <iostream>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "window-manager.h"
#include "states-container.h"
#include "game.h"

int main()
{
	WindowManager window;
	StatesContainer states;

	Game game(states, window);
	
	game.Loop();

	return 0;
}