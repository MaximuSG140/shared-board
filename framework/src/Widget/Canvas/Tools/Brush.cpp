#include "pch.h"
#include "framework/include/Widget/Canvas/Tools/Brush.h"

#include "framework/include/Widget/Canvas/Canvas.h"

Brush::Brush(Canvas& owner,
             const int thickness,
             const sf::Color& color)
	: owner_(owner),
	color_(color),
	thickness_(thickness)
{}

void Brush::hold(const sf::Vector2i position)
{
	auto& redactor = owner_.redactor();

	if (!first_point_)
	{
		redactor.drawSegment(previous_point_,
			position,
			&ImageRedactor::drawSmoothPoint,
			thickness_,
			color_);
	}
	redactor.drawSmoothPoint(position,
	                         thickness_,
	                         color_);
	previous_point_ = position;
	first_point_ = false;
}

void Brush::unHold()
{
	first_point_ = true;
}

void Brush::click(
	sf::Vector2i position) {}
