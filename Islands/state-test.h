#pragma once

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "state-i.h"

class StateTest
	: public StateI
{
public:
	StateTest() : paused_(true) {}
	~StateTest() {}

	virtual void Init();
	virtual void Cleanup();

	virtual void Update(Game & game);
	virtual void Draw(Game & game);

	virtual void Pause();
	virtual void Resume();


private:
	bool paused_;
	sf::VertexArray quad_;;
	sf::Vector2f pos_;
	sf::Vector2f size_;
};