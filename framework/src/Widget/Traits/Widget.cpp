#include "pch.h"
#include "framework/include/Widget.h"

#include "logger/log.h"

Widget::Widget(std::string name,
               const sf::Vector2i position,
               const sf::Vector2u size)
	: name_(std::move(name)),
	position_(position),
	size_(size)
{}

Widget::Widget(const sf::Vector2i position, const sf::Vector2u size)
	:Widget("Unnamed", position, size)
{}

std::string Widget::name() const
{
	return name_;
}

sf::Vector2i Widget::position() const
{
	return position_;
}

sf::Vector2u Widget::size() const
{
	return size_;
}

void Widget::setPosition(const sf::Vector2i position)
{
	position_ = position;
	Logger::log(Logger::LogLevel::DEBUG, "Widget " + name_ + " position changed to " +
		std::to_string(position_.x) + " " + std::to_string(position_.y));
}

void Widget::setSize(const sf::Vector2u size)
{
	Logger::log(Logger::LogLevel::DEBUG, "Widget " + name_ + " size changed to " +
		std::to_string(size_.x) + " " + std::to_string(size_.y));
	size_ = size;
}

void Widget::scale(const sf::Vector2f scale_proportions)
{
	position_.x = static_cast<int>(position_.x * scale_proportions.x);
	position_.y = static_cast<int>(position_.y * scale_proportions.y);
	size_.x = static_cast<unsigned>(size_.x * scale_proportions.x);
	size_.y = static_cast<unsigned>(size_.y * scale_proportions.y);
	Logger::log(Logger::LogLevel::DEBUG, "Widget " + name_ + " was scaled for " +
		std::to_string(scale_proportions.x) + " " + std::to_string(scale_proportions.y));
}

void Widget::invalidate() const
{
	valid_ = false;
}

bool Widget::valid() const
{
	return valid_;
}

void Widget::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	valid_ = true;
}
