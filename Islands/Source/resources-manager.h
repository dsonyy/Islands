#pragma once

#include <string>
#include <map>

#include "SFML\Graphics.hpp"

class ResourcesManager
{
public:
	ResourcesManager();
	~ResourcesManager();

	bool ImportFont(const std::string & filename);
	bool ImportTexture(const std::string & filename);

	void RemoveFont(const std::string & filename);
	void RemoveTexture(const std::string & filename);

	sf::Font & GetFont(const std::string & filename);
	sf::Texture & GetTexture(const std::string & filename);

private:
	std::map<std::string /*filename*/, sf::Font /*data*/> fonts_;
	std::map<std::string /*filename*/, sf::Texture /*data*/> textures_;


};