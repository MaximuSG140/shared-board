#include "pch.h"
#include "Widget/ElementList/FileExplorer/DirectoryElementFactory.h"

#include "Widget/ElementList/FileExplorer/DirectoryElement.h"
#include "Widget/ElementList/FileExplorer/IFileExplorerElement.h"
#include "Widget/ElementList/FileExplorer/RegularFileElement.h"


std::unique_ptr<IFileExplorerElement> DirectoryElementFactory::getElement(
	const std::filesystem::directory_entry& directory_element) const
{
	if(directory_element.is_regular_file())
	{
		return std::make_unique<RegularFileElement>(directory_element.path().filename().string(),
			directory_element.file_size());
	}
	return std::make_unique<DirectoryElement>(directory_element.path().filename().string());
}
