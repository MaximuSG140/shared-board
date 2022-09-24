#include "pch.h"
#include "Widget/Traits/RectangleWidget.h"

RectangleWidget::RectangleWidget(const std::string& name,
                                 const sf::Vector2i position,
                                 const sf::Vector2u size)
		:Widget(name,
			position,
			size)
{}

bool RectangleWidget::containsCursor(const sf::Vector2i cursor_point) const
{
	auto widget_position = position();
	auto widget_size = size();
	auto upper_border = widget_position.y;
	auto bottom_border = widget_position.y + widget_size.y;
	auto left_border = widget_position.x;
	auto right_border = widget_position.x + widget_size.x;
	return cursor_point.x >= left_border && cursor_point.x < right_border&&
		cursor_point.y >= upper_border && cursor_point.y < bottom_border;
}
