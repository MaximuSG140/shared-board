#pragma once
#include "DirectoryElementFactory.h"
#include "IFileExplorerElement.h"
#include "RectangleWidget.h"
#include "IMouseClickable.h"


class FileExplorer :
    public RectangleWidget, public IMouseClickable
{
public:
    explicit FileExplorer(const std::string& name,
                          sf::Vector2i position,
                          sf::Vector2u size,
                          std::filesystem::path start_directory = std::filesystem::current_path());
private:
    std::filesystem::path current_directory_;
    inline constexpr static DirectoryElementFactory FACTORY{};
    std::vector<std::unique_ptr<IFileExplorerElement>> directory_elements_;
};

