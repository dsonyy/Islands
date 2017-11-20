#include <cstdlib>
#include <iostream>

#include "globals.h"
#include "state-test.h"
#include "window-manager.h"
#include "states-manager.h"

void StateTest::Init(ResourcesManager & resources)
{
	update_counter_ = 0;
	redraw_counter_ = 0;

	resources_.ImportFont(Global::Font::Courier);
}

void StateTest::Cleanup()
{
	resources_.Clear();
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
	sf::Text text("Update: 2115", resources_.GetFont(Global::Font::Courier), 30);
	text.setStyle(sf::Text::Style::Bold);
	text.setPosition(sf::Vector2f(0, 0));
	text.setOrigin(sf::Vector2f(0, 0));
	window.draw(text);
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

