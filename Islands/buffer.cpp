
#include <cmath>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "buffer.h"


Buffer::Buffer(sf::Vector2f size, sf::Vector2f pos)
{
	size_.x = std::floor(size.x);
	size_.y = std::floor(size.y);

	pos_ = pos;

	texture_.create(unsigned int(size.x), unsigned int(size.y));
	sprite_.setTexture(texture_);

	sd.reserve(12);
	

}

Buffer::Buffer(const Buffer & buffer)
{

}

Buffer::Buffer(const Buffer && buffer)
{

}

Buffer & Buffer::operator=(const Buffer & buffer)
{
	return *this;
}

Buffer & Buffer::operator=(const Buffer && buffer)
{
	return *this;
}

Buffer::~Buffer()
{

}

bool Buffer::SetPixel(sf::Vector2f pos, sf::Color color)
{
	return true;
}

void Buffer::Clear(sf::Color color)
{

}