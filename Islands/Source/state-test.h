#pragma once

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "state-null.h"
#include "state-i.h"
#include "game.h"
#include "input-record.h"
#include "window-manager.h"

class StatesManager;

class StateTest
	: public StateI
{
public:
	StateTest() : init_(false), paused_(true) {}
	~StateTest() {}

	virtual void Init(ResourcesManager & resources = ResourcesManager());
	virtual void Cleanup();

	virtual void HandleInput(const InputRecord & input_record);
	virtual void Update();
	virtual void Draw(WindowManager & window);

	virtual void Pause();
	virtual void Resume();

	virtual bool IsInit() const { return init_; }
	virtual bool IsPaused() const { return paused_; }

	virtual StateI * GetNextState(StatesManager & states_manager);

protected:
	bool init_;
	bool paused_;
	ResourcesManager resources_;

private:
	long long update_counter_;
	long long redraw_counter_;

};