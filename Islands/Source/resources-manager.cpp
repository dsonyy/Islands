#include <string>
#include <map>

#include <SFML\Graphics.hpp>

#include "resources-manager.h"


bool ResourcesManager::ImportFont(const std::string & filename, const std::string & name)
{
	sf::Font font;
	if (!font.loadFromFile(filename))
	{
		return false;
	}

	fonts_[name] = font;

	return true;
}

bool ResourcesManager::ImportTexture(const std::string & filename, const std::string & name)
{
	sf::Texture tex;
	if (!tex.loadFromFile(filename))
	{
		return false;
	}
	
	textures_[name] = tex;

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

sf::Font & ResourcesManager::GetDefaultFont()
{
	if (fonts_.find(Default::Resources::FontRegular) == fonts_.end() &&
		!ImportFont("Resources/Fonts/Lato-Regular.ttf",
			Default::Resources::FontRegular))
	{
		return sf::Font();
	}
	
	return fonts_[Default::Resources::FontRegular];
}