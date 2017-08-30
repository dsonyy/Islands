#pragma once

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "state-i.h"
#include "buffer.h"

class StateTest
	: public StateI
{
public:
	StateTest() : paused_(true), buffer_(100,100,sf::Vector2f(400,300)){}
	~StateTest() {}

	virtual void Init();
	virtual void Cleanup();

	virtual void Update();
	virtual void Draw(WindowManager & window);

	virtual void Pause();
	virtual void Resume();


private:
	sf::Vector2f RotatePoint(sf::Vector2f pos, float angle) const;

	bool paused_;
	Buffer buffer_;

	sf::VertexArray quad_;
	sf::Vector2f pos_;
	sf::Vector2f size_;
};