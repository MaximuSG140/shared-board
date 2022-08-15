#include "pch.h"
#include "IMouseHoldable.h"

void IMouseHoldable::startHolding(const sf::Vector2i mouse_position)
{
	holding_ = true;
	if(containsCursor(mouse_position))
	{
		onHold(mouse_position);
	}
}

void IMouseHoldable::proceedHolding(const sf::Vector2i mouse_position)
{
	if (holding_ && containsCursor(mouse_position))
	{
		onHold(mouse_position);
	}
}

void IMouseHoldable::endHolding(const sf::Vector2i mouse_position)
{
	holding_ = false;
	if(containsCursor(mouse_position))
	{
		onHoldEnded();
	}
}
