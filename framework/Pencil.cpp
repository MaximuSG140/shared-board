#include "pch.h"
#include "Pencil.h"

Pencil::Pencil(const int thickness,
               const sf::Color& color)
	: color_(color),
	  thickness_(thickness)
{}

void Pencil::hold(ImageRedactor& redactor,
                  const sf::Vector2i position)
{
	if (!first_point_)
	{
		redactor.drawSegment(previous_point_,
			position,
			&ImageRedactor::drawPoint,
			thickness_,
			color_);
	}
	redactor.drawPoint(position,
	                   thickness_,
	                   color_);
	previous_point_ = position;
	first_point_ = false;
}

void Pencil::unHold(ImageRedactor& redactor)
{
	first_point_ = true;
}

void Pencil::click(ImageRedactor& redactor,
                   sf::Vector2i position)
{}
