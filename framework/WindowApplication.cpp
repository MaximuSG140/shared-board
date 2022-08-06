#include "pch.h"
#include "WindowApplication.h"

#include "logger/log.h"

void WindowApplication::run()
{
	Logger::log(Logger::LogLevel::INFO, "Window application started");
	sf::Event received_event{};
	while(main_window_.isOpen())
	{
		main_window_.waitEvent(received_event);
		Logger::log(Logger::LogLevel::DEBUG, "Event dispatched");
		baseHandle(received_event);
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
	Logger::log(Logger::LogLevel::INFO, "Redrawing client area");
	for(const auto& widget : widgets_)
	{
		main_window_.draw(*widget);
	}
}

void WindowApplication::baseHandle(const sf::Event& event)
{
	switch(event.type)
	{
	case sf::Event::Closed:
		Logger::log(Logger::LogLevel::DEBUG, "Handling 'Closed' event");
		main_window_.close();
		break;
	case sf::Event::Resized:
		Logger::log(Logger::LogLevel::DEBUG, "Handling 'Resized' event");
		main_window_.setSize({ event.size.width, event.size.height });
		break;
	case sf::Event::MouseButtonPressed:
		Logger::log(Logger::LogLevel::DEBUG, "Handling 'MouseButtonPressed' event");
		for(auto widget : clickable_widgets_)
		{
			widget->startClick({ event.mouseButton.x,
				event.mouseButton.y });
		}
		break;
	case sf::Event::MouseButtonReleased:
		Logger::log(Logger::LogLevel::DEBUG, "Handling 'MouseButtonReleased' event");
		for (auto widget : clickable_widgets_)
		{
			widget->endClick({ event.mouseButton.x,
				event.mouseButton.y });
		}
		break;
	case sf::Event::MouseMoved:
		Logger::log(Logger::LogLevel::DEBUG, "Handling 'MouseMoved' event");
		break;
	default:;
	}
	handle(event);
	render();
}
