#pragma once
#include "Widget/Traits/RectangleWidget.h"

class TextBox final :
    public RectangleWidget
{
public:
	explicit TextBox(const std::string& name,
		sf::Vector2i position,
		sf::Vector2u size,
		std::string text);

	void draw(sf::RenderTarget& target,
		sf::RenderStates states) const override;
	[[nodiscard]] bool containsCursor(sf::Vector2i cursor_point) const override;
private:
	std::string text_;

};

