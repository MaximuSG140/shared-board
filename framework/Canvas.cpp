#include "pch.h"
#include "Canvas.h"

#include "Brush.h"
#include "CameraMoveTool.h"
#include "Pencil.h"
#include "logger/log.h"

namespace fs = std::filesystem;

Canvas::Canvas(const std::string& name,
               const sf::Vector2i position,
               const sf::Vector2u size)
	: RectangleWidget(name,
		position,
		size),
	redactor_(static_cast<int>(size.x),
	          static_cast<int>(size.y)),
	camera_position_(position)
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
	tool_ = std::make_unique<Pencil>(*this,
		thickness,
		color);
}

void Canvas::selectBrush(const int thickness,
                         const sf::Color& color)
{
	tool_ = std::make_unique<Brush>(*this,
		thickness,
		color);
}

void Canvas::selectViewer()
{
	tool_ = std::make_unique<CameraMoveTool>(*this);
}

void Canvas::doubleScale()
{
	scale_modifier_ *= 2;
}

void Canvas::lowerScale()
{
	scale_modifier_ /= 2;
}

void Canvas::moveView(const sf::Vector2i delta)
{
	auto body_size = size();
	auto image_size = redactor_.image().getSize();
	camera_position_ += delta;
	camera_position_.x = std::min(camera_position_.x,
		static_cast<int>(image_size.x - body_size.x / scale_modifier_));
	camera_position_.y = std::min(camera_position_.y,
		static_cast<int>(image_size.y - body_size.y / scale_modifier_));
	camera_position_.x = std::max(0,
		camera_position_.x);
	camera_position_.y = std::max(0,
		camera_position_.y);
}

void Canvas::draw(sf::RenderTarget& target,
                  sf::RenderStates states) const
{
	auto canvas_size = size();
	auto canvas_position = position();
	sf::RectangleShape body({ static_cast<float>(canvas_size.x),
		static_cast<float>(canvas_size.y)});
	body.setOutlineThickness(OUTLINE_THICKNESS);
	body.setOutlineColor(sf::Color::Black);
	body.setFillColor(sf::Color::White);
	body.setPosition({ static_cast<float>(canvas_position.x),
		static_cast<float>(canvas_position.y)});
	sf::Texture texture;
	if(!texture.loadFromImage(redactor_.image(),
			sf::IntRect{ camera_position_.x,
				camera_position_.y,
				static_cast<int>(canvas_size.x / scale_modifier_),
				static_cast<int>(canvas_size.y / scale_modifier_) }))
	{
		Logger::log(Logger::LogLevel::FATAL,
			"Error loading drawn image for rendering");
		std::abort();
	}
	
	sf::Sprite sprite(texture);
	sprite.scale(scale_modifier_,
		scale_modifier_);
	sprite.setPosition( static_cast<float>(canvas_position.x),
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
		tool_->click(relative_position);
	}
}

void Canvas::onHold(const sf::Vector2i mouse_position)
{
	if(tool_)
	{
		auto relative_position = mouse_position - position();
		tool_->hold(relative_position);
	}
}

void Canvas::onHoldEnded()
{
	if(tool_)
	{
		tool_->unHold();
	}
}

bool Canvas::containsCursor(const sf::Vector2i cursor_point) const
{
	return RectangleWidget::containsCursor(cursor_point);
}

void Canvas::loadImage(const fs::path& path_to_image) const
{
	redactor_.loadImage(path_to_image.string());
}

void Canvas::saveImage(const fs::path& path_to_image)
{
	auto image = redactor_.acquireImage();

	if(!image->saveToFile(path_to_image.string()))
	{
		Logger::log(Logger::LogLevel::ERROR,
			"Unable to save image as " + path_to_image.string());
	}

	redactor_.loadImage(std::move(image));
}

ImageRedactor& Canvas::redactor()
{
	return redactor_;
}

const ImageRedactor& Canvas::redactor() const
{
	return redactor_;
}
