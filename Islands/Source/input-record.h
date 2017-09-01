#pragma once

#include <vector>

#include <SFML\Window.hpp>

enum class InputStatus { UNCHANGED = -1, RELEASED = 0, PRESSED };


class InputRecord
{
public:
	InputRecord() : mouse_moved_(false) {}
	~InputRecord() {}

	void PackKeyboard(sf::Keyboard::Key keyboard_key, InputStatus status)
	{
		keys_[keyboard_key] = status;
	}

	void PackMousePos(sf::Vector2i mouse_pos)
	{
		mouse_pos_ = mouse_pos;
	}

	void PackMouseButton(sf::Mouse::Button mouse_button, InputStatus status)
	{
		buttons_[mouse_button] = status;
	}

	InputStatus UnpackKeyboard(sf::Keyboard::Key key_to_get) const
	{
		return keys_[key_to_get];
	}

	InputStatus UnpackMouseButton(sf::Mouse::Button mouse_button_to_get) const
	{
		return buttons_[mouse_button_to_get];
	}

	bool MouseMoved() const
	{
		return mouse_moved_;
	}

	sf::Vector2i UnpackMousePos() const
	{
		return mouse_pos_;
	}

private:
	InputStatus keys_[sf::Keyboard::KeyCount];
	InputStatus buttons_[sf::Mouse::ButtonCount];

	bool mouse_moved_;
	sf::Vector2i mouse_pos_;

};