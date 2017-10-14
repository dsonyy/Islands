/*
 *	Program:	Islands
 *	License:	GNU GPL 2.0
 *	Author:		dsonyy
 *	GitHub:		https://github.com/dsonyy/Islands
 */


#pragma once

#include "state-i.h"
#include "state-intro.h"
#include "state-menu.h"


class StatesManager
{
public:
	StatesManager();
	~StatesManager() {}

	StateI & GetActiveState();

	StateI & BeginState() { return menu_; }

	StateI & Intro() { return intro_; }
	StateI & Menu() { return menu_; }


private:
	StateI * active_state_;

	StateIntro intro_;
	StateMenu menu_;
};