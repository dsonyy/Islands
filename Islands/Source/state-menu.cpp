#include <cstdlib>

#include "state-menu.h"
#include "window-manager.h"
#include "states-manager.h"

void StateMenu::Init(const ResourcesManager & resources)
{
	paused_ = false;
}

void StateMenu::Cleanup()
{

}

void StateMenu::HandleInput(const InputRecord & input_record)
{

}

void StateMenu::Update()
{

}

void StateMenu::Draw(WindowManager & window)
{

}

void StateMenu::Pause()
{

}

void StateMenu::Resume()
{

}

StateI * StateMenu::IsCompleted(StatesManager & states_manager)
{
	return &states_manager.Menu();
}

