/*
 *	Program:	Islands
 *	License:	GNU GPL 2.0
 *	Author:		dsonyy
 *	GitHub:		https://github.com/dsonyy/Islands
 */


#pragma once

#include <vector>

#include <SFML\Window.hpp>

class InputRecord
{
public:

	typedef bool key;
	typedef bool button;

	const bool PRESSED = true;
	const bool RELEASED = false;
	
	InputRecord();
	~InputRecord() {}

	void Refresh();
	bool IsInputChanged() const;

	//
	//	MOUSE POSITION
	//
	void UpdateMousePos(const sf::Window & window);
	void SetMousePos(const sf::Vector2i & pos);
	sf::Vector2i GetMousePos() const;
	bool IsMousePosChanged() const;

	//
	//	MOUSE BUTTONS
	//
	void PressMouseButton(sf::Mouse::Button button);
	void ReleaseMouseButton(sf::Mouse::Button button);
	button GetMouseButton(sf::Mouse::Button button) const;
	bool IsMouseButtonsChanged() const;

	//
	//	KEYBOARD
	//
	void PressKeyboardKey(sf::Keyboard::Key key);
	void ReleaseKeyboardKey(sf::Keyboard::Key key);
	key  GetKeyboardKey(sf::Keyboard::Key key) const;
	bool IsKeyboardKeysChanged() const;


private:
	//	MOUSE POSITION
	bool mouse_moved_;
	sf::Vector2i mouse_pos_;

	//	MOUSE BUTTONS
	bool mouse_buttons_changed_;
	button buttons_[sf::Mouse::ButtonCount];

	//	KEYBOARD
	bool keyboard_keys_changed_;
	key keys_[sf::Keyboard::KeyCount];

};