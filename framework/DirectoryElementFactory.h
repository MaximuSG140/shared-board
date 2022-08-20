#pragma once
#include "IFileExplorerElement.h"

class DirectoryElementFactory
{
public:
	[[nodiscard]] std::unique_ptr<IFileExplorerElement> getElement(
		const std::filesystem::directory_entry& directory_element)const;
};

