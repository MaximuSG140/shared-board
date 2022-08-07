#include "pch.h"
#include "IMouseClickable.h"

void IMouseClickable::startClick(const sf::Vector2i mouse_position)
{
	click_started_ = containsCursor(mouse_position);
}

void IMouseClickable::endClick(const sf::Vector2i mouse_position)
{
	if(containsCursor(mouse_position) && click_started_)
	{
		click_started_ = false;
		onClick();
	}
	click_started_ = false;
}
