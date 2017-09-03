#include "states-manager.h"

StatesManager::StatesManager()
	: active_state_(&BeginState())
{
	active_state_->Init();
}


StateI & StatesManager::GetActiveState()
{
	StateI * next_state = active_state_->IsCompleted(*this);

	if (next_state == active_state_)
	{
		return *active_state_;
	}
	else
	{
		active_state_->Cleanup();
		next_state->Init();

		active_state_ = next_state;

		return *active_state_;
	}

}