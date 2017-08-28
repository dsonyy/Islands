/*
 *	Program:	Islands
 *	License:	GNU GPL 2.0
 *	Author:		dsonyy
 *	GitHub:		https://github.com/dsonyy/Islands
 */


#pragma once

#include <vector>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>


class Buffer
{
public:
	Buffer(size_t width, size_t height,
		   sf::Vector2f pos = sf::Vector2f(0, 0));
	~Buffer();

	operator sf::Sprite &()		{ return sprite_; };
	operator sf::Texture &() 	{ return texture_; };

	sf::Color & operator()(size_t x, size_t y);

	const sf::Sprite & GetSprite() const				{ return sprite_; }
	const sf::Texture & GetTexture() const				{ return texture_; }
	const std::vector<sf::Color> & GetColorMap() const	{ return color_map_; }

	size_t GetWidth() const		{ return width_; }
	size_t GetHeight() const	{ return height_; }
	size_t GetSize() const		{ return width_ * height_; }

	float GetX() const { return pos_.x; }
	float GetY() const { return pos_.y; }

	void Clear(const sf::Color & color);

private:
	size_t width_;
	size_t height_;
	sf::Vector2f pos_;

	std::vector<sf::Color> color_map_;
	sf::Texture texture_;
	sf::Sprite sprite_;

};

