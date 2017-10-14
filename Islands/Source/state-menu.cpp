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

	// load resources
	if (!resources_.ImportTexture("resources/textures/bg-menu.png", "bg-menu"))
	{
		std::cout << "Unable to load bg-menu";
	}
	background_texture_ = resources_.GetTexture("bg-menu");
	background_.setTexture(background_texture_);



	color_ = false;
	click_box_manager_.AddClickBox(ClickBox{ "test", sf::Vector2i(0,0), sf::Vector2i(100, 100) });
	

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
			color_ = true;
		}
		else
		{
			color_ = false;
		}
	}

}

void StateMenu::Update()
{
	
}

void StateMenu::Draw(WindowManager & window)
{
	window.draw(background_);



	///////////

	sf::Text txt("Start Game", resources_.GetDefaultFont(), 30);
	txt.setPosition(sf::Vector2f( 
		50,
		window.getSize().y / 2 - txt.getLocalBounds().height / 2));


	sf::Text quit("Quit", resources_.GetDefaultFont(), 30);
	quit.setPosition(sf::Vector2f(
		50,
		window.getSize().y / 2 - txt.getLocalBounds().height / 2 + 50));

	sf::RectangleShape rect(sf::Vector2f(100, 100));
	rect.setFillColor(sf::Color::White);
	if (color_)
	{
		window.draw(rect);
	}

	window.draw(txt);
	window.draw(quit);
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

