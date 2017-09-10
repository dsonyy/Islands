#include <cstdlib>

#include "state-menu.h"
#include "window-manager.h"
#include "states-manager.h"

void StateMenu::Init(ResourcesManager & resources)
{
	paused_ = false;
	resources_ = &resources;
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
	//sf::Text txt("Start Game", resources_->GetDefaultFont(), 30);
	//txt.setPosition(sf::Vector2f( 
	//	window.getSize().x / 2 - txt.getLocalBounds().width / 2,
	//	window.getSize().y / 2 - txt.getLocalBounds().height / 2));
	
	//window.draw(txt);
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

