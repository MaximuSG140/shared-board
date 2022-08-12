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
