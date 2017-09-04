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

class StateIntro
	: public StateI
{
public:
	StateIntro() : paused_(true), switch_to_menu_(false),
		rect_(Window::Width / 4, Window::Height / 4,
		sf::Vector2f(Window::Width / 2 , Window::Height / 2)) {}
	~StateIntro() {}

	virtual void Init(const ResourcesManager & resources = ResourcesManager());
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
	bool switch_to_menu_;
	Buffer rect_;
	int loops_;
};