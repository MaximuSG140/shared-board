#include "pch.h"
#include "Canvas.h"

#include "Brush.h"
#include "Pencil.h"
#include "logger/log.h"

Canvas::Canvas(const std::string& name,
               const sf::Vector2i position,
               const sf::Vector2u size)
	: RectangleWidget(name,
		position,
		size),
	redactor_(size.x,
		size.y)
{}

Canvas::Canvas(const sf::Vector2i position,
               const sf::Vector2u size)
	: RectangleWidget("Unnamed canvas",
		position,
		size),
	redactor_(static_cast<int>(size.x),
		static_cast<int>(size.y))
{}

void Canvas::selectPencil(const int thickness,
                          const sf::Color& color)
{
	tool_ = std::make_unique<Pencil>(thickness,
		color);
}

void Canvas::selectBrush(const int thickness,
                         const sf::Color& color)
{
	tool_ = std::make_unique<Brush>(thickness,
		color);
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
	Widget::draw(target,
		states);
}

void Canvas::onClick(const sf::Vector2i mouse_position)
{
	if(tool_)
	{
		auto relative_position = mouse_position - position();
		tool_->click(redactor_,
			relative_position);
	}
}

void Canvas::onHold(const sf::Vector2i mouse_position)
{
	if(tool_)
	{
		auto relative_position = mouse_position - position();
		tool_->hold(redactor_,
			relative_position);
	}
}

void Canvas::onHoldEnded()
{
	if(tool_)
	{
		tool_->unHold(redactor_);
	}
}

bool Canvas::containsCursor(const sf::Vector2i cursor_point) const
{
	return RectangleWidget::containsCursor(cursor_point);
}

void Canvas::loadImage(const std::filesystem::path& path_to_image) const
{
	redactor_.loadImage(path_to_image.string());
}

void Canvas::saveImage(const std::filesystem::path& path_to_image)
{
	auto image = redactor_.acquireImage();

	if(!image->saveToFile(path_to_image.string()))
	{
		Logger::log(Logger::LogLevel::ERROR,
			"Unable to save image as " + path_to_image.string());
	}

	redactor_.loadImage(std::move(image));
}
