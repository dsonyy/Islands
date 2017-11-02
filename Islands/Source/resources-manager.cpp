#include <string>
#include <map>

#include <SFML\Graphics.hpp>

#include "resources-manager.h"

ResourcesManager::ResourcesManager()
{

}

ResourcesManager::~ResourcesManager()
{
	fonts_.clear();
	textures_.clear();
}

bool ResourcesManager::ImportFont(const std::string & filename)
{
	sf::Font font;
	if (!font.loadFromFile(filename))
	{
		return false;
	}

	fonts_[filename] = font;

	return true;
}

bool ResourcesManager::ImportTexture(const std::string & filename)
{
	sf::Texture tex;
	if (!tex.loadFromFile(filename))
	{
		return false;
	}
	
	textures_[filename] = tex;

	return true;
}

sf::Font & ResourcesManager::GetFont(const std::string & filename)
{
	return fonts_[filename];
}

sf::Texture & ResourcesManager::GetTexture(const std::string & filename)
{
	return textures_[filename];
}

void ResourcesManager::RemoveFont(const std::string & filename)
{
	fonts_.erase(filename);
}

void ResourcesManager::RemoveTexture(const std::string & filename)
{
	textures_.erase(filename);
}