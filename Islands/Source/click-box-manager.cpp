#include <vector>

#include <SFML/Graphics.hpp>

#include "click-box-manager.h"

std::vector<sf::Drawable> ClickBoxManager::Hover(const sf::Vector2i & pos)
{
	for each (auto & d in drawables_)
	{

	}

	return std::vector<sf::Drawable>();
}

std::vector<sf::Drawable> ClickBoxManager::Click(const sf::Vector2i & pos)
{

	return std::vector<sf::Drawable>();
}

std::vector<sf::Drawable> ClickBoxManager::Release(const sf::Vector2i & pos)
{

	return std::vector<sf::Drawable>();
}

std::vector<sf::Drawable> ClickBoxManager::Hover(size_t pos_x, size_t pos_y)
{

	return std::vector<sf::Drawable>();
}

std::vector<sf::Drawable> ClickBoxManager::Click(size_t pos_x, size_t pos_y)
{

	return std::vector<sf::Drawable>();
}

std::vector<sf::Drawable> ClickBoxManager::Release(size_t pos_x, size_t pos_y)
{

	return std::vector<sf::Drawable>();
}
