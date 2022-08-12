#include "pch.h"
#include "Canvas.h"

Canvas::Canvas(const std::string& name,
               const sf::Vector2i position,
               const sf::Vector2u size)
	: RectangleWidget(name,
		position,
		size)
{}

Canvas::Canvas(const sf::Vector2i position,
               const sf::Vector2u size)
	: RectangleWidget("Unnamed canvas",
		position,
		size),
	redactor_(size.x,
		size.y)
{}

void Canvas::selectPencil(const int thickness,
                       const sf::Color& color)
{
	unSelectAllTools();
	
}

void Canvas::selectBrush(int thickness, const sf::Color& color)
{
	unSelectAllTools();
	hold_action_ = [&,
		previous_x = 0,
		previous_y = 0,
		first = true]
		(const sf::Vector2i position)mutable
	{
		if (!first)
		{
			redactor_.drawSegment({ previous_x, previous_y },
				position,
				&ImageRedactor::drawPoint,
				thickness,
				color);
			first = false;
		}
		previous_x = position.x;
		previous_y = position.y;
	};
}

void Canvas::unSelectAllTools()
{
	click_action_ = [](sf::Vector2i) {};
	hold_action_ = [](sf::Vector2i) {};
	hold_ended_action_ = []() {};
}

void Canvas::draw(sf::RenderTarget& target,
                  sf::RenderStates states) const
{
	auto canvas_size = size();
	auto canvas_position = position();
	sf::RectangleShape body({static_cast<float>(canvas_size.x),
		static_cast<float>(canvas_size.y)});
	body.setOutlineThickness(3);
	body.setOutlineColor(sf::Color::Black);
	body.setFillColor(sf::Color::White);
	body.setPosition({static_cast<float>(canvas_position.x),
		static_cast<float>(canvas_position.y)});
	auto image = redactor_.getImageCopy();
	sf::Texture texture;
	texture.loadFromImage(image);
	sf::Sprite sprite(texture);
	sprite.setPosition(static_cast<float>(canvas_position.x),
		static_cast<float>(canvas_position.y));
	target.draw(body);
	target.draw(sprite);
}

void Canvas::onClick(const sf::Vector2i mouse_position)
{
	click_action_(mouse_position);
}

void Canvas::onHold(const sf::Vector2i mouse_position)
{
	hold_action_(mouse_position);
}

void Canvas::onHoldEnded()
{
	hold_ended_action_();
}
