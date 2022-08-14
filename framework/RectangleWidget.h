#pragma once
#include "IMouseAccessible.h"
#include "Widget.h"

class RectangleWidget :
    public Widget, IMouseAccessible
{
public:
	explicit RectangleWidget(const std::string& name,
		sf::Vector2i position,
		sf::Vector2u size);
	[[nodiscard]] bool containsCursor(sf::Vector2i cursor_point) const override;
};

