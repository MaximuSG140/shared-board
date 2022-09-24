#pragma once
#include "framework/include/pch.h"


class Widget : public sf::Drawable
{
public:
	explicit Widget(std::string name,
		sf::Vector2i position,
		sf::Vector2u size);
	explicit Widget(sf::Vector2i position,
		sf::Vector2u size);

	[[nodiscard]] std::string name()const;
	[[nodiscard]] sf::Vector2i position()const;
	[[nodiscard]] sf::Vector2u size()const;

	void setPosition(sf::Vector2i position);
	void setSize(sf::Vector2u size);

	void scale(sf::Vector2f scale_proportions);

	void invalidate() const;
	[[nodiscard]] bool valid()const;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	const std::string name_;
	sf::Vector2i position_;
	sf::Vector2u size_;
	mutable bool valid_ = false;
};
