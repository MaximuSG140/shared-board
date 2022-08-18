#include "pch.h"
#include "RegularFileElement.h"

RegularFileElement::RegularFileElement(std::string file_name)
	: file_name_(std::move(file_name))
{}

void RegularFileElement::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}
