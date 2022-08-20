#pragma once
#include "pch.h"

class IFileExplorerElement
	: public sf::Drawable
{
public:
	IFileExplorerElement() = default;
	[[nodiscard]] sf::Vector2i position()const;
	[[nodiscard]] sf::Vector2u size()const;

	virtual std::string fileName()const = 0;

	void setPosition(sf::Vector2i position);
	void setSize(sf::Vector2u size);
private:
	sf::Vector2i position_ = {0, 0};
	sf::Vector2u size_ = {0, 0};
};

