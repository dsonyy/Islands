#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

typedef sf::Rect<sf::Vector2f> ClickBox;

class ClickBoxManager
{
public:


	ClickBoxManager() {}
	~ClickBoxManager() {}

	std::vector<ClickBox> Hover(const sf::Vector2i & pos);
	std::vector<ClickBox> Click(const sf::Vector2i & pos);
	std::vector<ClickBox> Release(const sf::Vector2i & pos);
	
	std::vector<ClickBox> Hover(size_t pos_x, size_t pos_y);
	std::vector<ClickBox> Click(size_t pos_x, size_t pos_y);
	std::vector<ClickBox> Release(size_t pos_x, size_t pos_y);

private:
	bool IsPointInsideRect(size_t px, size_t py, 
		size_t x0, size_t y0, size_t x1, size_t y1) const;

	std::vector<ClickBox> click_boxes_;
};