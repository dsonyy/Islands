#include <cstdlib>
#include <iostream>

#include "state-null.h"
#include "window-manager.h"
#include "states-manager.h"

void StateNull::Init(ResourcesManager & resources)
{
	paused_ = false;
	init_ = true;
	resources_ = resources;

}


void StateNull::Cleanup()
{
	paused_ = true;
	init_ = false;
}

void StateNull::HandleInput(const InputRecord & input_record)
{

}

void StateNull::Update()
{

}

void StateNull::Draw(WindowManager & window)
{

}

void StateNull::Pause()
{
	paused_ = true;
}

void StateNull::Resume()
{
	paused_ = false;
}

StateI * StateNull::GetNextState(StatesManager & states_manager)
{
	return &states_manager.Null();
}

