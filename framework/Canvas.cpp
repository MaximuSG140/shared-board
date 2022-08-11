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
		size),
	redactor_(size.x,
		size.y)
{}

void Canvas::onClick(const sf::Vector2i mouse_position)
{
	click_action_(mouse_position);
}

void Canvas::onHold(const sf::Vector2i mouse_position)
{
	hold_action_(mouse_position);
}

void Canvas::onHoldEnded()
{
	hold_ended_action_();
}
