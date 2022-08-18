#pragma once
#include "IFileExplorerElement.h"

class RegularFileElement final
	: public IFileExplorerElement
{
public:
	inline const static std::string ICON_IMAGE_PATH = "regular-icon.png";

	explicit RegularFileElement(std::string file_name,
		int file_size);
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	std::string file_name_;
	int file_size_;
};

