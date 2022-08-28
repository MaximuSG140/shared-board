#pragma once
#include "RectangleWidget.h"

class Label final :
    public RectangleWidget
{
public:
	explicit Label(const std::string& name,
	               sf::Vector2i position,
	               sf::Vector2u size,
	               std::string text);

	void draw(sf::RenderTarget& target,
		sf::RenderStates states) const override;
private:
	unsigned calculateLetterSize()const;

	std::string text_;
};



