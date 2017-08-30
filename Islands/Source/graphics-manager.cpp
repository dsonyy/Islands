#include <vector>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "graphics-manager.h"
#include "window-manager.h"
#include "buffer.h"


GraphicsManager::GraphicsManager(WindowManager * window)
	: window_(window)
{
}

GraphicsManager::~GraphicsManager()
{
}

Layer & GraphicsManager::PushLayer()
{
	layers_.push_back(Layer());
	return layers_.back();
}

Layer & GraphicsManager::PushLayer(const Layer & layer)
{
	layers_.push_back(layer);
	return layers_.back();
}

void GraphicsManager::PopLayer()
{
	layers_.pop_back();

}

void GraphicsManager::Draw(const sf::Drawable & drawable, sf::RenderStates states)
{
	window_->draw(drawable, states);
}

void GraphicsManager::Draw(const Layer & layer,
	sf::RenderStates states)
{
	for each (auto & drawable in layer)
	{
		window_->draw(*drawable, states);
	}
}

void GraphicsManager::Draw(sf::RenderStates states)
{
	for each (auto & layer in layers_)
	{
		for each (auto & drawable in layer)
		{
			window_->draw(*drawable, states);
		}
	}

}

void GraphicsManager::Render()
{
	window_->display();
}
