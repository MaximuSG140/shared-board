#pragma once
#include "IFileExplorerElement.h"

class RegularFileElement final
	: public IFileExplorerElement
{
public:
	inline const static std::string ICON_IMAGE_PATH = "regular-icon.png";

	explicit RegularFileElement(std::string file_name,
		long long file_size);
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	static sf::Text generateTruncatedText(const std::string& text,
		const sf::Font& font,
		unsigned character_size,
		unsigned desired_size);

	std::string file_name_;
	long long file_size_;
};

