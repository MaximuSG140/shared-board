#include "pch.h"
#include "Canvas.h"

Canvas::Canvas(const std::string& name,
               const sf::Vector2i position,
               const sf::Vector2u size)
	: Widget(name,
		position,
		size)
{}

Canvas::Canvas(const sf::Vector2i position,
               const sf::Vector2u size)
	: Widget("Unnamed canvas",
		position,
		size)
{}
