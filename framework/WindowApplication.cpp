#include "pch.h"
#include "WindowApplication.h"

#include "logger/log.h"

void WindowApplication::run()
{
	Logger::log(Logger::LogLevel::INFO, "Window application started");
	sf::Event received_event{};
	while (main_window_.pollEvent(received_event))
	{
		Logger::log(Logger::LogLevel::DEBUG, "Event dispatched");
		handle(received_event);
		Logger::log(Logger::LogLevel::DEBUG, "Polling next event");
	}
	Logger::log(Logger::LogLevel::INFO, "Application exited");
}

void WindowApplication::setWindowSize(const sf::Vector2u size)
{
	main_window_.setSize(size);
}

sf::Vector2u WindowApplication::windowSize() const
{
	return main_window_.getSize();
}

void WindowApplication::render()
{
	for(const auto& widget : widgets_)
	{
		main_window_.draw(*widget);
	}
}
