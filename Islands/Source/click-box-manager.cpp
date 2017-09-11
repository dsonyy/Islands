#include <vector>

#include <SFML/Graphics.hpp>

#include "click-box-manager.h"

std::vector<ClickBox> ClickBoxManager::Hover(const sf::Vector2i & pos)
{
	std::vector<ClickBox> clicked;

	for each (auto & d in click_boxes_)
	{
		//if (IsPointInsideRect(pos.x, pos.y,
		//	d.getPosition().x, d.getPosition().y,
		//	d.getPosition().x + d., d.getPosition().y))
	}
	return clicked;
}

std::vector<ClickBox> ClickBoxManager::Click(const sf::Vector2i & pos)
{
	std::vector<ClickBox> clicked;

	return clicked;
}

std::vector<ClickBox> ClickBoxManager::Release(const sf::Vector2i & pos)
{
	std::vector<ClickBox> clicked;


	return clicked;
}

std::vector<ClickBox> ClickBoxManager::Hover(size_t pos_x, size_t pos_y)
{
	std::vector<ClickBox> clicked;


	return clicked;
}

std::vector<ClickBox> ClickBoxManager::Click(size_t pos_x, size_t pos_y)
{
	std::vector<ClickBox> clicked;

	return clicked;
}

std::vector<ClickBox> ClickBoxManager::Release(size_t pos_x, size_t pos_y)
{
	std::vector<ClickBox> clicked;

	return clicked;
}

bool ClickBoxManager::IsPointInsideRect(size_t px, size_t py,
	size_t x0, size_t y0, size_t x1, size_t y1) const
{
	if (px >= x0 && px <= x1 &&
		py >= y0 && py <= y1)
	{
		return true;
	}

	return false;
}
