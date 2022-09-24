#pragma once
#include "framework/include/Widget/Traits/IMouseClickable.h"
#include "framework/include/Widget/Traits/RectangleWidget.h"

class Button :
    public RectangleWidget, public IMouseClickable
{
public:
	explicit Button(const std::string& name,
		sf::Vector2i position,
		sf::Vector2u size);
	[[nodiscard]] bool containsCursor(sf::Vector2i cursor_point) const override;
};

