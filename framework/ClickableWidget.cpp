#include "pch.h"
#include "ClickableWidget.h"

ClickableWidget::ClickableWidget(const std::string& name,
                                 const sf::Vector2i position,
                                 const sf::Vector2u size)
	: Widget(name,
		position,
		size)
{}

ClickableWidget::ClickableWidget(const sf::Vector2i position,
                                 const sf::Vector2u size)
	:Widget("Unnamed clickable widget",
		position,
		size)
{}

void ClickableWidget::startClick(const sf::Vector2i mouse_position)
{
	click_started_ = containsPoint(mouse_position);
}

void ClickableWidget::endClick(const sf::Vector2i mouse_position)
{
	if(containsPoint(mouse_position) && click_started_)
	{
		click_started_ = false;
		onClick();
	}
	click_started_ = false;
}
