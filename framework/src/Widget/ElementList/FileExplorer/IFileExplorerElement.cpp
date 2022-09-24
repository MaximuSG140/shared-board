#include "pch.h"
#include "framework/include/Widget/ElementList/FileExplorer/IFileExplorerElement.h"

sf::Vector2i IFileExplorerElement::position() const
{
	return position_;
}

sf::Vector2u IFileExplorerElement::size() const
{
	return size_;
}

void IFileExplorerElement::choose()
{
	chosen_ = true;
}

void IFileExplorerElement::unChoose()
{
	chosen_ = false;
}

bool IFileExplorerElement::chosen() const
{
	return chosen_;
}

void IFileExplorerElement::setPosition(const sf::Vector2i position)
{
	position_ = position;
}

void IFileExplorerElement::setSize(const sf::Vector2u size)
{
	size_ = size;
}
