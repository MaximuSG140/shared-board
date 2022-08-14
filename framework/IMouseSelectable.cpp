#include "pch.h"
#include "IMouseSelectable.h"


void IMouseSelectable::interact(const sf::Vector2i mouse_position)
{
	if(containsCursor(mouse_position))
	{
		onSelect();
	}
	else
	{
		onUnSelect();
	}
}
