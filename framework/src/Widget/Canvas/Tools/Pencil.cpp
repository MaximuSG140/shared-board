#include "pch.h"
#include "framework/include/Widget/Canvas/Tools/Pencil.h"

#include "logger/log.h"
#include "framework/include/Widget/Canvas/Canvas.h"

Pencil::Pencil(Canvas& owner,
               const int thickness,
               const sf::Color& color)
	: owner_(owner),
	color_(color),
	thickness_(thickness)
{}

void Pencil::hold(const sf::Vector2i position)
{
	Logger::log(Logger::LogLevel::DEBUG,
		"Drawing using pencil of size " + std::to_string(thickness_));
	auto& redactor = owner_.redactor();
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

void Pencil::unHold()
{
	first_point_ = true;
}

void Pencil::click(
	sf::Vector2i position)
{}
