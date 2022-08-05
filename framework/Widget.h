#pragma once
#include "pch.h"


class Widget : public sf::Drawable
{
public:
	explicit Widget(std::string name,
		sf::Vector2i position,
		sf::Vector2u size);
	explicit Widget(sf::Vector2i position,
		sf::Vector2u size);

	std::string name()const;
	sf::Vector2i position()const;
	sf::Vector2u size()const;

	void setPosition(sf::Vector2i position);
	void setSize(sf::Vector2u size);

	void scale(sf::Vector2f scale_proportions);

	virtual bool containsPoint(sf::Vector2f point_coordinates)const = 0;
private:
	const std::string name_;
	sf::Vector2i position_;
	sf::Vector2u size_;
};
