#include "pch.h"
#include "framework/include/Widget/ElementList/FileExplorer/DirectoryElement.h"

#include "framework/include/Resource/Resources.h"


DirectoryElement::DirectoryElement(std::string directory_name)
		: directory_name_(std::move(directory_name))
{}

std::string DirectoryElement::fileName() const
{
    return directory_name_;
}

void DirectoryElement::draw(sf::RenderTarget& target,
                            const sf::RenderStates states) const
{
    sf::Sprite icon_sprite(GetDirectoryIcon());
    float scale_proportion = static_cast<float>(size().y) / icon_sprite.getLocalBounds().height;
    icon_sprite.scale(scale_proportion,
        scale_proportion);
    icon_sprite.setPosition({ static_cast<float>(position().x),
		static_cast<float>(position().y)});
    target.draw(icon_sprite,
        states);
	sf::Text directory_name = generateTruncatedText(directory_name_,
		GetDefaultFont(),
		size().y / 2,
		size().x - static_cast<unsigned>(icon_sprite.getGlobalBounds().width));
    directory_name.setFillColor(sf::Color::Black);
    directory_name.setPosition(static_cast<float>(position().x) + icon_sprite.getGlobalBounds().width,
        static_cast<float>(position().y));
    target.draw(directory_name,
        states);
}

sf::Text DirectoryElement::generateTruncatedText(const std::string& text,
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
