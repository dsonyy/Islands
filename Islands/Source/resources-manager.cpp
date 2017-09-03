#include <string>
#include <map>

#include <SFML\Graphics.hpp>

#include "resources-manager.h"


bool ResourcesManager::ImportFont(const std::string & filename, const std::string & new_name)
{
	sf::Font font;
	if (!font.loadFromFile(filename))
	{
		return false;
	}

	auto ret = fonts_.insert(std::pair<std::string, sf::Font>(new_name, font));
	if (ret.second == false)
	{
		return false;
	}

	return true;
}

bool ResourcesManager::ImportTexture(const std::string & filename, const std::string & new_name)
{
	sf::Texture tex;
	if (!tex.loadFromFile(filename))
	{
		return false;
	}

	auto ret = textures_.insert(std::pair<std::string, sf::Texture>(new_name, tex));
	if (ret.second == false)
	{
		return false;
	}

	return true;
}

sf::Font & ResourcesManager::GetFont(const std::string & name)
{
	return fonts_[name];
}

sf::Texture & ResourcesManager::GetTexture(const std::string & name)
{
	return textures_[name];
}

void ResourcesManager::RemoveFont(const std::string & name)
{
	fonts_.erase(name);
}

void ResourcesManager::RemoveTexture(const std::string & name)
{
	textures_.erase(name);
}
