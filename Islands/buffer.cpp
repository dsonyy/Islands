
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
	texture_.create(width, height);

	sprite_.setTexture(texture_);

	texture_.update((sf::Uint8*)&color_map_[0]);
}

Buffer::~Buffer()
{
}

sf::Color & Buffer::operator()(size_t x, size_t y)
{
	try
	{
		if (x >= width_) throw std::range_error("X position out of range");
		if (y >= height_) throw std::range_error("Y position out of range");
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	texture_.update((sf::Uint8*)&color_map_[0]);

	return color_map_[y * width_ + x];

}

void Buffer::Clear(const sf::Color & color)
{
	std::fill(color_map_.begin(), color_map_.end(), color);
}