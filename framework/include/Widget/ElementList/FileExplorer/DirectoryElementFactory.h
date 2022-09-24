#pragma once
#include "framework/include/Widget/ElementList/FileExplorer/IFileExplorerElement.h"

class DirectoryElementFactory
{
public:
	[[nodiscard]] std::unique_ptr<IFileExplorerElement> getElement(
		const std::filesystem::directory_entry& directory_element)const;
};

