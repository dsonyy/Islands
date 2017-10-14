#include <vector>
#include <string>

#include <SFML\Graphics.hpp>

#include "dialog.h"


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
