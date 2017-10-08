#include <vector>

#include <SFML/Graphics.hpp>

#include "click-box-manager.h"

void ClickBoxManager::AddClickBox(const ClickBox & click_box)
{
	click_boxes_.push_back(click_box);
}

void ClickBoxManager::RemoveClickBox(const std::string & id)
{
	for (int i = 0; i < click_boxes_.size(); i++)
	{
		if (click_boxes_[i].id == id)
		{
			click_boxes_.erase(click_boxes_.begin() + i);
		}
	}
}

bool ClickBoxManager::Check(const sf::Vector2i & pos, const std::string & id) const
{
	for each (auto & d in click_boxes_)
	{
		if (d.id == id && IsPointInsideRect(pos, d.position, d.size))
		{
			return true;
		}
	}

	return false;
}

std::vector<ClickBox> ClickBoxManager::CheckAll(const sf::Vector2i & pos) const
{
	std::vector<ClickBox> c;

	for each (auto & d in click_boxes_)
	{
		if (IsPointInsideRect(pos, d.position, d.size))
		{
			c.push_back(d);
		}
	}
	return c;
}


bool ClickBoxManager::IsPointInsideRect(const sf::Vector2i & point,
	const sf::Vector2i & position,
	const sf::Vector2i & size) const
{
	if (point.x >= position.x && point.x <= position.x + size.x &&
		point.y >= position.y && point.y <= position.y + size.y)
	{
		return true;
	}

	return false;
}
