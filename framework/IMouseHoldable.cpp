#include "pch.h"
#include "IMouseHoldable.h"

void IMouseHoldable::proceedHolding(const sf::Vector2i mouse_position)
{
	if (containsCursor(mouse_position))
	{
		onHold();
	}
	else
	{
		onHoldEnded();
	}
}
