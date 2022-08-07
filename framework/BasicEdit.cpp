#include "pch.h"
#include "BasicEdit.h"

bool BasicEdit::containsCursor(const sf::Vector2i point_coordinates) const
{
	auto button_position = position();
	auto button_size = size();
	auto upper_border = button_position.y;
	auto bottom_border = button_position.y + button_size.y;
	auto left_border = button_position.x;
	auto right_border = button_position.x + button_size.x;
	return point_coordinates.x >= left_border && point_coordinates.x < right_border &&
		point_coordinates.y >= upper_border && point_coordinates.y < bottom_border;
}
