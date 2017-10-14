#include <cstdlib>
#include <iostream>

#include "state-menu.h"
#include "window-manager.h"
#include "states-manager.h"

void StateMenu::Init(ResourcesManager & resources)
{
	// initialize variables
	paused_ = false;
	resources_ = resources;

	//
	//  BACKGROUND
	if (!resources_.ImportTexture("resources/textures/bg-menu.png", "bg-menu"))
	{
		std::cout << "Unable to load bg-menu";
	}
	background_texture_ = resources_.GetTexture("bg-menu");
	background_.setTexture(background_texture_);
	float x = float(Window::Width) / float(background_texture_.getSize().x);
	float y = float(Window::Height) / float(background_texture_.getSize().y);

	background_.setScale(sf::Vector2f(
		float(Window::Width) / float(background_texture_.getSize().x),
		float(Window::Height) / float(background_texture_.getSize().y)
	));

	//
	// MENU
	menu_.AddHeader("Main Menu");
	menu_.AddButton("Load Game");
	menu_.AddButton("New Game");
	menu_.AddButton("Delete Game");
	menu_.AddButton("Miscellaneous");
	menu_.AddButton("Exit");
	menu_.AddText("No copyright (c) 2017 dsonyy");


}

void StateMenu::Cleanup()
{

}

void StateMenu::HandleInput(const InputRecord & input_record)
{
	if (input_record.MouseMoved())
	{
		if (click_box_manager_.Check(input_record.UnpackMousePos(), "test"))
		{
		}
		else
		{
		}
	}

}

void StateMenu::Update()
{
	
}

void StateMenu::Draw(WindowManager & window)
{
	window.draw(background_);

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

