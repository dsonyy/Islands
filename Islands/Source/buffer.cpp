/*
 *	Program:	Islands
 *	License:	GNU GPL 2.0
 *	Author:		dsonyy
 *	GitHub:		https://github.com/dsonyy/Islands
 */



#include <exception>
#include <iostream>
#include <algorithm>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "buffer.h"

Buffer::Buffer(size_t width, size_t height, sf::Vector2f pos)
	: width_(width), height_(height), pos_(pos), color_map_(width * height)
{
	setPosition(pos);
	setOrigin(sf::Vector2f(pos.x + width / 2, pos.y + height / 2));

	texture_.create(width, height);

	sprite_.setTexture(texture_);
	sprite_.setPosition(pos);
}

Buffer::~Buffer()
{
}

void Buffer::UpdateTexture()
{
	texture_.update((sf::Uint8*)&color_map_[0]);
}

void Buffer::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	
	states.texture = &texture_;

	target.draw(sprite_, states);
}

const sf::Color & Buffer::GetColor(size_t x, size_t y) const
{
	if (x >= width_ || y >= height_)
	{
		return sf::Color::Transparent;
	}

	return color_map_[y * width_ + x];
}

bool Buffer::SetColor(size_t x, size_t y, sf::Color color)
{
	if (x >= width_ || y >= height_)
	{
		return false;
	}

	color_map_[y * width_ + x] = color;
}

void Buffer::Clear(const sf::Color & color)
{
	std::fill(color_map_.begin(), color_map_.end(), color);
	
	UpdateTexture();
}