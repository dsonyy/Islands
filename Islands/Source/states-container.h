/*
 *	Program:	Islands
 *	License:	GNU GPL 2.0
 *	Author:		dsonyy
 *	GitHub:		https://github.com/dsonyy/Islands
 */


#pragma once

#include "state-i.h"
#include "state-test.h"

class StatesContainer
{
public:
	StatesContainer() {}
	~StatesContainer() {}

	StateI & Intro()	{ return test_; }
	StateI & Outro()	{ return test_; }
	StateI & Game()		{ return test_; }
	StateI & Menu()		{ return test_; }
	StateI & Test()		{ return test_; }

private:
	StateTest test_;
	
};