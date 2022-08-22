#pragma once
#include "IFileExplorerElement.h"

class DirectoryElement final :
    public IFileExplorerElement
{
public:
	inline const static std::string ICON_IMAGE_PATH = "directory-icon.png";

	explicit DirectoryElement(std::string directory_name);

	[[nodiscard]] std::string fileName() const override;
protected:
    void draw(sf::RenderTarget& target,
        sf::RenderStates states) const override;
private:
	static sf::Text generateTruncatedText(const std::string& text,
		const sf::Font& font,
		unsigned character_size,
		unsigned desired_size);

    std::string directory_name_;
};

