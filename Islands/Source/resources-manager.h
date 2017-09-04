#pragma once

#include <string>
#include <map>

#include "SFML\Graphics.hpp"


class ResourcesManager
{
public:
	ResourcesManager() {}
	~ResourcesManager() {}

	bool ImportFont(const std::string & filename, const std::string & name);
	bool ImportTexture(const std::string & filename, const std::string & name);

	void RemoveFont(const std::string & new_name);
	void RemoveTexture(const std::string & new_name);

	sf::Font & GetFont(const std::string & name);
	sf::Texture & GetTexture(const std::string & name);

	sf::Font & GetDefaultFont();

private:
	std::map<std::string, sf::Font> fonts_;
	std::map<std::string, sf::Texture> textures_;


};