#pragma once

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "game.h"
#include "state-i.h"
#include "buffer.h"
#include "input-record.h"
#include "window-manager.h"

class StatesManager;

class StateMenu
	: public StateI
{
public:
	StateMenu() : paused_(true) {}
	~StateMenu() {}

	virtual void Init(ResourcesManager & resources = ResourcesManager());
	virtual void Cleanup();

	virtual void HandleInput(const InputRecord & input_record);
	virtual void Update();
	virtual void Draw(WindowManager & window);

	virtual void Pause();
	virtual void Resume();

	virtual bool IsInit() const { return init_; }
	virtual bool IsPaused() const { return paused_; }

	virtual StateI * IsCompleted(StatesManager & states_manager);


private:
	bool init_;
	bool paused_;
	ResourcesManager * resources_;
};