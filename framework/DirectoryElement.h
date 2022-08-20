#pragma once
#include "IFileExplorerElement.h"

class DirectoryElement final :
    public IFileExplorerElement
{
public:
	inline const static std::string ICON_IMAGE_PATH = "directory-icon.png";

	explicit DirectoryElement(std::string directory_name);

	std::string fileName() const override;
protected:
    void draw(sf::RenderTarget& target,
        sf::RenderStates states) const override;
private:
    std::string directory_name_;
};

