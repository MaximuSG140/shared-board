#pragma once
#include "IMouseClickable.h"
#include "RectangleWidget.h"
#include "logger/log.h"

template<typename FunctorT>
class SimpleButton final :
    public RectangleWidget, IMouseClickable
{
public:
	explicit SimpleButton(std::string text,
		sf::Vector2i position,
		sf::Vector2u size,
		FunctorT&& on_click_action);

	constexpr static sf::Color BODY_COLOR{ 230, 230, 230 };
	constexpr static sf::Color OUTLINE_COLOR{ 220, 220, 220 };
	constexpr static sf::Color TEXT_COLOR = sf::Color::Black;

	constexpr static int OUTLINE_THICKNESS = 3;
protected:
	void onClick(sf::Vector2i position) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	[[nodiscard]] sf::Vector2i calculateTextPosition(const sf::Text& text_to_pose)const;
	[[nodiscard]] unsigned calculateLetterSize() const;

	std::string text_;
	FunctorT on_click_action_;
};

template <typename FunctorType>
SimpleButton<FunctorType>::SimpleButton(std::string text,
                            const sf::Vector2i position,
                            const sf::Vector2u size,
                            FunctorType&& on_click_action)
	: RectangleWidget("Button " + text,
	                  position,
	                  size),
	text_(std::move(text)),
	on_click_action_(std::forward<FunctorType>(on_click_action))
{}

template <typename FunctorType>
void SimpleButton<FunctorType>::onClick(sf::Vector2i position)
{
	Logger::log(Logger::LogLevel::INFO, "Activating" + name());
	on_click_action_();
}

template <typename FunctorType>
void SimpleButton<FunctorType>::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	auto button_size = size();
	sf::RectangleShape body({static_cast<float>(button_size.x),
		static_cast<float>(button_size.y)});
	body.setFillColor(BODY_COLOR);
	body.setOutlineThickness(OUTLINE_THICKNESS);
	body.setOutlineColor(OUTLINE_COLOR);
	body.setPosition({static_cast<float>(button_size.x),
		static_cast<float>(button_size.y)});
	target.draw(body, states);
	sf::Text printable_text(text_, sf::Font(), calculateLetterSize());
	printable_text.setPosition(calculateTextPosition(printable_text));
	printable_text.setFillColor(TEXT_COLOR);
	target.draw(printable_text);
}

template <typename FunctorType>
sf::Vector2i SimpleButton<FunctorType>::calculateTextPosition(const sf::Text& text_to_pose) const
{
	auto text_bounds = text_to_pose.getLocalBounds();
	auto button_size = size();
	auto button_position = position();
	return { static_cast<int>(button_position.x + button_size.x / 2),
		static_cast<int>(button_position.y + button_size.y / 2) };
}

template <typename FunctorType>
unsigned SimpleButton<FunctorType>::calculateLetterSize() const
{
	unsigned letter_size_left = 1;
	auto button_size = size();
	unsigned letter_size_right = std::min(button_size.x / 2, button_size.y / 2);
	while(letter_size_right - letter_size_left > 1)
	{
		auto new_bound = (letter_size_right + letter_size_left) / 2;
		sf::Text test_text(text_, sf::Font(), new_bound);
		if(auto text_bounds = test_text.getLocalBounds();
			text_bounds.width > button_size.x / 2 || 
			text_bounds.height > button_size.y / 2)
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

