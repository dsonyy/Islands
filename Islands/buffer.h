/*
 *	Program:	Islands
 *	License:	GNU GPL 2.0
 *	Author:		dsonyy
 *	GitHub:		https://github.com/dsonyy/Islands
 */


#pragma once

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>


class Buffer
{
public:
	Buffer(sf::Vector2f size = sf::Vector2f(0, 0), 
		   sf::Vector2f position = sf::Vector2f(0, 0));
	Buffer(const Buffer & buffer);
	Buffer(const Buffer && buffer);
	Buffer & operator=(const Buffer & buffer);
	Buffer & operator=(const Buffer && buffer);
	~Buffer();


	operator sf::Sprite() const		{ return sprite_; };
	operator sf::Texture() const	{ return texture_; };
	operator sf::Color*() const		{ return color_map_; };

	const sf::Sprite & GetSprite() const	{ return sprite_; }
	const sf::Texture & GetTexture() const	{ return texture_; }
	const sf::Color * GetColorMap() const	{ return color_map_; }

	unsigned int GetWidth() const	{ return unsigned int(size_.x); }
	unsigned int GetHeight() const	{ return unsigned int(size_.y); }
	unsigned int GetSize() const	{ return unsigned int(size_.x * size_.y); }

	float GetX() const { return pos_.x; }
	float GetY() const { return pos_.y; }


	bool SetPixel(sf::Vector2f pos, sf::Color color);
	void Clear(sf::Color color);

private:
	sf::Texture texture_;
	sf::Sprite sprite_;
	sf::Color * color_map_;
	sf::Vector2f pos_;
	sf::Vector2f size_;
};

