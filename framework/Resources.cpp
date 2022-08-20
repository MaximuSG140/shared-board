#include "pch.h"

#include "DirectoryElement.h"
#include "RegularFileElement.h"
#include "FontOwner.h"
#include "Resources.h"
#include "TextureOwner.h"

const sf::Texture& GetDirectoryIcon()
{
    const static TextureOwner icon_holder(DirectoryElement::ICON_IMAGE_PATH);
    return icon_holder.get();
}

const sf::Texture& GetRegularFileIcon()
{
    const static TextureOwner texture_holder(RegularFileElement::ICON_IMAGE_PATH);
    return texture_holder.get();
}

const sf::Font& GetDefaultFont()
{
    const static FontOwner font_holder(DEFAULT_FONT_PATH);
    return font_holder.get();
}


