#include "pch.h"
#include "Button.h"

Button::Button(const std::string& name,
               const sf::Vector2i position,
               const sf::Vector2u size)
	: RectangleWidget("Button" + name,
		position,
		size)
{}

bool Button::containsCursor(const sf::Vector2i cursor_point) const
{
	return RectangleWidget::containsCursor(cursor_point);
}
