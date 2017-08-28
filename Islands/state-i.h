#pragma once

class Game;

class StateI
{
public:
	virtual ~StateI() {}

	virtual void Init() = 0;
	virtual void Cleanup() = 0;

	virtual void Update(Game & game) = 0;
	virtual void Draw(Game & game) = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

};

