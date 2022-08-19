#include "pch.h"
#include "FileExplorer.h"

FileExplorer::FileExplorer(const std::string& name,
                           const sf::Vector2i position,
                           const sf::Vector2u size,
                           std::filesystem::path start_directory)
		:RectangleWidget("Explorer " + name,
			position,
			size),
	current_directory_(std::move(start_directory))
{
	std::filesystem::directory_iterator iterator(current_directory_);
	for(const auto& entry : iterator)
	{
		auto element = FACTORY.getElement(entry);
	}
}
