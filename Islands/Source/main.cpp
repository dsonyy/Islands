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

#include "state-i.h"
#include "state-test.h"
#include "game.h"

int main()
{



	StateTest state_test;

	std::vector<StateI *> avalible_states 
	{ 
		&state_test 
	};

	Game game(avalible_states);

	game.Loop();

	return 0;
}