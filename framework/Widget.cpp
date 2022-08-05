#include "pch.h"
#include "Widget.h"

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
}

void Widget::setSize(const sf::Vector2u size)
{
	size_ = size;
}

void Widget::scale(const sf::Vector2f scale_proportions)
{
	position_.x = static_cast<int>(position_.x * scale_proportions.x);
	position_.y = static_cast<int>(position_.y * scale_proportions.y);
	size_.x = static_cast<unsigned>(size_.x * scale_proportions.x);
	size_.y = static_cast<unsigned>(size_.y * scale_proportions.y);
}
