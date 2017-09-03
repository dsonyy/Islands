/*
 *	Program:	Islands
 *	License:	GNU GPL 2.0
 *	Author:		dsonyy
 *	GitHub:		https://github.com/dsonyy/Islands
 */


#pragma once

#include "state-i.h"
#include "state-intro.h"


class StatesManager
{
public:
	StatesManager() {}
	~StatesManager() {}

	StateI & GetActiveState();

	StateI & Intro() 	{ return intro_; }


private:
	StateIntro intro_;

};