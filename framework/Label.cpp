#include "pch.h"
#include "Label.h"

#include "Resources.h"

Label::Label(const std::string& name,
             const sf::Vector2i position,
             const sf::Vector2u size,
             std::string text)
	: RectangleWidget(name,
		position,
		size),
	text_(std::move(text))
{}

void Label::draw(sf::RenderTarget& target,
                 const sf::RenderStates states) const
{
	sf::Text text(text_,
		GetDefaultFont(),
		calculateLetterSize());
	text.setFillColor(sf::Color::Black);
	text.setPosition(static_cast<sf::Vector2f>(position()));
	target.draw(text,
		states);
	RectangleWidget::draw(target,
		states);
}


unsigned Label::calculateLetterSize() const
{
	unsigned letter_size_left = 1;
	auto label_size = size();
	unsigned letter_size_right = std::min(label_size.x, label_size.y / 2);
	while (letter_size_right - letter_size_left > 1)
	{
		auto new_bound = (letter_size_right + letter_size_left) / 2;
		sf::Text test_text(text_,
			GetDefaultFont(),
			new_bound);
		if (auto text_bounds = test_text.getLocalBounds();
			text_bounds.width > static_cast<float>(label_size.x) ||
			text_bounds.height > static_cast<float>(label_size.y) / 2)
		{
			letter_size_right = new_bound;
		}
		else
		{
			letter_size_left = new_bound;
		}
	}
	return letter_size_left;
}

