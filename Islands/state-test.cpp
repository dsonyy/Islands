#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "game.h"
#include "state-i.h"
#include "state-test.h"

void StateTest::Init()
{
	paused_ = false;

	size_.x = 50;
	size_.y = 50;

	pos_.x = Window::Width / 2 - size_.x / 2;
	pos_.y = Window::Height / 2 - size_.y / 2;

	quad_.setPrimitiveType(sf::PrimitiveType::Quads);
	quad_.append(pos_ + sf::Vector2f(0, 0));
	quad_.append(pos_ + sf::Vector2f(pos_.x, 0));
	quad_.append(pos_ + sf::Vector2f(pos_.x, pos_.y));
	quad_.append(pos_ + sf::Vector2f(0, pos_.y));
}

void StateTest::Cleanup()
{
	paused_ = true;
}

void StateTest::Update(Game & game)
{

}

void StateTest::Draw(Game & game)
{
	game.Draw(quad_);
}

void StateTest::Pause()
{
	paused_ = true;
}

void StateTest::Resume()
{
	paused_ = false;
}
