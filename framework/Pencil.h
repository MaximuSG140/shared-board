#pragma once
#include "IDrawingTool.h"


class Pencil final:
    public IDrawingTool
{
public:
	Pencil() = default;
	explicit Pencil(int thickness,
		const sf::Color& color);

	void hold(ImageRedactor& redactor,
		sf::Vector2i position) override;
	void unHold(ImageRedactor& redactor) override;
	void click(ImageRedactor& redactor,
		sf::Vector2i position) override;
private:
	bool first_point_ = true;
	sf::Vector2i previous_point_;
	sf::Color color_ = sf::Color::Black;
	int thickness_ = 1;
};

