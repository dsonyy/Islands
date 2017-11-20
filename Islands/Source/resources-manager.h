#pragma once

#include <string>
#include <map>

#include "SFML\Graphics.hpp"

class ResourcesManager
{
public:
	ResourcesManager();
	~ResourcesManager();

	// importing content form file
	bool ImportFont(const std::string & filename);
	bool ImportTexture(const std::string & filename);

	// clearing data form resource manager
	void Clear();
	void ClearFont(const std::string & filename);
	void ClearTexture(const std::string & filename);

	// returning loaded resources
	sf::Font & GetFont(const std::string & filename);
	sf::Texture & GetTexture(const std::string & filename);

private:
	std::map<std::string /*filename*/, sf::Font /*data*/> fonts_;
	std::map<std::string /*filename*/, sf::Texture /*data*/> textures_;


};