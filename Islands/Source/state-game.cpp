#include "state-game.h"

void StateGame::Init()
{

}

void StateGame::Cleanup()
{

}

void StateGame::HandleInput(const InputRecord & input_record)
{

}

void StateGame::Update()
{

}

void StateGame::Draw(WindowManager & window)
{

}

void StateGame::Pause()
{

}

void StateGame::Resume()
{

}

StateI * StateGame::WaitForChange(StatesManager & states_manager)
{

	return &states_manager.Game();
}