/*
 *	Program:	Islands
 *	License:	GNU GPL 2.0
 *	Author:		dsonyy
 *	GitHub:		https://github.com/dsonyy/Islands
 */


#pragma once

#include "game.h"
#include "input-record.h"
#include "window-manager.h"
#include "resources-manager.h"

class StatesManager;

class StateI
{
public:
	virtual ~StateI() {}

	virtual void Init(const ResourcesManager & resources = ResourcesManager()) = 0;
	virtual void Cleanup() = 0;

	virtual void HandleInput(const InputRecord & input_record) = 0;
	virtual void Update() = 0;
	virtual void Draw(WindowManager & window) = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual bool IsInit() const = 0;
	virtual bool IsPaused() const = 0;
	virtual StateI * IsCompleted(StatesManager & states_manager) = 0;

};

