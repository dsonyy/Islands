#include <cstdlib>
#include <iostream>

#include "state-test.h"
#include "window-manager.h"
#include "states-manager.h"

void StateTest::Init(ResourcesManager & resources)
{
	update_counter_ = 0;
	redraw_counter_ = 0;
}

void StateTest::Cleanup()
{

}

void StateTest::HandleInput(const InputRecord & input_record)
{
	if (input_record.IsInputChanged())
	{
		std::cout << "Input Record Changed: " << 
			"KB:" << input_record.IsKeyboardKeysChanged() <<
			" MM: " << input_record.IsMousePosChanged() <<
			" MB: " << input_record.IsMouseButtonsChanged() << std::endl;
	}
	
}

void StateTest::Update()
{
	std::cout << "Update: " << ++update_counter_ << std::endl;
}

void StateTest::Draw(WindowManager & window)
{
	std::cout << "Redraw: " << ++redraw_counter_ << std::endl;
}

void StateTest::Pause()
{
	std::cout << "**** Paused **** " << std::endl;

	paused_ = true;
}

void StateTest::Resume()
{
	std::cout << "**** Resumed **** " << std::endl;

	paused_ = false;
}

StateI * StateTest::GetNextState(StatesManager & states_manager)
{
	return this;
}

