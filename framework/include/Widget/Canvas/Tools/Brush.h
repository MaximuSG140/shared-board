#pragma once
#include "framework/include/Widget/Canvas/Tools/ICanvasTool.h"


class Canvas;

class Brush final :
    public ICanvasTool
{
public:
	explicit Brush(Canvas& owner,
		int thickness,
		const sf::Color& color);

	void hold(sf::Vector2i position) override;
	void unHold() override;
	void click(sf::Vector2i position) override;
private:
	Canvas& owner_;
	bool first_point_ = true;
	sf::Vector2i previous_point_;
	sf::Color color_ = sf::Color::Black;
	int thickness_ = 1;
};

