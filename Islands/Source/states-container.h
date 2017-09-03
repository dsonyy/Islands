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

class StatesContainer
{
public:
	StatesContainer() {}
	~StatesContainer() {}

	StateI & Intro()	{ return intro_; }
	StateI & Outro()	{ return intro_; }
	StateI & Game()		{ return intro_; }
	StateI & Menu()		{ return intro_; }
	StateI & Test()		{ return intro_; }

private:
	StateIntro intro_;

};