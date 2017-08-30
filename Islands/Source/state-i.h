#pragma once

#include "window-manager.h"

class Game;

class StateI
{
public:
	virtual ~StateI() {}

	virtual void Init() = 0;
	virtual void Cleanup() = 0;

	virtual void Update() = 0;
	virtual void Draw(WindowManager & window) = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

};

