#include "states-manager.h"

StatesManager::StatesManager()
	: active_state_(&BeginState())
{
	active_state_->Init();
}


StateI & StatesManager::GetActiveState()
{
	active_state_ = active_state_->GetNextState(*this);

	return *active_state_;

}