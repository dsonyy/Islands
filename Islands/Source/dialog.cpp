#include <vector>
#include <string>

#include <SFML\Graphics.hpp>

#include "dialog.h"


Dialog::Dialog()
{
	dialog_border_.setSize(sf::Vector2f(100, 150));
	dialog_border_.setFillColor(sf::Color::White);

	dialog_background_.setSize(sf::Vector2f(98, 148));
	dialog_background_.setOrigin(sf::Vector2f(-1, -1));
	dialog_background_.setFillColor(sf::Color::Blue);


	button_border_;
	button_background_;
}


void Dialog::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(dialog_border_, states);
	target.draw(dialog_background_, states);

}

void Dialog::AddButton(const std::string & title)
{
	column_.push_back({ Element::BUTTON, title });
}

void Dialog::AddButton(const std::string & title, int position)
{
	column_.insert(column_.begin() + position, { Element::BUTTON, title });
}
	
void Dialog::AddHeader(const std::string & header)
{
	column_.push_back({ Element::HEADER, header });
}

void Dialog::AddHeader(const std::string & header, int position)
{
	column_.insert(column_.begin() + position, { Element::HEADER, header });
}

void Dialog::AddText(const std::string & text)
{
	column_.push_back({ Element::TEXT, text });
}

void Dialog::AddText(const std::string & text, int position)
{
	column_.insert(column_.begin() + position, { Element::TEXT, text });
}
