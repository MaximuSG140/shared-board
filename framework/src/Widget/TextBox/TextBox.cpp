#include "pch.h"
#include "Widget/TextBox/TextBox.h"

#include "Widget/Traits/RectangleWidget.h"

TextBox::TextBox(const std::string& name,
                 const sf::Vector2i position,
                 const sf::Vector2u size,
                 std::string text)
	: ::RectangleWidget("Text box " + name,
	                    position,
	                    size),
	  text_(std::move(text))
{}

bool TextBox::containsCursor(const sf::Vector2i cursor_point) const
{
	return RectangleWidget::containsCursor(cursor_point);
}
