#include "pch.h"
#include "DirectoryElement.h"

#include "Resources.h"


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
    float scale_proportion = size().y / icon_sprite.getLocalBounds().height;
    icon_sprite.scale(scale_proportion,
        scale_proportion);
    icon_sprite.setPosition({ static_cast<float>(position().x),
		static_cast<float>(position().y)});
    target.draw(icon_sprite,
        states);
    sf::Text directory_name(directory_name_,
        GetDefaultFont(),
        size().y);
    directory_name.setFillColor(sf::Color::Black);
    directory_name.setPosition(static_cast<float>(position().x) + icon_sprite.getGlobalBounds().width,
        static_cast<float>(position().y));
    target.draw(directory_name,
        states);
}
