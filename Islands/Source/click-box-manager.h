#pragma once

#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

struct ClickBox
{
	std::string id;
	sf::Vector2i position;
	sf::Vector2i size;
};

class ClickBoxManager
{
public:
	ClickBoxManager() {}
	~ClickBoxManager() {}

	void AddClickBox(const ClickBox & click_box);
	void RemoveClickBox(const std::string & id);

	bool Check(const sf::Vector2i & pos, const std::string & id) const;

	std::vector<ClickBox> CheckAll(const sf::Vector2i & pos) const;
	
private:
	bool IsPointInsideRect(const sf::Vector2i & point_to_check,
		const sf::Vector2i & position,
		const sf::Vector2i & size) const;

	std::vector<ClickBox> click_boxes_;
};