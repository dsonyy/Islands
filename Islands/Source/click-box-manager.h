#pragma once

#include <vector>

#include <SFML/Graphics.hpp>



class ClickBoxManager
{
public:
	ClickBoxManager() {}
	~ClickBoxManager() {}

	std::vector<sf::Drawable> Hover(const sf::Vector2i & pos);
	std::vector<sf::Drawable> Click(const sf::Vector2i & pos);
	std::vector<sf::Drawable> Release(const sf::Vector2i & pos);
	
	std::vector<sf::Drawable> Hover(size_t pos_x, size_t pos_y);
	std::vector<sf::Drawable> Click(size_t pos_x, size_t pos_y);
	std::vector<sf::Drawable> Release(size_t pos_x, size_t pos_y);

private:
	std::vector<sf::Drawable> drawables_;
};