#include <cmath>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "window-manager.h"
#include "game.h"
#include "state-i.h"
#include "state-test.h"

void StateTest::Init()
{
	paused_ = false;

	size_.x = 200;
	size_.y = 200;

	pos_.x = Window::Width / 2 - size_.x / 2;
	pos_.y = Window::Height / 2 - size_.y / 2;

	quad_.setPrimitiveType(sf::PrimitiveType::Quads);
	quad_.append(sf::Vertex(pos_ + sf::Vector2f(0, 0),
		sf::Color::Red));
	quad_.append(sf::Vertex(pos_ + sf::Vector2f(size_.x, 0),
		sf::Color::Red));
	quad_.append(sf::Vertex(pos_ + sf::Vector2f(size_.x, size_.y),
		sf::Color::Blue));
	quad_.append(sf::Vertex(pos_ + sf::Vector2f(0, size_.y),
		sf::Color::Blue));
}

void StateTest::Cleanup()
{
	paused_ = true;
}

sf::Vector2f StateTest::RotatePoint(sf::Vector2f pos, float angle) const
{
	float cx = 400;
	float cy = 300;

	float tempX = pos.x - cx;
	float tempY = pos.y - cy;

	float rotatedX = tempX*cos(angle) - tempY*sin(angle);
	float rotatedY = tempX*sin(angle) + tempY*cos(angle);

	pos.x = rotatedX + cx;
	pos.y = rotatedY + cy;

	return sf::Vector2f(pos.x, pos.y);
}

void StateTest::HandleInput(const InputRecord & input_record)
{

}

void StateTest::Update()
{
	quad_[0].position = RotatePoint(quad_[0].position, 0.01f);
	quad_[1].position = RotatePoint(quad_[1].position, 0.01f);
	quad_[2].position = RotatePoint(quad_[2].position, 0.01f);
	quad_[3].position = RotatePoint(quad_[3].position, 0.01f);

}

void StateTest::Draw(WindowManager & window)
{
	window.draw(quad_);
}

void StateTest::Pause()
{
	paused_ = true;
}

void StateTest::Resume()
{
	paused_ = false;
}
