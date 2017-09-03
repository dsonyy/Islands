#include <cstdlib>

#include "state-intro.h"
#include "window-manager.h"
#include "states-manager.h"

void StateIntro::Init()
{
	loops_ = 0;
	paused_ = false;
}

void StateIntro::Cleanup()
{

}

void StateIntro::HandleInput(const InputRecord & input_record)
{
	if (input_record.ButtonClicked() || input_record.KeyClicked())
	{
		switch_to_menu_ = true;
	}

	if (input_record.MouseMoved())
	{
		rect_.setPosition(
			static_cast<sf::Vector2f>(input_record.UnpackMousePos()));
	}
}

void StateIntro::Update()
{
	if (!paused_)
	{
		loops_++;

		if (loops_ >= Window::FrameRate)
		{
			rect_.Clear(sf::Color(
				std::rand() % 128 + 128,
				std::rand() % 128 + 128,
				std::rand() % 128 + 128
			));

			loops_ = 0;
		}

	}

	rect_.rotate(1.0f);
}

void StateIntro::Draw(WindowManager & window)
{
	window.draw(rect_);
}

void StateIntro::Pause()
{
	paused_ = true;
}

void StateIntro::Resume()
{
	paused_ = false;
}

StateI * StateIntro::IsCompleted(StatesManager & states_manager)
{
	if (switch_to_menu_)
	{
		return &states_manager.Menu();
	}

	return &states_manager.Intro();
}

