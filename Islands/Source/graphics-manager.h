#pragma once

#include <vector>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "window.h"
#include "buffer.h"

typedef std::vector<sf::Drawable *> Layer;

class GraphicsManager
{
public:

	enum class Position { TOP, BOTTOM };

	GraphicsManager();
	~GraphicsManager();

	Layer & Front() { return layers_.front(); }
	Layer & Back() { return layers_.back(); }

	Layer & PushLayer();
	Layer & PushLayer(const Layer & layer);
	void PopLayer();

	void CreateWindow(size_t width = Window::Width,
		size_t height = Window::Height, 
		const std::string & title = Window::Title,
		size_t style = Window::Style);

	void Draw(const sf::Drawable & drawable,
		sf::RenderStates states = sf::RenderStates::Default);
	void Draw(const Layer & layer,
		sf::RenderStates states = sf::RenderStates::Default);
	void Draw(sf::RenderStates states = sf::RenderStates::Default);

	void Render();

private:
	std::vector<Layer> layers_;
	sf::RenderWindow window_;
};
