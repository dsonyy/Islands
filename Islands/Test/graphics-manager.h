#pragma once

#include <vector>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "window-manager.h"
#include "buffer.h"

typedef std::vector<sf::Drawable *> Layer;

class GraphicsManager
{
public:

	enum class Position { TOP, BOTTOM };

	GraphicsManager(WindowManager * window);
	~GraphicsManager();

	Layer & Front() { return layers_.front(); }
	Layer & Back() { return layers_.back(); }

	Layer & PushLayer();
	Layer & PushLayer(const Layer & layer);
	void PopLayer();

	void Draw(const sf::Drawable & drawable,
		sf::RenderStates states = sf::RenderStates::Default);
	void Draw(const Layer & layer,
		sf::RenderStates states = sf::RenderStates::Default);
	void Draw(sf::RenderStates states = sf::RenderStates::Default);

	void Render();

private:
	WindowManager * window_;
	std::vector<Layer> layers_;
};
