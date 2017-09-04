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
#include "states-manager.h"
#include "resources-manager.h"
#include "game.h"


#include <map>
#include <string>
int main()
{
	WindowManager window;
	StatesManager states;
	ResourcesManager resources;

	Game game(states, window, resources);
	
	game.Loop();

	return 0;
}