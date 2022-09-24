#include "pch.h"
#include "Widget/Traits/IMouseSelectable.h"

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
