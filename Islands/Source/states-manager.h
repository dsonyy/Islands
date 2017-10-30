/*
 *	Program:	Islands
 *	License:	GNU GPL 2.0
 *	Author:		dsonyy
 *	GitHub:		https://github.com/dsonyy/Islands
 */


#pragma once

#include "state-i.h"
#include "state-null.h"


class StatesManager
{
public:
	StatesManager();
	~StatesManager() {}

	StateI & GetActiveState();

	StateI & BeginState() { return null_; }

	StateI & Null() { return null_; }


private:
	StateI * active_state_;

	StateNull null_;
};