#include "pch.h"
#include "framework/include/Widget/Edit/BasicEdit.h"

#include "framework/include/Utility.h"
#include "framework/include/Resource/Resources.h"
#include "framework/include/Widget/Traits/RectangleWidget.h"

BasicEdit::BasicEdit(const std::string& name,
                     const sf::Vector2i position,
                     const sf::Vector2u size)
	: ::RectangleWidget("Edit " + name,
	                    position,
	                    size)
{}

BasicEdit::BasicEdit(const sf::Vector2i position,
                     const sf::Vector2u size)
		: RectangleWidget("Unnamed edit", 
			position,
			size)
{}

void BasicEdit::setText(std::string new_text)
{
	text_.swap(new_text);
}

std::string BasicEdit::text() const
{
	return text_;
}

void BasicEdit::handleKeyPress(const sf::Event::KeyEvent& event)
{
	if(!editing_)
	{
		return;
	}
	text_.push_back(GetCorrespondingCharacter(event));
}

bool BasicEdit::selected() const
{
	return editing_;
}

void BasicEdit::draw(sf::RenderTarget& target,
                     sf::RenderStates states) const
{
	auto edit_size = size();
	sf::RectangleShape body({static_cast<float>(edit_size.x),
		static_cast<float>(edit_size.y)});
	auto edit_position = position();
	body.setPosition({ static_cast<float>(edit_position.x),
		static_cast<float>(edit_position.y) });
	body.setFillColor(BODY_COLOR);
	sf::Text printable_text(text_,
		GetDefaultFont(),
		calculateLetterSize());
	auto text_position = calculateTextPosition();
	printable_text.setPosition({ static_cast<float>(text_position.x),
		static_cast<float>(text_position.y) });
	printable_text.setFillColor(TEXT_COLOR);
	if(editing_)
	{
		body.setOutlineColor(SELECTED_OUTLINE_COLOR);
	}
	else
	{
		body.setOutlineColor(OUTLINE_COLOR);
	}
	body.setOutlineThickness(OUTLINE_THICKNESS);
	target.draw(body);
	target.draw(printable_text);
}

void BasicEdit::onSelect()
{
	editing_ = true;
}

void BasicEdit::onUnSelect()
{
	editing_ = false;
}

unsigned BasicEdit::calculateLetterSize() const
{
	auto edit_size = size();
	unsigned left_bound = 1;
	unsigned right_bound = std::min(edit_size.x,
		edit_size.y / 2);
	while(right_bound - left_bound > 1)
	{
		auto new_bound = (left_bound + right_bound) / 2;
		sf::Text test_text(text_, 
			GetDefaultFont(),
			new_bound);
		if(auto text_bounds = test_text.getLocalBounds(); 
			text_bounds.width < static_cast<float>(edit_size.x) && 
			text_bounds.height < static_cast<float>(edit_size.y) / 2)
		{
			left_bound = new_bound;
		}
		else
		{
			right_bound = new_bound;
		}
	}
	return left_bound;
}

sf::Vector2i BasicEdit::calculateTextPosition() const
{
	auto edit_position = position();
	auto edit_size = size();
	sf::Text test_text(text_,
		GetDefaultFont(),
		calculateLetterSize());
	return { edit_position.x,
		static_cast<int>(static_cast<float>(edit_position.y) + 
			static_cast<float>(edit_size.y) / 2 - test_text.getLocalBounds().height / 2) };
}

bool BasicEdit::containsCursor(const sf::Vector2i cursor_point) const
{
	return RectangleWidget::containsCursor(cursor_point);
}
