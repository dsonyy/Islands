
#include <vector>

#include "input-record.h"


InputRecord::InputRecord()
	: mouse_moved_(false),
	  mouse_buttons_changed_(false),
	  keyboard_keys_changed_(false)
{
	for each (auto & b in buttons_)
	{
		b = false;
	}

	for each (auto & k in keys_)
	{
		k = false;
	}
}

bool InputRecord::IsInputChanged() const
{
	return (mouse_moved_ || mouse_buttons_changed_ || keyboard_keys_changed_);
}

void InputRecord::Refresh()
{
	mouse_moved_ = false;
	mouse_buttons_changed_ = false;
	keyboard_keys_changed_ = false;
}


void InputRecord::UpdateMousePos(const sf::Window & window)
{
	auto new_mouse_pos = sf::Mouse::getPosition(window);

	if (new_mouse_pos != mouse_pos_)
	{
		mouse_moved_ = true;
		mouse_pos_ = new_mouse_pos;
	}

}

void InputRecord::SetMousePos(const sf::Vector2i & new_mouse_pos)
{
	if (new_mouse_pos != mouse_pos_)
	{
		mouse_moved_ = true;
		mouse_pos_ = new_mouse_pos;
	}
	
}

sf::Vector2i InputRecord::GetMousePos() const
{
	return mouse_pos_;
}

bool InputRecord::IsMousePosChanged() const
{
	return mouse_moved_;
}



void InputRecord::PressMouseButton(sf::Mouse::Button button)
{
	if (buttons_[button] != PRESSED)
	{
		buttons_[button] = PRESSED;
		mouse_buttons_changed_ = true;
	}
}

void InputRecord::ReleaseMouseButton(sf::Mouse::Button button)
{
	if (buttons_[button] != RELEASED)
	{
		buttons_[button] = RELEASED;
		mouse_buttons_changed_ = true;
	}
}

InputRecord::button InputRecord::GetMouseButton(sf::Mouse::Button button) const 
{
	return buttons_[button];
}

bool InputRecord::IsMouseButtonsChanged() const
{
	return mouse_buttons_changed_;
}





void InputRecord::PressKeyboardKey(sf::Keyboard::Key key)
{
	if (keys_[key] != PRESSED)
	{
		keys_[key] = PRESSED;
		keyboard_keys_changed_ = true;
	}
}

void InputRecord::ReleaseKeyboardKey(sf::Keyboard::Key key)
{
	if (keys_[key] != RELEASED)
	{
		keys_[key] = RELEASED;
		keyboard_keys_changed_ = true;
	}
}

InputRecord::key InputRecord::GetKeyboardKey(sf::Keyboard::Key key) const
{
	return keys_[key];
}

bool InputRecord::IsKeyboardKeysChanged() const
{
	return keyboard_keys_changed_;
}

