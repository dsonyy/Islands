/*
 *	Program:	Islands
 *	License:	GNU GPL 2.0
 *	Author:		dsonyy
 *	GitHub:		https://github.com/dsonyy/Islands
 */


#pragma once

#include "state-i.h"
#include "state-null.h"
#include "state-test.h"


class StatesManager
{
public:
	StatesManager();
	~StatesManager() {}

	StateI & GetActiveState();

	StateI & BeginState() { return test_; }

	StateI & Null() { return null_; }
	StateI & Test() { return test_; }

private:
	StateI * active_state_;

	StateNull null_;
	StateTest test_;
};