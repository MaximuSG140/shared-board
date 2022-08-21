#include "pch.h"
#include "RegularFileElement.h"

#include "Resources.h"

RegularFileElement::RegularFileElement(std::string file_name,
                                       const long long file_size)
	: file_name_(std::move(file_name)),
	file_size_(file_size)
{}

std::string RegularFileElement::fileName() const
{
	return file_name_;
}

void RegularFileElement::draw(sf::RenderTarget& target,
                              sf::RenderStates states) const
{
	sf::Sprite icon_sprite(GetRegularFileIcon());
	float scale_proportion = size().y / icon_sprite.getLocalBounds().height;
	icon_sprite.scale(scale_proportion,
		scale_proportion);
	icon_sprite.setPosition({ static_cast<float>(position().x),
		static_cast<float>(position().y) });
	target.draw(icon_sprite,
		states);
	sf::Text file_name = generateTruncatedText(file_name_,
		GetDefaultFont(),
		size().y / 2,
		size().x - icon_sprite.getGlobalBounds().width);
	file_name.setPosition(static_cast<float>(position().x) + icon_sprite.getGlobalBounds().width,
		static_cast<float>(position().y));
	file_name.setFillColor(sf::Color::Black);
	target.draw(file_name,
		states);
}

sf::Text RegularFileElement::generateTruncatedText(const std::string& text,
	const sf::Font& font,
	const unsigned character_size,
	const unsigned desired_size)
{
	unsigned size_left = 0;
	unsigned size_right = text.length();
	while (size_right - size_left > 1)
	{
		unsigned size_current = (size_right + size_left) / 2;
		if (sf::Text printable_text(text.substr(0,
				size_current),
			font,
			character_size);
			printable_text.getLocalBounds().width < static_cast<float>(desired_size))
		{
			size_left = size_current;
		}
		else
		{
			size_right = size_current;
		}
	}
	return sf::Text(text.substr(0,
			size_right),
		font,
		character_size);
}
