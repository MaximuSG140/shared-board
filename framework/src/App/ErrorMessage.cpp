#include "pch.h"
#include "App/ErrorMessage.h"

ErrorMessage::ErrorMessage(const std::string& name,
                           const std::string& message)
	: WindowApplication(sf::VideoMode(DEFAULT_WINDOW_WIDTH,
		DEFAULT_WINDOW_HEIGHT),
		name,
		sf::Style::Titlebar | sf::Style::Close)
{
	
}
