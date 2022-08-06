#include "pch.h"
#include "HoldableWidget.h"

HoldableWidget::HoldableWidget(const std::string& widget_name,
                               const sf::Vector2i position,
                               const sf::Vector2u size)
	: Widget(widget_name,
		position,
		size)
{}

HoldableWidget::HoldableWidget(const sf::Vector2i position,
                               const sf::Vector2u size)
	: Widget("Unnamed holdable",
		position,
		size)
{}

void HoldableWidget::proceedHolding(sf::Vector2i mouse_position)
{
	if (containsPoint(mouse_position))
	{
		onHold();
	}
}
