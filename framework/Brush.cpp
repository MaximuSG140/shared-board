#include "pch.h"
#include "Brush.h"

Brush::Brush(const int thickness,
             const sf::Color& color)
	: color_(color),
	thickness_(thickness)
{}

void Brush::hold(ImageRedactor& redactor,
                 const sf::Vector2i position)
{
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

void Brush::unHold(ImageRedactor& redactor)
{
	first_point_ = true;
}

void Brush::click(ImageRedactor& redactor,
                  sf::Vector2i position) {}
