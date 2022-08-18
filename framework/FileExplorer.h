#pragma once
#include "IFileExplorerElement.h"
#include "RectangleWidget.h"
#include "IMouseClickable.h"
class FileExplorer :
    public RectangleWidget, public IMouseClickable
{
public:
	explicit FileExplorer
private:
    std::vector<std::unique_ptr<IFileExplorerElement>> list_elements_;
};

