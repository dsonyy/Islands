/*
 *	Program:	Islands
 *	License:	GNU GPL 2.0
 *	Author:		dsonyy
 *	GitHub:		https://github.com/dsonyy/Islands
 */


#pragma once

#include "state-i.h"

#include "state-intro.h"
#include "state-outro.h"
#include "state-menu.h"
#include "state-game.h"
#include "state-test.h"

class StatesManager
{
public:
	StatesManager() {}
	~StatesManager() {}

	StateI & GetActiveState() const;

	StateI & Intro() 	{ return intro_; }
	StateI & Outro() 	{ return outro_; }
	StateI & Game()		{ return game_; }
	StateI & Menu()		{ return menu_; }
	StateI & Test()		{ return test_; }

private:
	StateIntro intro_;
	StateOutro outro_;
	StateGame game_;
	StateMenu menu_;
	StateTest test_;

};